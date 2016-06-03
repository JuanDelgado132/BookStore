#ifndef H_BookType //If BookType not defined then define it. If it is already defined then it will skip the definitions.
#define H_BookType 

#include<string>

namespace lib 
{
	class BookType
	{
	private:
		std::string title = " ";
		std::string publisher = " ";
		std::string authors[4];
		std::string ISBN = " ";
		std::string publicationYear = " ";
		double price = 0;
		int stock = 0;
		int numOfAuthors = 0;
	public:
		int getStock() const;
		double getPrice() const;
		int getNumOfAuthors() const;
		std::string getTitle() const;
		std::string getAuthors() const;
		std::string getISBN() const;
		std::string getPublisher() const;
		std::string getPublicationYear() const;
		void setTitle(std::string);
		void updateStock(int);
		void setStock(int);
		void setISBN(std::string);
		void setAuthors();
		void setPrice(double);
		void setnumOfAuthors(int);
		void setPublishYear(std::string);
		void setPublisher(std::string);
		bool checkTitle(std::string);
		void showBookInfo() const;
		void decrementStock();
		BookType();
	};
}
#endif