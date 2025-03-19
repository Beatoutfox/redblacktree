#include "Controls.h"

Employee add_employee(const string& filename)
{
	Employee e;
	ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Unable to open file for reading " << endl;
		return e;
	}


	int hd, hm, hy;
	int bd, bm, by;
	int vd, vm, vy;
	Medical medical;
	int gender, bloodtype, bloodpresuresistoic, bloodpresurediasotic, heartrate, respiratoryrate;
	double height, weight, oxygenlevel, temperature;
	string emergencycontact;
	string doctor, visitreasons, allergies, medications, medicationschedule, prescriptions, healthopserv, diagnoses, treatments, chronicconditions, mentalhealth, drugtest, vaccines, surgeries, labresults, imagingresults, pastmedicalhistory, familyhistory, mpreferences;
	int id, employmnttype, vacationdays, maritalstatus, kids;
	double salary, salaryperhour, hours, overtime, bonus;
	string name, position, department, supervisor, code, nickname, nationality, phone, email, address;
	string benefits, skills, trainings, certifications, projects, publications, memberships, awards, references, backgroundcheck, languages, education, preferences, photos;
	int pr;
	string performancereviews;
	int bo;
	vector<bool> clearance(CLRLN);

	string line;
	string nr;
	while (getline(file, line))
	{
		istringstream iss(line);
		iss >> nr;
		if (nr == "1.")
		{
			iss >> id;
			e.setId(id);
		}
		else if (nr == "2.")
		{
			iss.ignore();
			getline(iss, name);
			e.setName(name);
		}
		else if (nr == "3.")
		{
			iss.ignore();
			getline(iss, position);
			e.setPosition(position);
		}
		else if (nr == "4.")
		{
			for (int i = 0; i < CLRLN; i++)
			{
				iss >> bo;
				e.setClearance(i, bo);
			}
		}
		else if (nr == "5.")
		{
			iss.ignore(); getline(iss, department);
			e.setDepartment(department);
		}
		else if (nr == "6.")
		{
			iss.ignore(); getline(iss, supervisor);
			e.setSupervisor(supervisor);
		}
		else if (nr == "7.")
		{
			iss >> employmnttype;
			e.setEmploymnttype(employmnttype);
		}
		else if (nr == "8.")
		{
			iss >> salary;
			e.setSalary(salary);
		}
		else if (nr == "9.")
		{
			iss >> salaryperhour;
			e.setSalaryperhour(salaryperhour);
		}
		else if (nr == "10.")
		{
			iss >> hours;
			e.setHours(hours);
		}
		else if (nr == "11.")
		{
			iss >> overtime;
			e.setOvertime(overtime);
		}
		else if (nr == "12.")
		{
			iss >> bonus;
			e.setBonus(bonus);
		}
		else if (nr == "13.")
		{
			iss >> hd >> hm >> hy;
			e.setHiredate(Date(hd, hm, hy));
		}
		else if (nr == "14.")
		{
			iss >> vacationdays;
			e.setVacationdays(vacationdays);
		}
		else if (nr == "15.")
		{
			iss.ignore(); getline(iss, benefits);
			e.addBenefit(benefits);
		}
		else if (nr == "16.")
		{
			iss.ignore(); getline(iss, skills);
			e.addSkill(skills);
		}
		else if (nr == "17.")
		{
			iss.ignore(); getline(iss, trainings);
			e.addTraining(trainings);
		}
		else if (nr == "18.")
		{
			iss.ignore(); getline(iss, certifications);
			e.addCertification(certifications);
		}
		else if (nr == "19.")
		{
			iss.ignore(); getline(iss, projects);
			e.addProject(projects);
		}
		else if (nr == "20.")
		{
			iss.ignore(); getline(iss, publications);
			e.addPublication(publications);
		}
		else if (nr == "21.")
		{
			iss.ignore(); getline(iss, memberships);
			e.addMembership(memberships);
		}
		else if (nr == "22.")
		{
			iss.ignore(); getline(iss, awards);
			e.addAward(awards);
		}
		else if (nr == "23.")
		{
			iss >> pr;
			iss.ignore(); getline(iss, performancereviews);
			e.addPerformancereview(pr, performancereviews);
		}
		else if (nr == "24.")
		{
			iss.ignore(); getline(iss, references);
			e.addReference(references);
		}
		else if (nr == "25.")
		{
			iss.ignore(); getline(iss, backgroundcheck);
			e.addBackgroundcheck(backgroundcheck);
		}
		else if (nr == "26.")
		{
			iss.ignore(); getline(iss, code);
			e.setCode(code);
		}
		else if (nr == "27.")//birthdate
		{
			iss >> bd >> bm >> by;
			medical.setBirth(Date(bd, bm, by));
		}
		else if (nr == "28.")//gender
		{
			iss >> gender;
			medical.setGender(gender);
		}
		else if (nr == "29.")
		{
			iss >> height;
			medical.setHeight(height);
		}
		else if (nr == "30.")
		{
			iss >> weight;
			medical.setWeight(weight);
		}
		else if (nr == "31.")
		{
			iss >> bloodtype;
			medical.setBloodType(bloodtype);
		}
		else if (nr == "32.")
		{
			iss >> bloodpresuresistoic >> bloodpresurediasotic;
			medical.setBloodPressuresistoic(bloodpresuresistoic);
			medical.setBloodPressurediatolic(bloodpresurediasotic);
		}
		else if (nr == "33.")
		{
			iss >> heartrate;
			medical.setHeartRate(heartrate);
		}
		else if (nr == "34.")
		{
			iss >> respiratoryrate;
			medical.setRespiratoryRate(respiratoryrate);
		}
		else if (nr == "35.")
		{
			iss >> oxygenlevel;
			medical.setOxygenLevel(oxygenlevel);
		}
		else if (nr == "36.")
		{
			iss >> temperature;
			medical.setTemperature(temperature);
		}
		else if (nr == "37.")
		{
			iss.ignore(); getline(iss, emergencycontact);
			medical.setEmergencyContact(emergencycontact);
		}
		else if (nr == "38.")
		{
			iss.ignore(); getline(iss, doctor);
			medical.addDoctor(doctor);
		}
		else if (nr == "39.")
		{
			iss >> vd >> vm >> vy;
			iss.ignore(); getline(iss, visitreasons);
			medical.addVisitDate(Date(vd, vm, vy));
			medical.addVisitReason(visitreasons);

		}
		else if (nr == "40.")
		{
			iss.ignore(); getline(iss, allergies);
			medical.addAllergy(allergies);
		}
		else if (nr == "41.")
		{
			iss.ignore(); getline(iss, medications);
			medical.addMedications(medications);
		}
		else if (nr == "42.")
		{
			iss.ignore(); getline(iss, medicationschedule);
			medical.addMedicationSchedule(medicationschedule);
		}
		else if (nr == "43.")
		{
			iss.ignore(); getline(iss, prescriptions);
			medical.addPrescription(prescriptions);
		}
		else if (nr == "44.")
		{
			iss.ignore(); getline(iss, healthopserv);
			medical.addHealthopserv(healthopserv);
		}
		else if (nr == "45.")
		{
			iss.ignore(); getline(iss, diagnoses);
			medical.addDiagnosis(diagnoses);

		}
		else if (nr == "46.")
		{
			iss.ignore(); getline(iss, treatments);
			medical.addTreatment(treatments);
		}
		else if (nr == "47.")
		{
			iss.ignore(); getline(iss, chronicconditions);
			medical.addChronicConditions(chronicconditions);
		}
		else if (nr == "48.")
		{
			iss.ignore(); getline(iss, mentalhealth);
			medical.addMentalHealth(mentalhealth);
		}
		else if (nr == "49.")
		{
			iss.ignore(); getline(iss, drugtest);
			medical.addDrugTest(drugtest);
		}
		else if (nr == "50.")
		{
			iss.ignore(); getline(iss, vaccines);
			medical.addVaccine(vaccines);
		}
		else if (nr == "51.")
		{
			iss.ignore(); getline(iss, surgeries);
			medical.addSurgeries(surgeries);
		}
		else if (nr == "52.")
		{
			iss.ignore(); getline(iss, labresults);
			medical.addLabResults(labresults);
		}
		else if (nr == "53.")
		{
			iss.ignore(); getline(iss, imagingresults);
			medical.addImagingResults(imagingresults);
		}
		else if (nr == "54.")
		{
			iss.ignore(); getline(iss, pastmedicalhistory);
			medical.addPastMedicalHistory(pastmedicalhistory);
		}
		else if (nr == "55.")
		{
			iss.ignore(); getline(iss, familyhistory);
			medical.addFamilyHistory(familyhistory);
		}
		else if (nr == "56.")
		{
			iss.ignore(); getline(iss, mpreferences);
			medical.addPreference(mpreferences);
		}
		else if (nr == "57.")
		{
			iss.ignore(); getline(iss, nickname);
			e.setNickname(nickname);
		}
		else if (nr == "58.")
		{
			iss >> maritalstatus;
			e.setMaritalstatus(maritalstatus);
		}
		else if (nr == "59.")
		{
			iss >> kids;
			e.setKids(kids);
		}
		else if (nr == "60.")
		{
			iss.ignore(); getline(iss, nationality);
			e.setNationality(nationality);
		}
		else if (nr == "61.")
		{
			iss.ignore(); getline(iss, languages);
			e.addLanguage(languages);
		}
		else if (nr == "62.")
		{
			iss.ignore(); getline(iss, education);
			e.addEducation(education);
		}
		else if (nr == "63.")
		{
			iss.ignore(); getline(iss, preferences);
			e.addPreference(preferences);
		}
		else if (nr == "64.")
		{
			iss.ignore(); getline(iss, phone);
			e.setPhone(phone);
		}
		else if (nr == "65.")
		{
			iss.ignore(); getline(iss, email);
			e.setEmail(email);
		}
		else if (nr == "66.")
		{
			iss.ignore(); getline(iss, address);
			e.setAddress(address);
		}
		else if (nr == "67.")
		{
			iss.ignore(); getline(iss, photos);
			e.addPhoto(photos);
		}
	}
	e.setHealth(medical);
	file.close();
	return e;
}


RedBlackTree<Employee> add_companys_data(const string& filename)
{
	RedBlackTree<Employee> company;
	ifstream file(filename);
	if (file.is_open())
	{
		string name;
		while (file >> name)
		{
			company.insertN(add_employee(name));
		}
		file.close();
	}
	else
	{
		cerr << "Unable to open file for reading: charactersheets.txt" << endl;
	}
	return company;
}


void startprogram()
{
	string cp = "comp1.txt";
	RedBlackTree<Employee> compani=add_companys_data(cp);
	console(compani);
}

void console(RedBlackTree<Employee>&c)
{
	cout << "Welcome to our companies Database" << endl;
	cout << "Please select an option:" << endl;
	cout << "1. Login" << endl;
	cout << "2. Exit" << endl;
	int a = getanumber("> ");
	switch (a)
	{
	case 1:
		login(c);
		break;
	case 2:
		cout << "Goodbye" << endl;
		exit(0);
		break;
	default:
		clearconsol();
		console(c);
	}
}

void error_at_login()
{
	cout << "Error at login" << endl;
	cout << "Please try again" << endl;
	cout << "Press any key to continue" << endl;
	cin.get();
	clearconsol();
}

void login(RedBlackTree<Employee>&c)
{
	cout<<"Please enter your id number: ";
	int id;
	cin >> id;
	cout << "Please enter your code: ";
	string code;
	cin >> code;
	Elem<Employee>* e=nullptr;
	if (existing_person(id,code,c,e) && e!=nullptr)
	{
		clearconsol();
		cout << endl<<"Welcome to the system " << e->info.getName() << endl;
		decidewhattoshow(e,c);
	}
	else
	{
		error_at_login();
		login(c);
	}
}

bool existing_person(int i, string a,RedBlackTree<Employee>&c,Elem<Employee>* &e)
{
	e = c.searchN(Employee(i));
	if (e!=c.getnil() && e->info.getCode() == a)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void decidewhattoshow(Elem<Employee>* &e,RedBlackTree<Employee>&c)
{
	cout<< "Please select what to do:" << endl;
	vector<bool>cl;
	e->info.getClearance(cl);
	int n = 1;
	if(cl[0])
	{
		cout <<n <<". View personal infos" << endl;
		n++;
	}
	if(cl[1])
	{
		cout <<n <<". View medical infos of employees" << endl;
		n++;
	}
	if(cl[2])
	{
		cout <<n <<". View contact infos of employees" << endl;
		n++;
	}
	if(cl[3])
	{
		cout <<n <<". View employment infos of employees" << endl;
		n++;
	}
	if(cl[4])
	{
		cout <<n <<". View performance and skill infos of employees" << endl;
		n++;
	}
	if(cl[5])
	{
		cout <<n <<". View security infos of employees" << endl;
		n++;
	}
	if(cl[6])
	{
		cout <<n <<". View all infos of employees" << endl;
		n++;
	}
	if(cl[7])
	{
		cout <<n <<". Edit information of employees" << endl;
		n++;
	}
	cout <<"0. Exit" << endl;
	cout << "> ";
	int a = getanumber("");
	if(a>=n || a<0)
	{
		cout << "Invalid input" << endl;
		cout<<"Press any key to continue" << endl;
		cin.get();
		clearconsol();
		decidewhattoshow(e,c);
	}
	else
	{
		clearconsol();
		if (a == 0)
		{
			console(c);
		}
		else if (a == 1 && rethowmanyTtoI(cl,0)==1)
		{
			showpersonal(e,c);
		}
		else if (cl[1] && ((a == 2 && rethowmanyTtoI(cl,1)==2) || (a==1 && rethowmanyTtoI(cl,1)==0)))
		{
			showmedical(e,c);
		}
		else if (cl[2] && ((a == 3 && rethowmanyTtoI(cl,2)==3) || (a == 2 && rethowmanyTtoI(cl,2)==2) || (a == 1 && rethowmanyTtoI(cl,2)==1)))
		{
			showcontact(e, c);
		}
		else if (cl[3] && ( (a == 4 && rethowmanyTtoI(cl, 3) == 4) || (a == 3 && rethowmanyTtoI(cl, 3) == 3) || (a == 2 && rethowmanyTtoI(cl, 3) == 2) || (a == 1 && rethowmanyTtoI(cl, 3) == 1)))
		{
			showemployment(e, c);
		}
		else if (cl[4] && ((a==5 && rethowmanyTtoI(cl, 4) == 5) || (a == 4 && rethowmanyTtoI(cl, 4) == 4) || (a == 3 && rethowmanyTtoI(cl, 4) == 3) || (a == 2 && rethowmanyTtoI(cl, 4) == 2) || (a == 1 && rethowmanyTtoI(cl, 4) == 1)))
		{
			showperformance(e, c);
		}
		else if (cl[5] && ((a == 6 && rethowmanyTtoI(cl, 5) == 6) || (a == 5 && rethowmanyTtoI(cl, 5) == 5) || (a == 4 && rethowmanyTtoI(cl, 5) ==4) || (a == 3 && rethowmanyTtoI(cl, 5) == 3) || (a == 2 && rethowmanyTtoI(cl, 5) == 2) || (a == 1 && rethowmanyTtoI(cl, 5) == 1)))
		{
			showsecurity(e, c);
		}
		else if (cl[6] && ((a == 7 && rethowmanyTtoI(cl, 6) == 7) || (a == 6 && rethowmanyTtoI(cl, 6) == 6) || (a == 5 && rethowmanyTtoI(cl, 6) == 5) || (a == 4 && rethowmanyTtoI(cl, 6) == 4) || (a == 3 && rethowmanyTtoI(cl, 6) == 3) || (a == 2 && rethowmanyTtoI(cl, 6) == 2) || (a == 1 && rethowmanyTtoI(cl, 6) == 1)))

		{
			showall(e, c);
		}
		else if (cl[7] && ((a == 8 && rethowmanyTtoI(cl, 7) == 8) || (a == 7 && rethowmanyTtoI(cl, 7) == 7) || (a == 6 && rethowmanyTtoI(cl, 7) == 6) || (a == 5 && rethowmanyTtoI(cl, 7) == 5) || (a == 4 && rethowmanyTtoI(cl, 7) == 4) || (a == 3 && rethowmanyTtoI(cl, 7) == 3) || (a == 2 && rethowmanyTtoI(cl, 7) == 2) || (a == 1 && rethowmanyTtoI(cl, 7) == 1)))
		{
			showadmin(e,c);
		}
	}
}

void showpersonal(Elem<Employee>* &e, RedBlackTree<Employee>&c)
{
	cout<< "1. Show personal info" << endl;
	cout << "2. Edit personal info" << endl;
	cout<<"3. Edit password" << endl;
	cout<<"0. Exit" << endl;
	cout<<"> ";
	int a;
	cin >> a;
	switch (a)
	{
		case 1:
		{
			clearconsol();
			e->info.display0();
			cout << "Press p to go to previus page" << endl;
			bool ok = true;;
			while (ok)
			{
				char c;
				cin >> c;
				if (c == 'p')
				{
					ok = false;
				}
			}
			clearconsol();
			showpersonal(e, c);
		}
		case 2:
		{
			clearconsol();
			e->info.editpersonal();
			clearconsol();
			showpersonal(e, c);
		}
		case 3:
		{
			clearconsol();
			e->info.editpassword();
			cout << "Press p to go to previus page" << endl;
			bool ok = true;;
			while (ok)
			{
				char c;
				cin >> c;
				if (c == 'p')
				{
					ok = false;
				}
			}
			clearconsol();
			showpersonal(e, c);
		}
		case 0:
		{
			clearconsol();
			decidewhattoshow(e, c);
		}
		default:
		{
			cout << "Invalid input" << endl;
			clearconsol();
			showpersonal(e, c);
		}
	}
}

void showmedical(Elem<Employee>* &e,RedBlackTree<Employee>&c)
{
	cout<<"1. Show medical info of an employee" << endl;
	cout << "2. Edit medical info of an employee" << endl;
	cout<<"3. Show medical info of all employees" << endl;
	cout<<"4. Filter medical info of employees" << endl;
	cout<<"5. Filter employees by medical info" << endl;
	cout<<"0. Exit" << endl;
	cout<<"> ";
	int a;
	cin >> a;
	switch (a)
	{
		case 1:
		{
			cout << "Please enter the id of the employee: ";
			int id;
			cin >> id;
			Elem<Employee>* e2 = c.searchN(Employee(id));
			if (e2 != nullptr)
			{
				clearconsol();
				e2->info.displaymedical();
				cout << endl;
				cout<<"Press p to go to previus page" << endl;
				bool ok = true;;
				while(ok)
				{
					char c;
					cin >> c;
					if (c == 'p')
					{
						ok = false;
					
					}
				}
				showmedical(e,c);
			}
			else
			{
				cout << "Employee not found" << endl;
				clearconsol();
				showmedical(e, c);
			}

		}
		case 2:
		{
			cout << "Please enter the id of the employee: ";
			int id;
			cin >> id;
			Elem<Employee>* e2 = c.searchN(Employee(id));
			if (e2 != nullptr)
			{
				clearconsol();
				e2->info.editmedical();
				clearconsol();
				showmedical(e, c);
			}
			else
			{
				cout << "Employee not found" << endl;
				clearconsol();
				showmedical(e, c);
			}
		}
		case 3:
		{
			clearconsol();
			c.inorder(4);
			cout << "Press p to go to previus page" << endl;
			bool ok = true;;
			while (ok)
			{
				char c;
				cin >> c;
				if (c == 'p')
				{
					ok = false;

				}
			}
			clearconsol();
			showmedical(e, c);
		}
		case 4:
		{
			cout<<"You can filter by: "<<endl;
			int h=e->info.getHealth().displayInformations();
			bool ok = true;
			vector<bool>ff(h,false);
			
			while (ok)
			{
				int a=getanumber("Please enter the number of the filters or 0 if you dont want to choose other filters : ");
				if(a<0 || a>h)
				{
					cout << "Invalid input" << endl;
				}
				else if (a == 0)
				{
					ok = false;
				}
				else
				{
					ff[a-1] = true;
				}
			}
			clearconsol();
			c.inorder(1,ff);
			clearconsol();
			showmedical(e, c);
		}
		case 5:
		{
			cout << "You can filter by: " << endl;
			int h = e->info.getHealth().displayInformations();
			bool ok = true;
			Employee dummy;
			while (ok)
			{
				int a = getanumber("Please enter the number of the filter: ");
				if (a < 0 || a>h)
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
						dummy.getHealth().setBirth(Date(d, m, y));
						break;
					}
					case 2:
					{
						int w = getanumber("Please enter age: ");
						dummy.getHealth().setAge(w);
						break;
					}
					case 3:
					{
						cout<<"Please enter gender: ";
						string s;
						cin >> s;
						dummy.getHealth().setGenderS(s);
						break;
					}
					case 4:
					{
						double w=getanumberD("Please enter height: ");
						dummy.getHealth().setHeight(w);
						break;
					}
					case 5:
					{
						double w = getanumberD("Please enter weight: ");
						dummy.getHealth().setWeight(w);
						break;
					}
					case 6:
					{
						cout << "Please enter blood type: ";
						string s;
						cin >> s;
						dummy.getHealth().setBloodTypeS(s);
						break;
					}
					case 7:
					{
						int w = getanumber("Please enter blood pressure sistoic: ");
						int b = getanumber("Please enter blood pressure diatolic: ");
						dummy.getHealth().setBloodPressuresistoic(w);
						dummy.getHealth().setBloodPressurediatolic(w);
						break;
					}
					case 8:
					{
						int w = getanumber("Please enter heart rate: ");
						dummy.getHealth().setHeartRate(w);
						break;
					}
					case 9:
					{
						int w = getanumber("Please enter respiratory rate: ");
						dummy.getHealth().setRespiratoryRate(w);
						break;
					}
					case 10:
					{
						double w = getanumberD("Please enter oxygen level: ");
						dummy.getHealth().setOxygenLevel(w);
						break;
					}
					case 11:
					{
						double w = getanumberD("Please enter temperature: ");
						dummy.getHealth().setTemperature(w);
						break;
					}
					case 12:
					{
						cout << "Please enter emergency contact: ";
						string s;
						getline(cin,s);
						dummy.getHealth().setEmergencyContact(s);
						break;
					}
					case 13:
					{
						cout<<"Please enter a doctor: ";
						string s;
						getline(cin,s);
						dummy.getHealth().addDoctor(s);
						break;
					}
					case 14:
					{
						cout << "Please enter visit date: ";
						int d = getanumber("Day: ");
						int m = getanumber("Month: ");
						int y = getanumber("Year: ");
						dummy.getHealth().addVisitDate(Date(d, m, y));
						break;
					}
					case 15:
					{
						cout << "Please enter visit reason: ";
						string s;
						getline(cin,s);
						dummy.getHealth().addVisitReason(s);
						break;
					}
					case 16:
					{
						cout << "Please enter allergy: ";
						string s;
						getline(cin,s);
						dummy.getHealth().addAllergy(s);
						break;
					}
					case 17:
					{
						cout << "Please enter medication:" << endl;
						string s;
						getline(cin,s);
						dummy.getHealth().addMedications(s);
						break;
					}
					case 18:
					{
						cout << "Please enter medication schedule: ";
						string s;
						getline(cin, s);
						dummy.getHealth().addMedicationSchedule(s);
						break;
					}
					case 19:
					{
						cout << "Please enter prescription: ";
						string s;
						getline(cin,s);
						dummy.getHealth().addPrescription(s);
						break;
					}
					case 20:
					{
						cout << "Please enter health observation: ";
						string s;
						getline(cin, s);
						dummy.getHealth().addHealthopserv(s);
						break;
					}
					case 21:
					{
						cout << "Please enter diagones: ";
						string s;
						getline(cin,s);
						dummy.getHealth().addDiagnosis(s);
						break;
					}
					case 22:
					{
						cout << "Please enter treatment: ";
						string s;
						getline(cin, s);
						dummy.getHealth().addTreatment(s);
						break;
					}
					case 23:
					{
						cout << "Please enter chronic condition: ";
						string s;
						getline(cin, s);
						dummy.getHealth().addChronicConditions(s);
						break;
					}
					case 24:
					{
						cout << "Please enter mental health ";
						string s;
						getline(cin, s);
						dummy.getHealth().addMentalHealth(s);
						break;
					}
					case 25:
					{
						cout << "Please enter drug test: ";
						string s;
						getline(cin,s);
						dummy.getHealth().addDrugTest(s);
						break;
					}
					case 26:
					{
						cout << "Please enter vaccine: ";
						string s;
						getline(cin,s);
						dummy.getHealth().addVaccine(s);
						break;
					}
					case 27:
					{
						cout << "Please enter surgery: ";
						string s;
						getline(cin,s);
						dummy.getHealth().addSurgeries(s);
						break;
					}
					case 28:
					{
						cout << "Please enter laboratory result: ";
						string s;
						getline(cin,s);
						dummy.getHealth().addLabResults(s);
						break;
					}
					case 29:
					{
						cout << "Please enter imaging result: ";
						string s;
						getline(cin,s);
						dummy.getHealth().addImagingResults(s);
						break;
					}
					case 30:
					{
						cout << "Please enter past medical history: ";
						string s;
						getline(cin,s);
						dummy.getHealth().addPastMedicalHistory(s);
						break;
					}
					case 31:
					{
						cout << "Please enter family history: ";
						string s;
						getline(cin,s);
						dummy.getHealth().addFamilyHistory(s);
						break;
					}
					case 32:
					{
						cout << "Please enter medication preferences: ";
						string s;
						getline(cin, s);
						dummy.getHealth().addPreference(s);
						break;
					}
					default:
						break;
					}
				}
			}
			vector<Elem<Employee>*>v=c.filter(1, dummy);
			clearconsol();
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->info.displaybasic();
			}
			cout << "Press p to go to previus page" << endl;
			bool ok2 = true;;
			while (ok2)
			{
				char c;
				cin >> c;
				if (c == 'p')
				{
					ok2 = false;
				}
			}
			clearconsol();
			showmedical(e, c);
		}
		case 0:
		{
			clearconsol();
			decidewhattoshow(e, c);
		}
		default:
		{
			cout << "Invalid input" << endl;
			clearconsol();
			showmedical(e, c);
		}
	}
}

void showemployment(Elem<Employee>* &e, RedBlackTree<Employee>&c)
{
	cout << "1. Show employment info of an employee" << endl;
	cout << "2. Edit employment info of an employee" << endl;
	cout << "3. Show employment info of all employees" << endl;
	cout << "4. Filter employment info of employees" << endl;
	cout << "5. Filter employees by employment info" << endl;
	cout << "0. Exit" << endl;
	cout << "> ";
	int a;
	cin >> a;
	switch (a)
	{
	case 1:
	{
		cout << "Please enter the id of the employee: ";
		int id;
		cin >> id;
		Elem<Employee>* e2 = c.searchN(Employee(id));
		if (e2 != nullptr)
		{
			clearconsol();
			e2->info.displayemployment();
			cout << endl;
			cout << "Press p to go to previus page" << endl;
			bool ok = true;;
			while (ok)
			{
				char c;
				cin >> c;
				if (c == 'p')
				{
					ok = false;

				}
			}
			showemployment(e, c);
		}
		else
		{
			cout << "Employee not found" << endl;
			clearconsol();
			showemployment(e, c);
		}

	}
	case 2:
	{
		cout << "Please enter the id of the employee: ";
		int id;
		cin >> id;
		Elem<Employee>* e2 = c.searchN(Employee(id));
		if (e2 != nullptr)
		{
			clearconsol();
			e2->info.editemployment();
			clearconsol();
			showemployment(e, c);
		}
		else
		{
			cout << "Employee not found" << endl;
			clearconsol();
			showemployment(e, c);
		}
	}
	case 3:
	{
		clearconsol();
		c.inorder(3);
		cout << "Press p to go to previus page" << endl;
		bool ok = true;;
		while (ok)
		{
			char c;
			cin >> c;
			if (c == 'p')
			{
				ok = false;

			}
		}
		clearconsol();
		showemployment(e, c);
	}
	case 4:
	{
		cout << "You can filter by: " << endl;
		int h = e->info.displayemploymentN();
		bool ok = true;
		vector<bool>ff(h, false);

		while (ok)
		{
			int a = getanumber("Please enter the number of the filters or 0 if you dont want to choose other filters : ");
			if (a<0 || a>h)
			{
				cout << "Invalid input" << endl;
			}
			else if (a == 0)
			{
				ok = false;
			}
			else
			{
				ff[a - 1] = true;
			}
		}
		clearconsol();
		c.inorder(2, ff);
		clearconsol();
		showemployment(e, c);
	}
	case 5:
	{
		cout << "You can filter by: " << endl;
		int h = e->info.displayemploymentN();
		bool ok = true;
		Employee dummy;
		while (ok)
		{
			int a = getanumber("Please enter the number of the filter: ");
			if (a < 0 || a>h)
			{
				cout << "Invalid input" << endl;
			}
			else if (a == 0)
			{
				ok = false;
			}
			else
			{
				Employee dummy;
				switch (a)
				{
					case 1:
					{
						cout<< "Please enter position: ";
						string s;
						getline(cin,s);
						dummy.setPosition(s);
						break;
					}
					case 2:
					{
						cout<<"Plase enter department: ";
						string s;
						getline(cin,s);
						dummy.setDepartment(s);
						break;
					}
					case 3:
					{
						cout << "Please enter supervisor: ";
						string s;
						getline(cin,s);
						dummy.setSupervisor(s);
						break;
					}
					case 4:
					{
						cout<<"Please enter employment type: ";
						string s;
						getline(cin,s);
						dummy.setEmploymnttypeS(s);
						break;
					}
					case 5:
					{
						double a = getanumberD("Please enter salary: ");
						dummy.setSalary(a);
						break;
					}
					case 6:
					{
						double a = getanumberD("Please enter salary per hour: ");
						dummy.setSalaryperhour(a);
						break;
					}
					case 7:
					{
						double a = getanumberD("Please enter hours worked: ");
						dummy.setHours(a);
						break;
					}
					case 8:
					{
						double a = getanumberD("Please enter overtime: ");
						dummy.setOvertime(a);
						break;
					}
					case 9:
					{
						double a = getanumberD("Please enter bonus: ");
						dummy.setBonus(a);
						break;
					}
					case 10:
					{
						int a = getanumber("Please enter vacantion days: ");
						dummy.setVacationdays(a);
						break;
					}
					case 11:
					{
						cout << "Please enter hire date: ";
						int d = getanumber("Day: ");
						int m = getanumber("Month: ");
						int y = getanumber("Year: ");
						dummy.setHiredate(Date(d, m, y));
						break;
					}
					case 12:
					{
						cout << "Please enter benefits: ";
						string s;
						getline(cin,s);
						dummy.addBenefit(s);
						break;
					}
					case 13:
					{
						double w = getanumberD("Please enter payment: ");
						dummy.setPayment(w);
						break;
					}
				default:
					break;
				}
			}
		}
		vector<Elem<Employee>*>v = c.filter(2, dummy);
		clearconsol();
		for (int i = 0; i < v.size(); i++)
		{
			v[i]->info.displaybasic();
		}
		cout << "Press p to go to previus page" << endl;
		bool ok2 = true;;
		while (ok2)
		{
			char c;
			cin >> c;
			if (c == 'p')
			{
				ok2 = false;

			}
		}
		clearconsol();
		showemployment(e, c);
	}
	case 0:
	{
		clearconsol();
		decidewhattoshow(e, c);
	}
	default:
	{
		cout << "Invalid input" << endl;
		clearconsol();
		showemployment(e, c);
	}
	}
}

void showperformance(Elem<Employee>* &e, RedBlackTree<Employee>&c)
{
	cout << "1. Show skill and performance infos of an employee" << endl;
	cout << "2. Edit skill info of an employee" << endl;
	cout << "3. Add performance review of an employee" << endl;
	cout << "4. Show skill and performance info of all employees" << endl;
	cout << "5. Filter skill info of employees" << endl;
	cout << "6. Filter employees by skill info" << endl;
	cout << "0. Exit" << endl;
	cout << "> ";
	int a;
	cin >> a;
	switch (a)
	{
	case 1:
	{
		cout << "Please enter the id of the employee: ";
		int id;
		cin >> id;
		Elem<Employee>* e2 = c.searchN(Employee(id));
		if (e2 != nullptr)
		{
			clearconsol();
			e2->info.displayskills();
			e2->info.displayperformance();
			cout << endl;
			cout << "Press p to go to previus page" << endl;
			bool ok = true;;
			while (ok)
			{
				char c;
				cin >> c;
				if (c == 'p')
				{
					ok = false;

				}
			}
			showperformance(e, c);
		}
		else
		{
			cout << "Employee not found" << endl;
			clearconsol();
			showperformance(e, c);
		}

	}
	case 2:
	{
		cout << "Please enter the id of the employee: ";
		int id;
		cin >> id;
		Elem<Employee>* e2 = c.searchN(Employee(id));
		if (e2 != nullptr)
		{
			clearconsol();
			e2->info.editskills();
			clearconsol();
			showperformance(e, c);
		}
		else
		{
			cout << "Employee not found" << endl;
			clearconsol();
			showperformance(e, c);
		}
	}
	case 3:
	{
		cout << "Please enter the id of the employee: ";
		int id;
		cin >> id;
		Elem<Employee>* e2 = c.searchN(Employee(id));
		if (e2 != nullptr)
		{
			clearconsol();
			cout << "Please enter the performance review for employee " << e2->info.getId() << " " << e2->info.getName() << endl;
			string s;
			getline(cin, s);
			e2->info.addPerformancereview(e->info.getId(),s);
			cout << endl;
			cout << "Press p to go to previus page" << endl;
			bool ok = true;;
			while (ok)
			{
				char c;
				cin >> c;
				if (c == 'p')
				{
					ok = false;

				}
			}
			showperformance(e, c);
		}
		else
		{
			cout << "Employee not found" << endl;
			clearconsol();
			showperformance(e, c);
		}
	

	}
	case 4:
	{
		clearconsol();
		c.inorder(5);
		cout << "Press p to go to previus page" << endl;
		bool ok = true;;
		while (ok)
		{
			char c;
			cin >> c;
			if (c == 'p')
			{
				ok = false;

			}
		}
		clearconsol();
		showperformance(e, c);
	}
	case 5:
	{
		cout << "You can filter by: " << endl;
		int h = e->info.displayskillsN();
		bool ok = true;
		vector<bool>ff(h, false);

		while (ok)
		{
			int a = getanumber("Please enter the number of the filters or 0 if you dont want to choose other filters : ");
			if (a<0 || a>h)
			{
				cout << "Invalid input" << endl;
			}
			else if (a == 0)
			{
				ok = false;
			}
			else
			{
				ff[a - 1] = true;
			}
		}
		clearconsol();
		c.inorder(3, ff);
		clearconsol();
		showperformance(e, c);
	}
	case 6:
	{
		cout << "You can filter by: " << endl;
		int h = e->info.displayskillsN();
		bool ok = true;
		Employee dummy;
		while (ok)
		{
			int a = getanumber("Please enter the number of the filter: ");
			if (a < 0 || a>h)
			{
				cout << "Invalid input" << endl;
			}
			else if (a == 0)
			{
				ok = false;
			}
			else
			{
				Employee dummy;
				switch (a)
				{
					case 1:
				{
					cout << "Please enter skill: ";
					string s;
					getline(cin, s);
					dummy.addSkill(s);
					break;
				}
				case 2:
				{
					cout<<"Please enter tarining: ";
					string s;
					getline(cin,s);
					dummy.addTraining(s);
					break;
				}
				case 3:
				{
					cout << "Please enter certification: ";
					string s;
					getline(cin, s);
					dummy.addCertification(s);
					break;
				}
				case 4:
				{
					cout<<"Please enter project: ";
					string s;
					getline(cin,s);
					dummy.addProject(s);
					break;
				}
				case 5:
				{
					cout<<"Please enter publication: ";
					string s;
					getline(cin,s);
					dummy.addPublication(s);
					break;
				}
				case 6:
				{
					cout<<"Please enter membership: ";
					string s;
					getline(cin,s);
					dummy.addMembership(s);
					break;
				}
				case 7:
				{
					cout<<"Please enter award: ";
					string s;
					getline(cin,s);
					dummy.addAward(s);
					break;
				}
				default:
					break;
				}
			}
		}
		vector<Elem<Employee>*>v = c.filter(3, dummy);
		clearconsol();
		for (int i = 0; i < v.size(); i++)
		{
			v[i]->info.displaybasic();
		}
		cout << "Press p to go to previus page" << endl;
		bool ok2 = true;;
		while (ok2)
		{
			char c;
			cin >> c;
			if (c == 'p')
			{
				ok2 = false;

			}
		}
		clearconsol();
		showperformance(e, c);
	}
	case 0:
	{
		clearconsol();
		decidewhattoshow(e, c);
	}
	default:
	{
		cout << "Invalid input" << endl;
		clearconsol();
		showperformance(e, c);
	}
	}
}

void showsecurity(Elem<Employee>* &e, RedBlackTree<Employee>&c)
{
	cout << "1. Show security info of an employee" << endl;
	cout << "2. Edit security info of an employee" << endl;
	cout << "3. Show security info of all employees" << endl;
	cout << "4. Filter security info of employees" << endl;
	cout << "5. Filter employees by security info" << endl;
	cout << "0. Exit" << endl;
	cout << "> ";
	int a;
	cin >> a;
	switch (a)
	{
	case 1:
	{
		cout << "Please enter the id of the employee: ";
		int id;
		cin >> id;
		Elem<Employee>* e2 = c.searchN(Employee(id));
		if (e2 != nullptr)
		{
			clearconsol();
			e2->info.displaysecurity();
			e2->info.printclearance();
			clearconsol();
			showsecurity(e, c);
		}
		else
		{
			cout << "Employee not found" << endl;
			clearconsol();
			showsecurity(e, c);
		}

	}
	case 2:
	{
		cout << "Please enter the id of the employee: ";
		int id;
		cin >> id;
		Elem<Employee>* e2 = c.searchN(Employee(id));
		if (e2 != nullptr)
		{
			clearconsol();
			e2->info.editsecurity();
			clearconsol();
			showsecurity(e, c);
		}
		else
		{
			cout << "Employee not found" << endl;
			clearconsol();
			showsecurity(e, c);
		}
	}
	case 3://show security info of all employees
	{
		clearconsol();
		c.inorder(6);
		cout << "Press p to go to previus page" << endl;
		bool ok = true;;
		while (ok)
		{
			char c;
			cin >> c;
			if (c == 'p')
			{
				ok = false;

			}
		}
		clearconsol();
		showsecurity(e, c);
	}
	case 4:
	{
		cout << "You can filter by: " << endl;
		int h = e->info.displaysecurityN();
		bool ok = true;
		vector<bool>ff(h, false);

		while (ok)
		{
			int a = getanumber("Please enter the number of the filters or 0 if you dont want to choose other filters : ");
			if (a<0 || a>h)
			{
				cout << "Invalid input" << endl;
			}
			else if (a == 0)
			{
				ok = false;
			}
			else
			{
				ff[a - 1] = true;
			}
		}
		clearconsol();
		c.inorder(6, ff);
		clearconsol();
		showsecurity(e, c);
	}
	case 5:
	{
		cout<<"You can filter by the clearance levels "<<endl;
		Elem<Employee>dummy;
		cout << "Please enter the clearance levels of the employee: " << endl;
		for (int i = 0; i < CLRLN; i++)
		{
			cout << "Please enter 1 if the employee has clearance level " << i << " or 0 if he doesnt: ";
			int a;
			cin >> a;
			if (a == 1)
			{
				dummy.info.setClearance(i, true);
			}
			else
			{
				dummy.info.setClearance(i, false);
			}
		}
		vector<Elem<Employee>*>v = c.filter(5, dummy);
		clearconsol();
		for (int i = 0; i < v.size(); i++)
		{
			v[i]->info.displaybasic();
		}
		cout << "Press p to go to previus page" << endl;
		bool ok2 = true;;
		while (ok2)
		{
			char c;
			cin >> c;
			if (c == 'p')
			{
				ok2 = false;

			}
		}
		clearconsol();
		showsecurity(e, c);
	}
	case 0:
	{
		clearconsol();
		decidewhattoshow(e, c);
	}
	default:
	{
		cout << "Invalid input" << endl;
		clearconsol();
		showsecurity(e, c);
	}
	}
	clearconsol();
	showsecurity(e,c);
}

void showcontact(Elem<Employee>* &e, RedBlackTree<Employee>& c)
{
	cout << "1. Show contact info of an employee" << endl;
	cout << "2. Edit contact info of an employee" << endl;
	cout << "3. Show contact info of all employees" << endl;
	cout << "4. Filter contact info of employees" << endl;
	cout << "0. Exit" << endl;
	cout << "> ";
	int a;
	cin >> a;
	switch (a)
	{
		case 1:
		{
			cout << "Please enter the id of the employee: ";
			int id;
			cin >> id;
			Elem<Employee>* e2 = c.searchN(Employee(id));
			if (e2 != nullptr)
			{
				clearconsol();
				e2->info.displaycontact();
				clearconsol();
				showcontact(e, c);
			}
			else
			{
				cout << "Employee not found" << endl;
				clearconsol();
				showcontact(e, c);
			}
			break;
		}
		case 2:
		{
			cout << "Please enter the id of the employee: ";
			int id;
			cin >> id;
			Elem<Employee>* e2 = c.searchN(Employee(id));
			if (e2 != nullptr)
			{
				clearconsol();
				e2->info.editcontact();
				cout << endl;
				cout << "Press p to go to previus page" << endl;
				bool ok = true;;
				while (ok)
				{
					char c;
					cin >> c;
					if (c == 'p')
					{
						ok = false;

					}
				}
				showcontact(e, c);
			}
			else
			{
				cout << "Employee not found" << endl;
				clearconsol();
				showcontact(e, c);
			}
		}
	case 3:
	{
		clearconsol();
		c.inorder(8);
		cout << "Press p to go to previus page" << endl;
		bool ok = true;;
		while (ok)
		{
			char c;
			cin >> c;
			if (c == 'p')
			{
				ok = false;

			}
		}
		clearconsol();
		showcontact(e, c);
	}
	case 4:
	{
		cout << "You can filter by: " << endl;
		int h = e->info.displaycontactN();
		bool ok = true;
		vector<bool>ff(h, false);
		while (ok)
		{
			int a = getanumber("Please enter the number of the filters or 0 if you dont want to choose other filters : ");
			if (a<0 || a>h)
			{
				cout << "Invalid input" << endl;
			}
			else if (a == 0)
			{
				ok = false;
			}
			else
			{
				ff[a - 1] = true;
			}
		}
		clearconsol();
		c.inorder(4, ff);
		clearconsol();
		showcontact(e, c);
	}
	case 0:
	{
		clearconsol();
		decidewhattoshow(e, c);
	}
	default:
	{
		cout << "Invalid input" << endl;
		clearconsol();
		showcontact(e, c);
	}
	}
	clearconsol();
	showcontact(e, c);
}

void showall(Elem<Employee>* &e, RedBlackTree<Employee>&c)
{
	cout<<"1. Show all info of an employee"<<endl;
	cout<<"2. Show all info of all employees"<<endl;
	cout<<"3. Filter info to show"<<endl;
	cout << "4. Filter employees by all info" << endl;
	cout<<"0. Exit"<<endl;
	cout<<"> ";
	int a;
	cin>>a;
	switch (a)
	{
	case 1:
	{
		cout << "Please enter the id of the employee: ";
		int id;
		cin >> id;
		Elem<Employee>* e2 = c.searchN(Employee(id));
		if (e2 != nullptr)
		{
			clearconsol();
			e2->info.displayall();
			cout << endl;
			cout << "Press p to go to previus page" << endl;
			bool ok = true;;
			while (ok)
			{
				char c;
				cin >> c;
				if (c == 'p')
				{
					ok = false;

				}
			}
			showall(e, c);
		}
		else
		{
			cout << "Employee not found" << endl;
			clearconsol();
			showall(e, c);
		}
		break;
	}
	case 2:
	{
		clearconsol();
		c.inorder(10);
		cout << "Press p to go to previus page" << endl;
		bool ok = true;;
		while (ok)
		{
			char c;
			cin >> c;
			if (c == 'p')
			{
				ok = false;

			}
		}
		clearconsol();
		showall(e, c);
	}
	case 3:
	{
		cout << "You can filter by: " << endl;
		int h = e->info.displayallN();
		vector<bool>ff(h, false);
		bool ok = true;
		while (ok)
		{
			int a = getanumber("Please enter the number of the filter: ");
			if (a < 0 || a>h)
			{
				cout << "Invalid input" << endl;
			}
			else if (a == 0)
			{
				ok = false;
			}
			else
			{
				ff[a - 1] = true;
			}
		}
		clearconsol();
		c.inorder(7, ff);
		clearconsol();
		showall(e, c);
	}
	case 4:
	{
		cout << "You can filter by: " << endl;
		int h = e->info.displayallN();
		bool ok = true;
		Employee dummy;
		Medical hea;
		while (ok)
		{
			int a = getanumber("Please enter the number of the filter: ");
			if (a < 0 || a>h)
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
					cout << "Please enter id: ";
					int w = getanumber("Please enter id: ");
					dummy.setId(w);
					break;
				}
				case 2:
				{
					cout << "Please enter name: ";
					string s;
					getline(cin, s);
					dummy.setName(s);
					break;
				}
				case 3:
				{
					cout << "Please enter nicknam: ";
					string s;
					getline(cin, s);
					dummy.setNickname(s);
					break;
				}
				case 4:
				{
					cout << "Please enter clearnace level: ";
					for (int i = 0; i < CLRLN; i++)
					{
						cout << "Please enter 1 if the employee has clearance level " << i << " or 0 if he doesnt: ";
						int a;
						cin >> a;
						if (a == 1)
						{
							dummy.setClearance(i, true);
						}
						else
						{
							dummy.setClearance(i, false);
						}
					}
					break;
				}
				case 5:
				{
					cout << "Please enter position: ";
					string s;
					getline(cin, s);
					dummy.setPosition(s);
					break;
				}
				case 6:
				{
					cout << "Please enter department: ";
					string s;
					getline(cin, s);
					dummy.setDepartment(s);
					break;
				}
				case 7:
				{
					cout << "Please enter supervisor: ";
					string s;
					getline(cin, s);
					dummy.setSupervisor(s);
					break;
				}
				case 8:
				{
					cout << "Please enter employment type: ";
					string s;
					getline(cin, s);
					dummy.setEmploymnttypeS(s);
					break;
				}
				case 9:
				{
					double w = getanumberD("Please enter salary: ");
					dummy.setSalary(w);
					break;
				}
				case 10:
				{
					double w = getanumberD("Please enter salary per hour: ");
					dummy.setSalaryperhour(w);
					break;
				}
				case 11:
				{
					double w = getanumberD("Please enter hours worked: ");
					dummy.setHours(w);
					break;
				}
				case 12:
				{
					double w = getanumberD("Please enter overtime: ");
					dummy.setOvertime(w);
					break;
				}
				case 13:
				{
					double w = getanumberD("Please enter bonus: ");
					dummy.setBonus(w);
					break;
				}
				case 14:
				{
					int w = getanumber("Please enter vacantion days: ");
					dummy.setVacationdays(w);
					break;
				}
				case 15:
				{
					cout << "Please enter hire date: ";
					int d = getanumber("Day: ");
					int m = getanumber("Month: ");
					int y = getanumber("Year: ");
					dummy.setHiredate(Date(d, m, y));
					break;
				}
				case 16:
				{
					cout << "Please enter benefits: ";
					string s;
					getline(cin, s);
					dummy.addBenefit(s);
					break;
				}
				case 17:
				{
					double w = getanumberD("Please enter payment: ");
					dummy.setPayment(w);
					break;
				}
				case 18:
				{
					cout << "Pleas enter phone number: ";
					string s;
					getline(cin, s);
					dummy.setPhone(s);
					break;
				}
				case 19:
				{
					cout << "Please enter email: ";
					string s;
					getline(cin, s);
					dummy.setEmail(s);
					break;
				}
				case 20:
				{
					cout << "Please enter address: ";
					string s;
					getline(cin, s);
					dummy.setAddress(s);
					break;
				}
				case 21:
				{
					cout << "Please enter birthday: ";
					int d = getanumber("Day: ");
					int m = getanumber("Month: ");
					int y = getanumber("Year: ");
					dummy.getHealth().setBirth(Date(d, m, y));
					break;
				}
				case 22:
				{
					cout << "Please enter age: ";
					int w = getanumber("Please enter age: ");
					hea.setAge(w);
					break;
				}
				case 23:
				{
					cout << "Please enter height: ";
					double w = getanumberD("Please enter height: ");
					hea.setHeight(w);
				}
				case 24:
				{
					cout << "Please enter weight: ";
					double w = getanumberD("Please enter weight: ");
					hea.setWeight(w);
					break;
				}
				case 25:
				{
					cout << "Please enter blood type: ";
					string s;
					getline(cin, s);
					hea.setBloodTypeS(s);
					break;
				}
				case 26:
				{
					cout << "Plase enter blood pressure: ";
					int w = getanumber("Please enter blood pressure sistoic: ");
					hea.setBloodPressurediatolic(w);
					w = getanumber("Please enter blood pressure diastolic: ");
					hea.setBloodPressurediatolic(w);
					break;
				}
				case 27:
				{
					cout << "Please enter heart rate: ";
					int w = getanumber("Please enter heart rate: ");
					hea.setHeartRate(w);
					break;
				}
				case 28:
				{
					cout << "Please enter respiratory rate: ";
					int w = getanumber("Please enter respiratory rate: ");
					hea.setRespiratoryRate(w);
					break;
				}
				case 29:
				{
					cout << "Please enter oxygen level: ";
					int w = getanumber("Please enter oxygen level: ");
					hea.setOxygenLevel(w);
					break;
				}
				case 30:
				{
					cout << "Please enter temperature: ";
					double w = getanumberD("Please enter temperature: ");
					hea.setTemperature(w);
					break;
				}
				case 31:
				{
					cout << "Please enter emergncy contact: ";
					string s;
					getline(cin, s);
					hea.setEmergencyContact(s);
					break;
				}
				case 32:
				{
					cout << "Please add a doctor: ";
					string s;
					getline(cin, s);
					hea.addDoctor(s);
				}
				case 33:
				{
					cout << "Please enter a doctor: ";
					string s;
					getline(cin, s);
					hea.addDoctor(s);
					break;
				}
				case 34:
				{
					cout << "Please enter visit date: ";
					int d = getanumber("Day: ");
					int m = getanumber("Month: ");
					int y = getanumber("Year: ");
					hea.addVisitDate(Date(d, m, y));
					break;
				}
				case 35:
				{
					cout << "Please enter visit reason: ";
					string s;
					getline(cin, s);
					hea.addVisitReason(s);
					break;
				}
				case 36:
				{
					cout << "Please enter allergy: ";
					string s;
					getline(cin, s);
					hea.addAllergy(s);
					break;
				}
				case 37:
				{
					cout << "Please enter medication:" << endl;
					string s;
					getline(cin, s);
					hea.addMedications(s);
					break;
				}
				case 38:
				{
					cout << "Please enter medication schedule: ";
					string s;
					getline(cin, s);
					hea.addMedicationSchedule(s);
					break;
				}
				case 39:
				{
					cout << "Please enter prescription: ";
					string s;
					getline(cin, s);
					hea.addPrescription(s);
					break;
				}
				case 40:
				{
					cout << "Please enter health observation: ";
					string s;
					getline(cin, s);
					hea.addHealthopserv(s);
					break;
				}
				case 41:
				{
					cout << "Please enter diagones: ";
					string s;
					getline(cin, s);
					hea.addDiagnosis(s);
					break;
				}
				case 42:
				{
					cout << "Please enter treatment: ";
					string s;
					getline(cin, s);
					hea.addTreatment(s);
					break;
				}
				case 43:
				{
					cout << "Please enter chronic condition: ";
					string s;
					getline(cin, s);
					hea.addChronicConditions(s);
					break;
				}
				case 44:
				{
					cout << "Please enter mental health ";
					string s;
					getline(cin, s);
					hea.addMentalHealth(s);
					break;
				}
				case 45:
				{
					cout << "Please enter drug test: ";
					string s;
					getline(cin, s);
					hea.addDrugTest(s);
					break;
				}
				case 46:
				{
					cout << "Please enter vaccine: ";
					string s;
					getline(cin, s);
					hea.addVaccine(s);
					break;
				}
				case 47:
				{
					cout << "Please enter surgery: ";
					string s;
					getline(cin, s);
					hea.addSurgeries(s);
					break;
				}
				case 48:
				{
					cout << "Please enter laboratory result: ";
					string s;
					getline(cin, s);
					hea.addLabResults(s);
					break;
				}
				case 49:
				{
					cout << "Please enter imaging result: ";
					string s;
					getline(cin, s);
					hea.addImagingResults(s);
					break;
				}
				case 50:
				{
					cout << "Please enter past medical history: ";
					string s;
					getline(cin, s);
					hea.addPastMedicalHistory(s);
					break;
				}
				case 51:
				{
					cout << "Please enter family history: ";
					string s;
					getline(cin, s);
					hea.addFamilyHistory(s);
					break;
				}
				case 52:
				{
					cout << "Please enter medication preferences: ";
					string s;
					getline(cin, s);
					hea.addPreference(s);
					break;
				}
				case 53:
				{
					cout<<"Please enter marital status: ";
					string s;
					getline(cin,s);
					dummy.setMaritalstatusS(s);
					break;
				}
				case 54:
				{
					cout<<"Please enter number of kids: ";
					int w = getanumber("Please enter number of kids: ");
					dummy.setKids(w);
					break;
				}
				case 55:
				{
					cout<<"Please enter nationality: ";
					string s;
					getline(cin,s);
					dummy.setNationality(s);
					break;
				}
				case 56:
				{
					cout << "Please enter a known language : ";
					string s;
					getline(cin, s);
					dummy.addLanguage(s);
					break;
				}
				case 57:
				{
					cout << "Please enter education : ";
					string s;
					getline(cin, s);
					dummy.addEducation(s);
					break;
				}
				case 58:
				{
					cout << "Please enter personal prference: ";
					string s;
					getline(cin, s);
					dummy.addPreference(s);
					break;
				}
				case 59:
				{
					cout << "Please enter a skill : ";
					string s;
					getline(cin, s);
					dummy.addSkill(s);
					break;
				}
				case 60:
				{
					cout << "Please enter a training : ";
					string s;
					getline(cin, s);
					dummy.addTraining(s);
					break;
				}
				case 61:
				{
					cout << "Please enter a certification : ";
					string s;
					getline(cin, s);
					dummy.addCertification(s);
					break;
				}
				case 62:
				{
					cout << "Please enter a project : ";
					string s;
					getline(cin, s);
					dummy.addProject(s);
					break;
				}
				case 63:
				{
					cout << "Please enter a publication : ";
					string s;
					getline(cin, s);
					dummy.addPublication(s);
					break;
				}
				case 64:
				{
					cout << "Please enter a membership : ";
					string s;
					getline(cin, s);
					dummy.addMembership(s);
					break;
				}
				case 65:
				{
					cout << "Please enter an award : ";
					string s;
					getline(cin, s);
					dummy.addAward(s);
					break;
				}
				case 66:
				{
					cout << "Please enter performance review: ";
					string s;
					getline(cin, s);
					dummy.addPerformancereview(e->info.getId(), s);
					break;
				}
				case 67:
				{
					cout<<"Plrase enter a reference: ";
					string s;
					getline(cin,s);
					dummy.addReference(s);
					break;
				}
				case 68:
				{
					cout<<"Please enter a background check: ";
					string s;
					getline(cin,s);
					dummy.addBackgroundcheck(s);
					break;
				}
				case 69:
				{
					cout<<"Please enter a photo: ";
					string s;
					getline(cin,s);
					dummy.addPhoto(s);
					break;
				}
				default:
					break;
				}
			}
		}
		dummy.setHealth(hea);
		vector<Elem<Employee>*>v = c.filter(2, dummy);
		clearconsol();
		for (int i = 0; i < v.size(); i++)
		{
			v[i]->info.displaybasic();
		}
		cout << "Press p to go to previus page" << endl;
		bool ok2 = true;;
		while (ok2)
		{
			char c;
			cin >> c;
			if (c == 'p')
			{
				ok2 = false;

			}
		}
		clearconsol();
		showall(e, c);
		}
	case 0:
	{
		clearconsol();
		decidewhattoshow(e, c);
	}
	default:
	{
		cout << "Invalid input" << endl;
		clearconsol();
		showall(e, c);
	}
	}
}

void showadmin(Elem<Employee>*& e,RedBlackTree<Employee>&c)
{
	cout<<"1. Edit info of an employee"<<endl;
	cout<<"2. Add an employee"<<endl;
	cout<<"3. Remove an employee"<<endl;
	cout<<"4. Edit passwords"<<endl;
	cout<<"0. Exit"<<endl;
	cout<<"> ";
	int a=getanumber("Please enter the number of the option: ");
	switch (a)
	{
		case 1:
		{
			int id = getanumber("Please enter the id of the employee: ");
			Elem<Employee>* e2 = c.searchN(Employee(id));
			if (e2 != nullptr)
			{
				clearconsol();
				e2->info.editall();

			}
			else
			{
				cout << "Employee not found" << endl;
				cout<<"Press any key to continue"<<endl;
				char s;
				cin>>s;
			}
			clearconsol();
			showadmin(e,c);
			break;
		}
		case 2:
		{
			clearconsol();
			int id = getanumber("Please enter the id numbr of the new employee: ");
			Elem<Employee>* e2 = c.searchN(Employee(id));
			
			if (e2 ==c.getnil())
			{
				Employee e3;
				e3.setId(id);
				string s;
				cout<<"Please enter the password of the employee: ";
				getline(cin,s);
				e3.setCode(s);
				c.insertN(e3);
				cout << "Employee added" << endl;
				cout<<"Do you want to add information about the employee? (y/n): ";
				char cc;
				cin>>cc;
				if (cc == 'y')
				{
					clearconsol();
					e3.editall();
				}

			}
			else
			{
				cout << "Employee already exists" << endl;
				cout<<"Press any key to continue"<<endl;
				char s;
				cin>>s;
			}
			clearconsol();
			showadmin(e,c);
			break;
		}
		case 3:
		{
			int id = getanumber("Please enter the id of the employee: ");
			Elem<Employee>* e2 = c.searchN(Employee(id));
			if (e2 != c.getnil())
			{
				c.deleteN(Employee(id));
				cout << "Employee removed" << endl;
			}
			else
			{
				cout << "Employee not found" << endl;
				
			}
			cout<<"Press any key to continue"<<endl;
			char s;
			cin>>s;
			clearconsol();
			showadmin(e,c);
			break;
		}
		case 4:
		{
			cout << "Please enter the id of the employee: ";
			int id;
			cin >> id;
			Elem<Employee>* e2 = c.searchN(Employee(id));
			if (e2 != c.getnil())
			{
				clearconsol();
				e2->info.editpassword();
				cout << "Password changed" << endl;
			}
			else
			{
				cout << "Employee not found" << endl;
			}
			cout<<"Press any key to continue"<<endl;
			char s;
			cin>>s;
			clearconsol();
			showadmin(e,c);
			break;
		}
		case 0:
		{	clearconsol();
			decidewhattoshow(e,c);

		}
	}
}