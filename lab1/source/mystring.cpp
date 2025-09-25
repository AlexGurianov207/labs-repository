#include "mystring.h"

using namespace std;

MyString::MyString() : length(0), str(new char[1]) { str[0] = '\0'; }

MyString::~MyString() { delete[] str; }

MyString::MyString(const char* newString) {
    if (newString == nullptr) {
        str = new char[1];
        str[0] = '\0';
        length = 0;

    }
    else {
        length = 0;
        while (newString[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (size_t i = 0; i <= length; i++) {
            str[i] = newString[i];
        }
    }
}

MyString::MyString(const MyString& other) : length(other.length) {
    str = new char[length + 1];
    for (size_t i = 0; i <= length; i++) {
        str[i] = other.str[i];
    }
}

void MyString::printStr() const { cout << str << endl; }

void MyString::inputStr() {
    cout << "Enter the string:" << endl;

    delete[] str;

    size_t capacity = 1;
    length = 0;
    str = new char[1];
    str[length] = '\0';

    char symbol;
    while (cin.get(symbol) && symbol != '\n') {
        if (length <= capacity - 1) {
            capacity = length + 2;
            auto* newStr = new char[capacity];
            for (size_t i = 0; i < length; i++) {
                newStr[i] = str[i];
            }

            delete[] str;
            str = newStr;
        }

        str[length++] = symbol;
    }
    str[length] = '\0';
}

MyString MyString::intersection(const MyString& other) const {
    if (length == 0 || other.length == 0) {
        return MyString();
    }

    auto* temp = new char[length + 1];
    size_t resultLength = 0;
    temp[resultLength] = '\0';

    for (int i = 0; i < length; i++) {
        char currentSymbol = str[i];

        bool foundInOther = false;
        for (int j = 0; j < other.length; j++) {
            if (currentSymbol == other.str[j]) {
                foundInOther = true;
                break;
            }
        }

        if (!foundInOther) continue;

        bool alreadyInResult = false;
        for (int k = 0; k < resultLength; k++) {
            if (currentSymbol == temp[k]) {
                alreadyInResult = true;
                break;
            }
        }

        if (!alreadyInResult) {
            temp[resultLength++] = currentSymbol;
        }
    }

    MyString resultString;
    if (resultLength > 0) {
        delete[] resultString.str;
        resultString.str = new char[resultLength + 1];
        for (size_t k = 0; k < resultLength; k++) {
            resultString.str[k] = temp[k];
        }
        resultString.str[resultLength] = '\0';
        resultString.length = resultLength;
    }
    delete[] temp;

    if (resultLength == 0) {
        cout << "No common symbols" << endl;
    }
    else
        cout << "Result:" << resultString.str << endl;

    return resultString;
}

void testInputPrint() {
    MyString firstStr;
    cout << "Enter the first string" << endl;
    firstStr.inputStr();
    cout << "Your string: ";
    firstStr.printStr();

    MyString secondStr;
    cout << "Enter the second string" << endl;
    secondStr.inputStr();
    cout << "Your string: ";
    secondStr.printStr();
}

void testIntersection() {
    MyString firstStrToIntersection;
    firstStrToIntersection.inputStr();

    MyString secondStrToIntersection;
    secondStrToIntersection.inputStr();

    MyString resultIntersection =
        firstStrToIntersection.intersection(secondStrToIntersection);

}

void testConstructors() {
    MyString emptyStr;
    cout << "Empty string:";
    emptyStr.printStr();

    MyString newStr("It is a test string");
    cout << "String:";
    newStr.printStr();

    MyString copiendStr(newStr);
    cout << "Copy:";
    copiendStr.printStr();
}

