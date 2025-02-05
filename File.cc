#include "File.h"

File::File(const string& name, const string& content,const Date& date): lastModified(date), name(name), content(content) {}

File::File(const File& e): File( e.name, e.content, e.lastModified){  }

void File::print() const{
	cout <<"File:          "<<name<<endl;
	cout <<"Last modified: ";
	lastModified.print(); cout<<endl;
}

bool File::lessThan(const File& e) const{
	// Return true if this File's name comes before the parameter's name
	// in alphabetical order
	const Date& current_date = this->lastModified;
	const Date& comparison_date = e.lastModified;

	const string current_name = this->getName();
	const string comparison_name = e.getName();


	// Case if file name comes before parameter name
	if (current_name == comparison_name){
		return (current_date.lessThan(comparison_date));
	}

	return (current_name < comparison_name);
}

// This method returns true if the name and the Date are equal
bool File::equals(const File& e) const{
	const Date& current_date = this->lastModified;
	const Date& comparison_date = e.lastModified;

	const string current_name = this->getName();
	const string comparison_name = e.getName();

	if (current_name!=comparison_name) {
		return false;
	} if ((current_date.getYear() == comparison_date.getYear()) &&
		  (current_date.getMonth() == comparison_date.getMonth()) &&
		  (current_date.getDay() == comparison_date.getDay())) {
			return true;
		  } else {
			return false;
		  }
}

void File::printContents() const{
	print();
	cout <<endl<< content<<endl<<endl;
}

