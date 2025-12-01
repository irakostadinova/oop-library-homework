#pragma once
#include <string>
#include <stdexcept>
#include "Author.h"

using namespace std;

class Book {
    string title;
    Author author;
    int year;
    double price;
    string isbn;

    static int totalBooks;

    void validate() {
        if (year < 1450 || year > 2025) {
            throw invalid_argument("Invalid year");
        }
        if (price < 0) {
            throw invalid_argument("Price cannot be negative");
        }
    }

public:
    Book() : title("Untitled"), author(), year(2000), price(0.0), isbn("UNKNOWN") {
        ++totalBooks;
    }

    Book(string t, const Author& a, int y, double p, string i)
        : title(t), author(a), year(y), price(p), isbn(i) {
        validate();
        ++totalBooks;
    }

    Book(const Book& other) = default;
    Book(Book&& other) = default;
    Book& operator=(const Book& other) = default;
    Book& operator=(Book&& other) = default;
    ~Book() = default;

    string getTitle() const { return title; }
    Author getAuthor() const { return author; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    string getIsbn() const { return isbn; }

    void setYear(int y) { year = y; validate(); }
    void setPrice(double p) { price = p; validate(); }

    string to_string() const {
        return title + " by " + author.to_string() + " (" + std::to_string(year) + ") - " +
               std::to_string(price) + "lv. [" + isbn + "]";
    }

    static int getTotalBooks() { return totalBooks; }
};

inline int Book::totalBooks = 0;


