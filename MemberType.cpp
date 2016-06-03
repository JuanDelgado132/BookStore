#include "MemberType.h"
#include <string>
#include <iostream>
#include <iomanip>
long mem::MemberType::idcount = 100000;

void mem::MemberType::setName(std::string n) {
	name = n;
}
std::string mem::MemberType::getName() const {
	return name;
}
void mem::MemberType::setBooksBought(int books) {
	booksBought = books;
}
int mem::MemberType::getBooksBought() const {
	return booksBought;
}
void mem::MemberType::setId() {
	id = ++idcount;
}
long mem::MemberType::getID() const {
	return id;
}
void mem::MemberType::setSpent(double cost) {
	spent = cost;
}
double mem::MemberType::getSpent() const {
	return spent;
}
void mem::MemberType::buyBooks(lib::BookType& book) {
	booksBought++;
	if (booksBought % 11 == 0) {
		spent += (tempSpent / 10);
		tempSpent = 0;
	}
	else{
		spent += (book.getPrice() - (book.getPrice() * .05));
		tempSpent += (book.getPrice() - (book.getPrice() * .05));
	}
	book.decrementStock();
}
void mem::MemberType::printInfo() const {
	using namespace std; // Did not really feel like typing std all the time at this point
	cout << showpoint << fixed << setprecision(2);
	cout << "----------------------------------------------------" << endl;
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Books Bought: " << booksBought << endl;
	cout << "Total Spent: " << spent << endl;
	cout << "----------------------------------------------------" << endl;
}
mem::MemberType::MemberType(std::string n, long i, int bought, double cost) {
	name = n;
	id = i;
	booksBought = bought;
	spent = cost;
	tempSpent = cost;

}
