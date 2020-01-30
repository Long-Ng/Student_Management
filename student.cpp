//student.cpp to implement your classes
#include "student.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;
////--------------------------------------STUDENT----------------------------------
//Getter Functions
string Student::getFirstname() const { return firstname; }
string Student::getLastname() const { return lastname; }
float Student::getCGPA() const { return CGPA; }
int Student::getResearchscore() const { return researchscore; }
int Student::getId() const { return id; }
bool Student::getValid() const { return valid; }
Student* Student::getNext() const { return next; }
//Setter Functions
void Student::setFirstname(const string& firstname) { this->firstname = firstname; }
void Student::setLastname(const string& lastname) { this->lastname = lastname; }
void Student::setCGPA(const float& CGPA) { this->CGPA = CGPA; }
void Student::setreasearchscore(const int& researchscore) { this->researchscore = researchscore; }
void Student::setid(const int& id) { this->id = id; }
void Student::setValid(const bool& valid) { this->valid = valid; }
void Student::setNext(Student* const& student) { this->next = student; }
//Student virtual printing function
void Student::print() const
{
}

//Student friend function
char compareCGPA(const Student& student1, const Student& student2)
{
	if (student1.CGPA < student2.CGPA)
		return '<';
	else if (student1.CGPA > student2.CGPA)
		return '>';
	else
		return '=';
}
char compareResearchScore(const Student& student1, const Student& student2)
{
	if (student1.researchscore < student2.researchscore)
		return '<';
	else if (student1.researchscore > student2.researchscore)
		return '>';
	else
		return '=';
}
//compare name 2 student
char compareFirstName(const Student& student1, const Student& student2)
{
	//Upgraded name compare function that neglects letter case
	//normalize both string, make them both uncapitalized before comparison
	string normname1 = student1.getFirstname();
	string normname2 = student2.getFirstname();
	int i = 0;
	while (normname1[i] == '\0')
	{
		if (normname1[i] >= 97)
		{
			normname1[i] = normname1[i] - 32;
		}
		i++;
	}
	while (normname2[i] == '\0')
	{
		if (normname2[i] >= 97)
		{
			normname2[i] = normname2[i] - 32;
		}
		i++;
	}
	if (normname1 < normname2)
		return '<';
	else if (student1.firstname > student2.firstname)
		return '>';
	else
		return '=';
}


char compareLastName(const Student& student1, const Student& student2)
{
	//Upgraded name compare function that neglects letter case
	//normalize both string, make them both uncapitalized before comparison
	string normname1 = student1.getLastname();
	string normname2 = student2.getLastname();
	int i = 0;
	
	while (normname1[i] == '\0')
	{
		if (normname1[i] >= 141)
		{
			normname1[i] = normname1[i] - 40;
		}
		i++;
	}
	while (normname2[i] == '\0')
	{
		if (normname2[i] >= 141)
		{
			normname2[i] = normname2[i] - 40;
		}
		i++;
	}
	cout << student1.getLastname() << " becomes " << normname1 << endl;
	cout << student2.getLastname() << " becomes " << normname2 <<endl;
	if (normname1 < normname2)
		return '<';
	else if (student1.firstname > student2.firstname)
		return '>';
	else
		return '=';
}
////---------------------------------------------------TOEFL--------------------------------
//ToeflScore Default Constructor
ToeflScore::ToeflScore()
{
	read = 0;
	listen = 0;
	speak = 0;
	write = 0;
}
//ToeflScore Non-Default Constructor
ToeflScore::ToeflScore(const int& read, const int& listen, const int& speak, const int& write)
{//Validity checking
	if (0 <= read && read <= 30 && 0 <= listen && listen <= 30
		&& 0 <= speak && speak <= 30 && 0 <= write && write <= 30)
	{
		this->read = read;
		this->listen = listen;
		this->speak = speak;
		this->write = write;
	}
	else
	{
		this->read = read;
		this->listen = listen;
		this->speak = speak;
		this->write = write;
		this->valid = false;
		cout << "Invalid TOEFL Input" << endl;
	}
	checkTScore();
}
////ToelfScore Functions Definition
//Getter Functions
int ToeflScore::getRead() const { return read; }
int ToeflScore::getListen() const { return listen; }
int ToeflScore::getSpeak() const { return speak; }
int ToeflScore::getWrite() const { return write; }
bool ToeflScore::getValid() const { return valid; }
bool ToeflScore::getQualified() const { return qualified; }
//Setter Functions
void ToeflScore::setRead(const int& read) { this->read = read; }
void ToeflScore::setListen(const int& listen) { this->listen = listen; }
void ToeflScore::setSpeak(const int& speak) { this->speak = speak; }
void ToeflScore::setWrite(const int& write) { this->write = write; }
void ToeflScore::setValid(const bool& valid) { this->valid = valid; }
void ToeflScore::setQualified(const bool& qualified) { this->qualified = qualified; }
//Print function
void ToeflScore::print() const
{
	cout << "\nRead: " << read << " "
		<< "Listen: " << listen << " "
		<< "Speak: " << speak << " "
		<< "Write: " << write << endl;
}
//Check TOEFL qualification functions
void ToeflScore::checkTScore()
{
	if (read < 20 || listen < 20 || speak < 20 || write < 20 || (read + listen + speak + write) < 93)
		qualified = false;
	else qualified = true;
}

////---------------------------------------------DOMESTIC STUDENT---------------------------
//DomesticStudent Default Constructor
DomesticStudent::DomesticStudent()
{
	this->setFirstname("Unknown");
	this->setLastname("Unknown");
	this->setCGPA(0.00);
	this->setreasearchscore(0);
	this->setid(0);
	province = "Unknown";
}
//DomesticStudent Non-Default Constructor
DomesticStudent::DomesticStudent(const string& firstname, const string& lastname, const string& province, const float& CGPA, const int& researchscore, const int& stu_count)
{
	if (CGPA >= 0 && CGPA <= 4.33 && researchscore >= 0 && researchscore <= 100)
	{
		this->setFirstname(firstname);
		this->setLastname(lastname);
		this->setCGPA(CGPA);
		this->setreasearchscore(researchscore);
		this->setid(IniID + stu_count);
		this->province = province;
	}
	else
	{
		cout << "Invalid input from constructor so don't worry about it" << endl;
		this->setValid(false);
	}
}
////DomesticStudent Functions Definitions
//Setter function 
void DomesticStudent::setProvince(const string& province) { this->province = province; }
void DomesticStudent::setNext(DomesticStudent* const& student) { this->next = student; }
//Getter function 
string DomesticStudent::getProvince() const { return province; }
DomesticStudent* DomesticStudent::getNext() const { return next; }
//Print function 
void DomesticStudent::print() const
{
	cout << "Domestic Student: " << this->getId() << "\n"
		<< "Name:" << this->getFirstname() << " " << this->getLastname() << "\n"
		<< "Province:" << province << "\n"
		<< "CPGA and research score:" << this->getCGPA() << " " << this->getResearchscore() << "\n"
		<< "END\n\n";
}
//Overloaded "<<" Operator
ostream& operator << (ostream& out, const DomesticStudent& student)
{
	cout << "\nDomestic Student: " << student.getId() << endl
		<< "Name:" << student.getFirstname() << " " << student.getLastname() << "\n"
		<< "Province:" << student.province << "\n"
		<< "CPGA and research score:" << student.getCGPA() << " " << student.getResearchscore() << "\n"
		<< "END\n\n";
	return out;
}
////----------------------------------------------------INTERNATIONAL STUDENT------------------
//InternationalStudent Default Constructor
InternationalStudent::InternationalStudent()
{
	this->setFirstname("Unknown");
	this->setLastname("Unknown");
	this->setCGPA(0.00);
	this->setreasearchscore(0);
	this->setid(0);
	country = "Unknown";
	this->TScore.setRead(0);
	this->TScore.setWrite(0);
	this->TScore.setSpeak(0);
	this->TScore.setListen(0);
	this->next = NULL;
}
//InternationalStudent Non-Default Constructor
InternationalStudent::InternationalStudent(const string& firstname, const string& lastname, const string& country, const float& CGPA, const int& researchscore,
	const int& stu_count, const ToeflScore& score)
{
	if (CGPA >= 0 && CGPA <= 4.33 && researchscore >= 0 && researchscore <= 100)
	{
		this->setFirstname(firstname);
		this->setLastname(lastname);
		this->setCGPA(CGPA);
		this->setreasearchscore(researchscore);
		this->setid(IniID + stu_count);
		this->country = country;
		TScore = score;
		this->next = NULL;
	}
	else
	{
		cout << "Invalid input" << endl;
		this->setValid(false);
	}
}
////InternationalStudent Functions Definition
//Print function 
void InternationalStudent::print() const
{
	if (this->getValid() == true && this->TScore.getValid() == true && this->TScore.getQualified() == true)
	{
		cout << "International student: " << this->getId() << "\n"
			<< "Name:" << this->getFirstname() << " " << this->getLastname() << "\n"
			<< "Country:" << country << "\n"
			<< "CPGA and research score:" << this->getCGPA() << " " << this->getResearchscore() << "\n"
			<< "TOEFL Result:";
		TScore.print();
		cout << "END" << endl << endl;
	}
}
//Print sorted list with ToeflScore checking function
void InternationalStudent::printSorted() const
{
	if (this->getValid() == true && this->TScore.getQualified() == true && this->TScore.getValid() == true)
	{
		this->print();
	}
	else
		cout << "Student was not listed because of underqualified TOEFL Score\n";
}
//Setter function
void InternationalStudent::setCountry(const string& country) { this->country = country; }
void InternationalStudent::setNext(InternationalStudent* const& student) { this->next = student; }
void InternationalStudent::setTScore(ToeflScore*& TScore) { this->TScore = *TScore; }
//Getter function
string InternationalStudent::getCountry() const { return country; }
ToeflScore InternationalStudent::getTScore() const { return this->TScore; }
InternationalStudent* InternationalStudent::getNext() const { return next; }

ostream& operator << (ostream& out, const InternationalStudent& student)
{
	cout << "International Student:" << student.getId() << endl
		<< "Name:" << student.getFirstname() << " " << student.getLastname() << "\n"
		<< "Country:" << student.getCountry() << "\n"
		<< "CPGA and research score:" << student.getCGPA() << " " << student.getResearchscore() << "\n"
		<< "TOEFL Result:";

	student.getTScore().print();
	cout << "END" << endl;
	return out;
}

//Swap function for sorting
template <class T>
void object_swap(T& student1, T& student2)
{
	T temp = student1;
	student1 = student2;
	student2 = temp;
}
void object_swap(DomesticStudent& student1, DomesticStudent& student2)
{
	DomesticStudent temp = student1;
	student1 = student2;
	student2 = temp;
}
//CGPA Sort functions
void CGPASort(DomesticStudent* student, const int& start, const int& end)
{
	if (start >= end) return;

	for (int i = start; i <= end - 1; i++)
		if ('<' == compareCGPA(student[i], student[i + 1]))
			object_swap(student[i], student[i + 1]);
	CGPASort(student, start, end - 1);
}

void CGPASort(InternationalStudent* student, const int& start, const int& end)
{
	if (start >= end) return;

	for (int i = start; i <= end - 1; i++)
		if ('<' == compareCGPA(student[i], student[i + 1]))
			object_swap(student[i], student[i + 1]);
	CGPASort(student, start, end - 1);
}
//researchScore Sort functions
void researchScoreSort(DomesticStudent* student, const int& start, const int& end)
{
	if (start >= end) return;

	for (int i = start; i <= end - 1; i++)
		if ('<' == compareResearchScore(student[i], student[i + 1]))
			object_swap(student[i], student[i + 1]);
	researchScoreSort(student, start, end - 1);
}

void researchScoreSort(InternationalStudent* student, const int& start, const int& end)
{
	if (start >= end) return;

	for (int i = start; i <= end - 1; i++)
		if ('<' == compareResearchScore(student[i], student[i + 1]))
			object_swap(student[i], student[i + 1]);
	researchScoreSort(student, start, end - 1);
}
//firstname Sort functions
void firstNameSort(DomesticStudent* student, const int& start, const int& end)
{
	if (start >= end) return;

	for (int i = start; i <= end - 1; i++)
		if ('>' == compareFirstName(student[i], student[i + 1]))
			object_swap(student[i], student[i + 1]);
	firstNameSort(student, start, end - 1);
}

void firstNameSort(InternationalStudent* student, const int& start, const int& end)
{
	if (start >= end) return;

	for (int i = start; i <= end - 1; i++)
		if ('>' == compareFirstName(student[i], student[i + 1]))
			object_swap(student[i], student[i + 1]);
	firstNameSort(student, start, end - 1);
}
//lastname Sort functions
void lastNameSort(DomesticStudent* student, const int& start, const int& end)
{
	if (start >= end) return;

	for (int i = start; i <= end - 1; i++)
		if ('>' == compareLastName(student[i], student[i + 1]))
			object_swap(student[i], student[i + 1]);
	lastNameSort(student, start, end - 1);
}

void lastNameSort(InternationalStudent* student, const int& start, const int& end)
{
	if (start >= end) return;

	for (int i = start; i <= end - 1; i++)
		if ('>' == compareLastName(student[i], student[i + 1]))
			object_swap(student[i], student[i + 1]);
	lastNameSort(student, start, end - 1);
}

//province Sort function
void provinceSort(DomesticStudent* student, const int& start, const int& end)
{
	if (start >= end) return;

	for (int i = start; i <= end - 1; i++)
		if (student[i].province > student[i + 1].province)
			object_swap(student[i], student[i + 1]);
	provinceSort(student, start, end - 1);
}

//country sort function
void countrySort(InternationalStudent* student, const int& start, const int& end)
{
	if (start >= end) return;
	for (int i = start; i <= end - 1; i++)
		if (student[i].country > student[i + 1].country)
			object_swap(student[i], student[i + 1]);
	countrySort(student, start, end - 1);
}


//Overall Sort functions for domesticstudent
void overallSort(DomesticStudent* student, const int& start, const int& end)
{
	researchScoreSort(student, start, end);
	int* arr = new int[2];
	arr[0] = -1;
	for (int i = start; i <= end - 1; i++)
	{
		if (arr[0] == -1)
		{
			if ('=' == compareResearchScore(student[i], student[i + 1]))
			{
				arr[0] = i;
				i++;
				if (i > end)
					break;
			}
			else continue;
		}
		if ('=' != compareResearchScore(student[i], student[i + 1]))
		{
			arr[1] = i;
			CGPASort(student, arr[0], arr[1]);
			arr[0] = -1;
		}
	}
	arr[0] = -1;
	/////////////////////province sort
	for (int i = start; i <= end - 1; i++)
	{
		if (arr[0] == -1)
		{
			if ('=' == compareResearchScore(student[i], student[i + 1]) && '=' == compareCGPA(student[i], student[i + 1]))
			{
				arr[0] = i;
				i++;
				if (i > end)
					break;
			}
			else continue;
		}
		if ('=' != compareResearchScore(student[i], student[i + 1]) || '=' != compareCGPA(student[i], student[i + 1]))
		{
			arr[1] = i;
			provinceSort(student, arr[0], arr[1]);
			arr[0] = -1;
		}
	}
}

//Overall Sort functions for international student
void overallSort(InternationalStudent* student, const int& start, const int& end)
{
	researchScoreSort(student, start, end);
	int* arr = new int[2];
	arr[0] = -1;
	for (int i = start; i <= end - 1; i++)
	{
		if (arr[0] == -1)
		{
			if ('=' == compareResearchScore(student[i], student[i + 1]))
			{
				arr[0] = i;
				i++;
				if (i > end)
					break;
			}
			else continue;
		}
		if ('=' != compareResearchScore(student[i], student[i + 1]))
		{
			arr[1] = i;
			CGPASort(student, arr[0], arr[1]);
			arr[0] = -1;
		}
	}
	arr[0] = -1;
	/////////////////////country sort
	for (int i = start; i <= end - 1; i++)
	{
		if (arr[0] == -1)
		{
			if ('=' == compareResearchScore(student[i], student[i + 1]) && '=' == compareCGPA(student[i], student[i + 1]))
			{
				arr[0] = i;
				i++;
				if (i > end)
					break;
			}
			else continue;
		}
		if ('=' != compareResearchScore(student[i], student[i + 1]) || '=' != compareCGPA(student[i], student[i + 1]))
		{
			arr[1] = i;
			cout << "INDEXES ARE " << arr[0] << "and " << arr[1] << endl;
			countrySort(student, arr[0], arr[1]);

			arr[0] = -1;
		}
	}
}
//Linked list helping function
char DoCompareAll(DomesticStudent* stu1, DomesticStudent* stu2)
{
	//First criteria: "Research Score"
	if (stu1->getResearchscore() > stu2->getResearchscore())
		return '>';
	else if (stu1->getResearchscore() < stu2->getResearchscore())
		return '<';
	else if (stu1->getResearchscore() == stu2->getResearchscore())
	{
		//Second criteria: "CGPA"
		if (stu1->getCGPA() > stu2->getCGPA())
			return '>';
		else if (stu1->getCGPA() < stu2->getCGPA())
			return '<';
		//Third criteria: "Province"
		else if (stu1->getCGPA() == stu2->getCGPA())
		{//Because char with smaller value is on the top so char comparison is the opposite of number comparison
			if (stu1->getProvince() < stu2->getProvince())
				return '>';
			else if (stu1->getProvince() > stu2->getProvince())
				return '<';
			else if (stu1->getProvince() == stu2->getProvince())
				return '=';
		}
	}
}


char InCompareAll(InternationalStudent* stu1, InternationalStudent* stu2)
{
	//First criteria: "Research Score"
	if (stu1->getResearchscore() > stu2->getResearchscore())
		return '>';
	else if (stu1->getResearchscore() < stu2->getResearchscore())
		return '<';
	else
	{
		//Second criteria: "CGPA"
		if (stu1->getCGPA() > stu2->getCGPA())
			return '>';
		else if (stu1->getCGPA() > stu2->getCGPA())
			return '<';
		//Third criteria: "Country"
		else
		{//Because char with smaller value is on the top so char comparison is the opposite of number comparison
			if (stu1->getCountry() < stu2->getCountry())
				return '>';
			else if (stu1->getCountry() > stu2->getCountry())
				return '<';
			else
				return '=';
		}
	}
}


//-------------------------------------------------------------------Linked list function------------------------------------------
//Add DomesticStudent
//Complexity: O(N)
void DoAddSorted(DomesticStudent* temp, DomesticStudent*& head, DomesticStudent*& tail)
{
	//case1: empty list
	if (head == NULL && tail == NULL)
	{
		head = temp;
		tail = temp;
		cout << "case 1" << endl;
	}
	//case2: first node added
	else if (head == tail)
	{
		if (DoCompareAll(head, temp) == '>' || DoCompareAll(head, temp) == '=')
		{
			head = temp;
			temp->setNext(tail);
		}
		else
		{
			temp->setNext(NULL);
			head->setNext(temp);
			tail = temp;
		}
		cout << "case 2" << endl;
	}
	//case3: normal cases
	else if (head != tail)
	{
		//case3.1:head insert when head != tail
		if (DoCompareAll(head, temp) == '<' || DoCompareAll(head, temp) == '=')
		{
			temp->setNext(head);
			head = temp;
			cout << "case 3.1 head != tail head insert" << endl;
		}
		//case 3.2: traverse to find the right place to insert
		else if (DoCompareAll(head, temp) == '>')
		{
			DomesticStudent* prev = head;
			DomesticStudent* here = head->getNext();
			while (DoCompareAll(temp, here) == '<' && here->getNext() != NULL)
			{
				//appropriate place found, where here is less than temp and prev is greater than temp
				prev = here;
				here = here->getNext();
			}
			if (DoCompareAll(temp, here) == '>')
			{
				temp->setNext(here);
				prev->setNext(temp);
				cout << "case 3.2 normal insert " << endl;
				return;

			}
			//case4: the end of the list is reached
			if (here->getNext() == NULL)
			{
				//tail replacemet
				if (DoCompareAll(temp, tail) == '<')
				{
					here->setNext(temp);
					temp->setNext(NULL);
					tail = temp;
					cout << "case 4: tail replacement" << endl;
				}
				else
				{
					temp->setNext(here);
					prev->setNext(temp);
					cout << "case 3.2: normal insert near tail" << endl;
				}
			}
		}
	}
}

//Add International Student
//Complexity: O(N)
void InAddSorted(InternationalStudent* student, InternationalStudent*& head, InternationalStudent*& tail)
{
	InternationalStudent* here = head;
	//1
	if (head == NULL && tail == NULL)
	{
		head = student;
		tail = student;
		cout << "1: empty list\n";
	}
	//2
	else if (head == tail)
		//2.1
	{
		if (InCompareAll(student, here) == '>' || InCompareAll(student, here) == '=')
		{
			head = student;
			student->setNext(tail);

		}
		//2.2
		else if (InCompareAll(student, here) == '<')
		{
			student->setNext(NULL);
			head->setNext(student);
			tail = student;

		}
		cout << "2: same head tail\n";
	}
	else if (head != tail)
	{
		//3
		//3.1.1
		if (InCompareAll(student, head) == '>')
		{
			student->setNext(head);
			head = student;
			cout << "3: normal head replacement\n";
		}
		//3.1.2
		else
		{
			InternationalStudent* prev = here;
			here = here->getNext();
			while (here->getNext() != NULL)
			{//normal insert
				if (InCompareAll(student, here) == '>')
				{
					student->setNext(here);
					prev->setNext(student);
					cout << "3.1: normal insert\n";
					return;
				}
				prev = here;
				here = here->getNext();
			}
			//3.1.3
			if (InCompareAll(student, here) == '>')
			{
				student->setNext(here);
				prev->setNext(student);
				cout << "3.1: normal insert\n";
				return;
			}
			else
				here->setNext(student);
			student->setNext(NULL);
			tail = student;
			cout << "4: tail replacement\n";
		}
	}
}

void traverserprinter(Student* const& head)
{
	Student* here = head;
	while (here != NULL)
	{
		here->print();
		here = here->getNext();
	}
	return;
}


//Merge domestic student list international student list
//Complexity O(N)
Student* MergeVers2(DomesticStudent* const& doHead, InternationalStudent* const& inHead)
{


	Student* result = NULL;
	if(doHead == NULL && inHead == NULL)
	{
		std::cout << "Both lists are empty\n";
		return inHead;
	}
	if (doHead == NULL)
	{
		std::cout << "empty do\n";
		InternationalStudent* inHere = inHead;
		Student* stuHere = inHere;
		while (stuHere != NULL)
		{
			stuHere->setNext(inHere->getNext());
			stuHere = stuHere->getNext();
			inHere = inHere->getNext();
		}
		return(inHead);
	}

	else if (inHead == NULL)
	{
		cout << "empty in\n";
		DomesticStudent* doHere = doHead;
		Student* stuHere = doHere;
		while (stuHere != NULL)
		{
			stuHere->setNext(doHere->getNext());
			stuHere = stuHere->getNext();
			doHere = doHere->getNext();
		}
		return(doHead);
	}

	if (compareScore<Student>(doHead, inHead) == '>')
	{
		cout << "Merge in\n";
		result = doHead;
		result->setNext(MergeVers2(doHead->getNext(), inHead));
	}
	else
	{
		cout << "Merge do\n";
		result = inHead;
		result->setNext(MergeVers2(doHead, inHead->getNext()));
	}
	return result;
}
//Complexity: O(N)
void searchthreshold(Student* head, const float& cgpathreshold, const int& rscorethreshold)
{
	bool found = false;
	//empty list case
	if (head == NULL)
	{
		cout << "Empty list" << endl;
		return;
	}
	else if (head != NULL)
	{
		Student* here = head;
		while (here != NULL)
		{
			if (here->getCGPA() >= cgpathreshold && here->getResearchscore() >= rscorethreshold)
			{
				here->print();
				found = true;
			}
			here = here->getNext();
		}
		if (here == NULL && found == false)
		{
			cout << "No student found" << endl;
		}
		else if (here == NULL && found == true)
		{
			cout << "End of the list" << endl;
		}
	}
}

bool checkCountry(string country)
{
	//uncapitalized country for country eligibility checking
	int i = 0;
	while (country[i] != '\0')
	{
		if (country[i] >= 97)
		{
			country[i] = country[i] - 32;
		}
		i++;
	}
	//compare
	string arr[5] = {"CANADA","CHINA","INDIA","IRAN","KOREA"};
	for (int i = 0; i <= 4; i++)
	{
		if (country == arr[i])
		{
			return true;
		}
	}
	cout << "Invalid Country entry" << country << endl;
	return false;

}





bool checkProvince(string province)
{
	//uncapitalized country for country eligibility checking
	int i = 0;
	while (province[i] != '\0')
	{
		if (province[i] >= 97)
		{
			province[i] = province[i] - 32;
		}
		i++;
	}
	//compare
	string arr[13] = {"NL","PE","NS","NB","QC","ON","MB","SK","AB","BC","YT","NT","NU"};
	for (int i = 0; i <= 12; i++)
	{
		if (province == arr[i])
		{
			return true;
		}
	}
	cout << "Invalid Province entry: " << province << endl;
	return false;
}


void keyboardInsert(string firstname,string lastname,string country,float cgpa,int researchscore,int read,int write,int speak,int listen,InternationalStudent*& inHead, InternationalStudent*& inTail, int& index, int& stu_count)
{
	cout << "--------------------------------------------------------------" << endl;
	cout << "Adding new International student" << endl 
		<< "Enter the following information with a space in between every field" << endl;
	cout << "Enter [Firstname] [Lastname] [Country] [CGPA] [Researchscore] [TOEFL Read] [TOEFL Write] [TOEFL Speak] [TOEFL Listen] accordingly" << endl;
	cout << "Note: The [Country] entries must be one of these following: CANADA, CHINA, INDIA, IRAN, KOREA";
	cin >> firstname;
	cin >> lastname;
	while (true)
	{
		char countryexit = '0';
		cin >> country;
		if (country == "Idian")
		{
			cout << "You have just entered Idian, but I'm a nice person so I'll fix that for you" << endl;
			country = "India";
			cout << "Idian becomes India" << endl;
			break;
		}
		else if (checkCountry(country) == false)
		{
			cout << "The province entry is invalid, press [e] to exit or press any key to try again";
			cin >> countryexit;
			if (countryexit == 'e')
				exit(1);
			else
				continue;
		}
		else if (checkCountry(country) == true)
		{
			cout << "Input accepted,please proceed" << endl;
			break;
		}
	}
	cin >> cgpa;
	cin >> researchscore;
	cin >> read;
	cin >> write;
	cin >> speak;
	cin >> listen;
	ToeflScore* tempTScore = new ToeflScore(read, listen, speak, write);
	InternationalStudent* temp = new InternationalStudent(firstname, lastname, country, cgpa, researchscore, stu_count, *tempTScore);
	if (temp->getValid() == true && tempTScore->getValid() == true)
	{
		if (tempTScore)
			InAddSorted(temp, inHead, inTail);
	}
	else
	{
		cout << "Invalid input, No Student was added" << endl << endl;
		index--;
		stu_count--;
		delete temp;
		delete tempTScore;
	}
	index++;
	stu_count++;
}

void keyboardInsert(string firstname, string lastname, string province, float cgpa, int researchscore, DomesticStudent*& doHead, DomesticStudent*& doTail, int& index, int& stu_count)
{
	cout << "--------------------------------------------------------------" << endl;
	cout << "Adding new Domestic student" << endl
		<< "Enter the following information with a space in between every field" << endl;
	cout << "Enter [Firstname] [Lastname] [Province] [CGPA] [Researchscore] accordingly" << endl;
	cout << "Note: [Province] need to be one of these entries: NL,PE,NS,NB,QC,ON,MB,SK,AB,BC,YT,NT,NU" << endl;
	cin >> firstname;
	cin >> lastname;
	while (true)
	{
		char provinceexit = '0';
		cin >> province;
		if (checkProvince(province) == false)
		{
			cout << "The province entry is invalid, press [e] to exit or press any key to try again";
			cin >> provinceexit;
			if (provinceexit == 'e')
				exit(1);
			else
				continue;
		}
		else if (checkProvince(province) == true)
		{
			cout << "Input accepted,please proceed" << endl;
			break;
		}
	}
	cin >> cgpa;
	cin >> researchscore;
	DomesticStudent* temp = new DomesticStudent(firstname, lastname, province, cgpa, researchscore, stu_count);
	if (temp->getValid() == true)
	{
		DoAddSorted(temp, doHead, doTail);
	}
	else
	{
		cout << "Invalid Input, no student was added";
		stu_count--;
		delete temp;
	}
	stu_count++;

}
			