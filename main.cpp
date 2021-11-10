#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIN() {
	string username, password, un, pw;

	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	ifstream read(username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	int choice;

	cout << "1: Register\n2: Login\nChoice: ";
	cin >> choice;

	if (choice == 1) {
		string username, password;

		cout << "Enter username: "; 
		cin >> username;

		cout << "Enter password: ";
		cin >> password;

		ofstream file;
		file.open(username + ".txt");
		file << username << endl << password;
		file.close();

		main();
	}
	else if (choice == 2) {
		bool status = IsLoggedIN();

		if (!status) {
			cout << "Incorrect Login" << endl;
			system("PAUSE");
			return 0;
		}
		else {
			cout << "You are now logged in!";
			system("PAUSE");
			return 1;
		}
	}
}