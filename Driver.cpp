//============================================================================
// Names       : -
// Assignment  : 4
// File        : Driver.cpp
//============================================================================

#include "Doctor.h"
#include "Patient.h"
#include "Hospital.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){

	Hospital hospital;

	cout << endl << "============================================================================";
	cout << endl << "TESTING APPENDING PATIENTS TO THEIR FILE";
	cout << endl << "============================================================================" << endl;

	hospital.Append_Patient_To_File();

	cout << endl << "============================================================================";
	cout << endl << "TESTING APPENDING DOCTORS TO THEIR FILE";
	cout << endl << "============================================================================" << endl;

	hospital.Append_Doctor_To_File();

	cout << endl << "============================================================================";
	cout << endl << "TESTING ALL MEMBER FUNCTIONS IN HOSPITAL CLASS";
	cout << endl << "============================================================================" << endl;

	string specialty;
	long int patient_ID;
	long int doctor_ID;

	hospital.Find_Oldest_Patient();

	cout << endl << hospital.Count_Critical_Patients();

	cout << endl << hospital.Count_In_Patients();

	cout << endl << "Input the specialty of a doctor to receive a list of all doctors with that specialty: ";
	cin >> specialty;
	cout << "\n";
	hospital.Doctors_By_Specialty(specialty);

	cout << endl << "Input a patient ID to find a patient: ";
	cin >> patient_ID;
	cout << "\n";
	hospital.Show_Patient_by_ID(patient_ID);

	cout << endl << "Input a doctor ID to find a doctor: ";
	cin >> doctor_ID;
	cout << "\n";
	hospital.Show_Doctor_by_ID(doctor_ID);

	cout << endl << "Input a patient ID to view their assigned doctor: ";
	cin >> patient_ID;
	cout << "\n";
	hospital.Show_Assigned_Doctor(patient_ID);

	cout << endl << "Input a doctor ID to view their assigned patients: ";
	cin >> doctor_ID;
	cout << "\n";
	hospital.Show_Assigned_Patients(doctor_ID);

	cout << endl << "============================================================================";
	cout << endl << "TESTING ALL MEMBER FUNCTIONS IN PATIENT CLASS";
	cout << endl <<  "============================================================================" << endl;

	Patient patient;


    // Test setters
    patient.set_firstName("John");
    patient.set_lastName("Doe");
    patient.set_id(11122111);
    patient.set_doctor(87654321);
    patient.set_birthday("19901212");
    patient.set_bloodType("A+");
    patient.set_diagn("Critical injury in leg.");
    patient.set_admissionDate("20240101");
    patient.set_dischargeDate("-1");

    // Test getters
    cout << "First Name: " << patient.get_firstName() << endl;
    cout << "Last Name: " << patient.get_lastName() << endl;
    cout << "ID: " << patient.get_id() << endl;
    cout << "Assigned Doctor: " << patient.get_doctor() << endl;
    cout << "Birthday: " << patient.get_birthday() << endl;
    cout << "Blood Type: " << patient.get_bloodType() << endl;
    cout << "Diagnosis: " << patient.get_diagn() << endl;
    cout << "Admission Date: " << patient.get_admissionDate() << endl;
    cout << "Discharge Date: " << patient.get_dischargeDate() << endl;


    cout << "Is Discharged? " << patient.IsDischarged() << endl;

    cout << "Patient Status: " << patient.Patient_Status() << "\n\n";

    patient.Print_Patient_Info();


	cout << endl << "============================================================================";
	cout << endl << "TESTING ALL MEMBER FUNCTIONS IN DOCTOR CLASS";
	cout << endl << "============================================================================";

	Doctor doctor;

    // Test setters
    doctor.set_firstName("Sarah");
    doctor.set_lastName("Lee");
    doctor.set_id(87654321);
    doctor.set_specialty("Cardiology");
    doctor.set_yearsExperience(15);
    doctor.set_baseSalary(120000);
    doctor.set_performanceBonus(0.10);

    // Test getters
    cout << "First Name: " << doctor.get_firstName() << endl;
    cout << "Last Name: " << doctor.get_lastName() << endl;
    cout << "ID: " << doctor.get_id() << endl;
    cout << "Specialty: " << doctor.get_specialty() << endl;
    cout << "Experience: " << doctor.get_yearsExperience() << endl;
    cout << "Base Salary: " << doctor.get_baseSalary() << endl;
    cout << "Bonus: " << doctor.get_performanceBonus() << endl;

    cout << "Total Compensation: " << doctor.Calculate_Compensation() << "\n\n";

    doctor.Print_Doctor_Info();

	return 0;
}





