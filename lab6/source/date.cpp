#include"date.h"

void Date::setDate(const std::string& newDate) {
    isValidDate(newDate);
    date = newDate;
}

Date::Date():date(defaultDate) {

}

Date::Date(const std::string& newDate) {
    setDate(newDate);
}


void Date::isValidDate(const std::string& dateStr) const {
    isFormatDate(dateStr);
    isTrueDate(dateStr);
}

void Date::isFormatDate(const std::string& dateStr)const {
    if (dateStr.length() != formatSizeDate) {
        throw DateException("Invalid format.Should be 8 symbols - YY/MM/DD");
    }
    if (dateStr[2] != '/' || dateStr[5] != '/') {
        throw DateException("Invalid format.Should be - YY/MM/DD");
    }

    if (!(isdigit(dateStr[0]) && isdigit(dateStr[1]))) {
        throw DateException("YY - should be digits");
    }

    if (!(isdigit(dateStr[3]) && isdigit(dateStr[4]))) {
        throw DateException("MM - should be digits");
    }

    if (!(isdigit(dateStr[6]) && isdigit(dateStr[7]))) {
        throw DateException("DD - should be digits");
    }
}

void Date::isTrueDate(const std::string& dateStr)const {
    int year = (dateStr[0] - '0') * 10 + (dateStr[1] - '0');
    int month = (dateStr[3] - '0') * 10 + (dateStr[4] - '0');
    int day = (dateStr[6] - '0') * 10 + (dateStr[7] - '0');

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