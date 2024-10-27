/*
UCCD2303 DATABASE TECHNOLOGY
INDIVIDUAL ASSIGNMENT SUBMISSION

GROUP NUMBER : G090
PROGRAMME : CS
STUDENT ID : 2206932
STUDENT NAME : TAN KIA YEE
Submission date and time: 16-04-24
*/


/*Query 1: Show price of ticket after promotion for the Chinese new year promotion*/
SELECT t.Tic_ID, t.Tic_Name, t.PRICE AS "Original Price",
        p.Dis_Percent AS "Promotion Discount",
        TO_CHAR(t.PRICE - (t.PRICE* (p.Dis_Percent/100)),'$999999.99') AS "Price after promotion"
FROM TICKET t JOIN PAYMENT y
ON t.Tic_ID=y.Tic_ID
JOIN PROMOTION p
ON p.Prom_ID = y.Prom_ID
WHERE p.Prom_Name = 'CNY promotion'
ORDER BY t.Tic_ID;

/*Query 2: Show information of customer that membership expired and calculate the total days that expired*/
SELECT 
    cus.cus_id, 
    cus.cus_name, 
    cus.cus_email, 
    cus.cus_contact, 
    mem.mem_expdate,
    TRUNC(SYSDATE - mem.mem_expdate) AS "Total Day Expired"
FROM customer cus
JOIN membership mem 
ON cus.mem_id = mem.mem_id
WHERE mem.mem_expdate < SYSDATE;

/*Procedure 1: Add a new game record into the Game table*/

CREATE OR REPLACE PROCEDURE add_new_game(
    p_game_id     VARCHAR2,
    p_tic_id      VARCHAR2,
    p_game_name   VARCHAR2,
    p_min_player  NUMBER,
    p_max_player  NUMBER,
    p_game_type   VARCHAR2,
    p_duration    NUMBER
)
IS
BEGIN
    INSERT INTO game(game_id, tic_id, game_name, min_player, max_player, game_type, duration)
    VALUES (p_game_id, p_tic_id, p_game_name, p_min_player, p_max_player, p_game_type, p_duration);

    DBMS_OUTPUT.PUT_LINE('New game record added successfully.');

EXCEPTION
    WHEN DUP_VAL_ON_INDEX THEN
        DBMS_OUTPUT.PUT_LINE('Error: Game ID already exists.');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
END add_new_game;
/

BEGIN
    add_new_game('G011', 'T004', 'Fortnite', 1, 4, 'PC game', 40);
END;
/


/*Procedure 2: Update the minimum player to 1 if the duration of game is less than 30 minutes, 
otherwise update the minimum player to 2 if the duration of game is equal or more than 30 minutes.
 Display the game id that successfully updated. */

-- Enable DBMS_OUTPUT
SET SERVEROUTPUT ON SIZE 1000000;

CREATE OR REPLACE PROCEDURE UpdateGameMinPlayer
IS
    CURSOR game_cursor IS
        SELECT game_id, duration, min_player
        FROM game
        WHERE duration >= 30 OR duration < 30;
    
    v_game_id game.game_id%TYPE;
    v_duration game.duration%TYPE;
    v_min_player game.min_player%TYPE;
BEGIN
    -- Open the cursor
    OPEN game_cursor;
    
    -- Fetch and update min_player based on duration
    LOOP
        FETCH game_cursor INTO v_game_id, v_duration, v_min_player;
        
        EXIT WHEN game_cursor%NOTFOUND;
        
        IF v_duration >= 30 AND v_min_player != 2 THEN
            UPDATE game
            SET min_player = 2
            WHERE game_id = v_game_id;
            
            -- Display the updated game_id
            DBMS_OUTPUT.PUT_LINE('Game with game_id ' || v_game_id || ' updated successfully. min_player updated to 2.');
            
        ELSIF v_duration < 30 AND v_min_player != 1 THEN
            UPDATE game
            SET min_player = 1
            WHERE game_id = v_game_id;
            
            -- Display the updated game_id
            DBMS_OUTPUT.PUT_LINE('Game with game_id ' || v_game_id || ' updated successfully. min_player updated to 1.');
        
        END IF;
        
    END LOOP;
    
    -- Close the cursor
    CLOSE game_cursor;

EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
END UpdateGameMinPlayer;
/

-- Execute the procedure
EXEC UpdateGameMinPlayer;


/* Function 1: Create a function to show the most amount of ticket sold*/
CREATE OR REPLACE FUNCTION find_most_sold_ticket
RETURN VARCHAR2
IS
    v_tic_id payment.tic_id%TYPE;
    v_sold_count NUMBER;
    v_total_tickets_sold NUMBER;

BEGIN
    SELECT Tic_ID, COUNT(*) as sold_count, SUM(Total_Tic) as total_tickets_sold
    INTO v_tic_id, v_sold_count, v_total_tickets_sold
    FROM PAYMENT
    GROUP BY Tic_ID
    ORDER BY sold_count DESC, total_tickets_sold DESC
    FETCH FIRST 1 ROW ONLY;

    DBMS_OUTPUT.PUT_LINE('Most sold-out ticket ID: ' || v_tic_id);
    DBMS_OUTPUT.PUT_LINE('Sold Count: ' || v_sold_count);
    DBMS_OUTPUT.PUT_LINE('Total Tickets Sold: ' || v_total_tickets_sold);

    RETURN v_tic_id;

EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No tickets found.');
        RETURN NULL;
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
        RETURN NULL;

END find_most_sold_ticket;
/

DECLARE
    most_sold_tic_id VARCHAR2(10);
BEGIN
    most_sold_tic_id := find_most_sold_ticket;
    DBMS_OUTPUT.PUT_LINE('Most sold-out ticket ID: ' || most_sold_tic_id);
END;
/



/* Function 2: Calculate the total money receive*/

CREATE OR REPLACE FUNCTION calculate_total_money_received RETURN NUMBER
IS
    v_total_amount NUMBER := 0;
BEGIN
    -- Calculate the total amount for each payment
    FOR rec IN (
        SELECT (t.price * p.total_tic * (1 - NVL(prom.dis_percent, 0) / 100)) AS amount
        FROM payment p
        JOIN ticket t ON p.tic_id = t.tic_id
        LEFT JOIN promotion prom ON p.prom_id = prom.prom_id
    )
    LOOP
        v_total_amount := v_total_amount + rec.amount;
    END LOOP;

    RETURN v_total_amount;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        RETURN NULL;
    WHEN OTHERS THEN
        RAISE;
END calculate_total_money_received;
/

DECLARE
    v_money_received NUMBER;
BEGIN
    v_money_received := calculate_total_money_received();
    DBMS_OUTPUT.PUT_LINE('Total money received: ' || v_money_received);
END;
/




