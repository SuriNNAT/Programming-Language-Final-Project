#ifndef BOOK_H
#define BOOK_H
#include <string>

//Create the Book class
class Book {
private:
    int id;
    std::string title;
    std::string author;
	bool isAvailable; // Availability status of the book

public:
    Book(int id, const std::string& title, const std::string& author);

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    bool getAvailability() const;

    void setAvailability(bool status);
};

#endif