//============================================================================
// Names       : -
// Assignment  : 4
// File        : Patient.h
//============================================================================

#ifndef PATIENT_H_
#define PATIENT_H_

#include <iostream>
using namespace std;

class Patient {
public:

    // Constructors
	Patient();
	Patient(string, string, long int, long int, string, string, string, string, string);

	// Setters
    void set_firstName(string a);
    void set_lastName(string a);
    void set_id(long int a);
    void set_doctor(long int a);
    void set_birthday(string a);
    void set_bloodType(string a);
    void set_diagn(string a);
    void set_admissionDate(string a);
    void set_dischargeDate(string a);

    // Getters
    string get_firstName() const;
    string get_lastName() const;
    long int get_id() const;
    long int get_doctor() const;
    string get_birthday() const;
    string get_bloodType() const;
    string get_diagn() const;
    string get_admissionDate() const;
    string get_dischargeDate() const;

    // Member functions
    bool IsDischarged() const;
    string Patient_Status() const;
    void Print_Patient_Info();

private:
    // Attributes
    string firstName;
    string lastName;
    long int id;
    long int doctor;
    string birthday;
    string bloodType;
    string diagn;
    string admissionDate;
    string dischargeDate;
};


#endif /* PATIENT_H_ */
