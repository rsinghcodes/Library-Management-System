#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

// class used
class library
{
	int book_id;
	int book_isbn;
	string book_name;
	int price;
	string author_name;

	//***FUNCTION DECLARATIONS***
public:
	void add_book();  // Add new book
	void show_book(); // Display book
	void update();	  //update with new data from user
	int return_bid();
};
// end of class

//***FUNCTION DEFINITIONS***//
void library::add_book()
{
	cout << "Book Id: ";
	cin >> book_id;
	cout << "\nEnter Book ISBN: ";
	cin >> book_isbn;
	cout << "\nEnter Book name: ";
	cin >> book_name;
	cout << "\nEnter Author name: ";
	cin >> author_name;
	cout << "\nEnter Book price: ";
	cin >> author_name;
	cout << "\n====================== Book added successfully! ======================";
}

void library::show_book()
{
	cout << "\nBook Id: " << book_id;
	cout << "\nEnter Book ISBN: " << book_isbn;
	cout << "\nEnter Book name: " << book_name;
	cout << "\nEnter Author name: " << author_name;
	cout << "\nEnter Book price: " << price;
}

void library::update()
{
	cout << "Book Id: " << book_id;
	cout << "Enter book name: ";
	cin >> book_name;
	cout << "\nEnter Author name: ";
	cin >> author_name;
	cout << "\nEnter Book price: ";
	cin >> price;
}

int library::return_bid()
{
	return book_id;
}

//***FUNTIONS DECLARATIONS FOR FILES***//

void write_book();
void display_book();
void update_book(int);

void write_book()
{
	library book;
	ofstream outFile;
	//open file in write mode
	outFile.open("books.txt", ios::out);
	book.add_book();
	outFile.write((char *)&book, sizeof(library));
	outFile.close();
}

//Reading book details of an account from file
void display_book()
{
	library book;
	bool found = false;
	ifstream inFile;
	inFile.open("books.txt", ios::in);
	if (!inFile)
	{
		cout << "File not found...press any key to continue";
		return;
	}

	while (inFile.read((char *)&book, sizeof(library)))
	{
		book.show_book();
		found = true;
	}
	inFile.close();
	if (found == false)
	{
		cout << "Book does not exist" << endl;
	}
}

//Updating book record in the file
void update_book(int n)
{
	bool found = false;
	library book;
	fstream File;
	File.open("books.txt", ios::in, ios::out);
	if (!File)
	{
		cout << "File not found...press any key to continue\n";
		return;
	}
	while (File.read((char *)&book, sizeof(library)) && found == false)
	{
		if (book.return_bid() == n)
		{
			cout << "Old book details : ";
			book.show_book();
			cout << "\nEnter new details : ";
			book.update();
			int pos = (-1) * sizeof(library);
			File.seekp(pos, ios::cur);
			File.write((char *)&book, sizeof(library));
			cout << "\nRecord Updated successfully";
			found = true;
		}
	}
	File.close();
	if (found == false)
	{
		cout << "\nRecord not found";
	}
}

//***FUNTION DECLARATION FOR LOGIN***//
bool login()
{
	string username, password;
	cout << "\n\t\t  Librarian (Admin Login)" << endl;
	cout << "\n\tEnter username here: ";
	cin >> username;

	if (username == "qq")
	{
		cout << "\n\tEnter password here: ";
		cin >> password;
		if (password == "123")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int main()
{
	char choice;
	int num;

	system("cls");
	cout << "__________________________________________________________________________\n\n";
	cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb" << endl;
	cout << "\n\t======== Welcome to Library Management System ========\n\n";
	cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb" << endl;
	cout << "__________________________________________________________________________" << endl;

	// ------------------ Login Here ------------------

	if (login())
	{
		cout << "\n\n====================== Login Successful: Welcome : ) ======================";
		Sleep(1000);
		system("cls");
		cout << "\n\t================== MENU ==================\n\n";
		cout << "\t\t1) Add new book" << endl;
		cout << "\t\t2) See books list" << endl;
		cout << "\t\t3) Update book" << endl;
		cout << "\t\t4) Delete book" << endl;
		cout << "\t\t5) Exit" << endl;

		cout << "\nPlease enter a choice [1-4] : ";
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case '1':
			cout << "================ ADD BOOK DETAILS ==============\n\n";
			write_book();
			break;
		case '2':
			cout << "================ BOOK DETAILS ==============\n\n";
			display_book();
			break;
		case '3':
			cout << "Enter book Id : ";
			cin >> num;
			update_book(num);
		case '5':
			cout << "================ | THANK YOU FOR USING LIBRARY MANAGEMENT SYSTEM | ================" << endl;
			break;
		default:
			break;
		}
	}
	else
	{
		system("cls");
		cout << "\n\n====================== LOGIN FAILED: Try again! : ( ======================";
	}

	return 0;
}