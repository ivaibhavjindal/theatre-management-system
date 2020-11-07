#include "iostream"
#include "fstream"
using namespace std;

class User {
	int UserId = 0;
	string UserName;
public:
	int getUserId() {
		return UserId;
	}

	string getUserName() {
		return UserName;
	}

	void addUserId(int id) {
		UserId = id;
	}

	void addUserName(string name) {
		UserName = name;
	}

	void signUp(string name, string pass) {
		fstream fo;
		fstream fo2;
		string line;
		int c = 0;
		fo.open("Username.txt", ios::in|ios::out|ios::app);
		fo << name << endl;
		fo.seekg(0, ios::beg);
		addUserName(name); 
		while(fo) {
			getline(fo,line);
			c = c + 1;
		}
		fo2.open("Userpassword.txt", ios::in|ios::out|ios::app);
		fo2 << pass << endl;
		addUserId(c-1);
		cout << "Never forget your UserId\nYou will not be able to use your account without it." << endl;
		cout << "Your UserId: " << c-1 << endl;
		cout << "Enter 0 to continue : ";		
		cin >> line;
		fo.close();
		fo2.close();	
	}

	bool login(string pass, int n) {
		fstream fo;
		fstream fo2;
		string line1;
		string line2;
		fo.open("Userpassword.txt", ios::in|ios::out|ios::app);
		for(int i = 0; i < n; i++) {
			getline(fo, line1);
		}
		fo2.open("Username.txt", ios::in|ios::out|ios::app);
		for(int i = 0; i < n; i++) {
			getline(fo2,line2);
		}
		if(pass == line1) {
			addUserId(n);
			addUserName(line2);
			return true;
		}else {
			return false;
		}

	}

	bool isLoggedIn() {
		if(getUserId() == 0) {
			return false;
		}else {
			return true;
		}
	}
	
};