#pragma once
#include <string>
#include <stdexcept>

using namespace std;

class Member {
    string name;
    string memberId;
    int yearJoined;

public:
    Member() : name("Unknown"), memberId("0000"), yearJoined(2000) {}

    Member(string n, string id, int year) : name(n), memberId(id), yearJoined(year) {
        if (id.empty()) {
            throw invalid_argument("Member Id cannot be empty");
        }
    }

    string getName() const { return name; }
    string getMemberId() const { return memberId; }
    int getYearJoined() const { return yearJoined; }

    void setName(const string& n) { name = n; }

    void setMemberId(const string& id) {
        if (id.empty()) {
            throw invalid_argument("Member Id cannot be empty");
        }
        memberId = id;
    }

    void setYearJoined(int year) { yearJoined = year; }

    string to_string() const {
        return name + " [" + memberId + "] (Joined: " + std::to_string(yearJoined) + ")";
    }
};
