#include "Member.h"

//Constructor
Member::Member(int id, const std::string& name)
    : id(id), name(name) {
}

// Getters
int Member::getId() const { 
    return id;
}
std::string Member::getName() const { 
    return name; 
}
std::vector<int> Member::getBorrowedBooks() const {
    return borrowedBookIds; 
}

//Add a book to the borrowed list
void Member::borrowBook(int bookId) {
    borrowedBookIds.push_back(bookId);
}

//Remove a book from the borrowed list
void Member::returnBook(int bookId) {
    borrowedBookIds.erase(
        std::remove(borrowedBookIds.begin(), borrowedBookIds.end(), bookId),
        borrowedBookIds.end()
    );
}
