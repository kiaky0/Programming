---- script to create The Big Dipper Game Ticket Sales System ---- 
/*
COURSE CODE: UCCD2303
PROGRAMME (IA/IB/CS)/DE: CS
GROUP NUMBER e.g. G001: G090
GROUP LEADER NAME & EMAIL: TAN QI YANG & tanqiyang02@1utar.my
MEMBER 2 NAME: TAN KIA YEE 
MEMBER 3 NAME: LIM PHAI YUAN
MEMBER 4 NAME: OOI KHAI SHEN
Submission date and time (DD-MON-YY): 16-APR-24
*/



DROP TABLE prizeredemption CASCADE CONSTRAINTS;
DROP TABLE prize CASCADE CONSTRAINTS;
DROP TABLE membership CASCADE CONSTRAINTS;
DROP TABLE customer CASCADE CONSTRAINTS;
DROP TABLE promotion CASCADE CONSTRAINTS;
DROP TABLE game CASCADE CONSTRAINTS;
DROP TABLE gameinteraction CASCADE CONSTRAINTS;
DROP TABLE staff CASCADE CONSTRAINTS;
DROP TABLE ticket CASCADE CONSTRAINTS;
DROP TABLE payment CASCADE CONSTRAINTS;
DROP TABLE gstaff CASCADE CONSTRAINTS;
DROP TABLE pstaff CASCADE CONSTRAINTS;


Prompt ******  Creating prize table ****** 

CREATE TABLE prize
    ( prize_id      VARCHAR2(10)  NOT NULL
	, prize_name	VARCHAR2(40) NOT NULL
	, redeem_point	INTEGER NOT NULL
	, quantity		INTEGER  NOT NULL 
    );

ALTER TABLE prize
ADD ( CONSTRAINT prize_id_pk
       		 PRIMARY KEY (prize_id)
    ) ;

Prompt ******  Creating membership table ****** 

CREATE TABLE membership
    ( mem_id      VARCHAR2(10)  NOT NULL
	, mem_expdate DATE NOT NULL
	, mem_tier VARCHAR2(20) 
	   CONSTRAINT check_tier CHECK (mem_tier in('basic','premium') )
	, point_allocate INTEGER NOT NULL
    );

ALTER TABLE membership
ADD ( CONSTRAINT mem_id_pk
       		 PRIMARY KEY (mem_id)
    ) ;



Prompt ******  Creating prizeredemption table ****** 

CREATE TABLE prizeredemption
    ( mem_id      VARCHAR2(10) NOT NULL
    , prize_id		VARCHAR2(10) NOT NULL
    );

ALTER TABLE prizeredemption
ADD (  
		CONSTRAINT mem_prize_id PRIMARY KEY (mem_id,prize_id)
	,	CONSTRAINT prizeredeem_mem_fk
			FOREIGN KEY (mem_id)
			REFERENCES membership(mem_id)
	,  CONSTRAINT prizeredeem_prize_fk
			FOREIGN KEY (prize_id)
			REFERENCES prize(prize_id)
    ) ;
	
	
	
Prompt ******  Creating CUSTOMER table ****** 

CREATE TABLE customer
    ( cus_id      VARCHAR2(10)  NOT NULL 
	, mem_id 	VARCHAR2(10)
    , cus_name    VARCHAR2(50)  NOT NULL 
	, cus_email VARCHAR2(50)  
	, cus_contact VARCHAR2(20)  
    );

ALTER TABLE customer
ADD ( CONSTRAINT cus_id_pk
       		 PRIMARY KEY (cus_id)
	, CONSTRAINT cus_mem_fk
			FOREIGN KEY (mem_id)
			REFERENCES membership(mem_id)
    ) ;



Prompt ******  Creating TICKET table ****** 
CREATE TABLE ticket
    ( tic_id      VARCHAR2(10)  NOT NULL 
	, tic_name VARCHAR2(25)  NOT NULL 
	, price NUMBER(10,2)  NOT NULL 
    );

ALTER TABLE ticket
ADD ( CONSTRAINT tic_id_pk
       		 PRIMARY KEY (tic_id)
    ) ;
	
	
Prompt ******  Creating STAFF table ****** 
CREATE TABLE staff
    ( staff_id      VARCHAR2(10)  NOT NULL 
    , staff_name    VARCHAR2(20)  NOT NULL 
	, staff_contact  VARCHAR2(20)
	, basic_salary NUMBER(15)  NOT NULL 
    );

ALTER TABLE staff
ADD ( CONSTRAINT staff_id_pk
       		 PRIMARY KEY (staff_id)
    ) ;
	

Prompt ******  Creating GAMESTAFF table ****** 
CREATE TABLE gstaff
    ( gstaff_id      VARCHAR2(10)  NOT NULL 
    , staff_id VARCHAR2(10)  NOT NULL 
	, monitor_rate NUMBER(10,2) 
    );

ALTER TABLE gstaff
ADD ( CONSTRAINT gstaff_id_pk
       		 PRIMARY KEY (gstaff_id)
	, CONSTRAINT gstaff_staff_fk
			FOREIGN KEY (staff_id)
			REFERENCES staff(staff_id)
    ) ;
	
	Prompt ******  Creating PAYMENTSTAFF table ****** 
CREATE TABLE pstaff
    ( pstaff_id      VARCHAR2(10)  NOT NULL 
    , staff_id VARCHAR2(10)  NOT NULL 
	,commision DECIMAL(10,2)
    );

ALTER TABLE pstaff
ADD ( CONSTRAINT pstaff_id_pk
       		 PRIMARY KEY (pstaff_id)
	, CONSTRAINT pstaff_staff_fk
			FOREIGN KEY (staff_id)
			REFERENCES staff(staff_id)
    ) ;
	
Prompt ******  Creating PROMOTIONStable ****** 
CREATE TABLE promotion
    ( prom_id      VARCHAR2(10)  NOT NULL 
    , prom_name    VARCHAR2(20)  NOT NULL 
	, dis_percent   NUMBER(20) CONSTRAINT discheck CHECK(dis_percent BETWEEN 0 AND 100)
	, start_date DATE NOT NULL 
	, expiry_date DATE NOT NULL 
    );

ALTER TABLE promotion
ADD ( CONSTRAINT promotion_id_pk
       		 PRIMARY KEY (prom_id)
    ) ;
	
	
	
Prompt ******  Creating PAYMENT table ****** 
CREATE TABLE payment
    ( pay_id      VARCHAR2(10)  NOT NULL 
	, tic_id VARCHAR2(10) NOT NULL 
	, cus_id VARCHAR2(10) NOT NULL 
	, staff_id VARCHAR2(10) NOT NULL 
	, prom_id VARCHAR2(10)
    , pay_type VARCHAR2(20) CONSTRAINT paycheck CHECK(pay_type='Cash' OR 
	pay_type='Credit Card' OR pay_type='Debit Card' OR pay_type='Online Payment' 
	OR pay_type='Ewallet' OR pay_type='Others')
	, pay_date  DATE NOT NULL 
	, total_tic NUMBER(4) NOT NULL 
    );


ALTER TABLE payment
ADD ( CONSTRAINT pay_id_pk
       		 PRIMARY KEY (pay_id)
	, CONSTRAINT pay_tic_fk
			FOREIGN KEY (tic_id)
			REFERENCES ticket(tic_id)
	, CONSTRAINT pay_cus_fk
			FOREIGN KEY (cus_id)
			REFERENCES customer(cus_id)
	, CONSTRAINT paym_staff_fk
			FOREIGN KEY (staff_id)
			REFERENCES staff(staff_id)
	, CONSTRAINT pay_prom_fk
			FOREIGN KEY (prom_id)
			REFERENCES promotion(prom_id)
    );
	



		
Prompt ******  Creating GAME table ****** 
CREATE TABLE game
    ( game_id      VARCHAR2(10)  NOT NULL 
	, tic_id VARCHAR2(10) NOT NULL 
    , game_name    VARCHAR2(30) NOT NULL 
	, min_player NUMBER(10) CONSTRAINT minplayer CHECK(min_player>0)
	, max_player NUMBER(10) CONSTRAINT maxplayer CHECK(max_player>0) 
	, game_type 	VARCHAR2(20) CONSTRAINT gamecheck CHECK(game_type='Arcade game' OR
	game_type='PC game' OR game_type='Mobile game' OR game_type='Board game' OR
	game_type='VR game')
	, duration NUMBER(10) CONSTRAINT durationcheck CHECK(duration>0)
    );

	
	
ALTER TABLE game
ADD ( CONSTRAINT game_id_pk
       		 PRIMARY KEY (game_id)
	, CONSTRAINT game_tic_fk
			FOREIGN KEY (tic_id)
			REFERENCES ticket(tic_id)
    ) ;

		
Prompt ******  Creating GAMEINTERACTION table ****** 
CREATE TABLE gameinteraction
    ( gi_id     VARCHAR2(10)  NOT NULL 
	,cus_id VARCHAR2(10) NOT NULL
	, game_id VARCHAR2(10) NOT NULL
	, staff_id VARCHAR2(10) 
	, interactiondate DATE NOT NULL
	, interactiontime NUMBER(20) NOT NULL
    );

ALTER TABLE gameinteraction
ADD ( CONSTRAINT gi_id_pk
       		 PRIMARY KEY (gi_id)
	, CONSTRAINT gi_cus_fk
			FOREIGN KEY (cus_id)
			REFERENCES customer(cus_id)
	, CONSTRAINT gi_game_fk
			FOREIGN KEY (game_id)
			REFERENCES game(game_id)
	, CONSTRAINT gi_staff_fk
			FOREIGN KEY (staff_id)
			REFERENCES staff(staff_id)
    ) ;
	
	

	



	

Prompt ******  Populating prize table ....
INSERT INTO prize VALUES ( 'PR001','Nintendo switch', '10', '3');
INSERT INTO prize VALUES ( 'PR002','Play station 5', '30', '2');
INSERT INTO prize VALUES ( 'PR003','Marshall Acton', '20', '2');
INSERT INTO prize VALUES ( 'PR004','Apple Vision Pro', '35', '0');
INSERT INTO prize VALUES ( 'PR005','Fujifilm Instax', '15', '2');

Prompt ******  Populating MEMBERSHIP table ....
INSERT INTO membership VALUES ( 'M001',to_date('09-12-2025','DD-MM-YYYY'), 'premium', '30');
INSERT INTO membership VALUES ( 'M002',to_date('18-03-2022','DD-MM-YYYY'),  'basic', '23');
INSERT INTO membership VALUES ( 'M003',to_date('03-08-2025','DD-MM-YYYY'),  'basic', '45');
INSERT INTO membership VALUES ( 'M004',to_date('24-02-2026','DD-MM-YYYY'),  'premium', '24');
INSERT INTO membership VALUES ( 'M005',to_date('07-10-2025','DD-MM-YYYY'),  'premium', '12');
	
	
	
Prompt ******  Populating prizeredemption table ....
INSERT INTO prizeredemption VALUES ( 'M001','PR001');
INSERT INTO prizeredemption VALUES ( 'M001','PR002');
INSERT INTO prizeredemption VALUES ( 'M003','PR003');
INSERT INTO prizeredemption VALUES ( 'M004','PR003');
INSERT INTO prizeredemption VALUES ( 'M005','PR005');


Prompt ******  Populating CUSTOMER table ....
INSERT INTO customer VALUES ( 'C001','M001','Jane Doe','jane.doe@gmail.com','011-345-6789');
INSERT INTO customer VALUES ( 'C002',NULL,'John Smith','john.smith@gmail.com','013-456-7890');
INSERT INTO customer VALUES ( 'C003','M002','Michael Johnson','michael.johnson@gmail.com','014-567-8901');
INSERT INTO customer VALUES ( 'C004',NULL,'Emily Brown','emily.brown@gmail.com','015-678-9012');
INSERT INTO customer VALUES ( 'C005',NULL,'Christopher Lee','christopher.lee@gmail.com','016-789-0123');
INSERT INTO customer VALUES ( 'C006','M003','Sarah Johnson','sarah.johnson@gmail.com','017-890-1234');
INSERT INTO customer VALUES ( 'C007','M004','William Wilson','william.wilson@gmail.com','018-901-2345');
INSERT INTO customer VALUES ( 'C008','M005','Jessica Taylor','jessica.taylor@gmail.com','019-012-3456');
INSERT INTO customer VALUES ( 'C009',NULL,'Daniel Martinez','daniel.martinez@gmail.com','011-123-4567');
INSERT INTO customer VALUES ( 'C010',NULL,'Amanda Clark','amanda.clark@gmail.com','010-234-5678');



Prompt ******  Populating TICKET table ....
INSERT INTO ticket VALUES ( 'T001','VR game ticket',10.00);
INSERT INTO ticket VALUES ( 'T002','PC game ticket',6.50);
INSERT INTO ticket VALUES ( 'T003','Board game ticket',3.00);
INSERT INTO ticket VALUES ( 'T004','Mobile game ticket',5.00);
INSERT INTO ticket VALUES ( 'T005','Arcade game ticket',2.80);
		


Prompt ******  Populating STAFF table ....
INSERT INTO staff VALUES ( 'S001','Ashley Garcia','012-890-1234',2000);
INSERT INTO staff VALUES ( 'S002','Matthew Rodriguez','013-901-2345',2000);
INSERT INTO staff VALUES ( 'S003','Olivia Nguyen','014-012-3456',2000);
INSERT INTO staff VALUES ( 'S004','Ethan Cooper','015-123-4567',2500);
INSERT INTO staff VALUES ( 'S005','Sophia Rivera','016-234-5678',2500);
INSERT INTO staff VALUES ( 'S006','Tyler Patel','017-345-6789',2000);
INSERT INTO staff VALUES ( 'S007','Chloe Martinez','018-456-7890',2500);
INSERT INTO staff VALUES ( 'S008','Jacob Adams','019-567-8901',2500);
INSERT INTO staff VALUES ( 'S009','Grace Mitchell','011-678-9012',2000);
INSERT INTO staff VALUES ( 'S010','Ryan Campbell','010-789-0123',2500);




Prompt ******  Populating GAMESTAFF table ....
INSERT INTO gstaff VALUES ( 'GS001','S004',8.00);
INSERT INTO gstaff VALUES ( 'GS002','S010',10.00);
INSERT INTO gstaff VALUES ( 'GS003','S005',9.50);
INSERT INTO gstaff VALUES ( 'GS004','S007',8.00);
INSERT INTO gstaff VALUES ( 'GS005','S008',8.50);


Prompt ******  Populating PAYMENTSTAFF table ....
INSERT INTO pstaff VALUES ( 'PS001','S001',0.20);
INSERT INTO pstaff VALUES ( 'PS002','S006',0.50);
INSERT INTO pstaff VALUES ( 'PS003','S002',0.40);
INSERT INTO pstaff VALUES ( 'PS004','S003',null);
INSERT INTO pstaff VALUES ( 'PS005','S009',0.2);


Prompt ******  Populating PROMOTION table ....
INSERT INTO promotion VALUES ( 'R001','CNY promotion',10,to_date('25-01-2024','DD-MM-YYYY'), to_date('10-02-2024','DD-MM-YYYY'));
INSERT INTO promotion VALUES ( 'R002','Hari Raya promotion',20,to_date('03-04-2024','DD-MM-YYYY'), to_date('20-04-2024','DD-MM-YYYY'));
INSERT INTO promotion VALUES ( 'R003','Christmas promotion',15,to_date('25-12-2024','DD-MM-YYYY'), to_date('01-01-2025','DD-MM-YYYY'));
INSERT INTO promotion VALUES ( 'R004','Deepavali promotion',15,to_date('01-11-2024','DD-MM-YYYY'), to_date('15-11-2024','DD-MM-YYYY'));
INSERT INTO promotion VALUES ( 'R005','New year promotion',30,to_date('01-01-2024','DD-MM-YYYY'), to_date('15-01-2024','DD-MM-YYYY'));

Prompt ******  Populating PAYMENT table ....
INSERT INTO payment VALUES ( 'P001','T001','C001','S001','R001','Ewallet',to_date('09-01-2024','DD-MM-YYYY'),2);
INSERT INTO payment VALUES ( 'P002','T001','C001','S001','R001','Credit Card',to_date('10-01-2024','DD-MM-YYYY'),1);
INSERT INTO payment VALUES ( 'P003','T003','C006','S002',NULL,'Debit Card',to_date('15-01-2024','DD-MM-YYYY'),3);
INSERT INTO payment VALUES ( 'P004','T005','C004','S001',NULL,'Cash',to_date('19-01-2024','DD-MM-YYYY'),4);
INSERT INTO payment VALUES ( 'P005','T005','C003','S002',NULL,'Ewallet',to_date('09-02-2024','DD-MM-YYYY'),1);
INSERT INTO payment VALUES ( 'P006','T003','C009','S001','R003','Credit Card',to_date('09-02-2024','DD-MM-YYYY'),2);
INSERT INTO payment VALUES ( 'P007','T002','C010','S003','R002','Cash',to_date('11-03-2024','DD-MM-YYYY'),4);
INSERT INTO payment VALUES ( 'P008','T004','C005','S002',NULL,'Ewallet',to_date('08-04-2024','DD-MM-YYYY'),5);
INSERT INTO payment VALUES ( 'P009','T005','C004','S003',NULL,'Cash',to_date('09-04-2024','DD-MM-YYYY'),1);
INSERT INTO payment VALUES ( 'P010','T003','C008','S001','R001','Debit Card',to_date('10-04-2024','DD-MM-YYYY'),9);


Prompt ******  Populating GAME table ....
INSERT INTO game VALUES ( 'G001','T001','Cyberpunk',1,4,'VR game',10);
INSERT INTO game VALUES ( 'G002','T001','Beat Saber',1,1,'VR game',20);
INSERT INTO game VALUES ( 'G003','T004','Mobile Legend Bang Bang',1,5,'Mobile game',30);
INSERT INTO game VALUES ( 'G004','T002','Overcooked!2',1,4,'PC game',20);
INSERT INTO game VALUES ( 'G005','T003','Pokemon Trading Card Game',2,2,'Board game',15);
INSERT INTO game VALUES ( 'G006','T002','League of Legends',1,5,'PC game',40);
INSERT INTO game VALUES ( 'G007','T005','Pac-Man',1,1,'Arcade game',10);
INSERT INTO game VALUES ( 'G008','T004','Clash Royale',1,4,'Mobile game',10);
INSERT INTO game VALUES ( 'G009','T005','Street Fighter',2,2,'Arcade game',5);
INSERT INTO game VALUES ( 'G010','T003','YuGiOH',2,2,'Board game',15);



Prompt ******  Populating GAMEINTERACTION table ....
INSERT INTO gameinteraction VALUES ( 'GI001','C001','G006','S004',to_date('09-01-2024','DD-MM-YYYY'),1200);
INSERT INTO gameinteraction VALUES ( 'GI002','C002','G006','S004',to_date('10-01-2024','DD-MM-YYYY'),1100);
INSERT INTO gameinteraction VALUES ( 'GI003','C006','G010','S005',to_date('15-01-2024','DD-MM-YYYY'),1400);
INSERT INTO gameinteraction VALUES ( 'GI004','C004','G009','S007',to_date('19-01-2024','DD-MM-YYYY'),1530);
INSERT INTO gameinteraction VALUES ( 'GI005','C003','G007','S008',to_date('09-02-2024','DD-MM-YYYY'),1600);
INSERT INTO gameinteraction VALUES ( 'GI006','C009','G010','S005',to_date('09-02-2024','DD-MM-YYYY'),1500);
INSERT INTO gameinteraction VALUES ( 'GI007','C010','G006','S007',to_date('11-03-2024','DD-MM-YYYY'),1000);
INSERT INTO gameinteraction VALUES ( 'GI008','C005','G008','S008',to_date('08-04-2024','DD-MM-YYYY'),1230);
INSERT INTO gameinteraction VALUES ( 'GI009','C004','G009','S008',to_date('09-04-2024','DD-MM-YYYY'),1300);
INSERT INTO gameinteraction VALUES ( 'GI010','C008','G005','S004',to_date('10-04-2024','DD-MM-YYYY'),1400);


