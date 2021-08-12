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
	void add_book();	 // Add new book
	void display_book(); // Display book
};
// end of class

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
	cout << "Book added successfully!";
}

void library::display_book()
{
	cout << "Book Details";
	cout << "\nBook Id: " << book_id;
	cout << "\nEnter Book ISBN: " << book_isbn;
	cout << "\nEnter Book name: " << book_name;
	cout << "\nEnter Author name: " << author_name;
}

//***FUNTIONS DECLARATIONS FOR FILES***//

void write_book();
void display_book();

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
	cout << "\t***BOOK DETAILS***" << endl;
	while (inFile.read((char *)&book, sizeof(library)))
	{
		book.display_book();
		found = true;
	}
	inFile.close();
	if (found == false)
	{
		cout << "Book does not exist" << endl;
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
	system("cls");
	cout << "__________________________________________________________________________\n\n";
	cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb" << endl;
	cout << "\n\t======== Welcome to Library Management System =======\n\n";
	cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb" << endl;
	cout << "__________________________________________________________________________" << endl;

	// ------------------ Login Here ------------------

	if (login())
	{
		cout << "\n\n====================== Login Successful: Welcome : ) ======================";
		Sleep(1000);
		system("cls");
		cout << "\n=================== MENU ==================\n\n";
		cout << "\t1) Add new book" << endl;
		cout << "\t2) See book list" << endl;
		cout << "\t3) Delete book" << endl;

		cout << "\nPlease enter a choice [1-3] : ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			write_book();
			break;
		case '2':
			display_book();
			break;
		default:
			break;
		}
	}
	else
	{
		system("cls");
		cout << "\n\n====================== Login Failed: Try again! : ( ======================";
	}

	return 0;
}