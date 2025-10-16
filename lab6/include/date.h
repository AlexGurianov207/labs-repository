#ifndef DATE_H
#define DATE_H

#include"myexception.h" 

class Date {
private:
	std::string date;

	static constexpr const char* defaultDate = "01/01/01";
	static constexpr int formatSizeDate = 8;

	void isValidDate(const std::string& dateStr) const;
public:
	Date();
	explicit Date(const std::string& newDate);

	void setDate(const std::string& newDate);

	friend std::istream& operator>>(std::istream& inputStream, Date& myDate) {
		std::string buffer;
		inputStream >> buffer;

		myDate.setDate(buffer);

		return inputStream;
	}

	friend std::ostream& operator<<(std::ostream& outputStream, const Date& myDate) {
		outputStream << myDate.date;
		return outputStream;
	}
};

#endif