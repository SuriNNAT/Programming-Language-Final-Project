#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "Member.h"

class Library {
private:
	std::vector<Book> books; //List of books in the library
	std::vector<Member> members; //List of members in the library

public:
    void addBook(const Book& book);
    void addMember(const Member& member);

    void checkoutBook(int bookId, int memberId);
    void returnBook(int bookId);

    Book* searchTitle(const std::string& title);
    Book* searchId(int id);
    std::vector<Book*> searchAuthor(const std::string& author);

    void displayBooks() const;
    void displayMembers() const;
    void displayBooksByAuthor(const std::string& author);
};

#endif
