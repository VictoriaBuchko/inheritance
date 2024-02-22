#include <iostream>
using namespace std;


class  Passport
{
protected:
	char* name;
	char* lastName;
	char* surname;
	int age;
	char* country;

public:
	Passport() {

		name = nullptr;
		lastName = nullptr;
		surname = nullptr;
		age = 0;
		country = nullptr;
	 }

	Passport(const char* Name, const char* LastName, const char* Surname, int Age, const char* Country) {
		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);

		lastName = new char[strlen(LastName) + 1];
		strcpy_s(lastName, strlen(LastName) + 1, LastName);

		surname = new char[strlen(Surname) + 1];
		strcpy_s(surname, strlen(Surname) + 1, Surname);

		age = Age;

		country = new char[strlen(Country) + 1];
		strcpy_s(country, strlen(Country) + 1, Country);
	}

	void OutPut() {

		cout << "Info about persone: " << endl;
		if (name != nullptr) {
			cout << "Name: " << name << endl;
		}
		if (lastName != nullptr) {
			cout << "Last Name: " << lastName << endl;
		}
		if (surname != nullptr) {
			cout<<"Surname: "<<surname<< endl;
		}
		cout << "Age: " << age << endl;
		if (country != nullptr) {
			cout << "Country: " << country << endl;;
		}
	}

	~Passport() {

		if (name != nullptr) {
			delete[] name;
		}
		if (lastName != nullptr) {
			delete[] lastName;
		}
		if ( surname!= nullptr){
			delete[] surname;
		}
		if (country != nullptr){
			delete[] country;
		}
	}
};

class ForeignPassport:public Passport {
	int passportID;
	char* visaInfo;
public:
	ForeignPassport() {

		passportID = 0;
		visaInfo = nullptr;
	}
	ForeignPassport(const char* VisaInfo, int PassportID, const char* Name, const char* LastName, const char* Surname, int Age, const char* Country) :Passport(Name, LastName, Surname, Age, Country) {
		
		visaInfo = new char[strlen(VisaInfo) + 1];
		strcpy_s(visaInfo, strlen(VisaInfo) + 1, VisaInfo);

		passportID = PassportID;
	}
	void OutPut(){
		Passport::OutPut();
		cout << "Foreign Passport ID: " << passportID << endl;
		cout << "Visa:" << visaInfo << endl;
	}

	~ForeignPassport() {
		delete[] visaInfo;
	}
};


int main()
{
	ForeignPassport person("Tourist Visa", 12345678, "Vika", "Buchko", "Ihorivna", 18, "Ukraine");
	person.OutPut();
}

