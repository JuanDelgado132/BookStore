#ifndef MemberType_H
#define MemberType_H
#include<string>
#include"BookType.h"

namespace mem {
	class MemberType {
	private:
		std::string name;
		long id;
		int booksBought;
		double spent;
		double tempSpent = 0; //Temp spent is here to hold the amount of the last 10 books bought.
		static long idcount;
	public:
		void setName(std::string);
		std::string getName() const;
		void setId();
		long getID() const;
		void setBooksBought(int);
		int getBooksBought() const;
		void setSpent(double);
		double getSpent() const;
		void buyBooks(lib::BookType&);
		void printInfo() const;
		MemberType(std::string = " ", long = 00000000000, int = 0, double = 0);
	};
}
#endif
//Do exercise 14 from chapter 11 review.