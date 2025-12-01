//============================================================================
// Names       : -
// Assignment  : 4
// File        : Doctor.cpp
//============================================================================


#include "Doctor.h"
#include <iostream>
#include <limits>
using namespace std;

// Constructors
Doctor::Doctor(){

	 firstName = " ";
	 lastName = " ";
	 id = 0;
	 specialty = " ";
	 yearsExperience = 0;
	 baseSalary = 0;
	 performanceBonus = 0;

}

Doctor::Doctor(string first_name, string last_name, long int ID, string specialization, int experience, long double salary, long double bonus) {

	firstName = first_name;
	 lastName = last_name;
	 id = ID;
	 specialty = specialization;
	 yearsExperience = experience;
	 baseSalary = salary;
	 performanceBonus = bonus;

}

// Setters
void Doctor::set_firstName(string a) {

	while (a.empty()) {

		cout << endl << "This field cannot be empty. Please enter the doctor's first name: ";
	    cin >> a;
	}

    firstName = a;
}

void Doctor::set_lastName(string a) {

	while (a.empty()) {

		cout << endl << "This field cannot be empty. Please enter the doctor's last name: ";
	    cin >> a;
	}

    lastName = a;
}

void Doctor::set_id(long int a) {

    string input;

    while (true) {
    	input = to_string(a);

        bool number = !input.empty();
        for (char c : input) {
            if (!isdigit(c)) {
                number = false;
                break;
            }
        }

        if (number && input.size() == 8 && input != "0") {
            id = a;
            return;
        }

        cout << endl << "Invalid ID. Please enter a positive 8-digit integer: ";
        if(!(cin >> input)){
                	cin.clear();
                	cin.ignore(numeric_limits<streamsize>::max(), '\n');
                	a = -1;
                	continue;
                }

        try {
            a = stol(input);
        } catch (...) {
            a = -1;
        }

    }

}

void Doctor::set_specialty(string a) {

	while (a.empty()) {

		cout << endl << "This field cannot be empty. Please enter the doctor's specialty: ";
	    cin >> a;
	}

    specialty = a;
}

void Doctor::set_yearsExperience(int a) {

	while (a < 0){

		cout << endl << "Years of experience cannot be negative. Please try again: ";
		cin >> a;
	}

    yearsExperience = a;
}

void Doctor::set_baseSalary(long double a) {

	while (a < 0){

		cout << endl << "Salary cannot be negative. Please try again: ";
		cin >> a;
	}

    baseSalary = a;
}

void Doctor::set_performanceBonus(long double a) {

	while (a < 0 || a > 1){

		cout << endl << "Bonus cannot be negative or greater than 1. Please try again: ";
		cin >> a;
	}

    performanceBonus = a;
}

// Getters
string Doctor::get_firstName() const{
    return firstName;
}

string Doctor::get_lastName() const{
    return lastName;
}

long int Doctor::get_id() const{
    return id;
}

string Doctor::get_specialty() const{
    return specialty;
}

int Doctor::get_yearsExperience() const{
    return yearsExperience;
}

long double Doctor::get_baseSalary() const{
    return baseSalary;
}

long double Doctor::get_performanceBonus() const{
    return performanceBonus;
}

// Member Functions
long double Doctor::Calculate_Compensation() const{
    return (performanceBonus + 1) * baseSalary;
}

void Doctor::Print_Doctor_Info() {
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "ID: " << id << "\t";
    cout << "Specialty: " << specialty << "\t";
    cout << "Years of Experience: " << yearsExperience << "\t";
    cout << "Base Salary: " << baseSalary << "$" << "\t";
    cout << "Performance Bonus: " << performanceBonus * 100 << "%" << "\t";
}


