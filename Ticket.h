#include "iostream"
#include "iomanip"
#include "fstream"
#include <string>

using namespace std;

void split(string const &str, const char delim,
			vector<string> &out)
{
	// construct a stream from the string
	stringstream ss(str);

	string s;
	while (getline(ss, s, delim)) {
		out.push_back(s);
	}
}

void genTicket(string name, int price, int id, int  userId, int tickets = 1) {
	fstream fo;
	string total_amount = to_string(price * tickets);
	string Price = to_string(price);
	string Id = to_string(id);
	string Tickets = to_string(tickets);
	fo.open("Ticket.txt", ios::out);
		fo << setw(50) << "Cinema Hall Ticket\n";
		fo << setw(15) << "Movie Name" << setw(15) << "Movie Id" << setw(15) << "Price" << setw(15) << "Tickets" << setw(15) << "Amount" << endl;			
		fo << setw(15) << name << setw(15) << Id << setw(15) << Price << setw(15) << Tickets << setw(15) << total_amount << endl;
		fo << endl << endl << endl << endl ;
		fo << setw(75) << "Total Amount " << total_amount << endl;
		fo << setw(50) << "Enjoy Your Show";
	fo.close();
	fo.open("BookedTicket.txt", ios::in|ios::out|ios::app);
	fo << endl<< userId << " " << id << " " << name << " " << price << " " << Tickets << " "<< total_amount ; 
	fo.close();
}

void getBookedTickets(int n) {
	fstream fo;
	string movie;
	string movieName, movieId, noTickets, pricePerTicket, totalPrice;

	fo.open("BookedTicket.txt", ios::in|ios::out|ios::app);
	getline(fo, movie);
	while(fo) {
		vector<string> v;
		split(movie,' ',v);
		if(n == stoi(v[0])) {
			movieId = v[1];
			movieName = v[2];
			pricePerTicket = v[3];
			noTickets = v[4];
			totalPrice = v[5];
			for(int i= 0;i<60;i++) {
				cout << "-";
			}
			cout << endl;
			cout << "Movie Id: "<< movieId << endl;
			cout << "Movie Name: " << movieName << endl;
			cout << "Price per ticket: " << pricePerTicket << endl;
			cout << "No of tickets: " << noTickets << endl;
			cout << "Total Amount: " << totalPrice << endl;
			for(int i= 0;i<60;i++) {
				cout << "-";
			}
			cout << endl;
		}
		getline(fo, movie);
	}
	fo.close();
}




			
		
		