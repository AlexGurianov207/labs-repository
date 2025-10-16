#ifndef DATE_H
#define DATE_H

#include"myexception.h" 

class Date {
private:
	std::string date;

	void isValidDate() const;
public:
	Date();
	explicit Date(const std::string& newDate);

	friend std::istream& operator>>(std::istream& inputStream, Date& myDate) {
		std::string buffer;
		inputStream >> buffer;

		Date temp(buffer);

		myDate.date = temp.date;

		return inputStream;
	}

	friend std::ostream& operator<<(std::ostream& outputStream, const Date& myDate) {
		outputStream << myDate.date;
		return outputStream;
	}
};

#endif