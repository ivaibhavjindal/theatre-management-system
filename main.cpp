#include "iostream"
#include "vector"
#include "sstream"
#include "string"
#include "User.h"
#include "Movie.h"
#include "extra.h"
#include "Ticket.h"
using namespace std;

int main() {
	User a;
	Movie m;
	string s;
	int n;
	while(true) {
		system("cls");
		printHLine();
		printstarline();
		cout << "WELCOME to PVR Ticket Booking software" <<endl;
		if(a.isLoggedIn()) {
			string name = a.getUserName();
			cout << "WELCOME " << name << endl;
		}
		cout << "Enter quit if you want to exit" << endl;
		printstarline();
		printHLine();
		if(!a.isLoggedIn()) {
			cout << "Do you have an account ? (Y/N)" << endl;
			cin >> s;
			quit(s);
			if(s == "Y" || s == "y") {
				int n;
				string pass;
				cout << "Enter UserId: ";
				cin >> n;
				cout << "Enter Password: ";
				cin >> pass;
				quit(pass);
				a.login(pass, n);
			}
			if(s == "N" || s == "n") {
				string name;
				string pass;
				cout << "Enter UserName: ";
				cin >> name;
				quit(name);
				cout << "Enter Password: ";
				cin >> pass;
				quit(pass);
				a.signUp(name, pass);
			}
		} else { 
			{
				cout << "What would you like to do ??" <<endl;
				printHLine();
				cout << "1. Book Ticket for Movie" << endl;
				cout << "2. Add new Movie to database" << endl; 
				cout << "3. Check which Movie Tickets you already booked" << endl;
				cout << "Enter any number (1, 2, 3): ";
				cin >> s;
				quit(s);
				if(s == "1") {
					system("cls");
					while(true) {
						printHLine();
						cout << "Select which Movie You want to book ticket for"<<endl;
						cout << "enter 0 to cancel" << endl;
						printHLine();
						m.getMovies();
						cout << "Enter id of movie you want to see: ";
						cin >> n; 
						if(n == 0) {
							break;
						}
						m.selectMovie(n);
						int tickets, cvv;
						cout << "How Many Tickets Do You want to purchase ?" << endl;
						cin >> tickets;
						if(tickets == 0)
							break;
						cout << "Total Amount: " << stoi(m.getMoviePrice()) * tickets << endl; 
						string cno;
						cout << "Enter Debit/Credit Card Number" << endl;
						cin >> cno;
						if(cno == "0") break;
						cout << "Enter CVV" << endl;
						cin >> cvv;
						if(cvv == 0) break;
						cout << "Payment Successful" << endl;
						cout << "Generating Ticket ..." << endl;
						genTicket(m.getMovieName(), stoi(m.getMoviePrice()), n, a.getUserId(), tickets);
						cout << "Ticket Generated" << endl << "Visit Again!" << endl;
						cout << "Enter 0 if you want to exit or 1 if you want to visit home" << endl;
						cin >> s;
						if(s == "0") {
							quit("quit");
						}
						if(s == "1") {
							break;
						}
					}
				}
				if(s == "2") {
					string name;
					int price;
					cout << "Enter name of movie: " ;
					cin >> name;
					cout << "Enter price per ticket of movie: ";
					cin >> price;
					m.addMovie(name, price);
				}
				if(s == "3") {
					getBookedTickets(a.getUserId());
					cout << "Do You want to continue ?(Y/N)" << endl;
					cin >> s;
					quit(s);
					if(s=="Y"||s=="y") {
					}
					if(s=="n"||s=="N") {
						quit("quit");
					}
				}
			}
		}
	}
	return 0;
}
