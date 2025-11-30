//============================================================================
// Names       : Julien Clavier and Alexandra Kyrkas
// Assignment  : 4
// File        : Patient.cpp
//============================================================================

#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#include "Patient.h"
using namespace std;

// Constructors
Patient::Patient()  {

	firstName = " ";
	lastName = " ";
	id = 0;
	doctor = -1;
	birthday = " ";
	bloodType = " ";
	diagn = " ";
	admissionDate = " ";
	dischargeDate = "-1";


}

Patient::Patient(string first_name, string last_name, long int ID, long int doc, string dob, string blood_type, string diagnosis, string admission, string discharge) {

	firstName = first_name;
	lastName = last_name;
	id = ID;
	doctor = doc;
	birthday = dob;
	bloodType = blood_type;
	diagn = diagnosis;
	admissionDate = admission;
	dischargeDate = discharge;

}

// Setters
void Patient::set_firstName(string a) {

	while (a.empty()) {

		cout << endl << "This field cannot be empty. Please enter the patient's first name: ";
	    cin >> a;
	}

	firstName = a;
}

void Patient::set_lastName(string a) {

    while (a.empty()) {

        cout << endl << "This field cannot be empty. Please enter the patient's last name: ";
        cin >> a;
    }

    lastName = a;
}

void Patient::set_id(long int a) {

    while (a == 0 || a < 10000000 || a > 99999999) {

        cout << endl << "Invalid ID. Please enter a positive 8-digit integer: ";
        cin >> a;
    }

	id = a;
}

void Patient::set_doctor(long int a) {

	while (a != -1 && (a < 10000000 || a > 99999999)) {

		cout << endl << "Invalid ID. Please enter a positive 8-digit integer or -1 if not doctor is assigned: ";
	    cin >> a;
	}

    doctor = a;
}

void Patient::set_birthday(string a) {

	bool numbers = true;

	while (true) {

		numbers = true;
		if (a.size() == 8){

			for (char c:a){

				if(!isdigit(c)){

					numbers = false;
				}
			}

			if(numbers){

				break;
			}
		}

		cout << endl << "Please enter the date of birth of the patient in YYYYMMDD format: ";
		cin >> a;
	}

    birthday = a;
}

void Patient::set_bloodType(string a) {

	while (!(a == "A" || a == "AB" || a == "B" || a == "O" || a == "O+" || a == "O-")) {

		cout << endl << "This field cannot be empty. Please enter one of the following blood types: A, AB, B, O, O+, OR O-: ";
		cin >> a;

	}

    bloodType = a;
}

void Patient::set_diagn(string a) {


	string d = a;
	transform(d.begin(), d.end(), d.begin(), ::tolower);

	while(a.empty() || ((d.find("critical") == string::npos) && (d.find("moderate") == string::npos) && (d.find("stable") == string::npos))){

		cout << endl << "This field cannot be empty. Please be sure to include the terms \"critical\",  \"moderate\" or \"stable\": ";
		getline(cin, a);

		d = a;
	    transform(d.begin(), d.end(), d.begin(), ::tolower);

    }

    diagn = a;
}

void Patient::set_admissionDate(string a) {

	bool numbers = true;

	while (true) {

		numbers = true;
		if (a.size() == 8){

			for (char c:a){

				if(!isdigit(c)){

					numbers = false;
				}
			}

			if(numbers){

				break;
			}
		}

		cout << endl << "Please enter the admission date of the patient in YYYYMMDD format: ";
		cin >> a;
	}

	admissionDate = a;
}

void Patient::set_dischargeDate(string a) {


	bool numbers = true;

	while (true) {

		if (a == "-1") {

			break;
		}

		numbers = true;
		if (a.size() == 8) {

			for (char c:a) {

				if(!isdigit(c)) {

					numbers = false;
				}
			}

			if(numbers){

				break;
			}
		}

		cout << endl << "Please enter the discharge date of the patient in YYYYMMDD format. If not yet discharged, please enter -1: ";
		cin >> a;
	}

    dischargeDate = a;

}

// Getters
string Patient::get_firstName() const{
    return firstName;
}

string Patient::get_lastName() const{
    return lastName;
}

long int Patient::get_id() const{
    return id;
}

long int Patient::get_doctor() const{
    return doctor;
}

string Patient::get_birthday() const{
    return birthday;
}

string Patient::get_bloodType() const{
    return bloodType;
}

string Patient::get_diagn() const{
    return diagn;
}

string Patient::get_admissionDate() const{
    return admissionDate;
}

string Patient::get_dischargeDate() const{
    return dischargeDate;
}

//Member Functions
bool Patient::IsDischarged() const{
    return dischargeDate != "-1";
}

string Patient::Patient_Status() const{

	string d = diagn;

	transform(d.begin(), d.end(), d.begin(), ::tolower);

    if (d.find("critical") != string::npos) {
        return "Critical";
    }

    if (d.find("moderate") != string::npos) {
        return "Moderate";
    }

    return "Stable";
}

void Patient::Print_Patient_Info() {
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "ID: " << id << "\t";
    cout << "Assigned Doctor: " << doctor << "\t";
    cout << "Date of Birth: " << birthday << "\t";
    cout << "Blood Type: " << bloodType << "\t";
    cout << "Diagnosis: " << diagn << "\t";
    cout << "Date of Admission: " << admissionDate << "\t";
    cout << "Discharge Date: " << dischargeDate;
}

