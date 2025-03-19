#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS 
#include "Allcanuse.h"
using namespace std;

class Medical
{
private:
	Date birth;
	int age;
	int gender;//0-not specified 1-male 2-woman 3-wtm 4-mtf 5-intersex 6-other
	double height;
	double weight;
	int bloodtype;//0=O-,1=O+,2=A-,3=A+,4=B-,5=B+,6=AB-,7=AB+
	int bloodpresuresistoic;
	int bloodpresurediasotic;
	int heartrate;//bpm
	int respiratoryrate;//bpm
	double oxygenlevel;//%
	double temperature;
	string emergencycontact;
	vector<string> doctor;
	vector<Date> visitdates;
	vector<string> visitreasons;
	vector<string> allergies;
	vector<string> medications;
	vector<string> medicationschedule;
	vector<string> prescriptions;
	vector<string> healthopserv;	
	vector<string> diagnoses;
	vector<string> treatments;
	vector<string> chronicconditions;
	vector<string> mentalhealth;
	vector<string> drugtest;
	vector<string> vaccines;
	vector<string> surgeries;
	vector<string> labresults;
	vector<string> imagingresults;
	vector<string> pastmedicalhistory;
	vector<string> familyhistory;
	vector<string> preferences;

public:
	Medical();
	~Medical();

	//set
	void setGender(int g);
	void setGenderS(string g);
	void setAge(int a);
	void setWeight(double w);
	void setHeight(double h);
	void setBloodType(int b);
	void setBloodTypeS(string b);
	void setBirth(Date b);

	void setBirth(int d, int m, int y);
	void setEmergencyContact(string e);
	void addAllergy(string a);
	void addHealthopserv(string h);
	void addDrugTest(string d);
	void addPastMedicalHistory(string p);
	void addChronicConditions(string c);
	void addMedications(string m);
	void addSurgeries(string s);
	void addFamilyHistory(string f);
	void addVisitDate(Date d);
	void addVisitReason(string r);
	void addVaccine(string v);
	void addDiagnosis(string d);
	void addTreatment(string t);
	void addPrescription(string p);
	void addDoctor(string d);
	void addLabResults(string l);
	void addImagingResults(string i);
	void setBloodPressuresistoic(int b);
	void setBloodPressurediatolic(int b);
	void setHeartRate(int h);
	void setTemperature(double t);
	void setRespiratoryRate(int r);
	void setOxygenLevel(double o);
	void addMedicationSchedule(string m);
	void addMentalHealth(string m);
	void addPreference(string p);
	//get
	int getGender();
	string getGenderS();
	int getAge();
	double getWeight();
	double getHeight();
	int getBloodType();
	string getBloodTypeS();
	Date getBirth();
	void getBirth(int &d,int &m,int &y);
	string getEmergencyContact();
	vector<string> getAllergy();
	vector<string> getHealthopserv();
	vector<string> getDrugTest();
	vector<string> getPastMedicalHistory();
	vector<string> getChronicConditions();
	vector<string> getMedications();
	vector<string> getSurgeries();
	vector<string> getFamilyHistory();
	vector<Date> getVisitDate();
	vector<string> getVisitReason();
	vector<string> getVaccine();
	vector<string> getDiagnosis();
	vector<string> getTreatment();
	vector<string> getPrescription();
	vector<string> getDoctor();
	vector<string> getLabResults();
	vector<string> getImagingResults();
	int getBloodPressureSistoic();
	int getBloodPressureDiasotic();
	int getHeartRate();
	double getTemperature();
	int getRespiratoryRate();
	double getOxygenLevel();
	vector<string> getMedicationSchedule();
	vector<string> getMentalHealth();
	vector<string> getPreference();

	void printHealth();
	void printHealthNV();
	void displayImages();
	int displayInformations();
	void displayMedicalfiltered(vector<bool>&ff);
	bool matching(Medical e);
	void editMedical();
};
