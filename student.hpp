//header file student.hpp to declare your classes
#ifndef STUDENT_H
#define STUDENT_H
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>
#include <stdlib.h>
const int IniID = 2019999;
const int MaxSize = 10000;
class Student
{
private:
	string firstname;
	string lastname;
	float CGPA;
	int researchscore;
	int id;
	bool valid = true;
	Student* next = NULL;
public:
	//Default constructor
	//Student();
	//Non-default constructor 
	//Student(string firstname, string lastname, const float& CGPA, const int& researchscore, const int& id);
	//Getter functions declaration
	string getFirstname() const;
	string getLastname() const;
	float getCGPA() const;
	int getResearchscore() const;
	int getId() const;
	bool getValid() const;
	Student* getNext() const;
	//Setter functions declaration
	void setFirstname(const string& firstname);
	void setLastname(const string& lastname);
	void setCGPA(const float& CGPA);
	void setreasearchscore(const int& researchscore);
	void setid(const int& id);
	void setValid(const bool& valid);
	void setNext(Student* const& student);
	//Friend functions
	friend char compareCGPA(const Student& student1, const Student& student2);
	friend char compareResearchScore(const Student& student1, const Student& student2);
	friend char compareFirstName(const Student& student1, const Student& student2);
	friend char compareLastName(const Student& student1, const Student& student2);
	//Virtual printing function
	virtual void print() const;
};

class DomesticStudent : public Student
{
private:
	string province;
	DomesticStudent* next = NULL;
public:
	//Constructors declaration
	DomesticStudent(const string& firstname, const string& lastname, const string& province, const float& CGPA, const int& researchscore, const int& stu_count); //thêm const vao sau string  sau
	DomesticStudent();
	//Getter functions declaration
	string getProvince() const;
	DomesticStudent* getNext() const;
	//Setter functions declaration
	void setProvince(const string& province);
	void setNext(DomesticStudent* const& student);
	//Print function
	virtual void print() const;
	friend ostream& operator << (ostream& out, const DomesticStudent& student);

	//SORT FUNCTION (n is the size of the array)
	friend void CGPASort(DomesticStudent* student, const int& start, const int& end);
	friend void researchScoreSort(DomesticStudent* student, const int& start, const int& end);
	friend void firstNameSort(DomesticStudent* student, const int& start, const int& end);
	friend void lastNameSort(DomesticStudent* student, const int& start, const int& end);
	friend void provinceSort(DomesticStudent* student, const int& start, const int& end);
	friend void overallSort(DomesticStudent* student, const int& start, const int& end);


};

class ToeflScore
{
private:
	int read, listen, speak, write;
	bool valid = true;
	bool qualified = true;
public:
	//Constructors
	ToeflScore();
	ToeflScore(const int& read, const int& listen, const int& speak, const int& write);
	//Getter Functions Declaration
	int getRead() const;
	int getListen() const;
	int getSpeak() const;
	int getWrite() const;
	bool getValid() const;
	bool getQualified() const;
	//Setter Functions Declaration
	void setRead(const int& read);
	void setListen(const int& listen);
	void setSpeak(const int& speak);
	void setWrite(const int& write);
	void setValid(const bool& valid);
	void setQualified(const bool& qualified);
	void print() const;
	//Check TOEFL qualification function
	void checkTScore();
};



class InternationalStudent : public Student
{
private:
	ToeflScore TScore;
	string country;
	InternationalStudent* next = NULL;
public:
	InternationalStudent();
	InternationalStudent(const string& firstname, const string& lastname, const string& country, const float& CGPA, const int& researchscore,
		const int& stu_count, const ToeflScore& score);
	//getter
	string getCountry() const;
	ToeflScore getTScore() const;
	InternationalStudent* getNext() const;
	//setter
	void setCountry(const string& country);
	void setNext(InternationalStudent* const& student);
	void setTScore(ToeflScore*& TScore);
	//print function
	virtual void print() const;
	void printSorted() const;
	friend ostream& operator << (ostream& out, const InternationalStudent& student);
	//	//SORT FUNCTIONS (n is the size of the array)
	friend void CGPASort(InternationalStudent* student, const int& start, const int& end);
	friend void researchScoreSort(InternationalStudent* student, const int& start, const int& end);
	friend void firstNameSort(InternationalStudent* student, const int& start, const int& end);
	friend void lastNameSort(InternationalStudent* student, const int& start, const int& end);
	friend void countrySort(InternationalStudent* student, const int& start, const int& end);
	friend void overallSort(InternationalStudent* student, const int& start, const int& end);
};

//------------------------------------------------------------LINKED LIST-----------------------------------------------------

//Linked list helping funciton
//chỗ này k cần Do với In ở phía trước tại vì polymorphism, nhớ sữa lại
//t viết thêm 2 hàm compare score
char DoCompareAll(DomesticStudent* stu1, DomesticStudent* stu2);
char InCompareAll(InternationalStudent* stu1, InternationalStudent* stu2);

template <class T>
char compareScore(T* stu1, T* stu2)
{
	if (stu1->getResearchscore() > stu2->getResearchscore())
		return '>';
	else if (stu1->getResearchscore() < stu2->getResearchscore())
		return '<';
	else
	{
		//Second criteria: "CGPA"
		if (stu1->getCGPA() > stu2->getCGPA())
			return '>';
		else if (stu1->getCGPA() < stu2->getCGPA())
			return '<';
		else return '=';
	}
}


//Linked list basic function
void DoAddSorted(DomesticStudent* student, DomesticStudent*& head, DomesticStudent*& tail);
void InAddSorted(InternationalStudent* student, InternationalStudent*& head, InternationalStudent*& tail);
void traverserprinter(Student* const& head);



//Search for application id, cgpa and research score

//compare student object with a pass into value

template <class T>
char compareFirstName( T student1, string firstName)
{
	//Upgraded name compare function that neglects letter case
	//normalize both string, make them both uncapitalized before comparison
	string normname1 = student1.getFirstname();
	string normname2 = firstName;
	int i = 0;
	while (normname1[i] != '\0')
	{
		if (normname1[i] >= 97)
		{
			normname1[i] = normname1[i] - 32;
		}
		i++;
	}
	i = 0;
	while (normname2[i] != '\0')
	{
		if (normname2[i] >= 97)
		{
			normname2[i] = normname2[i] - 32;
		}
		i++;
	}
	if (normname1 < normname2)
		return '<';
	else if (normname1 > normname2)
		return '>';
	else
		return '=';
}


template <class T>
char compareLastName(T student1, string lastName)
{
	//Upgraded name compare function that neglects letter case
	//normalize both string, make them both uncapitalized before comparison
	string normname1 = student1.getLastname();
	string normname2 = lastName;
	int i = 0;
	while (normname1[i] != '\0')
	{
		if (normname1[i] >= 97)
		{
			normname1[i] = normname1[i] - 32;
		}
		i++;
	}
	i = 0;
	while (normname2[i] != '\0')
	{
		if (normname2[i] >= 97)
		{
			normname2[i] = normname2[i] - 32;
		}
		i++;
	}
	if (normname1 < normname2)
		return '<';
	else if (normname1 > normname2)
		return '>';
	else
		return '=';
}


//search for application id
//Complexity: O(N)
template <class T>
int	IdSearch(T* head, T* tail, int target)
{
	bool found = false;
	//empty list case
	if (head == NULL || tail == NULL)
	{
		std::cout << "Empty list" << std::endl;
		return -1;
	}
	//traverse to find target
	else if (head != NULL && tail != NULL)
	{
		T* here = head;
		while (here != NULL)
		{
			if (here->getId() == target)
			{
				std::cout << "Student found: " << std::endl;
				std::cout << *here;
				found = true;
			}
			here = here->getNext();
		}
		//Student not found exit
		if (here == NULL && found == false)
		{
			std::cout << "Student not found" << std::endl;
			return -1;
		}
		//student found exit
		else
		{
			std::cout << "End of the list" << std::endl;
			return 1;
		}
	}
}


//search for cgpa
//Complexity: O(N)
template <class T>
int CGPASearch(T* head, T* tail, float target)
{
	bool found = false;
	//empty list case
	if (head == NULL || tail == NULL)
	{
		std::cout << "Empty list" << std::endl;
		return -1;
	}
	//traverse to find target
	else if (head != NULL && tail != NULL)
	{
		T* here = head;
		while (here != NULL)
		{
			if (here->getCGPA() == target)
			{
				std::cout << "Student found: " << std::endl;
				std::cout << *here;
				found = true;
			}
			here = here->getNext();
		}
		//Student not found exit
		if (here == NULL && found == false)
		{
			std::cout << "Student not found" << std::endl;
			return -1;
		}
		//student found exit
		else
		{
			std::cout << "End of the list" << std::endl;
			return 1;
		}
	}
}



//search for researchscore
//Complexity: O(N)
template <class T>
int RScoreSearch(T* head, T* tail, int target)
{
	bool found = false;
	//empty list case
	if (head == NULL || tail == NULL)
	{
		std::cout << "Empty list" << std::endl;
		return -1;
	}
	//traverse to find target
	else if (head != NULL && tail != NULL)
	{
		T* here = head;
		while (here != NULL)
		{
			if (here->getResearchscore() == target)
			{
				std::cout << "Student found: " << std::endl;
				std::cout << *here;
				found = true;
			}
			here = here->getNext();
		}
		//Student not found exit
		if (here == NULL && found == false)
		{
			std::cout << "Student not found" << std::endl;
			return -1;
		}
		//student found exit
		else
		{
			std::cout << "End of the list" << std::endl;
			return 1;
		}
	}
}

//search for firstname AND lastname
//Complexity: O(N^2)
template <class T>
int nameSearch(T* head, T* tail, string firstname, string lastname)
{
	bool found = false;
	//empty list case
	if (head == NULL || tail == NULL)
	{
		std::cout << "Empty list" << std::endl;
		return -1;
	}
	//traverse to find target
	else if (head != NULL && tail != NULL)
	{
		T* here = head;
		while (here != NULL)
		{
	//		if (here->getFirstname() == firstname &&here->getLastname() == lastname)
			if(compareFirstName<Student>(*here,firstname) ==  '=' && compareLastName<Student>(*here,lastname) ==  '=' )
			{
				std::cout << "Student found: " << std::endl;
				std::cout << *here;
				found = true;
			}
			here = here->getNext();
		}
		//Student not found exit
		if (here == NULL && found == false)
		{
			std::cout << "Student not found" << std::endl;
			return -1;
		}
		//student found exit
		else
		{
			std::cout << "End of the list" << std::endl;
			return 1;
		}
	}
}

//Linked list add and delete function
//add new student node function// có thể cái này k cần tại trong main có 1 cái rồi, hoặc sửa main lại, thay cái này vô cho gọn
//void AddStudent(string firstName, string lastName, string province, float cgpa, int researchScore, int stu_count);
//void AddStudent(string firstName, string lastName, string country, float cgpa, int researchScore, int stu_count, int read, int write, int speak, int listen);

//delete student:
template <class T>
//complexity O(N^2)
void deleteStudent(T* head, T* tail, string firstname, string lastname)
{
	bool found = false;
	//empty list
	if (head == NULL || tail == NULL)
	{
		std::cout << "Empty list" << std::endl;
		return;
	}
	//traverse to find target
	else if (head != NULL && tail != NULL)
	{
		T* here = head;
		T* prev = here;
		while (here != NULL)
		{

			if (compareFirstName<Student>(*here, firstname) == '=' && compareLastName<Student>(*here, lastname) == '=')
			{
				std::cout << "Student found: " << std::endl;
				found = true;
				//if student found at head
				if (here == head && compareFirstName<Student>(*here, firstname) == '=' && compareLastName<Student>(*here, lastname) == '=')
				{
					std::cout << here->getFirstname() << " " << here->getLastname() << std::endl;
					here = here->getNext();
					delete head;
					head = here;
					std::cout << "delete head" << std::endl;
				}
				//student found at tail
				else if (here == tail)
				{
					tail = prev;
					prev->setNext(NULL);
					delete here;
					here = prev->getNext();
					std::cout << "delete tail" << std::endl;
				}
				else
				{
					prev->setNext(here->getNext());
					delete here;
					here = prev->getNext();
					std::cout << "normal delete" << std::endl;
				}
			}
			else if (here != NULL)
			{
				prev = here;
				here = here->getNext();
				std::cout << "moved";
			}
		}
		//Student not found exit
		if (here == NULL && found == false)
		{
			std::cout << "Student not found" << std::endl;
			return;
		}
		//student found exit
		else
		{
			std::cout << "End of the list" << std::endl;
			return;
		}
	}
}

//delete headtail
//Complexity: O(N)
template <class T>
void deleteHeadTail(T*& head, T*& tail)
{
	//Empty list
	if (head == NULL && tail == NULL)
	{
		std::cout << "Empty list\n";
		return;
	}
	//Head and tail points to the same object
	else if (head == tail)
	{
		delete head;
		head = NULL;
		tail = NULL;
		std::cout << "Delete head same as tail" << std::endl;
	}
	else
	{
		T* here = head->getNext();
		T* prev = head;
		T* targethead = head;
		//There are only two nodes in the list
		if (here->getNext() == NULL)
		{
			delete head;
			head = NULL;
			delete tail;
			tail = NULL;
			here = NULL;
			return;
		}
		//traverse
		while (here->getNext() != NULL)
		{
			prev = here;
			here = here->getNext();
			std::cout << "moved\n";
		}
		//delete process start
		head = head->getNext();
		delete targethead;
		targethead = NULL;
		delete tail;
		tail = prev;
		here = NULL;
		tail->setNext(NULL);
		std::cout << "head tail deleted and moved";
		return;

	}
}
//Fort debubgging only
template< class T>
void stupidPrint(T* const& head)
{
	int i = 1;
	T* traverse = head;
	while (traverse != NULL)
	{
		std::cout << i << ":  ";
		std::cout << traverse->getResearchscore() << "-------" << traverse->getCGPA() << std::endl;
		traverse = traverse->getNext();
		i++;
	}
}

//Merge domestic student list international student list

void searchthreshold(Student* head, const float& cgpathreshold, const int& rscorethreshold);
Student* MergeVers2(DomesticStudent* const& doHead, InternationalStudent* const& inHead);

//
//int getStringLength(string s)
//{
//	int count = 0;
//	for (int i = 0; s[i] != '\0'; i++)
//		count++;
//	return count;
//}


//Case insensitivity

bool checkProvince(string province);
bool checkCountry(string country);

//Keyboard Insert
void keyboardInsert(string firstname, string lastname, string country, float cgpa, int researchscore, int read, int write, int speak, int listen, InternationalStudent*& inHead, InternationalStudent*& inTail, int& index, int& stu_count);
void keyboardInsert(string firstname, string lastname, string province, float cgpa, int researchscore, DomesticStudent*& doHead, DomesticStudent*& doTail, int& index, int& stu_count);

#endif

