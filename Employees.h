#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Medical.h"
#define CLRLN 8//clearance levels
using namespace std;


class Employee
{
private:
	//basic
	int id;
	string name;
	string position;
	//positions
	bool clearance[CLRLN];//0 - personal info 1-medical infos 2-contacting 3-employment infos 4-performance infos 5-security 6-all infos 7-admin
	//job relatd
	string department;
	string supervisor;
	int employmnttype;//unemployd=0 fulltime=1 parttime=2 intern=3 contractor=4 consultant=5 temporary=6 volunteer=7 seasonal=8 retired=9
	double salary;
	double salaryperhour;
	double hours;
	double overtime;
	double bonus;
	Date hiredate;//day month year
	int vacationdays;
	vector<string> benefits;//health dental vision life disability retirement
	double payment;//---->calculatepayment
	//skills
	vector<string> skills;
	vector<string> trainings;
	vector<string> certifications;
	vector<string> projects;
	vector<string> publications;
	vector<string> memberships;
	vector<string> awards;
	//performance reviews
	vector<pair<int, string>> performancereviews;//by who and what
	//security
	vector<string> references;
	vector<string> backgroundcheck;
	string code;
	//medical
	Medical health;
	//nice to know
	string nickname;
	int maritalstatus;//0-single 1-dating 2-married 3-divorced 4-widowed 5-other
	int kids;
	string nationality;
	vector<string> languages;
	vector<string> education;
	vector<string> preferences;
	//contacting
	string phone;
	string email;
	string address;//street city country
	//photos
	vector<string> photos;

	void sinceatcompany(int&d,int&m,int&y);//calculate how long the employee is at the company
	double calculatepayment();//calculate the payment of the employee
	//display filtered
	void displaymedicalFiltered(vector<bool>&ff);
	void displayemploymentFiltered(vector<bool>&ff);
	void displayskillsFiltered(vector<bool>&ff);
	void displaycontactFiltered(vector<bool>&ff);
	void displaypersonalFiltered(vector<bool>&ff);
	void displaysecurityFiltered(vector<bool>&ff);
	void displayallFiltered(vector<bool>&ff);

	bool medicalmatching(Employee e);//check if the medical infos match
	bool employmentmatching(Employee e);//check if the employment infos match
	bool skillsmatching(Employee e);//check if the skills match
	bool personalmatching(Employee e);//check if the personal infos match
	bool securitymatching(Employee e);//check if the security infos match
	
	bool allmatching(Employee e);//check if all infos match

public:
	Employee();
	Employee(int id);//basic id
	Employee(int id, string n, string p, double s);//basic id name position salary
	Employee(int id, string n, string p, double sh, double h);//basic id name position salaryperhour hours
	~Employee();

	//display
	void displaywhat(int show);
	void displaywhatFilters(int show,vector<bool>&ff);

	void displaybasic();
	void displaypreferences();
	void displayemployment();
	int displayemploymentN();
	int displayemploymentNV();
	void displaymedical();
	void displaymedicalN();
	void displayperformance();
	void displayskills();
	int displayskillsN();
	int displayskillsNV();
	void displaysecurity();
	int displaysecurityN();
	int displaysecurityNV();
	void displaynice();
	void displaycontact();
	int displaycontactN();
	void display0();//clearance = 0 has access to own info (excluding some security)
	void displayall();
	int displayallN();
	void displayphotos();

	//edit
	void editpassword();
	void editpersonal();
	void editmedical();
	void editemployment();
	void editcontact();
	void editskills();
	void editsecurity();//+clearance
	void editall();

	//get
	int getId();
	string getCode();
	int getClearanceH();
	void getClearance(vector<bool>&cl);
	string getName();
	string getNickname();
	string getPosition();
	double getSalary();
	double getSalaryperhour();
	double getHours();
	double getOvertime();
	double getBonus();
	string getAddress();
	string getPhone();
	string getEmail();
	string getDepartment();
	string getSupervisor();
	Date getHiredate();
	int getMaritalstatus();
	string getMaritalstatusS();
	int getKids();
	int getVacationdays();
	string getNationality();
	vector<string> getLanguages();
	vector<string> getEducation();
	int getEmploymnttype();
	string getEmploymnttypeS();
	vector<string> getBenefits();
	vector<pair<int, string>> getPerformancereviews();
	vector<string> getTrainings();
	vector<string> getCertifications();
	vector<string> getProjects();
	vector<string> getPublications();
	vector<string> getMemberships();
	vector<string> getAwards();
	vector<string> getSkills();
	vector<string> getBackgroundcheck();
	vector<string> getReferences();
	Medical getHealth();
	vector<string> getPreferences();
	vector<string> getPhotos();
	double getPayment();
	//set
	void setId(int i);
	void setCode(string c);
	void setClearance(int c,bool ok);
	void setName(string n);
	void setNickname(string n);
	void setPosition(string p);
	void setSalary(double s);
	void setSalaryperhour(double s);
	void setHours(double h);
	void setOvertime(double o);
	void setBonus(double b);
	void setAddress(string a);
	void setPhone(string p);
	void setEmail(string e);
	void setDepartment(string d);
	void setSupervisor(string s);
	void setHiredate(Date h);
	void setMaritalstatus(int m);
	void setMaritalstatusS(string m);
	void setKids(int k);
	void setVacationdays(int v);
	void setNationality(string n);
	void addLanguage(string l);
	void addEducation(string e);
	void setEmploymnttype(int e);
	void setEmploymnttypeS(string e);
	void addBenefit(string b);
	void addPerformancereview(int p, string r);
	void addTraining(string t);
	void addCertification(string c);
	void addProject(string p);
	void addPublication(string p);
	void addMembership(string m);
	void addAward(string a);
	void addSkill(string s);
	void addBackgroundcheck(string b);
	void addReference(string r);
	void setHealth(Medical h);
	void addPreference(string p);
	void addPhoto(string p);
	void setPayment(double p);

	//functions
	bool matching(int show,const Employee&e);
	void printclearance();



	//operators
	bool operator<(Employee e);
	bool operator>(Employee e);
	bool operator==(Employee e);
	bool operator<=(Employee e);
	bool operator>=(Employee e);
	bool operator!=(Employee e);

	friend ostream& operator<<(ostream& os, const Employee& e);

};