#include "Library.h"
#include <iostream>

//Add book to the library
void Library::addBook(const Book& book) {
    books.push_back(book);
}

//Add member to the library
void Library::addMember(const Member& member) {
    members.push_back(member);
}

//Find the book by ID and check it out if available
//If the book is available, it will be marked as available and added to the member's borrowed list
void Library::checkoutBook(int bookId, int memberId) {
    Book* book = searchId(bookId);
    if (book && book->getAvailability()) {
        for (auto& member : members) {
            if (member.getId() == memberId) {
                member.borrowBook(bookId);
                book->setAvailability(false);
                std::cout << "Book checked out successfully.\n";
                return;
            }
        }
    }
    std::cout << "Checkout failed.\n";
}

//Find the book by ID
//Mark it as available and remove it from all members' borrowed lists
void Library::returnBook(int bookId) {
    Book* book = searchId(bookId);
    if (book && !book->getAvailability()) {
        for (auto& member : members) {
            member.returnBook(bookId);
        }
        book->setAvailability(true);
        std::cout << "Book returned successfully.\n";
    }
    else {
        std::cout << "Return failed.\n";
    }
}

//Search for a book by title
Book* Library::searchTitle(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title) return &book;
    }
    return nullptr;
}

//Search for a book by ID
Book* Library::searchId(int id) {
    for (auto& book : books) {
        if (book.getId() == id) return &book;
    }
    return nullptr;
}

//Search for books by author
std::vector<Book*> Library::searchAuthor(const std::string& author) {
    std::vector<Book*> results;
    for (auto& book : books) {
        if (book.getAuthor() == author) {
            results.push_back(&book);
        }
    }
    return results;
}


//Display all books in the library
void Library::displayBooks() const {
    for (const auto& book : books) {
        std::cout << "ID: " << book.getId()
            << ", Title: " << book.getTitle()
            << ", Author: " << book.getAuthor()
            << ", Available: " << (book.getAvailability() ? "Yes" : "No") << "\n";
    }
}

//Display all members in the library
void Library::displayMembers() const {
    for (const auto& member : members) {
        std::cout << "ID: " << member.getId()
            << ", Name: " << member.getName() << "\n";
    }
}

//Display all books by a specific author
void Library::displayBooksByAuthor(const std::string& author) {
    std::vector<Book*> foundBooks = searchAuthor(author);
    if (foundBooks.empty()) {
        std::cout << "No books found by author: " << author << "\n";
    }
    else {
        std::cout << "Books by " << author << ":\n";
        for (const auto* book : foundBooks) {
            std::cout << "ID: " << book->getId()
                << ", Title: " << book->getTitle()
                << ", Available: " << (book->getAvailability() ? "Yes" : "No") << "\n";
        }
    }
}
