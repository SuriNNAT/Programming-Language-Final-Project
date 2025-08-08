#include "Book.h"

//Constructor for the Book class, set isAvailable to true by default
Book::Book(int id, const std::string& title, const std::string& author)
    : id(id), title(title), author(author), isAvailable(true) {
}

//Getters
int Book::getId() const { 
    return id; 
}
std::string Book::getTitle() const {
    return title;
}
std::string Book::getAuthor() const { 
    return author; 
}
bool Book::getAvailability() const { 
    return isAvailable; 
}

//Setter for availability status
void Book::setAvailability(bool status) { 
    isAvailable = status; 
}
