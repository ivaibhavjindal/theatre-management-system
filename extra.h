#include "iostream"
using namespace std;

void printHLine() {
	for(int i=0 ; i < 60 ; i++) {
		cout << "=";
	}
	cout << endl;
}

void printstarline() {
	for(int i = 0; i < 60; i++) {
		cout << "*" ;
	}
	cout << endl;
}

void quit(string s) {
	if(s == "quit") {
		exit(0);
	}
}