#include "Employees.h"

Employee::Employee()
{
	id = -1;
	for (int i = 0; i < CLRLN; i++)
	{
		clearance[i] = false;
	}
	name = "";
	nickname = "";
	position = "";
	salary = -1;
	salaryperhour = -1;
	hours = -1;
	overtime =-1;
	bonus = -1;
	address = "";
	phone = "";
	email = "";
	department = "";
	supervisor = "";
	hiredate = Date();
	maritalstatus = -1;
	kids = -1;
	vacationdays = -1;
	nationality = "";
	employmnttype = -1;
	health = Medical();
	payment = -1;
}

Employee::Employee(int id)
{
	this->id = id;
	for (int i = 1; i < CLRLN; i++)
	{
		clearance[i] = false;
	}
	clearance[0] = true;
	name = "";
	nickname = "";
	position = "";
	salary = -1;
	salaryperhour = -1;
	hours = -1;
	overtime = -1;
	bonus = -1;
	address = "";
	phone = "";
	email = "";
	department = "";
	supervisor = "";
	hiredate = Date();
	maritalstatus = -1;
	kids = -1;
	vacationdays = -1;
	nationality = "";
	employmnttype = -1;
	health = Medical();

	payment = -1;
}

Employee::Employee(int i,string n, string p, double s)//basic id name position salary
{
	id = i;
	name = n;
	position = p;
	salary = s;
	for (int i = 1; i < CLRLN; i++)
	{
		clearance[i] = false;
	}
	clearance[0] = true;
	nickname = "";
	salaryperhour = -1;
	hours = -1;
	overtime = -1;
	bonus = -1;
	address = "";
	phone = "";
	email = "";
	department = "";
	supervisor = "";
	hiredate = Date();
	maritalstatus = -1;
	kids = -1;
	vacationdays = -1;
	nationality = "";
	employmnttype = -1;
	health = Medical();

	payment = -1;
}

Employee::Employee(int i, string n, string p, double sh, double h)//basic id name position salaryperhour hours
{
	id = i;
	name = n;
	position = p;
	salaryperhour = sh;
	hours = h;
	for (int i = 1; i < CLRLN; i++)
	{
		clearance[i] = false;
	}
	clearance[0] = true;
	nickname = "";
	salary = -1;
	overtime =-1;
	bonus = -1;
	address = "";
	phone = "";
	email = "";
	department = "";
	supervisor = "";
	hiredate = Date();
	maritalstatus = -1;
	kids = -1;
	vacationdays = -1;
	nationality = "";
	employmnttype = -1;
	health = Medical();
	payment = -1;
}

Employee::~Employee()
{
}

// ---- display ----

void Employee::displaywhat(int show)
{

	switch (show)
	{
	case 0:
		display0();
		break;
	case 1:
		displaybasic();
		break;
	case 2:
		displaypreferences();
		break;
	case 3:
		cout<<"ID: "<<id<<endl;
		displayemployment();
		break;
	case 4:
		cout << "ID: " << id << endl;
		displaymedical();
		break;
	case 5:
		cout << "ID: " << id << endl;
		displayskills();
		displayperformance();
		break;
	case 6:
		cout << "ID: " << id << endl;
		displaysecurity();
		break;
	case 7:
		cout << "ID: " << id << endl;
		displaynice();
		break;
	case 8:
		cout << "ID: " << id << endl;
		displaycontact();
		break;
	case 9:
		displayphotos();
		break;
	case 10:
		displayall();
		break;
	default:
		cout << "No such option." << endl;
		break;
	}
}

void Employee::displaywhatFilters(int show, vector<bool>&ff)
{
	switch (show)
	{
		case 1:
			cout << "ID: " << id << endl;
			displaymedicalFiltered(ff);
		break;
		case 2:
			cout << "ID: " << id << endl;
			displayemploymentFiltered(ff);
			break;
		case 3:
			cout << "ID: " << id << endl;
			displayskillsFiltered(ff);
			break;
		case 4:
			cout << "ID: " << id << endl;
			displaycontactFiltered(ff);
			break;
		case 5:
			displaypersonalFiltered(ff);
			break;
		case 6:
			cout << "ID: " << id << endl;
			displaysecurityFiltered(ff);
			break;
		case 7:
			displayallFiltered(ff);
			break;
	default:
		break;
	}
}


void Employee::displaybasic()
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Position: " << position << endl;
}

void Employee::displaypreferences()
{
	cout << "Preferences: ";
	displaywithtab(preferences);
	cout << endl;
}

void Employee::displaycontact()
{
	cout << "Phone: " << phone << endl;
	cout<<"Email: "<<email<<endl;
	cout << "Address: " << address << endl;
}

int Employee::displaycontactN()
{
	cout << "1. Phone" << endl;
	cout << "2. Email" << endl;
	cout << "3. Address" << endl;
	return 3;
}

void Employee::displayemployment()
{
	cout << "Position: " << position << endl;
	cout << "Department: " << department << endl;
	cout << "Supervisor: " << supervisor << endl;
	cout << "Employment type: " << employmnttype << endl;
	if (salary != -1)
	{
		cout << "Salary: " << salary << endl;
	}
	if(salaryperhour != -1)
	{
		cout << "Salary per hour: " << salaryperhour << endl;
	}
	if (hours != -1)
	{
		cout << "Hours worked: " << hours << endl;
	}
	cout << "Overtime: " << overtime << endl;
	cout << "Bonus: " << bonus << endl;
	cout << "Vacation days: " << vacationdays << endl;
	cout << "Hire date: ";
	hiredate.printDate();
	cout << endl;
	cout << "Benefits: ";
	displaywithtab(benefits);
	if (payment != -1)
	{
		cout<<"Payment for the month: "<<payment<<endl;
	}
}

int Employee::displayemploymentN()
{
	cout << "1. Position"<< endl;
	cout << "2. Department" << endl;
	cout << "3. Supervisor" << endl;
	cout << "4. Employment type"<< endl;
	cout << "5. Salary" << endl;
	cout << "6. Salary per hour" << endl;
	cout << "7. Hours worked"  << endl;
	cout << "8. Overtime" << endl;
	cout << "9. Bonus" << endl;
	cout << "10. Vacation days"  << endl;
	cout << "11. Hire date";
	cout << "12. Benefits";
	cout << "13. Payment for the month"<< endl;
	return 13;
}

int Employee::displayemploymentNV()
{
	cout << "1. Position: " << position << endl;
	cout << "2. Department: " << department << endl;
	cout << "3. Supervisor: " << supervisor << endl;
	cout << "4. Employment type: " << employmnttype << endl;
	cout << "5. Salary: " << salary << endl;
	cout << "6. Salary per hour: " << salaryperhour << endl;
	cout << "7. Hours worked: " << hours << endl;
	cout << "8. Overtime: " << overtime << endl;
	cout << "9. Bonus: " << bonus << endl;
	cout << "10. Vacation days: " << vacationdays << endl;
	cout << "11. Hire date: ";
	hiredate.printDate();
	cout << endl;
	cout << "12. Benefits: ";
	displaywithtab(benefits);
	cout<<"13. Payment for the month: "<<payment<<endl;
	return 13;
}

void Employee::displayskills()
{
	cout << "Skills: ";
	displaywithtab(skills);
	cout << "Trainings: ";
	displaywithtab(trainings);
	cout << "Certifications: ";
	displaywithtab(certifications);
	cout << "Projects: ";
	displaywithtab(projects);
	cout << "Publications: ";
	displaywithtab(publications);
	cout << "Memberships: ";
	displaywithtab(memberships);
	cout << "Awards: ";
	displaywithtab(awards);
}

int Employee::displayskillsN()
{
	cout << "1. Skills";
	cout << "2. Trainings: ";
	cout << "3. Certifications: ";
	cout << "4. Projects: ";
	cout << "5. Publications: ";
	cout << "6. Memberships: ";
	cout << "7. Awards: ";
	return 7;
}

int Employee::displayskillsNV()
{
	cout << "1. Skills: ";
	displaywithtab(skills);
	cout << "2. Trainings: ";
	displaywithtab(trainings);
	cout << "3. Certifications: ";
	displaywithtab(certifications);
	cout << "4. Projects: ";
	displaywithtab(projects);
	cout << "5. Publications: ";
	displaywithtab(publications);
	cout << "6. Memberships: ";
	displaywithtab(memberships);
	cout << "7. Awards: ";
	displaywithtab(awards);
	return 7;
}

void Employee::displayperformance()
{
	cout << "Performance reviews: "<<endl;
	for (int i = 0; i < performancereviews.size(); i++)
	{
		cout << "\t ID: "<<performancereviews[i].first << ": " << performancereviews[i].second << endl;
	}
	cout << endl;
}

void Employee::displaymedical()
{
	cout << "Health: ";
	health.printHealth();
	cout << endl;
}

void Employee::displaymedicalN()
{
	health.printHealthNV();
	cout << endl;
}

void Employee::displaymedicalFiltered(vector<bool>&ff)
{
	health.displayMedicalfiltered(ff);
	cout << endl;
}

void Employee::displayemploymentFiltered(vector<bool>& ff)
{
	if(ff[0])
	{
		cout << "Position: " << position << endl;
	}
	if(ff[1])
	{
		cout << "Department: " << department << endl;
	}
	if(ff[2])
	{
		cout << "Supervisor: " << supervisor << endl;
	}
	if(ff[3])
	{
		cout << "Employment type: " << employmnttype << endl;
	}
	if(ff[4])
	{
		cout << "Salary: " << salary << endl;
	}
	if(ff[5])
	{
		cout << "Salary per hour: " << salaryperhour << endl;
	}
	if(ff[6])
	{
		cout << "Hours worked: " << hours << endl;
	}
	if(ff[7])
	{
		cout << "Overtime: " << overtime << endl;
	}
	if(ff[8])
	{
		cout << "Bonus: " << bonus << endl;
	}
	if(ff[9])
	{
		cout << "Vacation days: " << vacationdays << endl;
	}
	if(ff[10])
	{
		cout << "Hire date: ";
		hiredate.printDate();
		cout << endl;
	}
	if(ff[11])
	{
		cout << "Benefits: ";
		displaywithtab(benefits);
	}
	if(ff[12])
	{
		cout << "Payment for the month: " << payment << endl;
	}
}

void Employee::displayskillsFiltered(vector<bool>& ff)
{
	if (ff[0])
	{
		cout << "Skills: ";
		displaywithtab(skills);
	}
	if (ff[1])
	{
		cout << "Trainings: ";
		displaywithtab(trainings);
	}
	if (ff[2])
	{
		cout << "Certifications: ";
		displaywithtab(certifications);
	}
	if (ff[3])
	{
		cout << "Projects: ";
		displaywithtab(projects);
	}
	if (ff[4])
	{
		cout << "Publications: ";
		displaywithtab(publications);
	}
	if (ff[5])
	{
		cout << "Memberships: ";
		displaywithtab(memberships);
	}
	if (ff[6])
	{
		cout << "Awards: ";
		displaywithtab(awards);
	}
}

void Employee::displaysecurityFiltered(vector<bool>& ff)
{
	if (ff[0])
	{
		printclearance();
	}
	if (ff[1])
	{
		cout << "References: ";
		displaywithtab(references);
	}
	if (ff[2])
	{
		cout << "Background check: ";
		displaywithtab(backgroundcheck);
	}
}

void Employee::displaypersonalFiltered(vector<bool>& ff)
{
	if (ff[0])
	{
		cout << "Name: " << name << endl;
	}
	if (ff[1])
	{
		cout << "Nickname: " << nickname << endl;
	}
	if (ff[2])
	{
		cout << "Birthday: ";
		getHealth().getBirth().printDate();
		cout << endl;
	}
	if (ff[3])
	{
		cout << "Marital status: " << getMaritalstatusS() << endl;
	}
	if (ff[4])
	{
		cout << "Kids: " << kids << endl;
	}
	if (ff[5])
	{
		cout << "Nationality: " << nationality << endl;
	}
	if (ff[6])
	{
		cout << "Languages: ";
		displaywithtab(languages);
	}
	if (ff[7])
	{
		cout << "Education: ";
		displaywithtab(education);
	}
	if(ff[8])
	{
		cout << "Preferences: ";
		displaywithtab(preferences);
	}
}

void Employee::displaycontactFiltered(vector<bool>& ff)
{
	if (ff[0])
	{
		cout << "Phone: " << phone << endl;
	}
	if (ff[1])
	{
		cout << "Email: " << email << endl;
	}
	if (ff[2])
	{
		cout << "Address: " << address << endl;
	}
}

void Employee::displayallFiltered(vector<bool>& ff)
{
	if(ff[0])
	{
		cout << "ID: " << id << endl;
	}
	if(ff[1])
	{
		cout << "Name: " << name << endl;
	}
	if(ff[2])
	{
		cout << "Nickname: " << nickname << endl;
	}
	if(ff[3])
	{
		cout << "Clearance level: " << getClearanceH() << endl;
	}
	if (ff[4])
	{
		cout << "Position: " << position << endl;
	}
	if (ff[5])
	{
		cout << "Department: " << department << endl;
	}
	if (ff[6])
	{
		cout << "Supervisor: " << supervisor << endl;
	}
	if (ff[7])
	{
		cout << "Employment type: " << employmnttype << endl;
	}
	if (ff[8])
	{
		cout << "Salary: " << salary << endl;
	}
	if (ff[9])
	{
		cout << "Salary per hour: " << salaryperhour << endl;
	}
	if (ff[10])
	{
		cout << "Hours worked: " << hours << endl;
	}
	if (ff[11])
	{
		cout << "Overtime: " << overtime << endl;
	}
	if (ff[12])
	{
		cout << "Bonus: " << bonus << endl;
	}
	if (ff[13])
	{
		cout << "Vacation days: " << vacationdays << endl;
	}
	if (ff[14])
	{
		cout << "Hire date: ";
		hiredate.printDate();
		cout << endl;
	}
	if (ff[15])
	{
		cout << "Benefits: ";
		displaywithtab(benefits);
	}
	if (ff[16])
	{
		cout << "Payment for the month: " << payment << endl;
	}
	if (ff[17])
	{
		cout << "Phone: " << phone << endl;
	}
	if (ff[18])
	{
		cout << "Email: " << email << endl;
	}
	if (ff[19])
	{
		cout << "Address: " << address << endl;
	}
	if (ff[20])
	{
		cout << "Birth date: ";
		health.getBirth().printDate();
		cout << endl;
	}
	if (ff[21])
	{
		cout << "Age: " << health.getAge() << endl;
	}
	if (ff[22])
	{
		cout << "Gender: " << health.getGenderS() << endl;
	}
	if (ff[23])
	{
		cout << "Height: " << health.getHeight() << "cm" << endl;
	}
	if (ff[24])
	{
		cout << "Weight: " << health.getWeight() << "kg" << endl;
	}
	if (ff[25])
	{
		cout << "Blood type: " << health.getBloodTypeS() << endl;
	}
	if (ff[26])
	{
		cout << "Blood pressure: " << health.getBloodPressureSistoic() << "/" << health.getBloodPressureDiasotic() << endl;
	}
	if (ff[27])
	{
		cout << "Heart rate: " << health.getHeartRate() << "bpm" << endl;
	}
	if (ff[28])
	{
		cout << "Respiratory rate: " <<health.getRespiratoryRate() << "bpm" << endl;
	}
	if (ff[29])
	{
		cout << "Oxygen level: " << health.getOxygenLevel()<< "%" << endl;
	}
	if (ff[30])
	{
		cout << "Temperature: " << health.getTemperature() << "C" << endl;
	}
	if (ff[31])
	{
		cout << "Emergency contact: " << health.getEmergencyContact() << endl;
	}
	if (ff[32])
	{
		cout << "Doctors: ";
		vector<string>v=health.getDoctor();
		displaywithtab(v);
	}
	if (ff[33])
	{
		cout << "Visit dates:" << endl;
		vector<Date>visitdates = health.getVisitDate();
		for (int i = 0; i < visitdates.size(); i++)
		{
			visitdates[i].printDate();
		}
	}
	if (ff[34])
	{
		cout << "Visit reasons: ";
		vector<string>visitreasons = health.getVisitReason();
		displaywithtab(visitreasons);
	}
	if (ff[35])
	{
		cout << "Allergies: ";
		vector<string>allergies = health.getAllergy();
		displaywithtab(allergies);
	}
	if (ff[36])
	{
		cout << "Medications: ";
		vector<string>medications = health.getMedications();
		displaywithtab(medications);
	}
	if (ff[37])
	{
		cout << "Medication schedule: ";
		vector<string>medicationschedule = health.getMedicationSchedule();
		displaywithtab(medicationschedule);
	}
	if (ff[38])
	{
		cout << "Prescriptions: ";
		vector<string>prescriptions = health.getPrescription();
		displaywithtab(prescriptions);
	}
	if (ff[39])
	{
		cout << "Health operations: ";
		vector<string>healthopserv = health.getHealthopserv();
		displaywithtab(healthopserv);
	}
	if (ff[40])
	{
		cout << "Diagnoses: ";
		vector<string>diagnoses = health.getDiagnosis();
		displaywithtab(diagnoses);
	}
	if (ff[41])
	{
		cout << "Treatments: ";
		vector<string>treatments = health.getTreatment();
		displaywithtab(treatments);
	}
	if (ff[42])
	{
		cout << "Chronic conditions: ";
		vector<string>chronicconditions = health.getChronicConditions();
		displaywithtab(chronicconditions);
	}
	if (ff[43])
	{
		cout << "Mental health: ";
		vector<string>mentalhealth = health.getMentalHealth();
		displaywithtab(mentalhealth);
	}
	if (ff[44])
	{
		cout << "Drug tests: ";
		vector<string>drugtest = health.getDrugTest();
		displaywithtab(drugtest);
	}
	if (ff[45])
	{
		cout << "Vaccines: ";
		vector<string>vaccines = health.getVaccine();
		displaywithtab(vaccines);
	}
	if (ff[46])
	{
		cout << "Surgeries: ";
		vector<string>surgeries = health.getSurgeries();
		displaywithtab(surgeries);
	}
	if (ff[47])
	{
		cout << "Lab results: ";
		vector<string>labresults = health.getLabResults();
		displaywithtab(labresults);
	}
	if (ff[48])
	{
		cout << "Imaging results: ";
		vector<string>imagingresults = health.getImagingResults();
		displaywithtab(imagingresults);
		health.displayImages();
	}
	if (ff[49])
	{
		cout << "Past medical history: ";
		vector<string>pastmedicalhistory = health.getPastMedicalHistory();
		displaywithtab(pastmedicalhistory);
	}
	if (ff[50])
	{
		cout << "Family history: ";
		vector<string>familyhistory = health.getFamilyHistory();
		displaywithtab(familyhistory);
	}
	if (ff[51])
	{
		cout << "Preferences: ";
		displaywithtab(preferences);
	}
	if(ff[52])
	{
		cout << "Marital status: " << getMaritalstatusS() << endl;
	}
	if(ff[53])
	{
		cout << "Kids: " << kids << endl;
	}
	if (ff[54])
	{
		cout<<"Nationality"<<nationality<<endl;
	}
	if (ff[55])
	{
		cout << "Languages: ";
		displaywithtab(languages);
	}
	if (ff[56])
	{
		cout << "Education: ";
		displaywithtab(education);
	}
	if (ff[57])
	{
		cout << "Personal Preferences: ";
		displaywithtab(preferences);
	}
	if (ff[58])
	{
		cout << "Skills: ";
		displaywithtab(skills);
	}
	if (ff[59])
	{
		cout << "Trainings: ";
		displaywithtab(trainings);
	}
	if (ff[60])
	{
		cout << "Certifications: ";
		displaywithtab(certifications);
	}
	if (ff[61])
	{
		cout << "Projects: ";
		displaywithtab(projects);
	}
	if (ff[62])
	{
		cout << "Publications: ";
		displaywithtab(publications);
	}
	if (ff[63])
	{
		cout << "Memberships: ";
		displaywithtab(memberships);
	}
	if (ff[64])
	{
		cout << "Awards: ";
		displaywithtab(awards);
	}
	if (ff[65])
	{
		cout << "Performance reviews: ";
		for (int i = 0; i < performancereviews.size(); i++)
		{
			cout << "\t ID: " << performancereviews[i].first << ": " << performancereviews[i].second << endl;
		}
	}
	if (ff[66])
	{
		cout << "References: ";
		displaywithtab(references);
	}
	if (ff[67])
	{
		cout << "Background check: ";
		displaywithtab(backgroundcheck);
	}
	if (ff[68])
	{
		cout << "Photos: ";
		displaywithtab(photos);
	}
}

void Employee::displaysecurity()
{
	cout << "References: ";
	for (int i = 0; i < references.size(); i++)
	{
		cout << references[i] << " ";
	}
	cout << endl;
	cout << "Background check: ";
	for (int i = 0; i < backgroundcheck.size(); i++)
	{
		cout << backgroundcheck[i] << " ";
	}
	cout << endl;
}

int Employee::displaysecurityN()
{
	cout<< "1. Clearance level"<<endl;
	cout << "2. References"<<endl;
	cout << "3. Background check"<<endl;
	return 3;
}

int Employee::displaysecurityNV()
{
	cout<<"1. Clearance level: ";
	for(int i=0;i<CLRLN;i++)
	{
		cout<<clearance[i]<<" ";
	}
	cout<<endl;
	cout << "2. References: ";
	displaywithtab(references);
	cout << "3. Background check: ";
	displaywithtab(backgroundcheck);
	cout << endl;
	return 3;
}

void Employee::displaynice()
{
	cout << "Nickname: " << nickname << endl;
	cout << "Birthday: ";
	health.getBirth().printDate();
	cout << endl;
	cout << "Marital status: " << getMaritalstatusS() << endl;
	cout << "Kids: " << kids << endl;
	cout << "Nationality: " << nationality << endl;
	cout << "Languages: ";
	for (int i = 0; i < languages.size(); i++)
	{
		if (i == 0)
		{
			cout << languages[i] << endl;
		}
		else
		{
			cout << "\t" << languages[i] << endl;
		}
	}
	cout << "Education: ";
	for (int i = 0; i < education.size(); i++)
	{
		if (i == 0)
		{
			cout << education[i] << endl;
		}
		else
		{
			cout << "\t" << education[i] << endl;
		}
	}
}

void Employee::displayall()
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Nickname: " << nickname << endl;
	cout<<"Clearance level: "<<getClearanceH()<<endl;
	displayemployment();
	cout << endl;
	displaycontact();
	cout << endl;
	displaymedical();
	cout << endl;
	displaynice();
	cout << endl;
	displaypreferences();
	cout << endl;
	displayskills();
	cout << endl;
	displayperformance();
	cout << endl;
	displaysecurity();
	cout << endl;
	displayphotos();
	cout << endl;
}

int Employee::displayallN()
{
	cout << "1. ID: " << endl;
	cout << "2. Name: " << endl;
	cout << "3. Nickname: " << endl;
	cout << "4. Clearance level: " << endl;
	cout << "5. Position" << endl;
	cout << "6. Department" << endl;
	cout << "7. Supervisor" << endl;
	cout << "8. Employment type" << endl;
	cout << "9. Salary" << endl;
	cout << "10. Salary per hour" << endl;
	cout << "11.Hours worked" << endl;
	cout << "12. Overtime" << endl;
	cout << "13. Bonus" << endl;
	cout << "14. Vacation days" << endl;
	cout << "15. Hire date";
	cout << "16. Benefits";
	cout << "17. Payment for the month" << endl;
	cout << "18. Phone" << endl;
	cout << "19. Email" << endl;
	cout << "20. Address" << endl;
	cout << "21. Birth date" << endl;
	cout << "22. Age" << endl;
	cout << "23. Gender" << endl;
	cout << "24. Height" << endl;
	cout << "25. Weight" << endl;
	cout << "26. Blood type" << endl;
	cout << "27. Blood pressure" << endl;
	cout << "28. Heart rate" << endl;
	cout << "29. Respiratory rate" << endl;
	cout << "30. Oxygen level" << endl;
	cout << "31. Temperature" << endl;
	cout << "32. Emergency contact" << endl;
	cout << "33. Doctors" << endl;
	cout << "34. Visits" << endl;
	cout << "35. Visit reasons" << endl;
	cout << "36. Allergies" << endl;
	cout << "37. Medications" << endl;
	cout << "38. Medication schedule" << endl;
	cout << "39. Prescriptions" << endl;
	cout << "40. Health operations" << endl;
	cout << "41. Diagnoses" << endl;
	cout << "42. Treatments" << endl;
	cout << "43. Chronic conditions" << endl;
	cout << "44. Mental health" << endl;
	cout << "45. Drug tests" << endl;
	cout << "46. Vaccines" << endl;
	cout << "47. Surgeries" << endl;
	cout << "48. Lab results" << endl;
	cout << "49. Imaging results" << endl;
	cout << "50. Past medical history" << endl;
	cout << "51. Family history" << endl;
	cout << "52. Medical Preferences" << endl;
	cout << "53. Marital status"  << endl;
	cout << "54. Kids" << endl;
	cout << "55. Nationality" << endl;
	cout << "56. Languages";
	cout << "57. Education";
	cout<<"58. Personal Preferences";
	cout << "59. Skills";
	cout << "60. Trainings";
	cout << "61. Certifications: ";
	cout << "62. Projects";
	cout << "63. Publications";
	cout << "64. Memberships";
	cout << "65. Awards";
	cout << "66. Performance reviews";
	cout << "67. References";
	cout << "68. Background check";
	cout << "69. Photos";
	return 69;
}

void Employee::display0()
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Clearance level: " << getClearanceH() << endl;
	cout<<endl<<"Job related information:"<<endl;
	displayemployment();
	cout<<endl<<"Personal information:"<<endl;
	displaynice();
	cout<<endl<<"Skills and performance: "<<endl;
	displayskills();
	cout<<endl<<"Medical information:"<<endl;
	displaymedical();
	cout<<endl<<"Contact information:"<<endl;
	displaycontact();
	cout<<endl<<"Photos: "<<endl;
	displayphotos();

	displaypreferences();
}

void Employee::displayphotos()
{
	//open photo
	if (!photos.empty())
	{
		cout << "Opening photo..." << endl;
		for(int i=0;i<photos.size();i++)
		{
			system(("start " + photos[i]).c_str() );
		}
	}
	else
	{
		cout << "No photo available." << endl;
	}
}

// ---- edit ----

void Employee::editpassword()
{
	bool ok = true;
	string s,ss;
	while (ok)
	{
		cout << "Enter old password: ";
		getline(cin, s);
		if (s == code)
		{
			ok = false;
		}
		else
		{
			cout << "Wrong password." << endl;
		}
	}
	ok = true;

	while (ok)
	{
		cout << "Enter new password: ";
		getline(cin, s);
		if(s!="")
		{
			cout << "Re-enter new password: ";
			getline(cin, ss);
			if (s == ss)
			{
				code = s;
				ok = false;
			}
			else
			{
				cout << "Passwords do not match." << endl;
			}
		}
		else
		{
			cout << "Password cannot be empty." << endl;
		}
	}
}

void Employee::editmedical()
{
	cout<<"Edit medical information of patient: "<<id<<" "<<name<<endl;
	health.editMedical();
}

void Employee::editemployment()
{
	cout<<"Edit employment information of employee: "<<id<<" "<<name<<endl;
	cout << "1. Edit Position: " << position << endl;
	cout << "2. Edit Department: " << department << endl;
	cout << "3. Edit Supervisor: " << supervisor << endl;
	cout << "4. Edit Employment type: " << employmnttype << endl;
	cout << "5. Edit Salary: " << salary << endl;
	cout << "6. Edit Salary per hour: " << salaryperhour << endl;
	cout << "7. Edit Hours worked: " << hours << endl;
	cout << "8. Edit Overtime: " << overtime << endl;
	cout << "9. Edit Bonus: " << bonus << endl;
	cout << "10. Edit Vacation days: " << vacationdays << endl;
	cout << "11. Edit Hire date: ";
	hiredate.printDate();
	cout << endl;
	cout << "12. Edit Benefits: ";
	displaywithtab(benefits);
	cout << endl;
	cout<<"13. Remove Benefits"<<endl;
	cout << endl;
	bool ok = true;
	while (ok)
	{
		int a = getanumber("Enter the number of the information you want to edit or 0 if you want to go back: ");
		if (a < 0 || a>13)
		{
			cout << "Invalid input" << endl;
		}
		else if (a == 0)
		{
			ok = false;
		}
		else
		{
			switch (a)
			{
				case 1: {
					cout << "Enter new position: ";
					string s;
					getline(cin, s);
					setPosition(s);
					break;
				}
				case 2: {
					cout << "Enter new department: ";
					string s;
					getline(cin, s);
					setDepartment(s);
					break;
				}
				case 3: {
					cout << "Enter new supervisor: ";
					string s;
					getline(cin, s);
					setSupervisor(s);
					break;
				}
				case 4: {
					cout << "Enter new employment type: ";
					string s;
					getline(cin, s);
					setEmploymnttypeS(s);
					break;
				}
				case 5: {
					double s=getanumberD("Enter new salary: ");
					setSalary(s);
					break;
				}
				case 6: {
					double s=getanumberD("Enter new salary per hour: ");
					setSalaryperhour(s);
					break;
				}
				case 7: {
					double s=getanumberD("Enter new hours worked: ");
					setHours(s);
					break;
				}
				case 8: {
					double s=getanumberD("Enter new overtime: ");
					setOvertime(s);
					break;
				}
				case 9: {
					double s=getanumberD("Enter new bonus: ");
					setBonus(s);
					break;
				}
				case 10: {
					int s=getanumber("Enter new vacation days: ");
					setVacationdays(s);
					break;
				}
				case 11: {
					cout << "Enter new hire date: ";
					int d, m, y;
					d=getanumber("Enter day: ");
					m=getanumber("Enter month: ");
					y=getanumber("Enter year: ");
					Date s(d,m,y);
					setHiredate(s);
					break;
				}
				case 12: {
					cout << "Enter new benefits: ";
					vector<string> s;
					string ss;
					getline(cin, ss);
					while (ss != "")
					{
						s.push_back(ss);
						getline(cin, ss);
					}
					benefits = s;
					break;
				}
				case 13: {
					cout<< "Benefits: ";
					displaywithtab(benefits);
					cout<<endl;
					cout << "Enter which benefit you would want to remove (1-" << benefits.size() << "): ";
					bool ok2 = true;
					int w;
					while (ok2)
					{
						w = getanumber("");
						if (w < 1 || w>benefits.size())
						{
							cout << "Invalid input" << endl;
						}
						else
						{
							ok2 = false;
						}
					}
					removefromvectorS(benefits[w - 1], benefits);
					break;
				}
				case 0: {
					ok = false;
					break;
				}
				default:
					break;
			}
			clearconsol();
			editemployment();
		}
	}
}

void Employee::editskills()
{
	cout << "Edit skills information for an employee: " << id << " " << name << endl;
	cout << "1. Add a skill: ";
	displaywithtab(skills);
	cout << endl;
	cout << "2. Remove a skill" << endl;
	cout << "3. Add a training: ";
	displaywithtab(trainings);
	cout << endl;
	cout << "4. Remove a training" << endl;
	cout << "5. Add a certification: ";
	displaywithtab(certifications);
	cout << endl;
	cout << "6. Remove a certification" << endl;
	cout << "7. Add a project: ";
	displaywithtab(projects);
	cout << endl;
	cout << "8. Remove a project" << endl;
	cout << "9. Add a publication: ";
	displaywithtab(publications);
	cout << endl;
	cout << "10. Remove a publication" << endl;
	cout << "11. Add a membership: ";
	displaywithtab(memberships);
	cout << endl;
	cout << "12. Remove a membership" << endl;
	cout << "13. Add an award: ";
	displaywithtab(awards);
	cout << endl;
	cout << "14. Remove an award" << endl;
	cout << "0. Go back" << endl;
	cout << endl;
	bool ok = true;
	while (ok)
	{
		int a = getanumber("Enter the number of the option: ");
		if (a < 0 || a>14)
		{
			cout << "Invalid input" << endl;
		}
		else if (a == 0)
		{
			ok = false;
		}
		else
		{
			switch (a)
			{
			case 1: {
				cout << "Enter a new skill: ";
				string s;
				getline(cin, s);
				addSkill(s);
				break;
			}
			case 2:
			{
				cout<<"Skills: ";
				displaywithtab(skills);
				cout<<endl;
				cout << "Enter which skill you would want to remove (1-" << skills.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>skills.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(skills[w - 1], skills);
				break;
			}
			case 3: {
				cout << "Enter a new training: ";
				string s;
				getline(cin, s);
				addTraining(s);
				break;
			}
			case 4:
			{
				cout << "Trainings: ";
				displaywithtab(trainings);
				cout << endl;
				cout << "Enter which training you would want to remove (1-" << trainings.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>trainings.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(trainings[w - 1], trainings);
				break;
			}
			case 5: {
				cout << "Enter a new certificate: ";
				string s;
				getline(cin, s);
				addCertification(s);
				break;
			}
			case 6:
			{
				cout << "Certifications: ";
				displaywithtab(certifications);
				cout << endl;
				cout << "Enter which certification you would want to remove (1-" << certifications.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>certifications.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(certifications[w - 1], certifications);
				break;
			}
			case 7: {
				cout << "Enter a new project: ";
				string s;
				getline(cin, s);
				addProject(s);
				break;
			}
			case 8:
			{
				cout << "Projects: ";
				displaywithtab(projects);
				cout << endl;
				cout << "Enter which project you would want to remove (1-" << projects.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>projects.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(projects[w - 1], projects);
				break;
			}
			case 9: {
				cout << "Enter a new publication: ";
				string s;
				getline(cin, s);
				addPublication(s);
				break;
			}
			case 10:
			{
				cout << "Publications: ";
				displaywithtab(publications);
				cout << endl;
				cout << "Enter which publication you would want to remove (1-" << publications.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>publications.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(publications[w - 1], publications);
				break;
			}
			case 11: {
				cout<<"Enter a new membership: ";
				string s;
				getline(cin, s);
				addMembership(s);
				break;
			}
			case 12:
			{
				cout << "Memberships: ";
				displaywithtab(memberships);
				cout << endl;
				cout << "Enter which membership you would want to remove (1-" << memberships.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>memberships.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(memberships[w - 1], memberships);
				break;
			}
			case 13: {
				cout << "Enter a new award: ";
				string s;
				getline(cin, s);
				addAward(s);
				break;
			}
			case 14:
			{
				cout << "Awards: ";
				displaywithtab(awards);
				cout << endl;
				cout << "Enter which award you would want to remove (1-" << awards.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>awards.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(awards[w - 1], awards);
				break;
			}
			case 0: {
				ok = false;
				break;
			}
			default:
				break;
			}
			clearconsol();
			editskills();
		}
	}
}

void Employee::editsecurity()
{
	cout << "Edit security information of employee: " << id << " " << name << endl;
	cout << "1. Edit clearance level" << endl;
	for(int i=0;i<CLRLN;i++)
	{
		cout<<clearance[i]<<" ";
	}
	cout<<endl;
	cout << "2. Add references" << endl;
	displaywithtab(references);
	cout << endl;
	cout<<"3. Remove references"<<endl;
	cout << "4. Add background check" << endl;
	displaywithtab(backgroundcheck);
	cout << endl;
	cout << "5. Remove background check" << endl;
	cout << "0. Go back" << endl;
	int choice;
	bool ok = true;
	while (ok)
	{
		choice = getanumber("Enter the number a number: ");
		if (choice < 0 || choice>5)
		{
			cout << "Invalid input" << endl;
		}
		else if (choice == 0)
		{
			ok = false;
		}
		else
		{
			switch (choice)
			{
			case 1: {
				cout << "Enter the new clearance levels (ex. 1 0 0 0 0 0 0): ";
				for (int i = 0; i < CLRLN; i++)
				{
					int s = getanumber("");
					if (s == 1)
					{
						setClearance(i, true);
					}
					else
					{
						setClearance(i, false);
					}
				}
				break;
			}
			case 2: {
				cout << "Enter a new reference: ";
				string s;
				getline(cin, s);
				addReference(s);
				break;
			}
			case 3:
			{
				cout << "References: ";
				displaywithtab(references);
				cout << endl;
				cout << "Enter which reference you would want to remove (1-" << references.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>references.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(references[w - 1], references);
				break;
			}
			case 4: {
				cout << "Enter a new background check: ";
				string s;
				getline(cin, s);
				addBackgroundcheck(s);
				break;
			}
			case 5:
			{
				cout << "Background check: ";
				displaywithtab(backgroundcheck);
				cout << endl;
				cout << "Enter which background check you would want to remove (1-" << backgroundcheck.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>backgroundcheck.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(backgroundcheck[w - 1], backgroundcheck);
				break;
			}
			case 0: {
				ok = false;
				break;
			}
			default:
				break;
			}
			clearconsol();
			editsecurity();
		}
	}
}

void Employee::editpersonal()
{
	cout << "Edit personal information of employee: " << id << " " << name << endl;
	cout << "1. Edit name: " <<name<< endl;
	cout << "2. Edit nickname: " <<nickname<< endl;
	cout << "3. Edit birthday: ";
	health.getBirth().printDate();
	cout<<endl;
	cout << "4. Edit marital status: "<<getMaritalstatusS()<<endl;
	cout << "5. Edit kids: "<<kids << endl;
	cout<<"6. Edit nationality: "<<nationality<<endl;
	cout << "7. Add languages: ";
	displaywithtab(languages);
	cout<<"8. Remove languages"<<endl;
	cout << "9. Add education: ";
	displaywithtab(education);
	cout<<"10. Remove education"<<endl;
	cout << "11. Add preferences: ";
	displaywithtab(preferences);
	cout << "12. Remove preferences"<<endl;
	cout << "0. Go back" << endl;
	int choice;
	bool ok = true;
	while (ok)
	{
		choice = getanumber("Enter the number a number: ");
		if (choice < 0 || choice>12)
		{
			cout << "Invalid input" << endl;
		}
		else if (choice == 0)
		{
			ok = false;
		}
		else
		{
			switch (choice)
			{
			case 1: {
				cout << "Enter new name: ";
				string s;
				getline(cin, s);
				setName(s);
				break;
			}
			case 2: {
				cout << "Enter new nickname: ";
				string s;
				getline(cin, s);
				setNickname(s);
				break;
			}
			case 3: {
				cout << "Enter new birthday: ";
				int d, m, y;
				d = getanumber("Enter day: ");
				m = getanumber("Enter month: ");
				y = getanumber("Enter year: ");
				Date s(d, m, y);
				health.setBirth(s);
				break;
			}
			case 4: {
				cout << "Enter new marital status: ";
				string s;
				getline(cin, s);
				setMaritalstatusS(s);
				break;
			}
			case 5: {
				int s = getanumber("Enter new number of kids: ");
				setKids(s);
				break;
			}
			case 6: {
				cout << "Enter nationality: ";
				string s;
				getline(cin, s);
				setNationality(s);
				break;
			}
			case 7: {
				cout << "Enter new language: ";
				string s;
				getline(cin, s);
				addLanguage(s);
				break;
			}
			case 8: {
				cout<<"Languages: ";
				displaywithtab(languages);
				cout << endl;
				cout << "Enter which language you would want to remove (1-"<<languages.size()<<"): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>languages.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(languages[w-1],languages);
				break;
			}
			case 9: {
				cout << "Enter new education: ";
				string s;
				getline(cin, s);
				addEducation(s);
				break;
			}
			case 10:
			{
				cout << "Education: ";
				displaywithtab(education);
				cout << endl;
				cout << "Enter which ducation you would want to remove (1-" << education.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>education.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(education[w - 1], education);
				break;
			}
			case 11: {
				cout << "Enter new preference: ";
				string s;
				getline(cin, s);
				addPreference(s);
				break;
			}
			case 12:
			{
				cout << "Preferences: ";
				displaywithtab(preferences);
				cout << endl;
				cout << "Enter which preference you would want to remove (1-" << preferences.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>preferences.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(preferences[w - 1], preferences);
				break;
			}
			case 0: {
				ok = false;
				break;
			}
			default:
				break;
			}
			clearconsol();
			editpersonal();
		}
	}
}

void Employee::editcontact()
{
	cout << "Edit contacting information of employee: " << id << " " << name << endl;
	cout << "1. Edit phone number " << phone << endl;
	cout << "2. Edit email " << email << endl;
	cout << "3. Edit address " << address << endl;
	cout << "0. Go back" << endl;
	int choice;
	bool ok = true;
	while (ok)
	{
		choice = getanumber("Enter the number a number: ");
		if (choice < 0 || choice>3)
		{
			cout << "Invalid input" << endl;
		}
		else if (choice == 0)
		{
			ok = false;
		}
		else
		{
			switch (choice)
			{
			case 1: {
				cout << "Enter new phone number: ";
				string s;
				getline(cin, s);
				setPhone(s);
				break;
			}
			case 2: {
				cout << "Enter new email: ";
				string s;
				getline(cin, s);
				setEmail(s);
				break;
			}
			case 3: {
				cout << "Enter new address: ";
				string s;
				getline(cin, s);
				setAddress(s);
				break;
			}
			case 0: {
				ok = false;
				break;
			}
			default:
				break;
			}
			clearconsol();
			editcontact();
		}
	}
}

void Employee::editall()
{
	cout << "Edit all information of employee: " << id << " " << name << endl;
	cout << "1. Edit personal information" << endl;
	cout << "2. Edit medical information" << endl;
	cout << "3. Edit contacting information" << endl;
	cout << "4. Edit employment information" << endl;
	cout << "5. Edit skills and performance" << endl;
	cout << "6. Edit security information" << endl;
	cout << "0. Go back" << endl;
	int choice;
	bool ok = true;
	while (ok)
	{
		choice = getanumber("Enter the number a number: ");
		if (choice < 0 || choice>6)
		{
			cout << "Invalid input" << endl;
		}
		else if (choice == 0)
		{
			ok = false;
		}
		else
		{
			switch (choice)
			{
			case 1: {
				editpersonal();
				break;
			}
			case 2: {
				editmedical();
				break;
			}
			case 3: {
				editcontact();
				break;
			}
			case 4: {
				editemployment();
				break;
			}
			case 5: {
				editskills();
				break;
			}
			case 6:
			{
				editsecurity();
				break;
			}
			case 0: {
				ok = false;
				break;
			}
			default:
				cout << "Invalid input" << endl;
				break;
			}
			clearconsol();
			editall();
		}
	}
}

// ---- getters and setters ----
int Employee::getId()
{
	return id;
}
void Employee::setId(int i)
{
	id = i;
}
string Employee::getCode()
{
	return code;
}
void Employee::setCode(string c)
{
	code = c;
}
int Employee::getClearanceH()
{
	int cl = 0;
	for (int i = 0; i < CLRLN; i++)
	{
		if (clearance[i])
		{
			cl = i;
		}
	}
	return cl;
}
void Employee::getClearance(vector<bool>&cl)
{
	for (int i = 0; i < CLRLN; i++)
	{
		cl.push_back(clearance[i]);
	}
}
void Employee::setClearance(int c,bool ok)
{
	clearance[c] = ok;
}
string Employee::getName()
{
	return name;
}
void Employee::setName(string n)
{
	name = n;
}
string Employee::getNickname()
{
	return nickname;
}
void Employee::setNickname(string n)
{
	nickname = n;
}
string Employee::getPosition()
{
	return position;
}
void Employee::setPosition(string p)
{
	position = p;
}
double Employee::getSalary()
{
	return salary;
}
void Employee::setSalary(double s)
{
	salary = s;
	payment = calculatepayment();
}
double Employee::getSalaryperhour()
{
	return salaryperhour;
}
void Employee::setSalaryperhour(double s)
{
	salaryperhour = s;
	payment = calculatepayment();
}
double Employee::getHours()
{
	return hours;
}
void Employee::setHours(double h)
{
	hours = h;
	payment = calculatepayment();
}
void Employee::setPayment(double p)
{
	payment = p;
}
double Employee::getPayment()
{
	return payment;
}
double Employee::getOvertime()
{
	return overtime;
}
void Employee::setOvertime(double o)
{
	overtime = o;
	payment = calculatepayment();
}
double Employee::getBonus()
{
	return bonus;
}
void Employee::setBonus(double b)
{
	bonus = b;
	payment = calculatepayment();
}
string Employee::getAddress()
{
	return address;
}
void Employee::setAddress(string a)
{
	address = a;
}
string Employee::getPhone()
{
	return phone;
}
void Employee::setPhone(string p)
{
	phone = p;
}
string Employee::getEmail()
{
	return email;
}
void Employee::setEmail(string e)
{
	email = e;
}
string Employee::getDepartment()
{
	return department;
}
void Employee::setDepartment(string d)
{
	department = d;
}
string Employee::getSupervisor()
{
	return supervisor;
}
void Employee::setSupervisor(string s)
{
	supervisor = s;
}
Date Employee::getHiredate()
{
	return hiredate;
}
void Employee::setHiredate(Date h)
{
	hiredate = h;
	payment = calculatepayment();
}
int Employee::getMaritalstatus()
{
	return maritalstatus;
}
string Employee::getMaritalstatusS()
{
	string m;
	switch (maritalstatus)
	{
	case 0:
		m = "single";
		break;
	case 1:
		m = "dateing";
		break;
	case 2:
		m = "married";
		break;
	case 3:
		m = "divorced";
		break;
	case 4:
		m = "widowed";
		break;
	case 5:
		m = "other";
		break;
	default:
		m = "unknown";
		break;
	}
	return m;
}
void Employee::setMaritalstatus(int m)
{
	maritalstatus = m;
}
void Employee::setMaritalstatusS(string m)
{
	if (m == "single")
	{
		maritalstatus = 0;
	}
	else if (m == "dateing")
	{
		maritalstatus = 1;
	}
	else if (m == "married")
	{
		maritalstatus = 2;
	}
	else if (m == "divorced")
	{
		maritalstatus = 3;
	}
	else if (m == "widowed")
	{
		maritalstatus = 4;
	}
	else if (m == "other")
	{
		maritalstatus = 5;
	}
	else
	{
		maritalstatus = -1;
	}

}
int Employee::getKids()
{
	return kids;
}
void Employee::setKids(int k)
{
	kids = k;
}
int Employee::getVacationdays()
{
	return vacationdays;
}
void Employee::setVacationdays(int v)
{
	vacationdays = v;
}
string Employee::getNationality()
{
	return nationality;
}
void Employee::setNationality(string n)
{
	nationality= n;
}
vector<string> Employee::getLanguages()
{
	return languages;
}
void Employee::addLanguage(string l)
{
	languages.push_back(l);
}
vector<string> Employee::getEducation()
{
	return education;
}
void Employee::addEducation(string e)
{
	education.push_back(e);
}
int Employee::getEmploymnttype()
{
	return employmnttype;
}
string Employee::getEmploymnttypeS()
{
	string e;
	switch (employmnttype)
	{
	case 0:
		e = "unemployed";
		break;
	case 1:
		e = "full-time";
		break;
	case 2:
		e = "part-time";
		break;
	case 3:
		e = "intern";
		break;
	case 4:
		e = "contract";
		break;
	case 5:
			e="consultant";
			break;
	case 6:
		e = "temporary";
		break;
	case 7:
		e = "volunteer";
				break;
	case 8:
		e = "volunteer";
		break;
	case 9:
		e = "retired";
		break;
	default:
		e = "unknown";
		break;
	}
	return e;
}
void Employee::setEmploymnttype(int e)
{
	employmnttype = e;
}
void Employee::setEmploymnttypeS(string e)
{
	if (e == "unemployed")
	{
		employmnttype = 0;
	}
	else if (e == "full-time")
	{
		employmnttype = 1;
	}
	else if (e == "part-time")
	{
		employmnttype = 2;
	}
	else if (e == "intern")
	{
		employmnttype = 3;
	}
	else if (e == "contract")
	{
		employmnttype = 4;
	}
	else if (e == "consultant")
	{
		employmnttype = 5;
	}
	else if (e == "temporary")
	{
		employmnttype = 6;
	}
	else if (e == "volunteer")
	{
		employmnttype = 7;
	}
	else if (e == "seasonal")
	{
		employmnttype = 8;
	}
	else if (e == "retired")
	{
		employmnttype = 9;
	}
	else
	{
		employmnttype = -1;
	}
}
vector<string> Employee::getBenefits()
{
	return benefits;
}
void Employee::addBenefit(string b)
{
	benefits.push_back(b);
}
vector<pair<int, string>> Employee::getPerformancereviews()
{
	return performancereviews;
}
void Employee::addPerformancereview(int p, string r)
{
	performancereviews.push_back(make_pair(p, r));
}
vector<string> Employee::getTrainings()
{
	return trainings;
}
void Employee::addTraining(string t)
{
	trainings.push_back(t);
}
vector<string> Employee::getCertifications()
{
	return certifications;
}
void Employee::addCertification(string c)
{
	certifications.push_back(c);
}
vector<string> Employee::getProjects()
{
	return projects;
}
void Employee::addProject(string p)
{
	projects.push_back(p);
}
vector<string> Employee::getPublications()
{
	return publications;
}
void Employee::addPublication(string p)
{
	publications.push_back(p);
}
vector<string> Employee::getMemberships()
{
	return memberships;
}
void Employee::addMembership(string m)
{
	memberships.push_back(m);
}
vector<string> Employee::getAwards()
{
	return awards;
}
void Employee::addAward(string a)
{
	awards.push_back(a);
}
vector<string> Employee::getSkills()
{
	return skills;
}
void Employee::addSkill(string s)
{
	skills.push_back(s);
}
vector<string> Employee::getBackgroundcheck()
{
	return backgroundcheck;
}
void Employee::addBackgroundcheck(string b)
{
	backgroundcheck.push_back(b);
}
vector<string> Employee::getReferences()
{
	return references;
}
void Employee::addReference(string r)
{
	references.push_back(r);
}
Medical Employee::getHealth()
{
	return health;
}
void Employee::setHealth(Medical h)
{
	health = h;
}
vector<string> Employee::getPreferences()
{
	return preferences;
}
void Employee::addPreference(string p)
{
	preferences.push_back(p);
}
vector<string> Employee::getPhotos()
{
	return photos;
}
void Employee::addPhoto(string p)
{
	photos.push_back(p);
}

// ---- functions ----

void Employee::sinceatcompany(int&d, int&m, int&y)
{
	y = 0;
	m = 0;
	d = 0;
	Date today = Date(1);
	y = today.getYear() - hiredate.getYear();
	m = today.getMonth() - hiredate.getMonth();
	d = today.getDay() - hiredate.getDay();

	if (d < 0)
	{
		m--;
		d += 30;
	}
	if (m < 0)
	{
		y--;
		m += 12;
	}
}


double Employee::calculatepayment()
{
	double payment = -1;
	if(salary != -1)
	{
		payment = salary;
	}
	else if(salaryperhour != -1 && hours != -1)
	{
		payment = salaryperhour * hours;
	}
	else
	{
		payment = -1;
	}
	if (payment != -1)
	{
		int d, m, y;
		sinceatcompany(d, m, y);
		if (y > 0)
		{
			payment += payment * 0.1 * y;
		}
		if (m > 6)
		{
			payment += payment * 0.05;
		}
		payment += bonus;
		if (overtime != -1)
		{
			if (salaryperhour != -1)
			{
				payment += salaryperhour * overtime * 1.5;
			}
			else
			{
				payment += (salary / (40 * 20)) * overtime * 1.5;
			}
		}
	}
	return payment;
}

void Employee::printclearance()
{
	cout << "Clearance level: ";
	for (int i = 0; i < CLRLN; i++)
	{
		if (clearance[i])
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

bool Employee::matching(int show, const Employee& e)
{
	switch (show)
	{
	case 1:
		return medicalmatching(e);
		break;
	case 2:
		return employmentmatching(e);
		break;
	case 3:
		return skillsmatching(e);
		break;
	case 4:
		return personalmatching(e);
		break;
	case 5:
		return securitymatching(e);
		break;
	case 6:
		return allmatching(e);
	default:
		return false;
		break;
	}
}

bool Employee::medicalmatching(Employee e)
{
	return health.matching(e.health);
}

bool Employee::employmentmatching(Employee e)
{
	Date d;
	if(e.payment!=-1 && payment==-1)
	{
		return false;
	}
	else if(e.payment!=-1 && payment!=-1 && e.payment!=payment)
	{
		return false;
	}
	if(e.salary!=-1 && salary==-1)
	{
		return false;
	}
	else if(e.salary!=-1 && salary!=-1 && e.salary!=salary)
	{
		return false;
	}
	if(e.salaryperhour!=-1 && salaryperhour==-1)
	{
		return false;
	}
	else if(e.salaryperhour!=-1 && salaryperhour!=-1 && e.salaryperhour!=salaryperhour)
	{
		return false;
	}
	if(e.hours!=-1 && hours==-1)
	{
		return false;
	}
	else if(e.hours!=-1 && hours!=-1 && e.hours!=hours)
	{
		return false;
	}
	if(e.overtime!=-1 && overtime==-1)
	{
		return false;
	}
	else if(e.overtime!=-1 && overtime!=-1 && e.overtime!=overtime)
	{
		return false;
	}
	if(e.bonus!=-1 && bonus==-1)
	{
		return false;
	}
	else if(e.bonus!=-1 && bonus!=-1 && e.bonus!=bonus)
	{
		return false;
	}
	else if (e.hiredate != d && hiredate == d)
	{
		return false;
	}
	else if (e.hiredate != d && hiredate != d && e.hiredate != hiredate)
	{
		return false;
	}
	else if (e.department != "" && department == "")
	{
		return false;
	}
	else if (e.department != "" && department != "" && e.department != department)
	{
		return false;
	}
	else if (e.supervisor != "" && supervisor == "")
	{
		return false;
	}
	else if (e.supervisor != "" && supervisor != "" && e.supervisor != supervisor)
	{
		return false;
	}
	else if (e.employmnttype != -1 && employmnttype == -1)
	{
		return false;
	}
	else if (e.employmnttype != -1 && employmnttype != -1 && e.employmnttype != employmnttype)
	{
		return false;
	}
	else if (e.vacationdays != -1 && vacationdays == -1)
	{
		return false;
	}
	else if (e.vacationdays != -1 && vacationdays != -1 && e.vacationdays != vacationdays)
	{
		return false;
	}
	else if (!e.benefits.empty() && benefits.empty())
	{
		return false;
	}
	else if (!e.benefits.empty() && !benefits.empty() && !isinvectorVS(e.benefits, benefits))
	{
		return false;
	}
	return true;
}

bool Employee::skillsmatching(Employee e)
{
	if (!e.skills.empty() && skills.empty())
	{
		return false;
	}
	else if (!e.skills.empty() && !skills.empty() && !isinvectorVS(e.skills, skills))
	{
		return false;
	}
	if (!e.trainings.empty() && trainings.empty())
	{
		return false;
	}
	else if (!e.trainings.empty() && !trainings.empty() && !isinvectorVS(e.trainings, trainings))
	{
		return false;
	}
	if (!e.certifications.empty() && certifications.empty())
	{
		return false;
	}
	else if (!e.certifications.empty() && !certifications.empty() && !isinvectorVS(e.certifications, certifications))
	{
		return false;
	}
	if (!e.projects.empty() && projects.empty())
	{
		return false;
	}
	else if (!e.projects.empty() && !projects.empty() && !isinvectorVS(e.projects, projects))
	{
		return false;
	}
	if (!e.publications.empty() && publications.empty())
	{
		return false;
	}
	else if (!e.publications.empty() && !publications.empty() && !isinvectorVS(e.publications, publications))
	{
		return false;
	}
	if (!e.memberships.empty() && memberships.empty())
	{
		return false;
	}
	else if (!e.memberships.empty() && !memberships.empty() && !isinvectorVS(e.memberships, memberships))
	{
		return false;
	}
	if (!e.awards.empty() && awards.empty())
	{
		return false;
	}
	else if (!e.awards.empty() && !awards.empty() && !isinvectorVS(e.awards, awards))
	{
		return false;
	}
	return true;
}

bool Employee::personalmatching(Employee e)
{
	if(e.maritalstatus!=-1 && maritalstatus==-1)
	{
		return false;
	}
	else if(e.maritalstatus!=-1 && maritalstatus!=-1 && e.maritalstatus!=maritalstatus)
	{
		return false;
	}
	if(e.kids!=-1 && kids==-1)
	{
		return false;
	}
	else if(e.kids!=-1 && kids!=-1 && e.kids!=kids)
	{
		return false;
	}
	if(e.nationality!="" && nationality=="")
	{
		return false;
	}
	else if (e.nationality!="" && nationality!="" && e.nationality!=nationality)
	{
		return false;
	}
	if (!e.languages.empty() && languages.empty())
	{
		return false;
	}
	else if (!e.languages.empty() && !languages.empty() && !isinvectorVS(e.languages, languages))
	{
		return false;
	}
	if (!e.education.empty() && education.empty())
	{
		return false;
	}
	else if (!e.education.empty() && !education.empty() && !isinvectorVS(e.education, education))
	{
		return false;
	}
	return true;
}

bool Employee::securitymatching(Employee e)
{
	for(int i=0;i<CLRLN;i++)
	{
		if(e.clearance[i]!=clearance[i])
		{
			return false;
		}
	}
	return true;
}

bool Employee::allmatching(Employee e)
{
	if (!medicalmatching(e))
	{
		return false;
	}
	if (!employmentmatching(e))
	{
		return false;
	}
	if (!skillsmatching(e))
	{
		return false;
	}
	if (!personalmatching(e))
	{
		return false;
	}
	if (!securitymatching(e))
	{
		return false;
	}
	return true;
}

// ---- operator overloading ----

bool Employee::operator<(Employee e)
{
	return id < e.id;
}

bool Employee::operator>(Employee e)
{
	return id > e.id;
}

bool Employee::operator==(Employee e)
{
	return id == e.id;
}

bool Employee::operator<=(Employee e)
{
	return id <= e.id;
}

bool Employee::operator>=(Employee e)
{
	return id >= e.id;
}

bool Employee::operator!=(Employee e)
{
	return id != e.id;
}

ostream& operator<<(ostream& os, const Employee& e)
{
	os << "ID: " << e.id << ", Name: " << e.name << ", Position: " << e.position << ", Salary: " << e.salary;
	return os;
}
