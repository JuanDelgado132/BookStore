#include<iostream>
#include<string>
#include"BookType.h"
#include"MemberType.h"

/*This is a sample size
This should work with 1000 books and 500 members*/

bool isMember(mem::MemberType[], const std::string&);
void menu();
void buyBook(mem::MemberType[], lib::BookType[]);
void printMembers(mem::MemberType[]);
void printBooks(lib::BookType[]);
void addBookInfo(lib::BookType[]);
void addMember(mem::MemberType[]);

int main() {
	int choice = 0;
	//int choice = 1;
	lib::BookType books[1000];
	mem::MemberType members[500];
	while (choice != 6)
	{
			menu();
			std::cin >> choice;
			std::cin.get();
			if (!std::cin)
			{
				std::cout << "Input stream failed\n";
				std::cout << "resetting......" << std::endl;
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Stream has been reset" << std::endl;
			}
			else if (choice == 1)
				printBooks(books);
			else if (choice == 2)
				printMembers(members);
			else if (choice == 3)
				addBookInfo(books);
			else if (choice == 4)
				addMember(members);
			else if (choice == 5)
				buyBook(members, books);
	}



	return 0;
}
// Name is pass by reference so memory will not have to be allocated for it since it is used to just compare the member name
bool isMember(mem::MemberType mems[], const std::string& name) {
	for (int i = 0; i < 500; i++) {
		if (mems[i].getName().compare(name) == 0)
			return true;
	}
	return false;
}
void menu() {
	std::cout << "***********************************************************" << std::endl;
	std::cout << "Enter 1 to see every book in stock and their info" << std::endl;
	std::cout << "Enter 2 to see every member of the bookstore" << std::endl;
	std::cout << "Enter 3 to add a book to the bookstore" << std::endl;
	std::cout << "Enter 4 to add a memeber to the bookstore" << std::endl;
	std::cout << "Enter 5 to buy a book" << std::endl;
	std::cout << "Enter 6 to exit the program" << std::endl;
	std::cout << "***********************************************************" << std::endl;
}
void printBooks(lib::BookType b[]) {
	for (int i = 0; i < 1000; i++)
		if(b[i].getTitle().compare(" ") != 0)
			b[i].showBookInfo();
}
void printMembers(mem::MemberType mems[]) {
	for (int i = 0; i < 500; i++)
		if(mems[i].getName().compare(" ") != 0)
			mems[i].printInfo();
}
void addMember(mem::MemberType mems[]) {
	using namespace std;
	bool spaceAvailable = false;
	int i;
	string name = " ";
	for (i = 0; i < 500; i++) {
		if (mems[i].getName().compare(" ") == 0) {
			
			cout << "Enter your name: ";
			getline(cin, name);
			mems[i].setName(name);
			mems[i].setId();
			return;
		}
	}
	cout << "Could not add member" << endl; // If array can no longer hold any data without overwritting existing data

}
void addBookInfo(lib::BookType b[]) {
	using namespace std;
	bool spaceAvailable = false;
	int i;
	string title = " ", isbn = " ", pub = " ", year = " ";
	double price = 0.0;
	int stock = 0;
	for (i = 0; i < 1000; i++) {
		if (b[i].getTitle().compare(" ") == 0) {
			do
			{
				if (!cin) {
					cout << "Input stream has failled" << endl;
					cout << "Resetting the stream........" << endl;
					cout << "Re-enter the book data" << endl;
					cin.clear();
					cin.ignore(100, '\n');
				}
				cout << "Enter the title of the book:" << endl;
				getline(cin, title);
				b[i].setTitle(title);
				cout << "Enter the ISBN:" << endl;
				getline(cin, isbn);
				b[i].setISBN(isbn);
				b[i].setAuthors();
				cout << "Enter the publisher:" << endl;
				getline(cin, pub);
				b[i].setPublisher(pub);
				cout << "Enter the publication year" << endl;
				getline(cin, year);
				b[i].setPublishYear(year);
				cout << "Enter price:" << endl;
				cin >> price;
				b[i].setPrice(price);
				cout << "Enter stock:" << endl;
				cin >> stock;
				b[i].setStock(stock);
			} while (!cin);
			return; //Stops the execution of the function call and exits both the function and loop
		}
	}
	cout << "Could not enter book." << endl; //If array can no longer hold any data without overwritting existing data
}
void buyBook(mem::MemberType mems[], lib::BookType b[]) {
	using namespace std;
	string name = "", title = "", response = "";
	int i , n;

	cout << "Enter name" << endl;
	getline(cin, name);

	for (i = 0; i < 500; i++)
		if (mems[i].getName().compare(name) == 0)
			break;

	cout << "Which book would you like to buy." << endl;
	printBooks(b);
	getline(cin, title);

	for (n = 0; n < 10000; n++) {
		if (b[n].getTitle().compare(title) == 0)
			break;
		else if(n == 999)
		{
			cout << "No book is found matching that title" << endl;
				return; //Exits the functions if no book matching the title is found
		}
	}

	if (b[n].getStock() == 0) {
		cout << "Book out of stock" << endl;
			return;
	}
	if (isMember(mems, name)) 
		mems[i].buyBooks(b[n]);
	else
	{
		cout << "Thank you for your buying: " << name << endl;
		b[n].decrementStock();
	}
}