#include <iostream>
#include "Library.h"

int main() {
    Library lib;
    int choice;

    while (true) {
        std::cout << "\nLibrary Menu:\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Add Member\n";
        std::cout << "3. Search Book by Title\n";
        std::cout << "4. Search Book by ID\n";
        std::cout << "5. Search Books by Author\n";
        std::cout << "6. Checkout Book\n";
        std::cout << "7. Return Book\n";
        std::cout << "8. Display Books\n";
        std::cout << "9. Display Members\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 0) break;

        int id, memberId;
        std::string title, author, name;

        switch (choice) {
        case 1: // Add a new book
            std::cout << "Enter Book ID, Title, Author: ";
            std::cin >> id >> title >> author;
            lib.addBook(Book(id, title, author));
            break;
        case 2: // Add a new member
            std::cout << "Enter Member ID, Name: ";
            std::cin >> id >> name;
            lib.addMember(Member(id, name));
            break;
        case 3: // Search for a book by title
            std::cout << "Enter Book Title to Search: ";
            std::cin >> title;
            if (Book* b = lib.searchTitle(title))
                std::cout << "Found: " << b->getTitle() << " by " << b->getAuthor()
                << ", ID: " << b->getId()
                << ", Available: " << (b->getAvailability() ? "Yes" : "No") << "\n";
            else
                std::cout << "Book not found.\n";
            break;
        case 4: // Search for a book by ID
            std::cout << "Enter Book ID to Search: ";
            std::cin >> id;
            if (Book* b = lib.searchId(id))
                std::cout << "Found: " << b->getTitle() << " by " << b->getAuthor()
                << ", Available: " << (b->getAvailability() ? "Yes" : "No") << "\n";
            else
                std::cout << "Book not found.\n";
            break;
        case 5: // Search books by author
            std::cout << "Enter Author Name to Search: ";
            std::cin >> author;
            lib.displayBooksByAuthor(author);
            break;
        case 6: // Checkout a book
            std::cout << "Enter Book ID and Member ID: ";
            std::cin >> id >> memberId;
            lib.checkoutBook(id, memberId);
            break;
        case 7: // Return a book
            std::cout << "Enter Book ID to return: ";
            std::cin >> id;
            lib.returnBook(id);
            break;
        case 8: // Display all books
            lib.displayBooks();
            break;
        case 9: // Display all members
            lib.displayMembers();
            break;
        default:
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
