#include"BookType.h"
#include<string>
#include<iomanip>
#include<iostream>

lib::BookType::BookType() {
	title = " ";
	publisher = " ";
	authors[4];
	ISBN = " ";
	publicationYear = " ";
	price = 0;
	stock = 0;
	numOfAuthors = 0;
}
int lib::BookType::getStock() const {
	return stock;
}
double lib::BookType::getPrice() const {
	return price;
}
int lib::BookType::getNumOfAuthors() const {
	return numOfAuthors;
}
std::string lib::BookType::getTitle() const {
	return title;
}
std::string lib::BookType::getAuthors() const {
	std::string names = "";
	for (int i = 0; i < numOfAuthors; i++) {
		if (authors[i].compare(" ") != 0)
			names = names + authors[i] + "; ";
	}
	return names;
}
std::string lib::BookType::getISBN() const {
	return ISBN;
}
std::string lib::BookType::getPublisher() const {
	return publisher;
}
std::string lib::BookType::getPublicationYear() const {
	return publicationYear;
}
void lib::BookType::setTitle(std::string newTitle) {
	title = newTitle;
}
void lib::BookType::updateStock(int addStock) {
	stock += addStock;
}
void lib::BookType::setStock(int newStock) {
	stock = newStock;
}
void lib::BookType::setISBN(std::string newISBN) {
	ISBN = newISBN;
}
void lib::BookType::setAuthors() {
	int count = 0;
	std::string author = " ";
	std::cout << "How many authors does this book have" << std::endl;
	std::cin >> count;
	std::cin.get();
	for (int i = 0; i < count; i++) {
		std::cout << "Enter author " << i << " name" << std::endl;
		std::getline(std::cin, author);
		authors[i] = author;
	}
	numOfAuthors = count;
}
void lib::BookType::setPrice(double cost) {
	price = cost;
}
void lib::BookType::decrementStock() {
	stock--;
}
void lib::BookType::setnumOfAuthors(int num) {
	numOfAuthors = num;
}
void lib::BookType::setPublishYear(std::string year) {
	publicationYear = year;
}
void lib::BookType::setPublisher(std::string name) {
	publisher = name;
}
bool lib::BookType::checkTitle(std::string newTitle) {
	if (title.compare(newTitle) == 0)
		return true;
	else
		return false;
}
void lib::BookType::showBookInfo() const{
	std::cout << std::fixed << std::showpoint << std::setprecision(2);
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Title: " << title << std::endl;
	std::cout << "Author(s): " << getAuthors() << std::endl;
	std::cout << "ISBN: " << ISBN << std::endl;
	std::cout << "Publisher: " << publisher << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Stock: " << stock << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
}
