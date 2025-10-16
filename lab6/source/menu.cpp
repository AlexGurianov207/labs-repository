#include"menu.h"

using namespace std;

void showMenu() {
	cout << "----------MENU----------" << endl;
	cout << "1. Test constructors" << endl;
	cout << "2. Enter the date" << endl;
	cout << "3. Print the date" << endl;
	cout << "0. Exit" << endl;
}

void testConstructors() {
	try {
		Date defaultDate;
		cout << defaultDate << endl;

		Date firstDate("13/03/23");
		cout << firstDate << endl;

		Date secondDate("35/04/32");
		cout << secondDate << endl;

	}
	catch (const DateException& ex) {
		cout << "Constructors error:" << ex.what() << endl;
	}
}

void testInputDate(Date& myDate) {
	try {
		cout << "Enter the date:";
		cin >> myDate;
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
}