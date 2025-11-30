//============================================================================
// Names       : -
// Assignment  : 4
// File        : Doctor.h
//============================================================================

#ifndef DOCTOR_H_
#define DOCTOR_H_

#include <iostream>
using namespace std;

class Doctor {

public:

    // Constructors
	Doctor();
	Doctor(string, string, long int, string, int, long double, long double);

	// Setters
    void set_firstName(string a);
    void set_lastName(string a);
    void set_id(long int a);
    void set_specialty(string a);
    void set_yearsExperience(int a);
    void set_baseSalary(long double a);
    void set_performanceBonus(long double a);

    // Getters
    string get_firstName() const;
    string get_lastName() const;
    long int get_id() const;
    string get_specialty() const;
    int get_yearsExperience() const;
    long double get_baseSalary() const;
    long double get_performanceBonus() const;

    // Member functions
    long double Calculate_Compensation() const;
    void Print_Doctor_Info();

private:
    // Attributes
    string firstName;
    string lastName;
    long int id;
    string specialty;
    int yearsExperience;
    long double baseSalary;
    long double performanceBonus;
};

#endif /* DOCTOR_H_ */
