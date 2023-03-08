#include<iostream>
#include<string>
using namespace std;
bool UserAffirms(string customer_preference);
void old_user(string &login, int &balance);
void rules();
void table_game(int& dice, int guess, int& bettingamount, int& balance, int User_new, string name, string &repeat);
int main()
{
	string name = "";
	string repeat =""; string goldentbl ="";
	int cnic;
	int dice;
	int guess = 0, choice;
	int balance=0, bettingamount;
	string address = "";
	cout << "------- Welcome to The Game House By Kabeer -------" << endl;
	string customer_preference = "";
	cout << "New to The Game House ? (NO / YES)" << endl;
	cin >> customer_preference;

	bool User_new = false;
	User_new = UserAffirms(customer_preference);

	if (User_new)
	{
		cout << "You need to sign up first ... " << endl;
		cout << "Enter Name " << ":";
		cin >> name;
		cout << "Enter CNIC..." << ":";
		cin >> cnic;
		cout << "Enter Address " << ":";
		cin >> address;
		cout << "Initial Balance" << ":";
		cin >> balance;
		cout << endl;
		cout << "----Sign Up Successful!---- " << endl << endl;
	}
	else
	{
		string login = "";
		cout << " KINDLY ENTER YOUR LOGIN PASSWORD : ";
		old_user(login, balance);
	}
	rules();
	cout << " Your current balance is Rs " << balance << endl;
	for (int i = 0;;)
	{ 
		table_game(dice, guess, bettingamount, balance, User_new, name, repeat);
		if (balance == 0)
		{
			cout << "You have no money to play ";
			return 0;
		}
		
		if (repeat == "y")
		{
			table_game(dice, guess, bettingamount, balance, User_new, name, repeat);
			if (balance == 0)
			{
				cout << "You have no money to play ";
				return 0;
			}
		}
		else if (repeat == "n")
		{
			int finalblc;
			int tax = (balance / 100) * 5;
			system("cls");
			cout << " YOU WILL HAVE TO PAY 5% TAX " << endl;
			finalblc = balance - tax;
			cout << " You Remaining Balance is Rs" << finalblc << endl;
			cout << " THANKS FOR PLAYING !";
			break;
		}
		else {
			cout << "\n\n-->Do you want to play again (y/n)? ";
			cin >> repeat;
		}
	}
}
bool UserAffirms(string customer_preference)
{
  bool User_new = false;
  User_new = customer_preference == "Yes" ||
              customer_preference == "y" ||
              customer_preference == "Y" ||
              customer_preference == "yes";
  return User_new;
}
void old_user(string &login, int &balance)
{
	string inppass;
	char login1[10] =  "Kabeer" ;
	char pass1[10] =  "1234" ;
	char login2[10] =  "Ahmad" ;
	char pass2[10] =  "1234" ;

	cout << "ENTER USERNAME : ";
	cin >> login;
	
		if (login == login1 || login == login2)
		{
			cout << " ENTER PASSWORD : ";
			cin >> inppass;

			if (inppass == pass1 || inppass == pass2)
			{
				cout << "SUCCESFULLY LOGGED IN ! " << endl<<endl;
				cout << "ENTER BALANCE : ";
				cin >> balance;

			}
			else { cout << "ENTER CORRECT PASSWORD .. "; }
		}
		else
		{
			cout << " ENTER CORRECT USERNAME .. " << endl;
		}
}
void rules()
{
	
	cout << "----RULES OF THE GAME----\n ";
	cout << " 1. Choose any number between 1 to 10\n";
	cout << " 2. If you win you will get DOUBLE of money you bet\n";
	cout << " 3. If you bet on wrong number you will lose your betting amount" << endl<<endl;
}
void table_game(int &dice, int guess, int &bettingamount, int &balance, int User_new, string name, string &repeat)
{
	string goldentbl = "" ; int your_player, bet1, bet2, bet3;
	if (User_new)
	{
		cout << name << ", enter money to bet : Rs";
	}
	else { cout << " Enter money to bet : Rs"; }
	cin >> bettingamount;
	cout << endl;
	if (bettingamount > balance)
	{
		cout << "Your betting amount is more than your current balance" << endl;
	}
	bet1 = rand() % 10 + 1;
	bet2 = rand() % 10 + 1;
	bet3 = rand() % 10 + 1;
	
	your_player = rand() % 3 + 1;
	cout << " YOU WILL BE PLAYING AT TABLE " << rand() % 4 + 1 << " WITH 2 Players!" << endl;
	cout << " You are PLAYER-" << your_player << endl << endl;
	cout << " Write your number to bet from 1 to 10 : ";
	cin >> guess; cout << endl << endl;
	cout << " Number for First Player : " << bet1 << endl;
	cout << " Betting Amount for this Player : " << rand() % 100 + 10 << endl;
	cout << " Number for Second Player : " << bet2 << endl;
	cout << " Betting Amount for this Player : " << rand() % 100 + 10 << endl;
	cout << " Your Number : " << guess << endl;
	cout << " Betting Amount for this Player : " << bettingamount << endl;
	dice = rand() % 10 + 1;
	if (dice == guess)
	{
		cout << "\n Good Luck! You won Rs." << bettingamount;
		balance = balance + (bettingamount*2);
	}
	else
	{
		cout << "\n Bad Luck this time !You lost Rs " << bettingamount << "\n";
		balance = balance - bettingamount;
	}
	cout << "\n\n The winning number was : " << dice<<endl;
	cout << "\n ===" << name << ", You have Rs " << balance <<"==="<< endl<<endl;
	
	if (dice == guess)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " DO YOU WANT TO PLAY GOLDEN TABLE? (y / n) = ";
			cin >> goldentbl;
			if (goldentbl == "y")
			{
				cout << " ----GOLDEN TABLE----" << endl;
				cout << " ONLY WINNERS PLAY HERE" << endl;
				cout << " WINNER GETS 4x BET AMOUNT" << endl<<endl;
				if (User_new)
				{
					cout << name << ", enter money to bet : Rs ";
				}
				else { cout << " Enter money to bet : Rs "; }
				cin >> bettingamount;
				cout << endl;
				if (bettingamount > balance)
				{
					cout << "\n Your betting amount is more than your current balance" << endl;
				}
				your_player = rand() % 3 + 1;
				cout << " YOU WILL BE PLAYING AT TABLE " << rand() % 4 + 1 << " WITH 2 Players!" << endl;
				cout << " You are PLAYER-" << your_player << endl << endl;
				cout << " Write your number to bet from 1 to 10 : ";
				cin >> guess; cout << endl << endl;
				cout << " Number for First Player : " << bet1 << endl;
				cout << " Betting Amount for this Player : " << rand() % 100 + 10 << endl;
				cout << " Number for Second Player : " << bet2 << endl;
				cout << " Betting Amount for this Player : " << rand() % 100 + 10 << endl;
				cout << " Your Number : " << guess << endl;
				cout << " Betting Amount for this Player : " << bettingamount << endl;
				dice = rand() % 10 + 1;
				if (dice == guess)
				{
					cout << "\n Good Luck! You won Rs." << bettingamount * 4;
					balance = balance + (bettingamount * 4);
				}
				else
				{
					cout << "\n Bad Luck this time !You lost Rs " << bettingamount << "\n";
					balance = balance - bettingamount;
				}
				cout << "\n The winning number was : " << dice<<endl;
				cout << "\n " << name << ", You have Rs " << balance << endl<<endl;
				if (balance == 0)
				{
					cout << " You have no money to play ";
					break;
				}
			}
			else if (goldentbl == "n")
			{ 
				if (j == 3) {
					break;
				}

				else
				{
					cout << " ----GOLDEN TABLE----" << endl;
					cout << " ONLY WINNERS PLAY HERE" << endl;
					cout << " WINNER GETS 4x BET AMOUNT" << endl << endl;
					if (User_new)
					{
						cout << name << ", enter money to bet : Rs ";
					}
					else { cout << " Enter money to bet : Rs "; }
					cin >> bettingamount;
					cout << endl;
					if (bettingamount > balance)
					{
						cout << "\n Your betting amount is more than your current balance" << endl;
					}
					your_player = rand() % 3 + 1;
					cout << " YOU WILL BE PLAYING AT TABLE " << rand() % 4 + 1 << " WITH 2 Players!" << endl;
					cout << " You are PLAYER-" << your_player << endl << endl;
					cout << " Write your number to bet from 1 to 10 : ";
					cin >> guess; cout << endl << endl;
					cout << " Number for First Player : " << bet1 << endl;
					cout << " Betting Amount for this Player : " << rand() % 100 + 10 << endl;
					cout << " Number for Second Player : " << bet2 << endl;
					cout << " Betting Amount for this Player : " << rand() % 100 + 10 << endl;
					cout << " Your Number : " << guess << endl;
					cout << " Betting Amount for this Player : " << bettingamount << endl;
					dice = rand() % 10 + 1;
					if (dice == guess)
					{
						cout << "\n Good Luck! You won Rs." << bettingamount * 4;
						balance = balance + (bettingamount * 4);
					}
					else
					{
						cout << "\n Bad Luck this time !You lost Rs " << bettingamount << "\n";
						balance = balance - bettingamount;
					}
					cout << "\n The winning number was : " << dice << endl;
					cout << "\n " << name << ", You have Rs " << balance << endl << endl;
					if (balance == 0)
					{
						cout << " You have no money to play ";
						break;
					}
				}
			}
			else {
				cout << "\n DO YOU WANT TO PLAY GOLDEN TABLE? (y / n) = ";
				cin >> goldentbl;
			}
		}
	}
	else
	{
		cout << "\n\n--> Do you want to play again (y/n)? ";
		cin >> repeat;
	}
}
