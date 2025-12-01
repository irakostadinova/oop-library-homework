#pragma once
#include <string>
#include <stdexcept>

using namespace std;

class Loan {
    string isbn;
    string memberId;
    string startDate;
    string dueDate;
    bool returned;

    void validateDates() {
        if (dueDate < startDate) {
            throw invalid_argument("Due date cannot be earlier than start date");
        }
    }

public:
    Loan(string isbn, string memberId, string startDate, string dueDate) {
        this->isbn = isbn;
        this->memberId = memberId;
        this->startDate = startDate;
        this->dueDate = dueDate;
        this->returned = false;
        validateDates();
    }

    string getISBN() const { return isbn; }
    string getMemberId() const { return memberId; }
    string getStartDate() const { return startDate; }
    string getDueDate() const { return dueDate; }
    bool isReturned() const { return returned; }

    void markReturned() { this->returned = true; }

    bool isOverdue(const string& today) const {
        return (!this->returned && today > this->dueDate);
    }

    string to_string() const {
        return "ISBN: " + this->isbn + ", Member: " + this->memberId +
               ", Start: " + this->startDate + ", Due: " + this->dueDate +
               ", Returned: " + (this->returned ? "Yes" : "No");
    }
};

