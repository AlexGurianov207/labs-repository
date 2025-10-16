#include"date.h"

Date::Date():date("01/01/01") {

}

Date::Date(const std::string& newDate):date(newDate) {
    isValidDate();
}

void Date::isValidDate() const {
    if (date.length() != 8) {
        throw DateException("Invalid format.Should be 8 symbols - YY/MM/DD");
    }
    if (date[2] != '/' || date[5] != '/') {
        throw DateException("Invalid format.Should be - YY/MM/DD");
    }

    if (!(isdigit(date[0]) && isdigit(date[1]))) {
        throw DateException("YY - should be digits");
    }

    if (!(isdigit(date[3]) && isdigit(date[4]))) {
        throw DateException("MM - should be digits");
    }

    if (!(isdigit(date[6]) && isdigit(date[7]))) {
        throw DateException("DD - should be digits");
    }

    int year = (date[0] - '0') * 10 + (date[1] - '0');
    int month = (date[3] - '0') * 10 + (date[4] - '0');
    int day = (date[6] - '0') * 10 + (date[7] - '0');

    if (month > 12 || month < 1) {
        throw DateException("The number of months cannot exceed 12 or be less than 1");
    }

    if (day < 1 || day > 31) {
        throw DateException("The number of days cannot exceed 31 or be less than 1");
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        throw DateException("The month you entered cannot have more than 30 days");
    }

    if (month == 2) {
        if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && day > 29) {
            throw DateException("In a leap year, February cannot have more than 29 days");
        }
        if (!((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && day > 28) {
            throw DateException("February cannot have more than 28 days");
        }
    }
}