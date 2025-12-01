//============================================================================
// Names       : -
// Assignment  : 4
// File        : Hospital.cpp
//============================================================================

#include "Doctor.h"
#include "Patient.h"
#include "Hospital.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Constructor
Hospital::Hospital(){

    ptrPatients = new vector<Patient>;
    ptrDoctors = new vector<Doctor>;

    ifstream patientFile("Patients.txt");
    if (!patientFile.is_open()) {
        ofstream create("Patients.txt");
        create << 0 << endl;
        create.close();
        patientFile.open("Patients.txt");
    }

    int numberOfPatients;
    patientFile >> numberOfPatients;

    for (int i = 1; i <= numberOfPatients ; i++) {
        string firstName;
        string lastName;
        long int id;
        long int doctor;
        string birthday;
        string bloodType;
        string diagn;
        string admissionDate;
        string dischargeDate;

        patientFile >> firstName >> lastName >> id >> doctor >> birthday >> bloodType;

        patientFile >> ws;
        getline(patientFile, diagn);

        patientFile >> admissionDate >> dischargeDate;

        Patient patient;
        patient.set_firstName(firstName);
        patient.set_lastName(lastName);
        patient.set_id(id);
        patient.set_doctor(doctor);
        patient.set_birthday(birthday);
        patient.set_bloodType(bloodType);
        patient.set_diagn(diagn);
        patient.set_admissionDate(admissionDate);
        patient.set_dischargeDate(dischargeDate);

        ptrPatients->push_back(patient);
    }

    patientFile.close();


    ifstream doctorFile("Doctors.txt");
    if (!doctorFile.is_open()) {
        ofstream create("Doctors.txt");
        create << 0 << endl;
        create.close();
        doctorFile.open("Doctors.txt");
    }

    int numberOfDoctors;
    doctorFile >> numberOfDoctors;


    for (int i = 0; i < numberOfDoctors; i++) {
        string firstName;
        string lastName;
        long int id;
        string specialty;
        int yearsExperience;
        long double baseSalary;
        long double performanceBonus;

        doctorFile >> firstName >> lastName >> id >> specialty >> yearsExperience >> baseSalary >> performanceBonus;
        Doctor doctor;
        doctor.set_firstName(firstName);
        doctor.set_lastName(lastName);
        doctor.set_id(id);
        doctor.set_specialty(specialty);
        doctor.set_yearsExperience(yearsExperience);
        doctor.set_baseSalary(baseSalary);
        doctor.set_performanceBonus(performanceBonus);

        ptrDoctors->push_back(doctor);
    }

    doctorFile.close();

}

// Destructor
Hospital::~Hospital(){

	delete ptrPatients;
	delete ptrDoctors;

}

// Member Functions

void Hospital::Find_Oldest_Patient() const{
	if (ptrPatients->empty()){

		cout << "No patients available.";
		return;
	}

	int oldest_patient = 0;

	for (size_t i= 1; i < ptrPatients->size(); i ++) {
		if(stoi((*ptrPatients)[i].get_birthday()) < stoi((*ptrPatients)[oldest_patient].get_birthday()) ) {

			oldest_patient = i;

		}
	}

	(*ptrPatients)[oldest_patient].Print_Patient_Info();
}

int Hospital::Count_Critical_Patients() const{

	if (ptrPatients->empty()){

			cout << "No patients available.";
	}

    int counter = 0;
    for (size_t i = 0; i < ptrPatients->size(); i++) {
        if ((*ptrPatients)[i].Patient_Status() == "Critical") {
            counter += 1;
        }
    }

    return counter;

}


int Hospital::Count_In_Patients() const{
	if (ptrPatients->empty()){

			cout << "No patients available.";
		}

	int counter = 0;
	for (size_t i = 0; i < ptrPatients->size(); i++) {
	        if (!(*ptrPatients)[i].IsDischarged())

	        	counter++;
	    }

    return counter;
}


void Hospital::Doctors_By_Specialty(string specialty) {
	if (ptrDoctors->empty()){

			cout << "No doctors available.";
			return;
		}
    for (size_t i = 0; i < ptrDoctors->size(); i++) {
        if ((*ptrDoctors)[i].get_specialty() == specialty) {
            cout << (*ptrDoctors)[i].get_firstName() << " " << (*ptrDoctors)[i].get_lastName() << endl;
        }
    }

}


void Hospital::Show_Patient_by_ID(long int patientID) {

    string input;

    while (true) {

    	input = to_string(patientID);

        bool number = true;
        for (char c : input) {
            if (!isdigit(c)) {
                number = false;
                break;
            }
        }

        if (number && input.size() == 8 && patientID != 0) {

            for (size_t i = 0; i < ptrPatients->size(); i++) {
                if ((*ptrPatients)[i].get_id() == patientID) {
                    (*ptrPatients)[i].Print_Patient_Info();
                    return;
                }
            }

            cout << "No patient has the provided ID.";
            return;
        }

        cout << endl << "Invalid ID. Please enter a positive 8-digit integer: ";
        if(!(cin >> input)){
                	cin.clear();
                	cin.ignore(numeric_limits<streamsize>::max(), '\n');
                	patientID = -1;
                	continue;
                }

        try {
            patientID = stol(input);
        } catch (...) {
            patientID = -1;
        }
    }
}


void Hospital::Show_Doctor_by_ID(long int doctorID) {

    string input;

    while (true) {

    	input = to_string(doctorID);

        bool number = true;
        for (char c : input) {
            if (!isdigit(c)) {
                number = false;
                break;
            }
        }

        if (number && input.size() == 8 && doctorID != 0) {

            for (size_t i = 0; i < ptrDoctors->size(); i++) {
                if ((*ptrDoctors)[i].get_id() == doctorID) {
                    (*ptrDoctors)[i].Print_Doctor_Info();
                    return;
                }
            }

            cout << "No doctor has the provided ID.";
            return;
        }

        cout << endl << "Invalid ID. Please enter a positive 8-digit integer: ";
        if(!(cin >> input)){
                	cin.clear();
                	cin.ignore(numeric_limits<streamsize>::max(), '\n');
                	doctorID = -1;
                	continue;
                }

        try {
            doctorID = stol(input);
        } catch (...) {
            doctorID = -1;
        }
    }
}

void Hospital::Show_Assigned_Doctor(long int patientID) {

    string input;

    while (true) {

    	input = to_string(patientID);

        bool number = true;
        for (char c : input) {
            if (!isdigit(c)) {
                number = false;
                break;
            }
        }

        if (number && input.size() == 8 && patientID != 0) {

            for (size_t i = 0; i < ptrPatients->size(); i++) {

                if ((*ptrPatients)[i].get_id() == patientID) {

                    long int doctorID = (*ptrPatients)[i].get_doctor();
                    if (doctorID == -1) {
                        cout << "No doctor assigned.";
                        return;
                    }

                    for (size_t j = 0; j < ptrDoctors->size(); j++) {
                        if ((*ptrDoctors)[j].get_id() == doctorID) {
                            cout << (*ptrDoctors)[j].get_firstName() << " "
                                 << (*ptrDoctors)[j].get_lastName();
                            return;
                        }
                    }

                    cout << "No doctor associated to this ID.";
                    return;
                }
            }

            cout << "No patient associated to this ID.";
            return;
        }

        cout << endl << "Invalid ID. Please enter a positive 8-digit integer: ";
        if(!(cin >> input)){
                	cin.clear();
                	cin.ignore(numeric_limits<streamsize>::max(), '\n');
                	patientID = -1;
                	continue;
                }

        try {
            patientID = stol(input);
        } catch (...) {
            patientID = -1;
        }
    }
}


void Hospital::Show_Assigned_Patients(long int doctorID) {

    string input;

    while (true) {

    	input = to_string(doctorID);

        bool number = true;
        for (char c : input) {
            if (!isdigit(c)) {
                number = false;
                break;
            }
        }

        if (number && input.size() == 8 && doctorID != 0) {

            bool found = false;

            for (size_t i = 0; i < ptrPatients->size(); i++) {
                if ((*ptrPatients)[i].get_doctor() == doctorID) {
                    cout << (*ptrPatients)[i].get_firstName() << " "
                         << (*ptrPatients)[i].get_lastName() << endl;
                    found = true;
                }
            }

            if (!found)
                cout << "No patients assigned.";

            return;
        }

        cout << endl << "Invalid ID. Please enter a positive 8-digit integer: ";
        if(!(cin >> input)){
                	cin.clear();
                	cin.ignore(numeric_limits<streamsize>::max(), '\n');
                	doctorID = -1;
                	continue;
                }

        try {

            doctorID = stol(input);

        } catch (...) {

            doctorID = -1;
        }
    }
}


void Hospital::Append_Patient_To_File() {

	Patient patient;

    string firstName;
    string lastName;
    long int id;
    long int doctor;
    string birthday;
    string bloodType;
    string diagn;
    string admissionDate;
    string dischargeDate;

    cout << "First Name of patient: ";
    cin >> firstName;
    patient.set_firstName(firstName);

    cout << endl << "Last Name of patient: ";
    cin >> lastName;
    patient.set_lastName(lastName);

    cout << endl << "ID of patient: ";
    cin >> id;
    patient.set_id(id);

    cout << endl << "Assigned Doctor of patient. Enter -1 if no doctor is assigned yet: ";
    cin >> doctor;
    patient.set_doctor(doctor);

    cout << endl << "Date of Birth of patient in YYYYMMDD format: ";
    cin >> birthday;
    patient.set_birthday(birthday);

    cout << endl << "Blood Type of patient: ";
    cin >> bloodType;
    patient.set_bloodType(bloodType);

    cout << endl << "Diagnosis of patient: ";
    cin.ignore();
    getline(cin,diagn);
    patient.set_diagn(diagn);

    cout << endl << "Date of Admission of patient in YYYYMMDD format: ";
    cin >> admissionDate;
    patient.set_admissionDate(admissionDate);

    cout << endl << "Discharge Date of patient in YYYYMMDD format. Enter -1 if the patient is not yet discharged: ";
    cin >> dischargeDate;
    patient.set_dischargeDate(dischargeDate);

    ptrPatients->push_back(patient);

    ofstream patientFile ("Patients.txt", ios::trunc);
    patientFile << ptrPatients->size() << endl;

    for (size_t i = 0; i < ptrPatients->size(); i++){

    	Patient &p = (*ptrPatients)[i];

    	patientFile << "\n" << p.get_firstName() << "\t"
    		        << p.get_lastName() << "\t" << p.get_id()
				    << "\t" << p.get_doctor() << "\t" << p.get_birthday()
				    << "\t" << p.get_bloodType() << "\t"
				    << p.get_diagn() << "\t" << p.get_admissionDate()
				    << "\t" << p.get_dischargeDate() << endl;
    }

patientFile.close();

}


void Hospital::Append_Doctor_To_File() {

	Doctor doctor;

	string firstName;
	string lastName;
	long int id;
	string specialty;
	int yearsExperience;
	long double baseSalary;
	long double performanceBonus;

	cout << "First Name: ";
	cin >> firstName;
	doctor.set_firstName(firstName);

	cout << endl << "Last Name: ";
	cin >> lastName;
	doctor.set_lastName(lastName);

	cout << endl << "ID: ";
	cin >> id;
	doctor.set_id(id);

	cout << endl << "Specialty: ";
	cin >> specialty;
	doctor.set_specialty(specialty);

	cout << endl << "Years of Experience: ";
	cin >> yearsExperience;
	doctor.set_yearsExperience(yearsExperience);

	cout << endl << "Base Salary: ";
	cin >> baseSalary;
	doctor.set_baseSalary(baseSalary);

	cout << endl << "Performance Bonus: ";
	cin >> performanceBonus;
	doctor.set_performanceBonus(performanceBonus);

    ptrDoctors->push_back(doctor);

    ofstream doctorFile ("Doctors.txt", ios::trunc);

    doctorFile << ptrDoctors->size() << endl;

    for (size_t i = 0; i < ptrDoctors->size(); i++){

    	Doctor &d = (*ptrDoctors)[i];

    	doctorFile << "\n" << d.get_firstName() << "\t"
    		        << d.get_lastName() << "\t" << d.get_id()
				    << "\t" << d.get_specialty() << "\t" << d.get_yearsExperience()
				    << "\t" << d.get_baseSalary() << "\t"
				    << d.get_performanceBonus() << endl;
    }

doctorFile.close();

}

