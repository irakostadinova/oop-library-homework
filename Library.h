#pragma once
#include <string>
#include <vector>
#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include "Author.h"

using namespace std;

class Library {
    vector<Book> books;
    vector<Member> members;
    vector<Loan> loans;

public:
    void addBook(const Book& b) {
        books.push_back(b);
    }

    void addMember(const Member& m) {
        members.push_back(m);
    }

    bool hasBook(const string& isbn) const {
        for (const auto& b : books) {
            if (b.getIsbn() == isbn) {
                return true;
            }
        }
        return false;
    }

    bool isBookAvailable(const string& isbn) const {
        for (const auto& loan : loans) {
            if (loan.getISBN() == isbn && !loan.isReturned()) {
                return false;
            }
        }
        return true;
    }

    bool loanBook(const string& isbn, const string& memberId, const string& start, const string& due) {
        if (!hasBook(isbn) || !isBookAvailable(isbn)) {
            return false;
        }
        loans.push_back(Loan(isbn, memberId, start, due));
        return true;
    }

    bool returnBook(const string& isbn, const string& memberId) {
        for (auto& loan : loans) {
            if (loan.getISBN() == isbn && loan.getMemberId() == memberId && !loan.isReturned()) {
                loan.markReturned();
                return true;
            }
        }
        return false;
    }

    vector<Book> findByAuthor(const string& authorName) const {
        vector<Book> result;
        for (const auto& b : books) {
            if (b.getAuthor().getName().find(authorName) != string::npos) {
                result.push_back(b);
            }
        }
        return result;
    }

    string to_string() const {
        int activeLoans = 0;
        for (const auto& l : loans) {
            if (!l.isReturned()) ++activeLoans;
        }

        return "Library:\n" +
               string("Total books: ") + std::to_string(books.size()) + "\n" +
               string("Total members: ") + std::to_string(members.size()) + "\n" +
               string("Active loans: ") + std::to_string(activeLoans);
    }
};

