#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>

//Create the class for member who can borrow books from the library
class Member {
private:
    int id;
    std::string name;
	std::vector<int> borrowedBookIds; // Store IDs of borrowed books

public:
    Member(int id, const std::string& name);

    int getId() const;
    std::string getName() const;
    std::vector<int> getBorrowedBooks() const;

    void borrowBook(int bookId);
    void returnBook(int bookId);
};
#endif
