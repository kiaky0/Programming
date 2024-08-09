#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include <cstring>
#include <cctype>

using namespace std;

void userUI();
void loginadmin();
void admin();
void home();
void mainpage();

// admin interf func
void addMovie();
void editMovie();
void deleteMovie();
void ViewTrans();
void adminShowMovie();

//login/register func
void LoginResgister();
void Register();
void Login();
bool userExist(string email_1);

// user interf func
void showMovie();
void bookMovie();
void showHistory();
void cancelBooking();
void paybill();

// pls call when u want to use array
void storeInfoInArray(int&);
void storeBookedInfoInArray(int&);


// store info in array
// every one can use the array
string MovieTitle[100], MovieDesc[100];
double MoviePrice[100] = { 0 };
int MovieSeat[100];
string startTime[100], endTime[100];
short i = 0;
string title, describe;
double price;
int seat;
string sTime, eTime;
double totalPrice = 0;

// booked item
int totalBookedMovie = 0;
string btitle;
int bSeat;
double bprice;
string bStartTime, bEndTime;
string bMovietitle[100];
string bMovieStartTime[100], bMovieEndTime[100];
int bNumMovieSeat[100];
double bMoviePrice[100];
string paidStatus = "No Paid";
// Global Variable
int totalMovie = 0;

// user info
string username;

// main function
int main()
{
	cout << fixed << setprecision(2);
	mainpage();
	home();
}

void mainpage()
{
	cout << "\t\t[] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ []^" << endl;
	cout << "\t\t ^      __ __                                    _______                  __           []" << endl;
	cout << "\t\t[]     / //_/___ _____ ___  ____  ____ ______   / ____(_)___  ___  ____  / /__  _  __  ^" << endl;
	cout << "\t\t ^    / ,< / __ `/ __ `__ \\/ __ \\/ __ `/ ___/  / /   / / __ \\/ _ \\/ __ \\/ / _ \\| |/_/  []" << endl;
	cout << "\t\t[]   / /| / /_/ / / / / / / /_/ / /_/ / /     / /___/ / / / /  __/ /_/ / /  __/>  <    ^" << endl;
	cout << "\t\t ^  /_/ |_\\__,_/_/ /_/ /_/ .___/\\__,_/_/      \\____/_/_/ /_/\\___/ .___/_/\\___/_/|_|    [] " << endl;
	cout << "\t\t[]                      /_/                                    /_/                     ^" << endl;
	cout << "\t\t ^                                                                                     []" << endl;
	cout << "\t\t[]\t\t\t\t\t\t\t\t\t\t       ^" << endl;
	cout << "\t\t ^\t\t\t\t\t\t\t\t\t\t       []" << endl;
	cout << "\t\t[]      __ __ __   ______   __       ______   ______   ___ __ __   ______               ^" << endl;
	cout << "\t\t ^     /_//_//_/\\ /_____/\\ /_/\\     /_____/\\ /_____/\\ /__//_//_/\\ /_____/\\             [] " << endl;
	cout << "\t\t[]     \\:\\\\:\\\\:\\ \\\\::::_\\/_\\:\\ \\    \\:::__\\/ \\:::_ \\ \\\\::\\| \\| \\ \\\\::::_\\/_            ^" << endl;
	cout << "\t\t ^      \\:\\\\:\\\\:\\ \\\\:\\/___/\\\\:\\ \\    \\:\\ \\  __\\:\\ \\ \\ \\\\:.      \\ \\\\:\\/___/\\	       []" << endl;
	cout << "\t\t[]       \\:\\\\:\\\\:\\ \\\\::___\\/_\\:\\ \\____\\:\\ \\/_/\\\\:\\ \\ \\ \\\\:.\\-/\\  \\ \\\\::___\\/_	       ^" << endl;
	cout << "\t\t ^        \\:\\\\:\\\\:\\ \\\\:\\____/\\\\:\\/___/\\\\:\\_\\ \\ \\\\:\\_\\ \\ \\\\. \\  \\  \\ \\\\:\\____/\\         []" << endl;
	cout << "\t\t[]         \\_______\\/ \\_____\\/ \\_____\\/ \\_____\\/ \\_____\\/ \\__\\/ \\__\\/ \\_____\\/	       ^" << endl;
	cout << "\t\t ^\t\t\t\t\t\t\t\t\t\t       []" << endl;
	cout << "\t\t[]\t\t\t\t\t\t\t\t\t\t       ^" << endl;
	cout << "\t\t ^\t\t\t\t\t\t\t\t\t\t       []" << endl;
	cout << "\t\t[]\t\t\t\t\t\t\t\t\t\t       ^" << endl;
	cout << "\t\t ^\t\t\t\t\t\t\t\t\t\t       []" << endl;
	cout << "\t\t[] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^ [] ^[] ^" << endl << endl << endl << endl;
	cout << "\t\t    ";
	system("pause");
}

void home()
{
	system("cls");
	cout << " _______         _                  ____                                 _                          _" << endl;
	cout << "(_______) _     (_)_   ____  _     (____)                ____           (_)                   ____ (_) _            " << endl;
	cout << "   (_)   (_)__  (___) (____)(_)__ (_)__    ____    ___  (____)      ___ (_)__    ___    ___  (____) _ (_)__    ____ " << endl;
	cout << "   (_)   (____) (_)  (_)_(_)(____)(____)  (____) _(___)(_)_(_)    _(___)(____)  (___)  (___) (_)__ (_)(____)  (____)" << endl;
	cout << " __(_)__ (_) (_)(_)_ (__)__ (_)   (_)    ( )_( )(_)___ (__)__    (_)___ (_) (_)(_)_(_)(_)_(_) _(__)(_)(_) (_)( )_(_)" << endl;
	cout << "(_______)(_) (_) (__) (____)(_)   (_)     (__)_) (____) (____)    (____)(_) (_) (___)  (___) (____)(_)(_) (_) (____)" << endl;
	cout << "                                                                                                             (_)_(_)" << endl;
	cout << "                                                                                                              (___) " << endl;
	char interfaceChoose[10];
	cout << endl;
	cout << endl;
	cout << "\t***please choose your interface before further action***" << endl << endl;
	cout << "\t================= " << "\t" << "================= " << "\t" << "================= " << endl;
	cout << "\t#  !! ADMIN[A]  # " << "\t" << "#  !! GUEST[G]  # " << "\t" << "#  !! EXIT[E]   # " << endl;
	cout << "\t================= " << "\t" << "================= " << "\t" << "================= " << endl;
	cout << endl;

	do
	{
		cout << "\tPlease Choose The Interface: ";
		cin >> interfaceChoose;
		if (strlen(interfaceChoose) != 1)
		{
			cout << "\tInvalid Input. Please Enter One Character Only." << endl;
			cout << "\t-----------------------------------------------" << endl << endl;
			continue;
		}
		else if (strcmp(interfaceChoose, "A") == 0 || strcmp(interfaceChoose, "a") == 0)
		{
			loginadmin();
		}
		else if (strcmp(interfaceChoose, "G") == 0 || strcmp(interfaceChoose, "g") == 0)
		{
			LoginResgister();
			userUI();
		}
		else if (strcmp(interfaceChoose, "E") == 0 || strcmp(interfaceChoose, "e") == 0)
		{
			cout << "\tSee You Again >_<" << endl;
			exit(0);
			system("pause");
		}
		else
		{
			cout << "\tInvalid Input.Please Key In (A,G,E) Only." << endl;
			cout << "\t-----------------------------------------" << endl << endl;
		}
	} while (strcmp(interfaceChoose, "A") != 0 && strcmp(interfaceChoose, "a") != 0
		&& strcmp(interfaceChoose, "G") != 0 && strcmp(interfaceChoose, "g") != 0
		&& strcmp(interfaceChoose, "E") != 0 && strcmp(interfaceChoose, "e") != 0);
}

//***********************************************
//	
//			
//        below all admin interface!!!!!!
//
//
//************************************************

void loginadmin()
{
	char id[50];
	char pass[50];
	bool correct = true;
	do
	{
		system("cls");
		cout << "  :::         ::::::::   ::::::::  ::::::::::  :::::   ::: " << endl;
		cout << "  :+:        :+:    :+: :+:    :+:     :+:     :+:+:   :+: " << endl;
		cout << "  +:+        +:+    +:+ +:+            +:+     :+:+:+  +:+ " << endl;
		cout << "  +#+        +#+    +:+ :#:            +#+     +#+ +:+ +#+ " << endl;
		cout << "  +#+        +#+    +#+ +#+   +#+#     +#+     +#+  +#+#+# " << endl;
		cout << "  #+#        #+#    #+# #+#    #+#     #+#     #+#   #+#+# " << endl;
		cout << "  ##########  ########   ########  ########### ###    #### \n\n\n";
		cout << "\t<< Welcome Admin >>" << endl;
		cout << "\t~~~~~~~~~~~~~~~~~~~" << endl << endl;
		cout << "\tUsername: ";
		cin >> id;
		if (strcmp(id, "admin") == 0)
		{
			cout << "\tPassword: ";
			cin >> pass;
			cout << endl;
			if (strcmp(pass, "admin") == 0)
			{
				cout << "\t***Correct Username and Password***" << endl;
				correct = false;
				cout << endl;
				cout << "\t";
				system("pause");
				admin();
			}
			else
			{
				cout << "\t !! Wrong password.Please Try Again" << endl;
				cout << "\t\t  [Hint: admin]" << endl << endl << endl << endl;
				cout << "\t";
				system("pause");
			}
		}
		else
		{
			cout << "\t !! Wong username.Please Try Again" << endl;
			cout << "\t\t  [Hint: admin]" << endl << endl << endl;
			cout << "\t";
			system("pause");
		}
	} while (correct == true);
}

void admin()
{

	system("cls");
	char choice[20];
	bool stop = true;
	cout << " ________   ______   ___ __ __    ________  ___   __" << endl;
	cout << "/_______/\\ /_____/\\ /__//_//_/\\  /_______/\\/__/\\ /__/\\    " << endl;
	cout << "\\::: _  \\ \\\\:::_ \\ \\\\::\\| \\| \\ \\ \\__.::._\\/\\::\\_\\\\  \\ \\   " << endl;
	cout << " \\::(_)  \\ \\\\:\\ \\ \\ \\\\:.      \\ \\   \\::\\ \\  \\:. `-\\  \\ \\  " << endl;
	cout << "  \\:: __  \\ \\\\:\\ \\ \\ \\\\. \\-/\\  \\ \\  _\\::\\ \\__\\:. _    \\ \\ " << endl;
	cout << "   \\:.\\ \\  \\ \\\\:\\/.:| |\\. \\  \\  \\ \\/__\\::\\__/\\\\. \\`-\\  \\ \\" << endl;
	cout << "    \\__\\/\\__\\/ \\____/_/ \\__\\/ \\__\\/\\________\\/ \\__\\/ \\__\\/" << endl << endl << endl << endl;
	cout << "\t## What's the plan taday ?" << endl << endl;
	cout << "\t------------MAIN MENU------------" << endl << endl;
	cout << "\t\t[1] Show Movie	                " << endl << endl;
	cout << "\t\t[2] Add Movie	                " << endl << endl;
	cout << "\t\t[3] Edit Movie		            " << endl << endl;
	cout << "\t\t[4] Delete Movie		        " << endl << endl;
	cout << "\t\t[5] View Transaction		    " << endl << endl;
	cout << "\t\t[6] Main Page	                " << endl << endl;
	cout << "\t\t[7] Exit Program	            " << endl << endl;
	cout << "\t---------------------------------" << endl << endl;


	do
	{
		cout << "\tYour choice: ";
		cin >> choice;
		if (strlen(choice) != 1)
		{
			cout << " \t!! Please Key In One Integer Only !! " << endl << endl;
			continue;
		}
		else
		{
			if (strcmp(choice, "1") == 0)
			{
				adminShowMovie();
				break;
			}
			else if (strcmp(choice, "2") == 0)
			{
				addMovie();
				break;
			}
			else if (strcmp(choice, "3") == 0)
			{
				editMovie();
				break;
			}
			else if (strcmp(choice, "4") == 0)
			{
				deleteMovie();
				break;
			}
			else if (strcmp(choice, "5") == 0)
			{
				ViewTrans();
				break;
			}
			else if (strcmp(choice, "6") == 0)
			{
				home();
				break;
			}
			else if (strcmp(choice, "7") == 0)
			{
				exit(0);
				system("pause");
			}
			else
			{
				cout << " \t!! Please Key In (1-7) Only !!" << endl << endl;
				continue;
			}
		}
	} while (stop == true);
}


void adminShowMovie()
{
	cout << fixed << setprecision(2);

	system("cls");
	cout << "\n\t\t\t== Movie List == " << endl << endl << endl;
	storeInfoInArray(totalMovie);
	for (int i = 0; i < totalMovie - 1; i++)
	{
		cout << "\t================================================================" << endl;
		cout << "\t\tMovie " << i + 1 << " : <" << MovieTitle[i] << "> " << endl;
		cout << "\t================================================================" << endl;
		cout << "\tDescription of movie: " << MovieDesc[i] << endl;
		cout << fixed << setprecision(2);
		cout << "\tPrice RM " << MoviePrice[i] << endl;
		cout << "\tAvailable Seat: " << MovieSeat[i] << endl;
		cout << "\tStart Time: " << startTime[i] << endl;
		cout << "\tEnd Time: " << endTime[i] << endl;
		cout << endl << endl << endl;
	}
	system("pause");
	admin();
}


void addMovie()
{
	cout << fixed << setprecision(2);
	// variable for new movie
	system("cls");
	string newMovieTitle, MovieDesc;
	double price;
	int seat;
	string sTime, eTime;
	int addedM = 0;
	ofstream outMovieFile;
	outMovieFile.open("MovieList.txt", ios::app);

	char choice[20];
	cin.ignore();
	cout << "\t- - - - - - - - - - - - - - - - - - - - - - - - -     " << endl;
	cout << "\t|                  Add Movie                    |     " << endl;
	cout << "\t- - - - - - - - - - - - - - - - - - - - - - - - -     " << endl;
	cout << "\t   =============                                      " << endl;
	cout << "\t   !! EXAMPLE !!                                      " << endl;
	cout << "\t   =============                                      " << endl;
	cout << "\t   Movie Title: POKEMON                               " << endl << endl;
	cout << "\t   Movie Price: RM15.00                               " << endl << endl;
	cout << "\t   Total Seats: 30                                    " << endl << endl;
	cout << "\t   Movie Description: Adventure of Ash and Pikachu    " << endl << endl;
	cout << "\t   Movie Start Time: 8:00PM                           " << endl << endl;
	cout << "\t   Movie End Time: 11:00PM                           " << endl << endl;
	cout << "\t* * * * * * * * * * * * * * * * * * * * * * * * *     " << endl << endl;
	bool again = true;
	bool yes = true;
	do
	{
		cout << "\t   New Movie Title: ";
		getline(cin, newMovieTitle);
		cout << endl;
		outMovieFile << newMovieTitle;
		outMovieFile << endl;

		cout << "\t   New Movie Price: RM";
		cin >> price;
		cout << endl;
		outMovieFile << price;
		outMovieFile << endl;

		cout << "\t   New Total Seats: ";
		cin >> seat;
		cout << endl;
		outMovieFile << seat;
		outMovieFile << endl;

		cin.ignore();
		cout << "\t   New Movie Description: ";
		getline(cin, MovieDesc);
		cout << endl;
		outMovieFile << MovieDesc;
		outMovieFile << endl;

		cout << "\t   New Movie Starting Time: ";
		getline(cin, sTime);
		cout << endl;
		outMovieFile << sTime;
		outMovieFile << endl;

		cout << "\t   New Movie Ending Time: ";
		getline(cin, eTime);
		cout << endl;
		outMovieFile << eTime;
		outMovieFile << endl;
		cout << "\n\t***********************************************" << endl;;
		addedM++;

		do
		{
			cout << "\n\n\t   ^^^Do you want to continue to add movie?(Y/N):^^^ ";
			cin >> choice;
			cout << "\n\t***********************************************" << endl << endl;
			cin.ignore();
			if (strlen(choice) != 1)
			{
				cout << "\t   !! PLease Key In One Character Only !! " << endl;
				cout << "\n\t***********************************************" << endl << endl;
			}
			else
			{
				if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0)
				{
					break;
				}
				else if (strcmp(choice, "N") == 0 || strcmp(choice, "n") == 0)
				{
					again = false;
					yes = false;
					cout << "\n\n\t   Total " << addedM << " New Movie Added." << endl;
					cout << endl << "\t";
					system("pause");
				}
				else
				{
					cout << "\t   !! Please Key In (Y/N) Only !!" << endl;
					cout << "\n\t***********************************************" << endl << endl;
				}
			}
		} while (yes);
	} while (again);
	outMovieFile.close();
	system("cls");
	admin();
}

// edit movie by edit in the array
// store the array that already edit into the txt file
void editMovie()
{
	cout << fixed << setprecision(2);
	system("cls");
	storeInfoInArray(totalMovie);
	cout << "\n\t--------------------------------------------------" << endl;
	cout << "\t|**** Please Choose The Desire Movie To Edit ****|" << endl;
	cout << "\t--------------------------------------------------" << endl << endl;
	for (int i = 0; i < totalMovie - 1; i++)
	{
		cout << "  Movie [" << i + 1 << "] " << MovieTitle[i] << endl;
		cout << "    Description of movie: " << MovieDesc[i] << endl;
		cout << "    Price RM " << MoviePrice[i] << endl;
		cout << "    Total Seats: " << MovieSeat[i] << endl;
		cout << "    Start Time: " << startTime[i] << endl;
		cout << "    End Time: " << endTime[i] << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	}
	bool check = false;
	int choice;
	do
	{
		cout << "\t   Please Select The Number of Movie You Want to Edit (1-" << totalMovie - 1 << ") : ";
		cin >> choice;
		cin.ignore();
		if (choice > totalMovie - 1 || choice <= 0)
		{
			cout << "   !! Invalid Input.Key in Number in Range Only !!" << endl << endl;
		}
		else
		{
			check = true;
		}
	} while (check == false);


	for (int i = 0; i < totalMovie - 1; i++)
	{
		if (i == choice - 1)
		{
			cout << "\t=================================" << endl;
			cout << "\t   A. Title" << endl << endl;
			cout << "\t   B. Description" << endl << endl;
			cout << "\t   C. Price" << endl << endl;
			cout << "\t   D. Seat" << endl << endl;
			cout << "\t   E. Start time" << endl << endl;
			cout << "\t   F. End time" << endl << endl;
			cout << "\t=================================" << endl << endl;

			char editChoice[20];
			bool stop = true;
			do
			{
				cout << "\t   << Please select what part of the movie you want to edit: >> ";
				cin >> editChoice;
				cin.ignore();

				if (strcmp(editChoice, "A") == 0 || strcmp(editChoice, "a") == 0)
				{
					string newTitle;
					cout << "\t\t   New title: ";
					getline(cin, newTitle);
					MovieTitle[i] = newTitle;
					cout << "\t\t" << "****New Title Updated****" << endl << endl;
					stop = false;
				}
				else if (strcmp(editChoice, "B") == 0 || strcmp(editChoice, "b") == 0)
				{
					string newDescription;
					cout << "\t\t   New description: ";
					getline(cin, newDescription);
					MovieDesc[i] = newDescription;
					cout << "\t\t" << "****New Description Updated****" << endl << endl;
					stop = false;
				}
				else if (strcmp(editChoice, "C") == 0 || strcmp(editChoice, "c") == 0)
				{
					double newPrice;
					cout << "\t\t   New price: ";
					cin >> newPrice;
					MoviePrice[i] = newPrice;
					cout << "\t\t" << "****New Price Updated****" << endl << endl;
					stop = false;
				}
				else if (strcmp(editChoice, "D") == 0 || strcmp(editChoice, "d") == 0)
				{
					int newSeat;
					cout << "\t\t   New Total Seat: ";
					cin >> newSeat;
					MovieSeat[i] = newSeat;
					cout << "\t\t" << "****New Seat Updated****" << endl << endl;
					stop = false;
				}
				else if (strcmp(editChoice, "E") == 0 || strcmp(editChoice, "e") == 0)
				{
					string newStartTime;
					cout << "\t\t   New starting time: ";
					cin >> newStartTime;
					startTime[i] = newStartTime;
					cout << "\t\t" << "****New Starting Time Updated****" << endl << endl;
					stop = false;
				}
				else if (strcmp(editChoice, "F") == 0 || strcmp(editChoice, "f") == 0)
				{
					string newEndTime;
					cout << "\t\t   New ending time: ";
					cin >> newEndTime;
					endTime[i] = newEndTime;
					cout << "\t\t" << "****New Ending Time Updated****" << endl << endl;
					stop = false;
				}
				else
				{
					cout << "\t !! Invalid Option. Please Try Again !!" << endl << endl;
				}
			} while (stop == true);

		}
	}

	// store the array info into txt file
	ofstream outMovieFile;
	outMovieFile.open("MovieList.txt");

	for (int i = 0; i < totalMovie - 1; i++)
	{
		outMovieFile << MovieTitle[i] << endl;
		outMovieFile << MoviePrice[i] << endl;
		outMovieFile << MovieSeat[i] << endl;
		outMovieFile << MovieDesc[i] << endl;
		outMovieFile << startTime[i] << endl;
		outMovieFile << endTime[i] << endl;
	}
	system("pause");
	admin();
}


void deleteMovie()
{
	cout << fixed << setprecision(2);
	int n;
	system("cls");
	cout << "\n\t--------------------------------------------------" << endl;
	cout << "\t|****Please Choose The Desire Movie To Delete****|" << endl;
	cout << "\t--------------------------------------------------" << endl << endl << endl;
	ofstream DeleteMovieFile;
	storeInfoInArray(totalMovie);
	n = totalMovie;
	for (int i = 0; i < n - 1; i++)
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "   Movie [" << i + 1 << "] " << MovieTitle[i] << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	}
	cout << "Which Movie You Want To Delete: ";
	cin >> i;
	if (i >= totalMovie)
	{
		cout << "\n  Invalid Movie. Back to Admin Interface\n\t";
		system("pause");
		admin();
	}
	cout << MovieTitle[i - 1] << " is deleted." << endl;
	for (i = i; i < n - 1; i++)
	{
		MovieTitle[i - 1] = MovieTitle[i];
		MoviePrice[i - 1] = MoviePrice[i];
		MovieSeat[i - 1] = MovieSeat[i];
		MovieDesc[i - 1] = MovieDesc[i];
		startTime[i - 1] = startTime[i];
		endTime[i - 1] = endTime[i];
	}
	n--;
	DeleteMovieFile.open("MovieList.txt");
	for (int i = 0; i < n - 1; i++)
	{
		DeleteMovieFile << MovieTitle[i] << endl;
		DeleteMovieFile << MoviePrice[i] << endl;
		DeleteMovieFile << MovieSeat[i] << endl;
		DeleteMovieFile << MovieDesc[i] << endl;
		DeleteMovieFile << startTime[i] << endl;
		DeleteMovieFile << endTime[i] << endl;
	}
	system("pause");
	admin();
}

void ViewTrans()
{
	cout << fixed << setprecision(2);
	system("cls");
	cout << "O))) O))))))                                                    O))						" << endl;
	cout << "     O))                                                        O))   O)                   " << endl;
	cout << "     O))    O) O)))   O))    O)) O))   O))))    O))       O)))O)O) O)      O))    O)) O))  " << endl;
	cout << "     O))     O))    O))  O))  O))  O))O))     O))  O))  O))     O))  O)) O))  O))  O))  O))" << endl;
	cout << "     O))     O))   O))   O))  O))  O))  O))) O))   O)) O))      O))  O))O))    O)) O))  O))" << endl;
	cout << "     O))     O))   O))   O))  O))  O))    O))O))   O))  O))     O))  O)) O))  O))  O))  O))" << endl;
	cout << "     O))    O)))     O)) O)))O)))  O))O)) O))  O)) O)))   O)))   O)) O))   O))    O)))  O))" << endl << endl << endl;

	string line;
	cout << "   ## Here the transaction all the time ##" << endl;
	cout << "^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ " << endl;
	ifstream adminview;
	adminview.open("AdminView.txt");
	if (adminview.is_open())
	{
		while (getline(adminview, line))
		{
			cout << "\t" << line << endl << endl;
		}
		adminview.close();
	}
	system("pause");
	admin();
}


//***********************************************
//	
// 
//      below all user interface!!!!!!
//		below all login register interface!!!!!!
// 
//
//
//************************************************

void LoginResgister()
{
	system("cls");
	cout << "   |    / |  / /     //   / /     / /        //   ) )     //   ) )     /|    //| |     //   / / " << endl;
	cout << "   ||  /  | / /     //____       / /        //           //   / /     //|   // | |    //____    " << endl;
	cout << "   || / /||/ /     / ____       / /        //           //   / /     // |  //  | |   / ____     " << endl;
	cout << "   ||/ / |  /     //           / /        //           //   / /     //  | //   | |  //          " << endl;
	cout << "   |  /  | /     //____/ /    / /____/ / ((____/ /    ((___/ /     //   |//    | | //____/ /    " << endl << endl << endl;
	char choose[100];
	bool check = false;
	do
	{
		cout << "\t   ***Do You Have Account Before[Y/N]*** : ";
		cin >> choose;
		if (strlen(choose) != 1)
		{
			cout << "\t!! Opps Wrong Input.Please Key In One Letter Only !!" << endl << endl;
			cout << "\t";
			system("pause");
			LoginResgister();
		}
		else if (strcmp(choose, "y") == 0 || strcmp(choose, "Y") == 0)
		{
			check = true;
			Login();

		}
		else if (strcmp(choose, "n") == 0 || strcmp(choose, "N") == 0)
		{
			check = true;
			Register();
		}
		else {
			cout << "\t!! Opps Wrong Input.Please Key In (Y/N)Only !!" << endl << endl;
			cout << "\t";
			system("pause");
			LoginResgister();
		}
	} while (check == false);
}


bool userExist(string email_1)
{
	ifstream userregister("userregister.txt");
	if (userregister.is_open()) {
		string username, password, email;
		while (!userregister.eof()) {
			userregister >> email >> password >> username;
			if (email_1 == email) {
				userregister.close();
				return true;
				break;
			}
		}
		userregister.close();
	}
	return false;
}


void Register()
{
	system("cls");
	cout << " ______    ______   _______    ________  ______   _________  ______   ______" << endl;
	cout << "/_____/\\  /_____/\\ /______/\\  /_______/\\/_____/\\ /________/\\/_____/\\ /_____/\\      " << endl;
	cout << "\\:::_ \\ \\ \\::::_\\/_\\::::__\\/__\\__.::._\\/\\::::_\\/_\\__.::.__\\/\\::::_\\/_\\:::_ \\ \\     " << endl;
	cout << " \\:(_) ) )_\\:\\/___/\\\\:\\ /____/\\  \\::\\ \\  \\:\\/___/\\  \\::\\ \\   \\:\\/___/\\\\:(_) ) )_   " << endl;
	cout << "  \\: __ `\\ \\\\::___\\/_\\:\\\\_  _\\/  _\\::\\ \\__\\_::._\\:\\  \\::\\ \\   \\::___\\/_\\: __ `\\ \\  " << endl;
	cout << "   \\ \\ `\\ \\ \\\\:\\____/\\\\:\\_\\ \\ \\ /__\\::\\__/\\ /____\\:\\  \\::\\ \\   \\:\\____/\\\\ \\ `\\ \\ \\ " << endl;
	cout << "  __\\_\\/_\\_\\/_\\_____\\/ \\_____\\/ \\________\\/ \\_____\\/_  \\__\\/___ \\_____\\/_\\_\\/_\\_\\/ __      " << endl;
	cout << " /_______/\\ /__/\\ /__/\\ /_____/\\     /_/\\     /_____/\\ /______/\\  /_______/\\/__/\\ /__/\\    " << endl;
	cout << " \\::: _  \\ \\\\::\\_\\\\  \\ \\\\:::_ \\ \\    \\:\\ \\    \\:::_ \\ \\\\::::__\\/__\\__.::._\\/\\::\\_\\\\  \\ \\   " << endl;
	cout << "  \\::(_)  \\ \\\\:. `-\\  \\ \\\\:\\ \\ \\ \\    \\:\\ \\    \\:\\ \\ \\ \\\\:\\ /____/\\  \\::\\ \\  \\:. `-\\  \\ \\  " << endl;
	cout << "   \\:: __  \\ \\\\:. _    \\ \\\\:\\ \\ \\ \\    \\:\\ \\____\\:\\ \\ \\ \\\\:\\\\_  _\\/  _\\::\\ \\__\\:. _    \\ \\ " << endl;
	cout << "    \\:.\\ \\  \\ \\\\. \\`-\\  \\ \\\\:\\/.:| |    \\:\\/___/\\\\:\\_\\ \\ \\\\:\\_\\ \\ \\ /__\\::\\__/\\\\. \\`-\\  \\ \\" << endl;
	cout << "     \\__\\/\\__\\/ \\__\\/ \\__\\/ \\____/_/     \\_____\\/ \\_____\\/ \\_____\\/ \\________\\/ \\__\\/ \\__\\/" << endl << endl << endl << endl;

	cout << "\t--------------------------" << endl;
	cout << "\t|    Register account    |" << endl;
	cout << "\t--------------------------" << endl;

	string email_1, email_2, password_1, password_2;
	ofstream userregister;
	userregister.open("userregister.txt", ios::app);
	if (userregister.is_open())
	{
		cout << "\t<< Please enter your email >>\n" << "Email: ";
		cin >> email_1;
		cout << "\t<< Please reenter your email >>\n" << "Email:";
		cin >> email_2;
		cout << "..........................................................." << endl;

		// check for email
		while (email_1 != email_2)
		{
			cout << "\t<< Email do not match, kindly retype agian >>\n" << "Email:";
			cin >> email_1;
			cout << "\t<< Please reenter your email >>\n" << "Email:";
			cin >> email_2;
			cout << "..........................................................." << endl;
		}
		if (userExist(email_1))
		{
			cout << "\t***Account already exist, proceed to login interface***" << endl;
			system("pause");
			cout << endl;
			Login();
		}

		// check for password
		cout << "\t<< Please enter your password >>\n" << "Password: ";
		cin >> password_1;
		cout << "\t<< Please reenter your password >>\n" << "Password:";
		cin >> password_2;
		cout << "..........................................................." << endl;
		while (password_1 != password_2)
		{
			cout << "\t<< Password do not match, kindly retype agian >>\n" << "Password:";
			cin >> password_1;
			cout << "\t<< Please reenter your password >>\n" << "Password:";
			cin >> password_2;
			cout << "..........................................................." << endl;
		}

		cout << "\t<< Please set a username for yourself >>\n" << "Username:";
		cin >> username;

		// input the email and password into the unresgister.txt
		userregister << email_1 << endl;
		userregister << password_1 << endl;
		userregister << username << endl;

		cout << "\t***Thanks for register an account with us***" << endl;
		userregister.close();
		system("pause");
		Login();
	}
	else
		cout << "\t!! cant open file !!";
	system("pause");
}


void Login()
{
	system("cls");
	cout << " __       ______   _______    ________  ___   __      " << endl;
	cout << "/_/\\     /_____/\\ /______/\\  /_______/\\/__/\\ /__/\\    " << endl;
	cout << "\\:\\ \\    \\:::_ \\ \\\\::::__\\/__\\__.::._\\/\\::\\_\\\\  \\ \\   " << endl;
	cout << " \\:\\ \\    \\:\\ \\ \\ \\\\:\\ /____/\\  \\::\\ \\  \\:. `-\\  \\ \\  " << endl;
	cout << "  \\:\\ \\____\\:\\ \\ \\ \\\\:\\\\_  _\\/  _\\::\\ \\__\\:. _    \\ \\ " << endl;
	cout << "   \\:\\/___/\\\\:\\_\\ \\ \\\\:\\_\\ \\ \\ /__\\::\\__/\\\\. \\`-\\  \\ \\" << endl;
	cout << "    \\_____\\/ \\_____\\/ \\_____\\/ \\________\\/ \\__\\/ \\__\\/" << endl;

	bool loggedIn = false;
	string  _password, _input;
	cout << "\t<< Please enter your registered email or username >>" << endl << "Email/Username:";
	cin >> _input;
	cout << "\t<< Please enter the password >>" << endl << "Password: ";
	cin >> _password;
	ifstream userregister;
	userregister.open("userregister.txt");

	if (userregister.is_open())
	{
		string email, username, password;
		while (!userregister.eof())
		{
			getline(userregister, email);
			getline(userregister, password);
			getline(userregister, username);

			if (email == _input && password == _password) {
				loggedIn = true;

				// write the username into a file
				ofstream userNameFile("username.txt");
				userNameFile << _input;
				break;
			}
			else if (username == _input && password == _password) {
				loggedIn = true;
				break;
			}
			else {
				loggedIn = false;
			}
		}
		userregister.close();
		if (loggedIn) {
			cout << "\t***Login successful. Welcome " << _input << "!***" << endl;
			cout << "\t" << system("pause");
			userUI();
		}
		else {
			if (password != _password)
			{
				cout << "--------------------------------------------------------------------------------------" << endl;
				cout << "\n\t\t\t***Password incorrect.***" << endl << endl;
			}
			else
			{
				cout << "--------------------------------------------------------------------------------------" << endl;
				cout << "\n\t\t\t***Oops user not found.***" << endl;
			}

			while (loggedIn == false) {
				char choose[10];
				cout << "\t- - > Do you want to login again or register a new account? < - -" << endl << endl << endl;
				cout << "\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
				cout << "\t# # #                           |                           # # #" << endl;
				cout << "\t# # #          [A] login        |      [B] register         # # #" << endl;
				cout << "\t# # #                           |                           # # #" << endl;
				cout << "\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
				cout << "Your choice: ";
				cin >> choose;
				if (strcmp(choose, "A") == 0 || strcmp(choose, "a") == 0) {
					Login();
				}
				else if (strcmp(choose, "B") == 0 || strcmp(choose, "b") == 0)
				{
					Register();
				}
				else {
					cout << "\t<< Invalid input proceed to login page >>" << endl;
					system("pause");
					Login();
				}
			}
		}

	}
	else {
		cout << " !! Error: Failed to open users file !! " << endl;
		system("pause");
		LoginResgister();
	}
}



void userUI()
{
	system("cls");
	cout << "\t      __ __                                    _______                  __           " << endl;
	cout << "\t     / //_/___ _____ ___  ____  ____ ______   / ____(_)___  ___  ____  / /__  _  __  " << endl;
	cout << "\t    / ,< / __ `/ __ `__ \\/ __ \\/ __ `/ ___/  / /   / / __ \\/ _ \\/ __ \\/ / _ \\| |/_/  " << endl;
	cout << "\t   / /| / /_/ / / / / / / /_/ / /_/ / /     / /___/ / / / /  __/ /_/ / /  __/>  <    " << endl;
	cout << "\t  /_/ |_\\__,_/_/ /_/ /_/ .___/\\__,_/_/      \\____/_/_/ /_/\\___/ .___/_/\\___/_/|_|     " << endl;
	cout << "\t                      /_/                                    /_/                     " << endl;

	char choice[25];
	cout << "\t- - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "\t                     MAIN MENU                    | " << endl;
	cout << "\t- - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "\t                                          " << endl << endl;
	cout << "\t         [1] Movie Description             " << endl << endl;
	cout << "\t         [2] Book Movie                    " << endl << endl;
	cout << "\t         [3] Show History                  " << endl << endl;
	cout << "\t         [4] Cancel Booking                " << endl << endl;
	cout << "\t         [5] Payment                       " << endl << endl;
	cout << "\t         [6] Home Page                     " << endl << endl;
	cout << "\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl << endl << endl;


	do
	{
		cout << "Your choice: ";
		cin >> choice;
		if (strlen(choice) != 1)
		{
			cout << " \t!! Please Key In One Integer Only !! " << endl << endl;
			continue;
		}
		else
		{
			if (strcmp(choice, "1") == 0)
			{
				showMovie();
				break;
			}
			else if (strcmp(choice, "2") == 0)
			{
				bookMovie();
				break;
			}
			else if (strcmp(choice, "3") == 0)
			{
				showHistory();
				break;
			}
			else if (strcmp(choice, "4") == 0)
			{
				cancelBooking();
				break;
			}
			else if (strcmp(choice, "5") == 0)
			{
				paybill();
				break;
			}
			else if (strcmp(choice, "6") == 0)
			{
				home();
				break;
			}
			else
			{
				cout << "Invalid input, please choose again" << endl;
				continue;
			}
		}

	} while (true);

}



// correct le
void showMovie()
{
	cout << fixed << setprecision(2);
	system("cls");
	cout << "\n\t\t\t!! POPULAR IN THEATER NOW !! " << endl << endl << endl;
	storeInfoInArray(totalMovie);
	for (int i = 0; i < totalMovie - 1; i++)
	{
		cout << "\t================================================================" << endl;
		cout << "\t\tMovie " << i + 1 << " : <" << MovieTitle[i] << "> " << endl;
		cout << "\t================================================================" << endl;
		cout << "\tDescription of movie: " << MovieDesc[i] << endl;
		cout << "\tPrice RM " << MoviePrice[i] << endl;
		cout << "\tAvailable Seat: " << MovieSeat[i] << endl;
		cout << "\tStart Time: " << startTime[i] << endl;
		cout << "\tEnd Time: " << endTime[i] << endl;
		cout << endl;

	}
	cout << endl << endl;
	system("pause");
	userUI();
}


void bookMovie()
{
	cout << fixed << setprecision(2);
	int noSeat;
	system("cls");
	//display movie for cust to choose
	storeInfoInArray(totalMovie);

	cout << "\n\t\t____________________________________" << endl;
	cout << "\t\t !!! Got'em All Before Sold Out !!!" << endl;
	cout << "\t\t------------------------------------" << endl << endl << endl;
	cout << "   .............................................................." << endl;


	for (int i = 0; i < totalMovie - 1; i++)
	{
		cout << "====================================================================" << endl;
		cout << "\t" << i + 1 << ") Movie: " << MovieTitle[i] << endl;
		cout << "\t" << "  Description of movie: " << MovieDesc[i] << endl;
		cout << "\t" << "  Movie seat: " << MovieSeat[i] << endl;
		cout << "\t" << "  Price RM " << MoviePrice[i] << endl;
		cout << "\t" << "  Start Time: " << startTime[i] << endl;
		cout << "\t" << "  End Time: " << endTime[i] << endl;
		cout << endl;

	}

	int movieChoice, bookedMovieNo;
	char custChoice[10];
	cout << endl << endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "\tDo you want to continue to book the movie?" << endl;
	cout << "\t\t--------------------" << endl;
	cout << "\t\t|   Y-yes , N-no   |" << endl;
	cout << "\t\t--------------------" << endl;
	cout << "\tYour choice: ";
	cin >> custChoice;
	if (strcmp(custChoice, "Y") == 0 || strcmp(custChoice, "y") == 0)
	{
		// let user choose movie
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "\tSelect the movie you want to book: ";
		cin >> movieChoice;
		cin.ignore();
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		if (movieChoice > totalMovie - 1 || movieChoice <= 0)
		{
			cout << "\tKey in the range from 1 to " << totalMovie - 1 << " only" << endl;
			system("pause");
			bookMovie();
		}
		else
		{
			cout << "\tYour movie booked is " << MovieTitle[movieChoice - 1] << endl;
			bookedMovieNo = movieChoice;
			if (MovieSeat[movieChoice - 1] <= 0)
			{
				cout << "\tThe movie was sold out" << endl;
				system("pause");
				bookMovie();
			}
			else
			{

				cout << "\tPlease select the number of seat you want to book: ";
				cin >> noSeat;

				if (noSeat > MovieSeat[movieChoice - 1])
				{
					cout << "\tThe seat left only " << MovieSeat[movieChoice - 1] << endl;
					system("pause");
					bookMovie();
				}
				else
				{
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "\t!!!The movie " << MovieTitle[movieChoice - 1] << " with " << noSeat << " seat booked successfully!!!" << endl << endl << endl;
				}
				MovieSeat[movieChoice - 1] = MovieSeat[movieChoice - 1] - noSeat;

				int n = totalMovie;
				ofstream storeMovieFile;
				storeMovieFile.open("MovieList.txt");
				for (int i = 0; i < n - 1; i++)
				{
					storeMovieFile << MovieTitle[i] << endl;
					storeMovieFile << MoviePrice[i] << endl;
					storeMovieFile << MovieSeat[i] << endl;
					storeMovieFile << MovieDesc[i] << endl;
					storeMovieFile << startTime[i] << endl;
					storeMovieFile << endTime[i] << endl;
				}
				storeMovieFile.close();

			}
		}

		// open text to store the book movie info into a text file for cust usage
		// store in permenent file
		ofstream outFile("temp_booked_movie_info.txt", ios::app);

		outFile << MovieTitle[movieChoice - 1] << endl;
		outFile << noSeat << endl;
		outFile << MoviePrice[movieChoice - 1] << endl;
		outFile << startTime[movieChoice - 1] << endl;
		outFile << endTime[movieChoice - 1] << endl;
		outFile.close();

	}
	else if (strcmp(custChoice, "N") == 0 || strcmp(custChoice, "n") == 0)
	{
		userUI();
	}
	else
	{
		cout << "Invalid input" << endl;
		system("pause");
		bookMovie();
	}
	system("pause");
	userUI();
}


// show cust the book history
void showHistory()
{
	cout << fixed << setprecision(2);
	double totalPrice = 0;
	system("cls");
	storeBookedInfoInArray(totalBookedMovie);
	ifstream nameFile;
	nameFile.open("username.txt");
	if (nameFile.is_open())
	{
		while (!nameFile.eof())
		{
			getline(nameFile, username);
		}
	}
	nameFile.close();

	if (totalBookedMovie - 1<= 0)
	{
		char choose[10];
		cout << "\t\t\t-------------------------" << endl;
		cout << "\t\t\t|        HISTORY         |" << endl;
		cout << "\t\t\t-------------------------" << endl;
		cout << "\n\tSo Empty Here, Go Get'em Shall We? >_<" << endl;
		cout << "\t= = = = = = = = = = = = = = = = = = = = " << endl;
		cout << "\t ***Press Y to get your ticket now***" << endl << "\t" << endl;
		cout << "\t     ***Press anykey to leave***" << endl << "\t" << endl;
		cout << "\t     Your Choice : ";
		cin >> choose;
		if (strcmp(choose, "y") == 0 || strcmp(choose, "Y") == 0) {
			cout << "\t      !!Great choice.Let's go!!" << endl;
			cout << "\t";
			system("pause");
			bookMovie();
		}
		else {
			cout << "\n\tBack to User Interface." << endl;
			system("pause");
			userUI();
		}
	}
	else
	{
		cout << "\t\t\t-------------------------" << endl;
		cout << "\t\t\t|        HISTORY         |" << endl;
		cout << "\t\t\t-------------------------" << endl << endl;
		cout << "\t\t       >_< Hi, my dear " << username << endl;
		cout << "\t\t       Here is your booking history" << endl << endl << endl;

		for (int i = 0; i < totalBookedMovie - 1; i++)
		{
			cout << "===============================================================================================" << endl;
			cout << "\t\t" << bMovietitle[i] << endl;
			cout << "\t\tNumber of seat booked: " << bNumMovieSeat[i] << endl << endl;
			cout << "\t\tPrice: RM " << bMoviePrice[i] << endl << endl;
			cout << "\t\tStarting Time: " << bMovieStartTime[i] << " , End time: " << bMovieEndTime[i] << endl << endl;
		}
		for (int i = 0; i < totalBookedMovie - 1; i++)
		{
			cout << fixed << setprecision(2);
			totalPrice += bMoviePrice[i] * bNumMovieSeat[i];
		}
		cout << "\t\tThe Total Price Is << RM" << totalPrice << " >> " << endl << endl;
		cout << "\t\t" << paidStatus << endl << endl;

		char paychoice[10];
		cout << "*****Do you want to make payment?(Y-yes, N-no)*****: ";
		cin >> paychoice;
		if (strcmp(paychoice, "Y") == 0 || strcmp(paychoice, "y") == 0)
		{
			paybill();
		}
		else if (strcmp(paychoice, "N") == 0 || strcmp(paychoice, "n") == 0)
		{
			system("pause");
			userUI();
		}
		else
		{
			cout << "\tInvalid Input. Key In (Y/N) only." << endl;
			system("pause");
			showHistory();
		}

	}
	cout << endl;


}

void cancelBooking()
{
	cout << fixed << setprecision(2);
	system("cls");
	int choice;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t|        CANCEL BOOKING         |" << endl;
	cout << "\t\t\t*********************************" << endl << endl;


	storeBookedInfoInArray(totalBookedMovie);
	if (totalBookedMovie - 1 <= 0)
	{

		cout << "\t\t\t----------------------------------" << endl;
		cout << "\t\t\t|             Empty              |" << endl;
		cout << "\t\t\t----------------------------------" << endl;


		cout << endl << endl << "\tYou have not book any movie" << endl << endl;
		system("pause");
		userUI();
	}

	ofstream CancelFile;
	for (int i = 0; i < totalBookedMovie - 1; i++)
	{
		cout << "\tBooked Movie " << i + 1 << ": " << bMovietitle[i] << endl << endl;
		cout << "\tBooked Seat: " << bNumMovieSeat[i] << endl << endl;
		cout << "\tMovie Price: " << bMoviePrice[i] << endl << endl;
		cout << "\tMovie Show Time : " << bMovieStartTime[i] << " - " << bMovieEndTime[i] << endl << endl;
		cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = " << endl;
	}
	cout << "\tWhich movie you want to cancel (1-" << totalBookedMovie - 1 << ") : ";
	cin >> choice;
	if (choice > totalBookedMovie-1 || choice <= 0)
	{
		cout << "\t!! Please key in movie in range only !!" << endl << endl;
		system("pause");
		cancelBooking();
	}
	else
	{
		cout << "\tYour Booked Movie ( " << bMovietitle[choice - 1] << " ) has canceled." << endl; 
		for (int i = choice; i < totalBookedMovie - 1; i++)
		{
			bMovietitle[i - 1] = bMovietitle[i];
			bNumMovieSeat[i - 1] = bNumMovieSeat[i];
			bMoviePrice[i - 1] = bMoviePrice[i];
			bMovieStartTime[i - 1] = bMovieStartTime[i];
			bMovieEndTime[i - 1] = bMovieEndTime[i];
		}
		CancelFile.open("temp_booked_movie_info.txt");
		for (int i = 0; i < totalBookedMovie - 2; i++)
		{
			CancelFile << bMovietitle[i] << endl;
			CancelFile << bNumMovieSeat[i] << endl;
			CancelFile << bMoviePrice[i] << endl;
			CancelFile << bMovieStartTime[i] << endl;
			CancelFile << bMovieEndTime[i] << endl;
		}
		CancelFile.close();
		system("pause");
		userUI();
	}

}

void paybill()
{

	system("cls");
	double totalPrice = 0;
	cout << fixed << setprecision(2);
	cout << "\n$$$$$$$\\                                                        $$\\     " << endl;
	cout << "$$  __$$\\                                                       $$ |    " << endl;
	cout << "$$ |  $$ |$$$$$$\\  $$\\   $$\\ $$$$$$\\$$$$\\   $$$$$$\\  $$$$$$$\\ $$$$$$\\   " << endl;
	cout << "$$$$$$$  |\\____$$\\ $$ |  $$ |$$  _$$  _$$\\ $$  __$$\\ $$  __$$\\\\_$$  _|  " << endl;
	cout << "$$  ____/ $$$$$$$ |$$ |  $$ |$$ / $$ / $$ |$$$$$$$$ |$$ |  $$ | $$ |    " << endl;
	cout << "$$ |     $$  __$$ |$$ |  $$ |$$ | $$ | $$ |$$   ____|$$ |  $$ | $$ |$$\\ " << endl;
	cout << "$$ |     \\$$$$$$$ |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$\ $$ |  $$ | \$$$$  |" << endl;
	cout << "\\__|      \\_______| \\____$$ |\\__| \\__| \\__| \\_______|\\__|  \\__|  \\____/ " << endl;
	cout << "                   $$\\   $$ |											   	 " << endl;
	cout << "                   \\$$$$$$  |												 " << endl;
	cout << "                    \\______/												 " << endl << endl << endl;
	storeBookedInfoInArray(totalBookedMovie);
	ofstream clearFile;
	char choice[15];
	cout << "\tDo you want to perform the payment?: " << endl;
	cout << "\t\t[Y - yes | N - no] :";
	cin >> choice;
	cout << endl;
	if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0)
	{
		for (int i = 0; i < totalBookedMovie - 1; i++)
		{
			cout << fixed << setprecision(2);
			totalPrice += bMoviePrice[i] * bNumMovieSeat[i];
		}
		char choice2[20];
		cout << "\t $$ The total price: RM " << totalPrice << " $$" << endl;
		cout << "\t--------------------------------------" << endl;
		cout << "\t|Press Y to comfirm the payment      |" << endl;
		cout << "\t|Press other key to exit the payment |" << endl;
		cout << "\t--------------------------------------" << endl;
		cout << "\tYour choice: ";
		cin >> choice2;
		cout << endl << "====================================================" << endl;
		if (strcmp(choice2, "Y") == 0 || strcmp(choice2, "y") == 0)
		{
			cout << "$$ Your payment are done hope you have a good day $$" << endl << endl;
			ifstream nameFile;
			nameFile.open("username.txt");
			getline(nameFile, username);
			nameFile.close();
			storeBookedInfoInArray(totalBookedMovie);
			ofstream adminFile("AdminView.txt", ios::app);
			adminFile << "USERNAME: " << username << endl;;
			for (int i = 0; i < totalBookedMovie - 1; i++)
			{
				adminFile << "BOOKED MOVIE: " << bMovietitle[i] << endl;
				adminFile << "BOOKED SEAT: " << bNumMovieSeat[i] << endl;
				cout << fixed << setprecision(2);
				adminFile << "PRICE FOR THE SEAT: RM" << bMoviePrice[i] * bNumMovieSeat[i] << endl;
			}
			cout << fixed << setprecision(2);
			adminFile << "TOTAL PRICE: RM" << totalPrice << endl;
			adminFile << "PAYMENT: PAID" << endl << endl;

			adminFile.close();
			clearFile.open("temp_booked_movie_info.txt");
			clearFile << "";
			clearFile.close();
			system("pause");
			userUI();
		}
		else
		{
			cout << "Exit the payment" << endl;
			system("pause");
			userUI();
		}

	}
	else if (strcmp(choice, "N") == 0 || strcmp(choice, "n") == 0)
	{
		cout << endl << "Back to User Interface. " << endl << endl;
		system("pause");
		userUI();
	}
	else
	{
		cout << endl << "Invalid Input. Key In (Y/N) Only. " << endl << endl;
		system("pause");
		paybill();
	}
}


// function to store the cust info from cust_info.txt to array
// when want to use the array pls call the function
void storeBookedInfoInArray(int& totalBookedMovie)
{
	cout << fixed << setprecision(2);
	int total = 0;
	int i = 0;
	ifstream bookfile;
	bookfile.open("temp_booked_movie_info.txt");
	if (bookfile.is_open())
	{
		while (!bookfile.eof())
		{
			//bookfile.ignore();
			getline(bookfile, btitle);
			bMovietitle[i] = btitle;

			//bookfile.ignore();
			bookfile >> bSeat;
			bNumMovieSeat[i] = bSeat;

			/*bookfile.ignore();*/
			bookfile >> bprice;
			bMoviePrice[i] = bprice;

			bookfile >> bStartTime;
			bMovieStartTime[i] = bStartTime;

			bookfile >> bEndTime;
			bMovieEndTime[i] = bEndTime;

			i++;
			total++;
			bookfile.ignore();
		}
	}
	totalBookedMovie = total;
	bookfile.close();
}


// function to store the info from txt file to array
// when want to use array please call out this function first
void storeInfoInArray(int& totalMovie)
{
	cout << fixed << setprecision(2);
	int total = 0;
	int i = 0;
	ifstream moviefile;
	moviefile.open("MovieList.txt");
	if (moviefile.is_open())

		while (!moviefile.eof())
		{
			getline(moviefile, title);
			MovieTitle[i] = title;

			moviefile >> price;
			MoviePrice[i] = price;

			moviefile >> seat;
			MovieSeat[i] = seat;

			moviefile.ignore();
			getline(moviefile, describe);
			MovieDesc[i] = describe;

			moviefile >> sTime;
			startTime[i] = sTime;

			moviefile >> eTime;
			endTime[i] = eTime;

			i++;
			total++;
			moviefile.ignore();
		}
	totalMovie = total;
	moviefile.close();
}