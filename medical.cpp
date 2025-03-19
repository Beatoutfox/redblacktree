#include "Medical.h"

Medical::Medical()
{
	birth=Date();
	age=-1;
	gender=-1;//0-not specified 1-male 2-woman 3-wtm 4-mtf 5-ersex 6-other
	height=-1;
	weight=-1;
	bloodtype=-1;//0=O-,1=O+,2=A-,3=A+,4=B-,5=B+,6=AB-,7=AB+
	bloodpresuresistoic = -1;
	bloodpresurediasotic=-1;
	heartrate=-1;//bpm
	respiratoryrate=-1;//bpm
	oxygenlevel=-1.00;//%
	temperature=-1.00;
	emergencycontact="";
}

Medical::~Medical()
{
}

//set
void Medical::setGender(int g)
{
	if (g >= 0 && g <= 6)
	{
		gender = g;
	}
}
void Medical::setGenderS(string g)
{
	if (g == "not specified")
	{
		gender = 0;
	}
	else if(g=="man"||g=="Man"||g=="MAN"||g == "male" || g == "Male" || g == "MALE" || g == "m"||g=="M")
	{
		gender = 1;
	}
	else if (g=="woman"||g=="Woman"||g=="WOMAN"||g == "famale" || g == "Female" || g == "FEMALE" || g == "f"||g=="F"||g=="w"||g=="W")
	{
		gender = 2;
	}
	else if (g == "wtm" || g == "Wtm" || g == "WTM" || g == "ftm" || g == "Ftm" || g == "FTM" || g == "female to male" || g == "Female to male" || g == "femaletomale" || g == "FemaletoMale" || g=="trans man" ||g=="trans male" || g=="Transgender man" || g=="Transgendr male" || g=="transgender man" || g=="transgender male")
	{
		gender = 3;
	}
	else if (g == "mtf" || g == "Mtf" || g == "MTF" || g == "mtw" || g == "MTW" || g == "Mtw" || g == "female to male" || g == "Male to female" || g == "Maletofemale" || g == "MaletoFemale" || g == "trans woman" || g == "trans female" || g == "trans fem" || g == "Transgender woman" || g == "Transgendr female" || g == "transgender woman" || g == "transgender female")
	{
		gender = 4;
	}
	else if (g == "intersex" || g == "Intersex" || g == "INTERSEX")
	{
		gender = 5;
	}
	else
	{
		gender = 6;
	}
}
void Medical::setAge(int a)
{
	if (a >= 0)
	{
		age = a;
	}
}
void Medical::setWeight(double w)
{
	if (w >= 0)
	{
		weight = w;
	}
}
void Medical::setHeight(double h)
{
	if (h >= 0)
	{
		height = h;
	}
}
void Medical::setBloodType(int b)
{
	if (b >= 0 && b <= 7)
	{
		bloodtype = b;
	}
}
void Medical::setBloodTypeS(string b)
{
	if (b == "O-" || b == "o-" || b == "o -" || b=="O -")
	{
		bloodtype = 0;
	}
	else if (b == "O+" || b == "o+" || b == "o +" || b == "O +")
	{
		bloodtype = 1;
	}
	else if (b == "A-" || b == "a-" || b == "a -" || b == "A -")
	{
		bloodtype = 2;
	}
	else if (b == "A+" || b == "a+" || b == "a +" || b == "A +")
	{
		bloodtype = 3;
	}
	else if (b == "B-" || b == "b-" || b == "b -" || b == "B -")
	{
		bloodtype = 4;
	}
	else if (b == "B+" || b=="b+" || b=="b +" ||b=="B +")
	{
		bloodtype = 5;
	}
	else if (b == "AB-" || b=="ab-" ||b=="ab -" ||b=="AB -")
	{
		bloodtype = 6;
	}
	else if(b=="AB+" || b=="ab+" || b=="ab +" || b=="AB +")
	{
		bloodtype = 7;
	}
}
void Medical::setBirth(Date b)
{
	birth = b;
	age = birth.age();
}
void Medical::setBirth(int d, int m, int y)
{
	birth.setDay(d);
	birth.setMonth(m);
	birth.setYear(y);
	age = birth.age();
}
void Medical::setEmergencyContact(string e)
{
	emergencycontact = e;
}
void Medical::addAllergy(string a)
{
	if (a != "")
	{
		allergies.push_back(a);
	}
}
void Medical::addHealthopserv(string h)
{
	if (h != "")
	{
		healthopserv.push_back(h);
	}
}
void Medical::addDrugTest(string d)
{
	if (d != "")
	{
		drugtest.push_back(d);
	}
}
void Medical::addPastMedicalHistory(string p)
{
	if (p != "")
	{
		pastmedicalhistory.push_back(p);
	}
}
void Medical::addChronicConditions(string c)
{
	if (c != "")
	{
		chronicconditions.push_back(c);
	}
}
void Medical::addMedications(string m)
{
	if (m != "")
	{
		medications.push_back(m);
	}
}
void Medical::addSurgeries(string s)
{
	if (s != "")
	{
		surgeries.push_back(s);
	}
}
void Medical::addFamilyHistory(string f)
{
	if (f != "")
	{
		familyhistory.push_back(f);
	}
}
void Medical::addVisitDate(Date d)
{
	visitdates.push_back(d);
}
void Medical::addVisitReason(string r)
{
	if (r != "")
	{
		visitreasons.push_back(r);
	}
}
void Medical::addVaccine(string v)
{
	if (v != "")
	{
		vaccines.push_back(v);
	}
}
void Medical::addDiagnosis(string d)
{
	if (d != "")
	{
		diagnoses.push_back(d);
	}
}
void Medical::addTreatment(string t)
{
	if (t != "")
	{
		treatments.push_back(t);
	}
}
void Medical::addPrescription(string p)
{
	if (p != "")
	{
		prescriptions.push_back(p);
	}
}
void Medical::addDoctor(string d)
{
	if (d != "")
	{
		doctor.push_back(d);
	}
}
void Medical::addLabResults(string l)
{
	if (l != "")
	{
		labresults.push_back(l);
	}
}
void Medical::addImagingResults(string i)
{
	if (i != "")
	{
		imagingresults.push_back(i);
	}
}
void Medical::setBloodPressuresistoic(int b)
{
	bloodpresurediasotic = b;
}
void Medical::setBloodPressurediatolic(int b)
{
	bloodpresurediasotic = b;
}
void Medical::setHeartRate(int h)
{
	heartrate = h;
}
void Medical::setTemperature(double t)
{
	temperature = t;
}
void Medical::setRespiratoryRate(int r)
{
	respiratoryrate = r;
}
void Medical::setOxygenLevel(double o)
{
	oxygenlevel = o;
}
void Medical::addMedicationSchedule(string m)
{
	if (m != "")
	{
		medications.push_back(m);
	}
}
void Medical::addMentalHealth(string m)
{
	if (m != "")
	{
		mentalhealth.push_back(m);
	}
}
void Medical::addPreference(string p)
{
	if (p != "")
	{
		preferences.push_back(p);
	}
}
//get
int Medical::getGender()
{
	return gender;
}
string Medical::getGenderS()
{
	switch (gender)
	{
	case 0:
		return "not specified";
		break;
	case 1:
		return "male";
		break;
	case 2:
		return "female";
		break;
	case 3:
		return "ftm";
		break;
	case 4:
		return "mtf";
		break;
	case 5:
		return "intersex";
		break;
	case 6:
		return "other";
		break;
	default:
		return "not specified";
		break;
	}
}
int Medical::getAge()
{
	return age;
}
double Medical::getWeight()
{
	return weight;

}
double Medical::getHeight()
{
	return height;

}
int Medical::getBloodType()
{
	return bloodtype;
}
string Medical::getBloodTypeS()
{
	switch (bloodtype)
	{
	case 0:
		return "O-";
		break;
	case 1:
		return "O+";
		break;
	case 2:
		return "A-";
		break;
	case 3:
		return "A+";
		break;
	case 4:
		return "B-";
		break;
	case 5:
		return "B+";
		break;
	case 6:
		return "AB-";
		break;
	case 7:
		return "AB+";
		break;
	default:
		return "O-";
		break;
	}
}
Date Medical::getBirth()
{
	return birth;
}
void Medical::getBirth(int& d, int& m, int& y)
{
	d = birth.getDay();
	m = birth.getMonth();
	y = birth.getYear();

}
string Medical::getEmergencyContact()
{
	return emergencycontact;
}
vector<string> Medical::getAllergy()
{
	return allergies;
}
vector<string> Medical::getHealthopserv()
{
	return healthopserv;
}
vector<string> Medical::getDrugTest()
{
	return drugtest;
}
vector<string> Medical::getPastMedicalHistory()
{
	return pastmedicalhistory;
}
vector<string> Medical::getChronicConditions()
{
	return chronicconditions;
}
vector<string> Medical::getMedications()
{
	return medications;
}
vector<string> Medical::getSurgeries()
{
	return surgeries;
}
vector<string> Medical::getFamilyHistory()
{
	return familyhistory;
}
vector<Date> Medical::getVisitDate()
{
	return visitdates;
}
vector<string> Medical::getVisitReason()
{
	return visitreasons;
}
vector<string> Medical::getVaccine()
{
	return vaccines;
}
vector<string> Medical::getDiagnosis()
{
	return diagnoses;
}
vector<string> Medical::getTreatment()
{
	return treatments;
}
vector<string> Medical::getPrescription()
{
	return prescriptions;
}
vector<string> Medical::getDoctor()
{
	return doctor;
}
vector<string> Medical::getLabResults()
{
	return labresults;
}
vector<string> Medical::getImagingResults()
{
	return imagingresults;
}
int Medical::getBloodPressureSistoic()
{
	return bloodpresuresistoic;
}
int Medical::getBloodPressureDiasotic()
{
	return bloodpresurediasotic;
}
int Medical::getHeartRate()
{
	return heartrate;
}
double Medical::getTemperature()
{
	return temperature;
}
int Medical::getRespiratoryRate()
{
	return respiratoryrate;
}
double Medical::getOxygenLevel()
{
	return oxygenlevel;
}
vector<string> Medical::getMedicationSchedule()
{
	return medicationschedule;
}
vector<string> Medical::getMentalHealth()
{
	return mentalhealth;
}
vector<string> Medical::getPreference()
{
	return preferences;
}

void Medical::displayImages()
{
	//open photo
	if (!imagingresults.empty())
	{
		cout << "Opening photo..." << endl;
		for (int i = 0; i < imagingresults.size(); i++)
		{
			system(("start" + imagingresults[i]).c_str());
		}
	}
	else
	{
		cout << "No photo available." << endl;
	}
}

int Medical::displayInformations()
{
	cout<<"1. Birth date"<<endl;
	cout<<"2. Age"<<endl;
	cout<<"3. Gender"<<endl;
	cout<<"4. Height"<<endl;
	cout<<"5. Weight"<<endl;
	cout<<"6. Blood type"<<endl;
	cout<<"7. Blood pressure"<<endl;
	cout<<"8. Heart rate"<<endl;
	cout<<"9. Respiratory rate"<<endl;
	cout<<"10. Oxygen level"<<endl;
	cout<<"11. Temperature"<<endl;
	cout<<"12. Emergency contact"<<endl;
	cout<<"13. Doctors"<<endl;
	cout<<"14. Visits"<<endl;
	cout<<"15. Visit reasons"<<endl;
	cout<<"16. Allergies"<<endl;
	cout<<"17. Medications"<<endl;
	cout<<"18. Medication schedule"<<endl;
	cout<<"19. Prescriptions"<<endl;
	cout<<"20. Health opservations"<<endl;
	cout<<"21. Diagnoses"<<endl;
	cout<<"22. Treatments"<<endl;
	cout<<"23. Chronic conditions"<<endl;
	cout<<"24. Mental health"<<endl;
	cout<<"25. Drug tests"<<endl;
	cout<<"26. Vaccines"<<endl;
	cout<<"27. Surgeries"<<endl;
	cout<<"28. Lab results"<<endl;
	cout<<"29. Imaging results"<<endl;
	cout<<"30. Past medical history"<<endl;
	cout<<"31. Family history"<<endl;
	cout<<"32. Preferences"<<endl;
	return 32;
}

void Medical::printHealth()
{
	cout << "Birth date: ";
	birth.printDate();
	cout<< endl;
	cout<<"Age: "<<age<<endl;
	cout << "Gender: " << getGenderS() << endl;
	cout<<"Height: "<<height<<"cm"<<endl;
	cout << "Weight: " << weight << "kg" << endl;
	cout << "Blood type: " << getBloodTypeS() << endl;
	cout << "Blood pressure: " << bloodpresuresistoic << "/" << bloodpresurediasotic << endl;
	cout << "Heart rate: " << heartrate << "bpm" << endl;
	cout << "Respiratory rate: " << respiratoryrate << "bpm" << endl;
	cout << "Oxygen level: " << oxygenlevel << "%" << endl;
	cout << "Temperature: " << temperature << "C" << endl;
	cout << "Emergency contact: " << emergencycontact << endl;
	cout << "Doctors: ";
	displaywithtab(doctor);
	cout << "Visits:" << endl;
	for (int i = 0; i < visitdates.size(); i++)
	{
		visitdates[i].printDate();
		cout << "\t Reason: " << visitreasons[i] << endl;
	}
	cout << "Allergies: ";
	displaywithtab(allergies);
	cout<<"Medications: ";
	displaywithtab(medications);
	cout << "Medication schedule: ";
	displaywithtab(medicationschedule);
	cout << "Prescriptions: ";
	displaywithtab(prescriptions);
	cout << "Health operations: ";
	displaywithtab(healthopserv);
	cout << "Diagnoses: ";
	displaywithtab(diagnoses);
	cout << "Treatments: ";
	displaywithtab(treatments);
	cout << "Chronic conditions: ";
	displaywithtab(chronicconditions);
	cout << "Mental health: ";
	displaywithtab(mentalhealth);
	cout << "Drug tests: ";
	displaywithtab(drugtest);
	cout << "Vaccines: ";
	displaywithtab(vaccines);
	cout << "Surgeries: ";
	displaywithtab(surgeries);
	cout << "Lab results: ";
	displaywithtab(labresults);
	cout << "Imaging results: ";
	displaywithtab(imagingresults);
	displayImages();
	cout << "Past medical history: ";
	displaywithtab(pastmedicalhistory);
	cout << "Family history: ";
	displaywithtab(familyhistory);
	cout << "Preferences: ";
	displaywithtab(preferences);
}

void Medical::printHealthNV()
{
	cout << "1. Birth date: ";
	birth.printDate();
	cout << endl;
	cout << "2. Age: " << age << endl;
	cout << "3. Gender: " << getGenderS() << endl;
	cout << "4. Height: " << height << "cm" << endl;
	cout << "5. Weight: " << weight << "kg" << endl;
	cout << "6. Blood type: " << getBloodTypeS() << endl;
	cout << "7. Blood pressure: " << bloodpresuresistoic << "/" << bloodpresurediasotic << endl;
	cout << "8. Heart rate: " << heartrate << "bpm" << endl;
	cout << "9. Respiratory rate: " << respiratoryrate << "bpm" << endl;
	cout << "10. Oxygen level: " << oxygenlevel << "%" << endl;
	cout << "11. Temperature: " << temperature << "C" << endl;
	cout << "12. Emergency contact: " << emergencycontact << endl;
	cout << "13. Doctors: ";
	displaywithtab(doctor);
	cout << "14. Visits /15. Reasons:" << endl;
	for (int i = 0; i < visitdates.size(); i++)
	{
		visitdates[i].printDate();
		cout << "\t Reason: " << visitreasons[i] << endl;
	}
	cout << "16. Allergies: ";
	displaywithtab(allergies);
	cout << endl;
	cout << "17. Medications: ";
	displaywithtab(medications);
	cout << endl;
	cout << "18. Medication schedule: ";
	displaywithtab(medicationschedule);
	cout << endl;
	cout << "19. Prescriptions: ";
	displaywithtab(prescriptions);
	cout << endl;
	cout << "20. Health opservations: ";
	displaywithtab(healthopserv);
	cout << endl;
	cout << "21. Diagnoses: ";
	displaywithtab(diagnoses);
	cout << endl;
	cout << "22. Treatments: ";
	displaywithtab(treatments);
	cout << endl;
	cout << "23. Chronic conditions: ";
	displaywithtab(chronicconditions);
	cout << endl;
	cout << "24. Mental health: ";
	displaywithtab(mentalhealth);
	cout << endl;
	cout << "25. Drug tests: ";
	displaywithtab(drugtest);
	cout << endl;
	cout << "26. Vaccines: ";
	displaywithtab(vaccines);
	cout << endl;
	cout << "27. Surgeries: ";
	displaywithtab(surgeries);
	cout << endl;
	cout << "28. Lab results: ";
	displaywithtab(labresults);
	cout << endl;
	cout << "29. Imaging results: ";
	displaywithtab(imagingresults);
	displayImages();
	cout << endl;
	cout << "30. Past medical history: ";
	displaywithtab(pastmedicalhistory);
	cout << endl;
	cout << "31. Family history: ";
	displaywithtab(familyhistory);
	cout << endl;
	cout << "32. Preferences: ";
	displaywithtab(preferences);
	cout << endl;
}

void Medical::displayMedicalfiltered(vector<bool>& ff)
{
	if(ff[0])
	{
		cout << "Birth date: ";
		birth.printDate();
		cout << endl;
	}
	if(ff[1])
	{
		cout << "Age: " << age << endl;
	}
	if (ff[2])
	{
		cout << "Gender: " << getGenderS() << endl;
	}
	if (ff[3])
	{
		cout << "Height: " << height << "cm" << endl;
	}
	if (ff[4])
	{
		cout << "Weight: " << weight << "kg" << endl;
	}
	if (ff[5])
	{
		cout << "Blood type: " << getBloodTypeS() << endl;
	}
	if (ff[6])
	{
		cout << "Blood pressure: " << bloodpresuresistoic << "/" << bloodpresurediasotic << endl;
	}
	if (ff[7])
	{
		cout << "Heart rate: " << heartrate << "bpm" << endl;
	}
	if (ff[8])
	{
		cout << "Respiratory rate: " << respiratoryrate << "bpm" << endl;
	}
	if (ff[9])
	{
		cout << "Oxygen level: " << oxygenlevel << "%" << endl;
	}
	if (ff[10])
	{
		cout << "Temperature: " << temperature << "C" << endl;
	}
	if (ff[11])
	{
		cout << "Emergency contact: " << emergencycontact << endl;
	}
	if (ff[12])
	{
		cout << "Doctors: ";
		displaywithtab(doctor);
	}
	if (ff[13])
	{
		cout << "Visit dates:" << endl;
		for (int i = 0; i < visitdates.size(); i++)
		{
			visitdates[i].printDate();
		}
	}
	if (ff[14])
	{
		cout << "Visit reasons: ";
		displaywithtab(visitreasons);
	}
	if (ff[15])
	{
		cout << "Allergies: ";
		displaywithtab(allergies);
	}
	if (ff[16])
	{
		cout << "Medications: ";
		displaywithtab(medications);
	}
	if (ff[17])
	{
		cout << "Medication schedule: ";
		displaywithtab(medicationschedule);
	}
	if (ff[18])
	{
		cout << "Prescriptions: ";
		displaywithtab(prescriptions);
	}
	if (ff[19])
	{
		cout << "Health operations: ";
		displaywithtab(healthopserv);
	}
	if (ff[20])
	{
		cout << "Diagnoses: ";
		displaywithtab(diagnoses);
	}
	if (ff[21])
	{
		cout << "Treatments: ";
		displaywithtab(treatments);
	}
	if (ff[22])
	{
		cout << "Chronic conditions: ";
		displaywithtab(chronicconditions);
	}
	if (ff[23])
	{
		cout << "Mental health: ";
		displaywithtab(mentalhealth);
	}
	if (ff[24])
	{
		cout << "Drug tests: ";
		displaywithtab(drugtest);
	}
	if (ff[25])
	{
		cout << "Vaccines: ";
		displaywithtab(vaccines);
	}
	if (ff[26])
	{
		cout << "Surgeries: ";
		displaywithtab(surgeries);
	}
	if (ff[27])
	{
		cout << "Lab results: ";
		displaywithtab(labresults);
	}
	if (ff[28])
	{
		cout << "Imaging results: ";
		displaywithtab(imagingresults);
		displayImages();
	}
	if (ff[29])
	{
		cout << "Past medical history: ";
		displaywithtab(pastmedicalhistory);
	}
	if (ff[30])
	{
		cout << "Family history: ";
		displaywithtab(familyhistory);
	}
	if (ff[31])
	{
		cout << "Preferences: ";
		displaywithtab(preferences);
	}
}

bool Medical::matching(Medical e)
{
	Date d;
	if(e.birth!=d && birth==d)
	{
		return false;
	}
	else if(e.birth!=d && birth!=d && e.birth!=birth)
	{
		return false;
	}
	else if(e.age!=-1 && age==-1)
	{
		return false;
	}
	else if (e.age != -1 && age != -1 && e.age != age)
	{
		return false;
	}
	else if (e.gender!=-1 && gender==-1)
	{
		return false;
	}
	else if (e.gender != -1 && gender != -1 && e.gender != gender)
	{
		return false;
	}
	else if (e.height!=-1 && height==-1)
	{
		return false;
	}
	else if (e.height != -1 && height != -1 && e.height != height)
	{
		return false;
	}
	else if (e.weight!=-1 && weight==-1)
	{
		return false;
	}
	else if (e.weight != -1 && weight != -1 && e.weight != weight)
	{
		return false;
	}
	else if (e.bloodtype!=-1 && bloodtype==-1)
	{
		return false;
	}
	else if (e.bloodtype != -1 && bloodtype != -1 && e.bloodtype != bloodtype)
	{
		return false;
	}
	else if (e.bloodpresuresistoic!=-1 && bloodpresuresistoic==-1)
	{
		return false;
	}
	else if (e.bloodpresuresistoic != -1 && bloodpresuresistoic != -1 && e.bloodpresuresistoic != bloodpresuresistoic)
	{
		return false;
	}
	else if (e.bloodpresurediasotic!=-1 && bloodpresurediasotic==-1)
	{
		return false;
	}
	else if (e.bloodpresurediasotic != -1 && bloodpresurediasotic != -1 && e.bloodpresurediasotic != bloodpresurediasotic)
	{
		return false;
	}
	else if (e.heartrate!=-1 && heartrate==-1)
	{
		return false;
	}
	else if (e.heartrate != -1 && heartrate != -1 && e.heartrate != heartrate)
	{
		return false;
	}
	else if (e.respiratoryrate!=-1 && respiratoryrate==-1)
	{
		return false;
	}
	else if (e.respiratoryrate != -1 && respiratoryrate != -1 && e.respiratoryrate != respiratoryrate)
	{
		return false;
	}
	else if (e.oxygenlevel!=-1 && oxygenlevel==-1)
	{
		return false;
	}
	else if (e.oxygenlevel != -1 && oxygenlevel != -1 && e.oxygenlevel != oxygenlevel)
	{
		return false;
	}
	else if (e.temperature!=-1 && temperature==-1)
	{
		return false;
	}
	else if (e.emergencycontact != "" && emergencycontact == "")
	{
		return false;
	}
	else if(e.emergencycontact!="" && emergencycontact!="" && e.emergencycontact!=emergencycontact)
	{
		return false;
	}
	else if (!e.doctor.empty() && doctor.empty())
	{
		return false;
	}
	else if (!e.doctor.empty() && !doctor.empty() && !isinvectorVS(e.doctor, doctor))
	{
		return false;
	}
	else if(!e.visitdates.empty() && visitdates.empty())
	{
		return false;
	}
	else if (!e.visitdates.empty() && !visitdates.empty() && !isinvectorVC(e.visitdates, visitdates))
	{
		return false;
	}
	else if(!e.visitreasons.empty() && visitreasons.empty())
	{
		return false;
	}
	else if(!e.visitreasons.empty() && !visitreasons.empty() && !isinvectorVS(e.visitreasons, visitreasons))
	{
		return false;
	}
	else if (!e.allergies.empty() && allergies.empty())
	{
		return false;
	}
	else if (!e.allergies.empty() && !allergies.empty() && !isinvectorVS(e.allergies, allergies))
	{
		return false;
	}
	else if (!e.medications.empty() && medications.empty())
	{
		return false;
	}
	else if (!e.medications.empty() && !medications.empty() && !isinvectorVS(e.medications, medications))
	{
		return false;
	}
	else if (!e.medicationschedule.empty() && medicationschedule.empty())
	{
		return false;
	}
	else if (!e.medicationschedule.empty() && !medicationschedule.empty() && !isinvectorVS(e.medicationschedule, medicationschedule))
	{
		return false;
	}
	else if (!e.prescriptions.empty() && prescriptions.empty())
	{
		return false;
	}
	else if (!e.prescriptions.empty() && !prescriptions.empty() && !isinvectorVS(e.prescriptions, prescriptions))
	{
		return false;
	}
	else if (!e.healthopserv.empty() && healthopserv.empty())
	{
		return false;
	}
	else if (!e.healthopserv.empty() && !healthopserv.empty() && !isinvectorVS(e.healthopserv, healthopserv))
	{
		return false;
	}
	else if (!e.diagnoses.empty() && diagnoses.empty())
	{
		return false;
	}
	else if (!e.diagnoses.empty() && !diagnoses.empty() && !isinvectorVS(e.diagnoses, diagnoses))
	{
		return false;
	}
	else if (!e.treatments.empty() && treatments.empty())
	{
		return false;
	}
	else if (!e.treatments.empty() && !treatments.empty() && !isinvectorVS(e.treatments, treatments))
	{
		return false;
	}
	else if (!e.chronicconditions.empty() && chronicconditions.empty())
	{
		return false;
	}
	else if (!e.chronicconditions.empty() && !chronicconditions.empty() && !isinvectorVS(e.chronicconditions, chronicconditions))
	{
		return false;
	}
	else if (!e.mentalhealth.empty() && mentalhealth.empty())
	{
		return false;
	}
	else if(!e.mentalhealth.empty() && mentalhealth.empty() && !isinvectorVS(e.mentalhealth, mentalhealth))
	{
		return false;
	}
	else if (!e.drugtest.empty() && drugtest.empty())
	{
		return false;
	}
	else if (!e.drugtest.empty() && !drugtest.empty() && !isinvectorVS(e.drugtest, drugtest))
	{
		return false;
	}
	else if (!e.vaccines.empty() && vaccines.empty())
	{
		return false;
	}
	else if (!e.vaccines.empty() && !vaccines.empty() && !isinvectorVS(e.vaccines, vaccines))
	{
		return false;
	}
	else if (!e.surgeries.empty() && surgeries.empty())
	{
		return false;
	}
	else if (!e.surgeries.empty() && !surgeries.empty() && !isinvectorVS(e.surgeries, surgeries))
	{
		return false;
	}
	else if (!e.labresults.empty() && labresults.empty())
	{
		return false;
	}
	else if (!e.labresults.empty() && !labresults.empty() && !isinvectorVS(e.labresults, labresults))
	{
		return false;
	}
	else if (!e.imagingresults.empty() && imagingresults.empty())
	{
		return false;
	}
	else if (!e.imagingresults.empty() && !imagingresults.empty() && !isinvectorVS(e.imagingresults, imagingresults))
	{
		return false;
	}
	else if (!e.pastmedicalhistory.empty() && pastmedicalhistory.empty())
	{
		return false;
	}
	else if (!e.pastmedicalhistory.empty() && !pastmedicalhistory.empty() && !isinvectorVS(e.pastmedicalhistory, pastmedicalhistory))
	{
		return false;
	}
	else if (!e.familyhistory.empty() && familyhistory.empty())
	{
		return false;
	}
	else if (!e.familyhistory.empty() && !familyhistory.empty() && !isinvectorVS(e.familyhistory, familyhistory))
	{
		return false;
	}
	else if (!e.preferences.empty() && preferences.empty())
	{
		return false;
	}
	else if (!e.preferences.empty() && !preferences.empty() && !isinvectorVS(e.preferences, preferences))
	{
		return false;
	}
	return true;
}

void Medical::editMedical()
{
	cout << "1. Edit birth date: " << birth << endl;
	cout<<"2. Edit Gender: "<<getGenderS()<<endl;
	cout<<"3. Edit Height: "<<height<<"cm"<<endl;
	cout<<"4. Edit Weight: "<<weight<<"kg"<<endl;
	cout<<"5. Edit Blood type: "<<getBloodTypeS()<<endl;
	cout<<"6. Edit Blood pressure: "<<bloodpresuresistoic<<"/"<<bloodpresurediasotic<<endl;
	cout<<"7. Edit Heart rate: "<<heartrate<<"bpm"<<endl;
	cout<<"8. Edit Respiratory rate: "<<respiratoryrate<<"bpm"<<endl;
	cout<<"9. Edit Oxygen level: "<<oxygenlevel<<"%"<<endl;
	cout<<"10. Edit Temperature: "<<temperature<<"C"<<endl;
	cout<<"11. Edit Emergency contact: "<<emergencycontact<<endl;
	cout<<"12. Add Doctors: ";
	displaywithtab(doctor);
	cout << endl;
	cout<<"13. Remove a doctor"<<endl;
	cout<<"14. Add Visits: "<<endl;
	for(int i=0;i<visitdates.size();i++)
	{
		cout<<visitdates[i]<<"\t Reason: "<<visitreasons[i]<<endl;
	}
	cout<<"15. Remove a visit"<<endl;
	cout<<"16. Add Allergies: ";
	displaywithtab(allergies);
	cout << endl;
	cout<<"17. Remove an allergy"<<endl;
	cout<<"18. Add Medications: ";
	displaywithtab(medications);
	cout << endl;
	cout<<"19. Remove a medication"<<endl;
	cout<<"20. Add Medication schedule: ";
	displaywithtab(medicationschedule);
	cout << endl;
	cout<<"21. Remove a medication schedule"<<endl;
	cout<<"22. Add Prescriptions: ";
	displaywithtab(prescriptions);
	cout << endl;
	cout<<"23. Remove a prescription"<<endl;
	cout<<"24. Add Health opservations: ";
	displaywithtab(healthopserv);
	cout << endl;
	cout<<"25. Remove a health opservation"<<endl;
	cout<<"26. Add Diagnoses: ";
	displaywithtab(diagnoses);
	cout << endl;
	cout<<"27. Remove a diagnosis"<<endl;
	cout<<"28. Add Treatments: ";
	displaywithtab(treatments);
	cout << endl;
	cout<<"29. Remove a treatment"<<endl;
	cout<<"30. Add Chronic conditions: ";
	displaywithtab(chronicconditions);
	cout << endl;
	cout<<"31. Remove a chronic condition"<<endl;
	cout<<"32. Add Mental health: ";
	displaywithtab(mentalhealth);
	cout << endl;
	cout<<"33. Remove a mental health"<<endl;
	cout<<"34. Add Drug tests: ";
	displaywithtab(drugtest);
	cout << endl;
	cout<<"35. Remove a drug test"<<endl;
	cout<<"36. Add Vaccines: ";
	displaywithtab(vaccines);
	cout << endl;
	cout<<"37. Remove a vaccine"<<endl;
	cout<<"38. Add Surgeries: ";
	displaywithtab(surgeries);
	cout << endl;
	cout<<"39. Remove a surgery"<<endl;
	cout<<"40. Add Lab results: ";
	displaywithtab(labresults);
	cout << endl;
	cout<<"41. Remove a lab result"<<endl;
	cout<<"42. Add Imaging results: ";
	displaywithtab(imagingresults);
	cout << endl;
	cout<<"43. Remove an imaging result"<<endl;
	cout<<"44. Add Past medical history: ";
	displaywithtab(pastmedicalhistory);
	cout << endl;
	cout<<"45. Remove a past medical history"<<endl;
	cout<<"46. Add Family history: ";
	displaywithtab(familyhistory);
	cout << endl;
	cout<<"47. Remove a family history"<<endl;
	cout<<"48. Add Preferences: ";
	displaywithtab(preferences);
	cout << endl;
	cout<<"49. Remove a preference"<<endl;
	cout<<"0. Exit"<<endl;

	bool ok = true;
	while (ok)
	{
		int a = getanumber("Enter the number of option: ");
		if (a < 0 || a>49)
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
			case 1:
			{
				cout << "Please enter birth date: ";
				int d = getanumber("Day: ");
				int m = getanumber("Month: ");
				int y = getanumber("Year: ");
				setBirth(Date(d, m, y));
				break;
			}
			case 2:
			{
				cout << "Please enter gender: ";
				string s;
				cin >> s;
				setGenderS(s);
				break;
			}
			case 3:
			{
				double w=getanumberD("Please enter height: ");
				setHeight(w);
				break;
			}
			case 4:
			{
				double w=getanumberD("Please enter weight: ");
				setWeight(w);
				break;
			}
			case 5:
			{
				cout << "Please enter blood type: ";
				string s;
				cin >> s;
				setBloodTypeS(s);
				break;
			}
			case 6:
			{
				int w = getanumber("Please enter blood pressure sistoic: ");
				int b = getanumber("Please enter blood pressure diatolic: ");
				setBloodPressuresistoic(w);
				setBloodPressurediatolic(w);
				break;
			}
			case 7:
			{
				int w = getanumber("Please enter heart rate: ");
				setHeartRate(w);
				break;
			}
			case 8:
			{
				int w = getanumber("Please enter respiratory rate: ");
				setRespiratoryRate(w);
				break;
			}
			case 9:
			{
				double w=getanumberD("Please enter oxygen level: ");
				setOxygenLevel(w);
				break;
			}
			case 10:
			{
				double w=getanumberD("Please enter temperature: ");
				setTemperature(w);
				break;
			}
			case 11:
			{
				cout << "Please enter emergency contact: ";
				string s;
				getline(cin, s);
				setEmergencyContact(s);
				break;
			}
			case 12:
			{
				cout << "Please add a doctor: ";
				string s;
				getline(cin, s);
				addDoctor(s);
				break;
			}
			case 13:
			{
				cout<<"Doctors: ";
				displaywithtab(doctor);
				cout << endl;
				cout << "Enter which doctor you would want to remove (1-" << doctor.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>doctor.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(doctor[w-1],doctor);
				break;
			}
			case 14:
			{
				cout << "Please enter visit date: ";
				int d = getanumber("Day: ");
				int m = getanumber("Month: ");
				int y = getanumber("Year: ");
				addVisitDate(Date(d, m, y));
				cout << "Please enter visit reason: ";
				string s;
				getline(cin, s);
				addVisitReason(s);
				break;
			}
			case 15:
			{
				cout << "Visits:" << endl;
				for (int i = 0; i < visitdates.size(); i++)
				{
					visitdates[i].printDate();
					cout << "\t Reason: " << visitreasons[i] << endl;
				}
				cout << "Enter which visit you would want to remove (1-" << visitdates.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>visitdates.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorC(visitdates[w - 1], visitdates);
				removefromvectorS(visitreasons[w - 1], visitreasons);
				break;
			}
			case 16:
			{
				cout << "Please enter allergy: ";
				string s;
				getline(cin, s);
				addAllergy(s);
				break;
			}
			case 17:
			{
				cout << "Allergies: ";
				displaywithtab(allergies);
				cout << endl;
				cout << "Enter which allergy you would want to remove (1-" << allergies.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>allergies.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(allergies[w - 1], allergies);
				break;
			}
			case 18:
			{
				cout << "Please enter medication:" << endl;
				string s;
				getline(cin, s);
				addMedications(s);
				break;
			}
			case 19:
			{
				cout << "Medications: ";
				displaywithtab(medications);
				cout << endl;
				cout << "Enter which medication you would want to remove (1-" << medications.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>medications.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(medications[w - 1], medications);
				break;
			}
			case 20:
			{
				cout << "Please enter medication schedule: ";
				string s;
				getline(cin, s);
				addMedicationSchedule(s);
				break;
			}
			case 21:
			{
				cout << "Medication schedule: ";
				displaywithtab(medicationschedule);
				cout << endl;
				cout << "Enter which medication schedule you would want to remove (1-" << medicationschedule.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>medicationschedule.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(medicationschedule[w - 1], medicationschedule);
				break;
			}
			case 22:
			{
				cout << "Please enter prescription: ";
				string s;
				getline(cin, s);
				addPrescription(s);
				break;
			}
			case 23:
			{
				cout << "Prescriptions: ";
				displaywithtab(prescriptions);
				cout << endl;
				cout << "Enter which prescription you would want to remove (1-" << prescriptions.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>prescriptions.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(prescriptions[w - 1], prescriptions);
				break;
			}
			case 24:
			{
				cout << "Please enter health observation: ";
				string s;
				getline(cin, s);
				addHealthopserv(s);
				break;
			}
			case 25:
			{
				cout << "Health opservations: ";
				displaywithtab(healthopserv);
				cout << endl;
				cout << "Enter which health opservation you would want to remove (1-" << healthopserv.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>healthopserv.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(healthopserv[w - 1], healthopserv);
				break;
			}
			case 26:
			{
				cout << "Please enter diagones: ";
				string s;
				getline(cin, s);
				addDiagnosis(s);
				break;
			}
			case 27:
			{
				cout << "Diagnoses: ";
				displaywithtab(diagnoses);
				cout << endl;
				cout << "Enter which diagnosis you would want to remove (1-" << diagnoses.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>diagnoses.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(diagnoses[w - 1], diagnoses);
				break;
			}
			case 28:
			{
				cout << "Please enter treatment: ";
				string s;
				getline(cin, s);
				addTreatment(s);
				break;
			}
			case 29:
			{
				cout << "Treatments: ";
				displaywithtab(treatments);
				cout << endl;
				cout << "Enter which treatment you would want to remove (1-" << treatments.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>treatments.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(treatments[w - 1], treatments);
				break;
			}
			case 30:
			{
				cout << "Please enter chronic condition: ";
				string s;
				getline(cin, s);
				addChronicConditions(s);
				break;
			}
			case 31:
			{
				cout << "Chronic conditions: ";
				displaywithtab(chronicconditions);
				cout << endl;
				cout << "Enter which chronic condition you would want to remove (1-" << chronicconditions.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>chronicconditions.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(chronicconditions[w - 1], chronicconditions);
				break;
			}
			case 32:
			{
				cout << "Please enter mental health ";
				string s;
				getline(cin, s);
				addMentalHealth(s);
				break;
			}
			case 33:
			{
				cout << "Mental health: ";
				displaywithtab(mentalhealth);
				cout << endl;
				cout << "Enter which mental health you would want to remove (1-" << mentalhealth.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>mentalhealth.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(mentalhealth[w - 1], mentalhealth);
				break;
			}
			case 34:
			{
				cout << "Please enter drug test: ";
				string s;
				getline(cin, s);
				addDrugTest(s);
				break;
			}
			case 35:
			{
				cout << "Drug tests: ";
				displaywithtab(drugtest);
				cout << endl;
				cout << "Enter which drug test you would want to remove (1-" << drugtest.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>drugtest.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(drugtest[w - 1], drugtest);
				break;
			}
			case 36:
			{
				cout << "Please enter vaccine: ";
				string s;
				getline(cin, s);
				addVaccine(s);
				break;
			}
			case 37:
			{
				cout << "Vaccines: ";
				displaywithtab(vaccines);
				cout << endl;
				cout << "Enter which vaccine you would want to remove (1-" << vaccines.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>vaccines.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(vaccines[w - 1], vaccines);
				break;
			}
			case 38:
			{
				cout << "Please enter surgery: ";
				string s;
				getline(cin, s);
				addSurgeries(s);
				break;
			}
			case 39:
			{
				cout << "Surgeries: ";
				displaywithtab(surgeries);
				cout << endl;
				cout << "Enter which surgery you would want to remove (1-" << surgeries.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>surgeries.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(surgeries[w - 1], surgeries);
				break;
			}
			case 40:
			{
				cout << "Please enter laboratory result: ";
				string s;
				getline(cin, s);
				addLabResults(s);
				break;
			}
			case 41:
			{
				cout << "Lab results: ";
				displaywithtab(labresults);
				cout << endl;
				cout << "Enter which lab result you would want to remove (1-" << labresults.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>labresults.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(labresults[w - 1], labresults);
				break;
			}
			case 42:
			{
				cout << "Please enter imaging result: ";
				string s;
				getline(cin, s);
				addImagingResults(s);
				break;
			}
			case 43:
			{
				cout << "Imaging results: ";
				displaywithtab(imagingresults);
				cout << endl;
				cout << "Enter which imaging result you would want to remove (1-" << imagingresults.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>imagingresults.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(imagingresults[w - 1], imagingresults);
				break;
			}
			case 44:
			{
				cout << "Please enter past medical history: ";
				string s;
				getline(cin, s);
				addPastMedicalHistory(s);
				break;
			}
			case 45:
			{
				cout << "Past medical history: ";
				displaywithtab(pastmedicalhistory);
				cout << endl;
				cout << "Enter which past medical history you would want to remove (1-" << pastmedicalhistory.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>pastmedicalhistory.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(pastmedicalhistory[w - 1], pastmedicalhistory);
				break;
			}
			case 46:
			{
				cout << "Please enter family history: ";
				string s;
				getline(cin, s);
				addFamilyHistory(s);
				break;
			}
			case 47:
			{
				cout << "Family history: ";
				displaywithtab(familyhistory);
				cout << endl;
				cout << "Enter which family history you would want to remove (1-" << familyhistory.size() << "): ";
				bool ok2 = true;
				int w;
				while (ok2)
				{
					w = getanumber("");
					if (w < 1 || w>familyhistory.size())
					{
						cout << "Invalid input" << endl;
					}
					else
					{
						ok2 = false;
					}
				}
				removefromvectorS(familyhistory[w - 1], familyhistory);
				break;
			}
			case 48:
			{
				cout << "Please enter preference: ";
				string s;
				getline(cin, s);
				addPreference(s);
				break;
			}
			case 49:
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
			default:
				break;
			}
			clearconsol();
			editMedical();
		}
	}
}