//main.cpp, put your driver code here,
//nhớ lấy file txt gốc trước khi làm câu 2
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <stdlib.h>
#include "student.hpp"
using namespace std;
//temporary function declaration in main

//Global variable
int stu_count = 1;
int pause;
/*I provide example code here to help you read the input
 *data from a file, so that you can focus on creating
 *and manipulating classes and objects
 */
int main() {
	//Initiating head and tail pointers to international, domestic and student
	DomesticStudent* doHead = NULL;
	DomesticStudent* doTail = NULL;
	InternationalStudent* inHead = NULL;
	InternationalStudent* inTail = NULL;
	Student* stuHead = NULL;
	Student* stuTail = NULL;
	//Read the domestic-stu.txt file and exit if failed
	string line;
	ifstream domesticFile("domestic-stu.txt");
	if (!domesticFile.is_open()) {
		cout << "Unable to open file domestic-stu.txt" << endl;
		return -1;
	}

	cout << "----------------------------------" << endl;
	cout << "Domestic Student file started" << endl;
	cout << "----------------------------------" << endl;
	//Read the first line of domestic-stu.txt, which specifies
	//the file format. And then print it out to the screen
	getline(domesticFile, line);
	cout << "File format: " << line << endl;

	/*Keep reading the rest of the lines in domestic-stu.txt.
	*In the example code here, I will read each data separated
	*by a comma, and then print it out to the screen.
	*In your lab assignment 1, you should use these read data
	*to initialize your DomesticStudent object. Then you can
	*use get and set functions to manipulate your object, and
	*print the object content to the screen
	*/
	while (getline(domesticFile, line)) {
		/*process each line, get each field separated by a comma.
		*We use istringstream to handle it.
		*Note in this example code here, we assume the file format
		*is perfect and do NOT handle error cases. We will leave the
		*error and exception handling of file format to Lab Assignment 4
		*/
		istringstream ss(line);

		string firstName, lastName, province, s_cgpa, s_researchScore;
		float cgpa = 0;
		int researchScore = -42069;

		//get firstName separated by comma and auto correct
		getline(ss, firstName, ',');

		//get lastName separated by comma
		getline(ss, lastName, ',');

		//get province separated by comma
		getline(ss, province, ',');
		if (checkProvince(province) == false)
			exit(1);
		/* get cpga separated by comma, and convert string to float*/
		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());

		//get researchScore separated by comma, and convert it to int
		getline(ss, s_researchScore, ',');
		if (s_researchScore == "\0")
			researchScore = -42069;
		else
			researchScore = atoi(s_researchScore.c_str());
		cout << "Name check: " << atoi(firstName.c_str()) << endl;


		//print the student info to the screen
		cout << "Domestic student " << stu_count << " " << firstName << " "
			<< lastName << " from " << province << " province has cgpa of "
			<< cgpa << ", and research score of " << researchScore << endl;
		//Instantiating a new node and add into linked list if valid
		DomesticStudent* temp = new DomesticStudent(firstName, lastName, province, cgpa, researchScore, stu_count);
		if (temp->getValid() == true)
		{
			DoAddSorted(temp, doHead, doTail);
		}
		else if (researchScore == -42069)
		{
			cout << "OMG THERE IS A MISSING FIELD" << endl << "PROGRAM TERMINATED" << endl;
			pause = getchar();;
			exit(1);
		}
		else
		{
			cout << "Invalid Input, no student was added" << endl;
			stu_count--;
			delete temp;
		}
		stu_count++;
	}
	//close your file
	domesticFile.close();
	cout << "------------------------------------------------END OF DOMESTIC STUDENT LIST----------------------------------------------" << endl;

	//---------------------------------------------------InternationalStudent file reading started
	int index = 0;
	//Read the domestic-stu.txt file and exit if failed
	ifstream internationalFile("international-stu.txt");
	if (!internationalFile.is_open()) {
		cout << "Unable to open file international-stu.txt" << endl;
		return -1;
	}
	cout << "----------------------------------" << endl;
	cout << "International Student file started" << endl;
	cout << "----------------------------------" << endl;
	getline(internationalFile, line);
	cout << "File format: " << line << endl;

	while (getline(internationalFile, line)) {
		istringstream ss(line);

		string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
		float cgpa;
		int researchScore = -42069;
		int readingScore, listeningScore, speakingScore;
		int writingScore = -42069;

		//get firstName separated by comma
		getline(ss, firstName, ',');

		//get lastName separated by comma
		getline(ss, lastName, ',');

		//get province separated by comma
		getline(ss, country, ',');
		if (country == "Idian")
		{
			cout << "No, it's not Idian\n" << endl;
			country = "India";
		}
		else if (checkCountry(country) == false)
			exit(1);

		//get cpga separated by comma, and convert string to float
		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());

		//get researchScore separated by comma, and convert it to int
		getline(ss, s_researchScore, ',');
		//check for missing field and data being pushed to the left
		if (s_researchScore == "\0")
			researchScore = -42069;
		else
			researchScore = atoi(s_researchScore.c_str());

		//get toeflScore sepearated by comm, and convert it to int
		getline(ss, s_reading, ',');
		readingScore = atof(s_reading.c_str());

		getline(ss, s_listening, ',');
		listeningScore = atof(s_listening.c_str());

		getline(ss, s_speaking, ',');
		speakingScore = atof(s_speaking.c_str());

		getline(ss, s_writing, ',');
		//check for missing field and data being pushed to the left
		if (s_writing == "\0")
			writingScore = -42069;
		else
			writingScore = atof(s_writing.c_str());

		//Instantiate ToeflScore object
		ToeflScore* tempTScore = new ToeflScore(readingScore, listeningScore, speakingScore, writingScore);

		//print the student info to the screen
		cout << "International student " << stu_count << " " << firstName << " "
			<< lastName << " from " << country << " has cgpa of "
			<< cgpa << ",research score of " << researchScore << " and TOEFL score (RLSW): ";
		tempTScore->print();
		//Instantiating a new InternationalStudent Node and add into the linked list if valid
		InternationalStudent* temp = new InternationalStudent(firstName, lastName, country, cgpa, researchScore, stu_count, *tempTScore);

		if (temp->getValid() == true && tempTScore->getValid() == true)
		{
			if (tempTScore)
				InAddSorted(temp, inHead, inTail);
		}
		else if (researchScore == -42069 || writingScore == -42069)
		{
			cout << "OMG THERE IS A MISSING FIELD" << endl << "PROGRAM TERMINATED" << endl;
			pause = getchar();;
			exit(1);
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



	//close your file
	internationalFile.close();
	cout << "----------------------------------------------END OF INTERNATIONAL STUDENT FILE-------------------------------------------------" << endl;




	//initializing selection and target variables:
	char actionselect = '0';
	char listselect = '0';
	char typeselect = '0';
	bool merged = false;
	string firstnametarget;
	string lastnametarget;
	int inttarget = 0;
	float floattarget = 0;




	////cout << traverse->getNext()->getResearchscore() << endl;

	/*stuHead = MergeVers2(doHead, inHead);
	stupidPrint<Student>(stuHead);
	stupidPrint<DomesticStudent>(doHead);
	stupidPrint<InternationalStudent>(inHead);*/

	while (true)
	{
		cout << "\n--------------------------------------------MAIN SCREEN-------------------------------------------\n";
		cout << "Merge and print all student[m]" << endl
			<< "Search students[s]" << endl
			<< "Insert new student[i]" << endl
			<< "Delete student[d]" << endl
			<< "Exit program[e]" << endl;
		cin >> actionselect;
		//========================================MERGE===========================
		if (actionselect == 'm')
		{
			cout << "--------------------------------------------------------------" << endl;
			cout << "Merge and print all student selected";
			merged = true;
			stuHead = MergeVers2(doHead, inHead);
			Student* here = stuHead;
			while (here->getNext() != NULL)
				here = here->getNext();
			stuTail = here;
			traverserprinter(stuHead);
		}
		//======================================SEARCH=============================
		else if (actionselect == 's')
		{
			cout << "--------------------------------------------------------------" << endl;
			cout << "Search selected" << endl;
			cout << "Select list to search" << endl
				<< "International Students[i]" << endl
				<< "Domestic Student[d]" << endl
				<< "All student (only available after merge all students) [s]" << endl;
			cout << "Or enter any key to go back to main screen " << endl;
			cin >> listselect;
			if (listselect == 'i')
			{
				cout << "--------------------------------------------------------------" << endl;
				cout << "International student list selected" << endl;
				cout << "Enter searching criteria:" << endl
					<< "CGPA[c]" << endl
					<< "ID[i]" << endl
					<< "Name[n]" << endl
					<< "Research score [r]" << endl;
				cout << "Or enter any key to go back to main screen" << endl;;
				cin >> typeselect;
				if (typeselect == 'c')
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "Search by CGPA selected" << endl;
					cout << "Enter CGPA: ";
					cin >> floattarget;
					CGPASearch<InternationalStudent>(inHead, inTail, floattarget);
				}
				else if (typeselect == 'i')
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "Search by ID selected" << endl;
					cout << "Enter ID: ";
					cin >> inttarget;
					IdSearch<InternationalStudent>(inHead, inTail, inttarget);
				}
				else if (typeselect == 'n')
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "Search by name selected" << endl;
					cout << "Enter firstname: ";
					cin >> firstnametarget;
					cout << "Enter lastname: ";
					cin >> lastnametarget;
					nameSearch<InternationalStudent>(inHead, inTail, firstnametarget, lastnametarget);
				}
				else if (typeselect == 'r')
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "Search by research score selected" << endl;
					cout << "Enter research score: ";
					cin >> inttarget;
					RScoreSearch<InternationalStudent>(inHead, inTail, inttarget);
				}
				else
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "You've entered " << typeselect << endl;
					cout << "Going back to main screen";
					continue;
				}
			}
			else if (listselect == 'd')
			{
				cout << "--------------------------------------------------------------" << endl;
				cout << "Domestic student list selected" << endl;
				cout << "Enter searching criteria:" << endl
					<< "CGPA[c]" << endl
					<< "ID[i]" << endl
					<< "Name[n]" << endl
					<< "Research score [r]" << endl;
				cout << "Or enter any key to go back to main screen" << endl;;
				cin >> typeselect;
				if (typeselect == 'c')
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "Search by CGPA selected" << endl;
					cout << "Enter CGPA: ";
					cin >> floattarget;
					CGPASearch<DomesticStudent>(doHead, doTail, floattarget);
				}
				else if (typeselect == 'i')
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "Search by ID selected" << endl;
					cout << "Enter ID: ";
					cin >> inttarget;
					IdSearch<DomesticStudent>(doHead, doTail, inttarget);
				}
				else if (typeselect == 'n')
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "Search by name selected" << endl;
					cout << "Enter firstname: ";
					cin >> firstnametarget;
					cout << "Enter lastname: ";
					cin >> lastnametarget;
					nameSearch<DomesticStudent>(doHead, doTail, firstnametarget, lastnametarget);
				}
				else if (typeselect == 'r')
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "Search by research score selected" << endl;
					cout << "Enter research score: ";
					cin >> inttarget;
					RScoreSearch<DomesticStudent>(doHead, doTail, inttarget);
				}
				else
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "You've entered " << typeselect << endl;
					cout << "Going back to main screen";
					continue;
				}
			}
			else if (listselect == 's' && merged == false)
			{
				cout << "--------------------------------------------------------------" << endl;
				cout << "Error: list must be merged before search all student selected" << endl
					<< " Going back to main screen";
				continue;
			}
			else if (listselect == 's' && merged == true)
			{
				cout << "--------------------------------------------------------------" << endl;
				cout << "Search all student based on score threshold selected" << endl
					<< "type [t] to continue";
				cout << "Or enter any key to go back to main screen" << endl;;
				cin >> typeselect;
				if (typeselect == 't')
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "Enter CGPA threshold: " << endl;
					cin >> floattarget;
					cout << "Enter Research Score threshold: " << endl;
					cin >> inttarget;
					searchthreshold(stuHead, floattarget, inttarget);
				}
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "You've entered " << typeselect << endl;
					cout << "Going back to main screen";
					continue;
				}
			}
			else
			{
				cout << "--------------------------------------------------------------" << endl;
				cout << "You've entered " << typeselect << endl;
				cout << "Going back to main screen";
				continue;
			}
		}
		//=======================================INSERT==============================
		else if (actionselect == 'i')
		{
		cout << "--------------------------------------------------------------" << endl;
		string firstname, lastname, province, country;
		int researchscore = 0, read = 0, listen = 0, write = -42069, speak = 0;
		float cgpa = 0;
		cout << "Insert new student selected" << endl;
		cout << "Select student list to insert" << endl
			<< "International Student[i]" << endl
			<< "Domestic Student[d]" << endl;
		cout << "Or enter any key to go back to main screen" << endl;;
		cin >> listselect;
		if (listselect == 'd')
		{
			keyboardInsert(firstname, lastname, province, cgpa, researchscore, doHead, doTail, index, stu_count);
		}
		else if (listselect == 'i')
		{
			keyboardInsert(firstname, lastname, country, cgpa, researchscore, read, write, speak, listen, inHead, inTail, index, stu_count);
		}
		}
		//=============================================================DELETE========================================================
		else if (actionselect == 'd')
		{
			cout << "--------------------------------------------------------------" << endl;
			cout << "Delete student selected" << endl
				<< "Select list to delete" << endl
				<< "International student[i]" << endl
				<< "Domestic Student [d]" << endl;
			cout << "Or enter any key to go back to main screen" << endl;;
			cin >> listselect;
			if (listselect == 'i')
			{
				cout << "--------------------------------------------------------------" << endl;
				cout << "International student file selected" << endl
					<< "Select deleting type: " << endl
					<< "Individual student (by name) [i]" << endl
					<< "Head and tail [h]" << endl;
				cout << "Or enter any key to go back to main screen" << endl;;
				cin >> typeselect;
				if (typeselect == 'i')
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "Delete individual student selected" << endl;
					cout << "Enter firstname: ";
					cin >> firstnametarget;
					cout << "Enter lastname: ";
					cin >> lastnametarget;
					deleteStudent<InternationalStudent>(inHead, inTail, firstnametarget, lastnametarget);
				}
				else if (typeselect == 'h')
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "Delete head and tail selected" << endl;
					deleteHeadTail<InternationalStudent>(inHead, inTail);
				}
				else
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "You've entered " << typeselect << endl;
					cout << "Going back to main screen";
					continue;
				}
			}
			else if (listselect == 'd')
			{
				cout << "--------------------------------------------------------------" << endl;
				cout << "Domestic student file selected" << endl
					<< "Select deleting type: " << endl
					<< "Individual student (by name) [i]" << endl
					<< "Head and tail [h]" << endl;
				cout << "Or enter any key to go back to main screen" << endl;;
				cin >> typeselect;
				if (typeselect == 'i')
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "Delete individual student selected" << endl;
					cout << "Enter firstname: ";
					cin >> firstnametarget;
					cout << "Enter lastname: ";
					cin >> lastnametarget;
					deleteStudent<DomesticStudent>(doHead, doTail, firstnametarget, lastnametarget);
				}
				else if (typeselect == 'h')
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "Delete head and tail selected" << endl;
					deleteHeadTail<DomesticStudent>(doHead, doTail);
				}
				else
				{
					cout << "--------------------------------------------------------------" << endl;
					cout << "You've entered " << typeselect << endl;
					cout << "Going back to main screen";
					continue;
				}
			}
			else
			{
				cout << "--------------------------------------------------------------" << endl;
				cout << "You've entered " << typeselect << endl;
				cout << "Going back to main screen";
				continue;
			}
		}
		else if (actionselect == 'e')
		{
			cout << "--------------------------------------------------------------" << endl;
			cout << "Press any key to exit program..." << endl;
			exit(0);
		}
		else if (actionselect == 'u')
		{
			//delete all list before
			while (inHead != NULL)
				deleteHeadTail(inHead, inTail);
			while (doHead != NULL)
				deleteHeadTail(doHead, doTail);
			cout << "Initializing unit test...\n" << "Press any key to test 'INSERT' function " << endl;
			pause = getchar();;
			cout << "1) Insert student to list" << endl;
			//---------------------------------------------------------------------------Do the samething like adding normal textfile to list
			//Initiating head and tail pointers to international, domestic and student
			DomesticStudent* doHead = NULL;
			DomesticStudent* doTail = NULL;
			InternationalStudent* inHead = NULL;
			InternationalStudent* inTail = NULL;
			Student* stuHead = NULL;
			Student* stuTail = NULL;
			DomesticStudent* doHeadNull = NULL;
			DomesticStudent* doTailNull = NULL;
			InternationalStudent* inHeadNull = NULL;
			InternationalStudent* inTailNull = NULL;
			Student* stuHeadNull = NULL;
			Student* stuTailNull = NULL;
			//Read the domestic-stu.txt file and exit if failed
			string line;
			ifstream domesticFileTest("domestic-stu-test.txt");
			if (!domesticFileTest.is_open()) {
				cout << "Unable to open file domestic-stu-test.txt" << endl;
				return -1;
			}

			cout << "----------------------------------" << endl;
			cout << "Domestic Student Test file started" << endl;
			cout << "----------------------------------" << endl;
			//Read the first line of domestic-stu.txt, which specifies
			//the file format. And then print it out to the screen
			getline(domesticFileTest, line);
			cout << "File format: " << line << endl;

			/*Keep reading the rest of the lines in domestic-stu.txt.
			*In the example code here, I will read each data separated
			*by a comma, and then print it out to the screen.
			*In your lab assignment 1, you should use these read data
			*to initialize your DomesticStudent object. Then you can
			*use get and set functions to manipulate your object, and
			*print the object content to the screen
			*/
			while (getline(domesticFileTest, line)) {
				/*process each line, get each field separated by a comma.
				*We use istringstream to handle it.
				*Note in this example code here, we assume the file format
				*is perfect and do NOT handle error cases. We will leave the
				*error and exception handling of file format to Lab Assignment 4
				*/
				istringstream ss(line);

				string firstName, lastName, province, s_cgpa, s_researchScore;
				float cgpa = 0;
				int researchScore = -42069;

				//get firstName separated by comma and auto correct
				getline(ss, firstName, ',');

				//get lastName separated by comma
				getline(ss, lastName, ',');

				//get province separated by comma
				getline(ss, province, ',');
				if (checkProvince(province) == false)
					exit(1);
				/* get cpga separated by comma, and convert string to float*/
				getline(ss, s_cgpa, ',');
				cgpa = atof(s_cgpa.c_str());

				//get researchScore separated by comma, and convert it to int
				getline(ss, s_researchScore, ',');
				if (s_researchScore == "\0")
					researchScore = -42069;
				else
					researchScore = atoi(s_researchScore.c_str());
				cout << "Name check: " << atoi(firstName.c_str()) << endl;


				//print the student info to the screen
				cout << "Domestic student " << stu_count << " " << firstName << " "
					<< lastName << " from " << province << " province has cgpa of "
					<< cgpa << ", and research score of " << researchScore << endl;
				//Instantiating a new node and add into linked list if valid
				DomesticStudent* temp = new DomesticStudent(firstName, lastName, province, cgpa, researchScore, stu_count);
				if (temp->getValid() == true)
				{
					DoAddSorted(temp, doHead, doTail);
				}
				else if (researchScore == -42069)
				{
					cout << "OMG THERE IS A MISSING FIELD" << endl << "PROGRAM TERMINATED" << endl;
					pause = getchar();;
					exit(1);
				}
				else
				{
					cout << "Invalid Input, no student was added" << endl;
					stu_count--;
					delete temp;
				}
				stu_count++;
			}
			//close your file
			domesticFileTest.close();
			cout << "------------------------------------------------END OF DOMESTIC STUDENT LIST----------------------------------------------" << endl;

			//---------------------------------------------------InternationalStudent file reading started
			int index = 0;
			//Read the domestic-stu.txt file and exit if failed
			ifstream internationalFileTest("international-stu-test.txt");
			if (!internationalFileTest.is_open()) {
				cout << "Unable to open file international-stu-test.txt" << endl;
				return -1;
			}
			cout << "----------------------------------" << endl;
			cout << "International Student Test file started" << endl;
			cout << "----------------------------------" << endl;
			getline(internationalFileTest, line);
			cout << "File format: " << line << endl;

			while (getline(internationalFileTest, line)) {
				istringstream ss(line);

				string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
				float cgpa;
				int researchScore = -42069;
				int readingScore, listeningScore, speakingScore;
				int writingScore = -42069;

				//get firstName separated by comma
				getline(ss, firstName, ',');

				//get lastName separated by comma
				getline(ss, lastName, ',');

				//get province separated by comma
				getline(ss, country, ',');
				if (country == "Idian")
				{
					cout << "No, it's not Idian\n" << endl;
					country = "India";
				}
				else if (checkCountry(country) == false)
					exit(1);

				//get cpga separated by comma, and convert string to float
				getline(ss, s_cgpa, ',');
				cgpa = atof(s_cgpa.c_str());

				//get researchScore separated by comma, and convert it to int
				getline(ss, s_researchScore, ',');
				//check for missing field and data being pushed to the left
				if (s_researchScore == "\0")
					researchScore = -42069;
				else
					researchScore = atoi(s_researchScore.c_str());

				//get toeflScore sepearated by comm, and convert it to int
				getline(ss, s_reading, ',');
				readingScore = atof(s_reading.c_str());

				getline(ss, s_listening, ',');
				listeningScore = atof(s_listening.c_str());

				getline(ss, s_speaking, ',');
				speakingScore = atof(s_speaking.c_str());

				getline(ss, s_writing, ',');
				//check for missing field and data being pushed to the left
				if (s_writing == "\0")
					writingScore = -42069;
				else
					writingScore = atof(s_writing.c_str());

				//Instantiate ToeflScore object
				ToeflScore* tempTScore = new ToeflScore(readingScore, listeningScore, speakingScore, writingScore);

				//print the student info to the screen
				cout << "International student " << stu_count << " " << firstName << " "
					<< lastName << " from " << country << " has cgpa of "
					<< cgpa << ",research score of " << researchScore << " and TOEFL score (RLSW): ";
				tempTScore->print();
				//Instantiating a new InternationalStudent Node and add into the linked list if valid
				InternationalStudent* temp = new InternationalStudent(firstName, lastName, country, cgpa, researchScore, stu_count, *tempTScore);

				if (temp->getValid() == true && tempTScore->getValid() == true)
				{
					if (tempTScore)
						InAddSorted(temp, inHead, inTail);
				}
				else if (researchScore == -42069 || writingScore == -42069)
				{
					cout << "OMG THERE IS A MISSING FIELD" << endl << "PROGRAM TERMINATED" << endl;
					pause = getchar();;
					exit(1);
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


			//close your file
			internationalFileTest.close();
			cout << "----------------------------------------------END OF INTERNATIONAL STUDENT FILE-------------------------------------------------" << endl;
			cout << "Finished inserting from test files" << endl;
			cout << "Starting Insert from keyboard test, press any key to continue... " << endl;
			pause = getchar();;
			cout << "Finished inserting from test files" << endl;
			////Insertfrom keyboard
			cout << "Starting Insert from keyboard test, press any key to continue... " << endl;
			pause = getchar();;
			string firstname, lastname, province, country;
			int researchscore = 0, read = 0, listen = 0, write = -42069, speak = 0;
			float cgpa = 0;
			cout << "Domestic keyboard insert function test, please enter entries" << endl;
			keyboardInsert(firstname, lastname, province, cgpa, researchscore, doHead, doTail, index, stu_count);
			pause = getchar();;
			cout << "International keyboard insert function test, please enter entries" << endl;
			keyboardInsert(firstname, lastname, country, cgpa, researchscore, read, write, speak, listen, inHead, inTail, index, stu_count);
			cout << "Finished inserting from keyboard" << endl;
			//Part2-2: Search by number test
			cout << "-------------------------------------------------" << endl;
			cout << "Starting Search Number Functions test, press any key to continue... " << endl;
			pause = getchar();;
			cout << "Normal case: Search CGPA in International Student text file: 3.00" << endl;
			CGPASearch(inHead, inTail, 3.00);
			cout << "-------------------------------------------------" << endl;
			pause = getchar();;
			cout << "Corner case: Search ResearchScore in Domestic Student text file: 100" << endl;
			RScoreSearch(doHead, doTail, 100);
			cout << "-------------------------------------------------" << endl;
			pause = getchar();;
			cout << "Illegal case: Search ID in Domestic Student text file: 300000000" << endl;
			IdSearch(inHead, inTail, 300000000);
			cout << "-------------------------------------------------" << endl;
			pause = getchar();;
			cout << "Illegal case: Search CGPA in a empty domestic list" << endl;
			CGPASearch(doHeadNull, doTailNull, 2.69);
			cout << "-------------------------------------------------" << endl;
			cout << "Finish search number functions" << endl;
			//Part 2-3: Search by name test
			cout << "-------------------------------------------------" << endl;

			cout << "Starting search by name functions test, press any key to continue..." << endl;
			pause = getchar();;
			cout << "Normal case: Search student's name in Domestic Student (Student actually exist): Find Me" << endl;
			nameSearch(doHead, doTail, "Find", "Me");
			cout << "-------------------------------------------------" << endl;
			cout << "Corner case: Search student's name that has duplication in International Student: Same McName" << endl;
			nameSearch(inHead, inTail, "Same", "McName");
			cout << "-------------------------------------------------" << endl;
			cout << "Illegal case: Search student's name in International Student (Student does not exist): Kash Register" << endl;
			nameSearch(inHead, inTail, "Kash", "Register");
			cout << "-------------------------------------------------" << endl;
			cout << "Finish search name functions" << endl;
			//Part 2-4: Delete student by name
			cout << "-------------------------------------------------" << endl;
			cout << "Starting Delete Function test, press any key to continue... " << endl;
			pause = getchar();;
			cout << "Normal case: Delete Domestic Student text file by name (Student actually exist):: Delete Me" << endl;
			deleteStudent<DomesticStudent>(doHead, doTail, "Delete", "Me");
			cout << "-------------------------------------------------" << endl;
			pause = getchar();;
			cout << "Corner case: Delete student's name that has duplication in International Student: Same McName" << endl;
			deleteStudent<InternationalStudent>(inHead, inTail, "Same","McName");
			cout << "-------------------------------------------------" << endl;
			pause = getchar();;
			cout << "Illegal case: Delete student's name in Domestic Student text file (Student with this ID does not exist): Long Huy" << endl;
			deleteStudent(doHead, doTail, "Long", "Huy");
			cout << "-------------------------------------------------" << endl;
			cout << "Finish search name function" << endl;

			//Part 2-5: Merge the two sorted DomesticStudent and InternationalStudent linked lists into a single list
			cout << "-------------------------------------------------" << endl;
			cout << "Starting merge function test, press any key to continue..." << endl;
			pause = getchar();;
			cout << "Corner case: Merge 1 empty list with 1 unempty list" << endl;
			stuHead = MergeVers2(doHeadNull, inHead);
			traverserprinter(stuHead); cout << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "Illegal case: Merge 2 empty lists" << endl;
			stuHead = MergeVers2(doHeadNull, inHeadNull);
			cout << "-------------------------------------------------" << endl;
			cout << "Normal case:" << endl;
			stuHead = MergeVers2(doHead, inHead);
			traverserprinter(stuHead); cout << endl;
			cout << "-------------------------------------------------" << endl;
			//Part 2-6:Threshold search
			cout << "-------------------------------------------------" << endl;
			cout << "Starting Delete head and tail function test, press any key to continue..." << endl;
			pause = getchar();;
			cout << "Normal case: Search for students has CPGA>3.5, ResearchScore>90 after merging 2 lists" << endl;
			searchthreshold(stuHead, 3.5, 90);
			cout << "-------------------------------------------------" << endl;
			cout << "Corner case: CGPA =4.33 Researchscore: " << endl;
			searchthreshold(stuHead, 4.33,100 );
			cout << "-------------------------------------------------" << endl;
			cout << "Illegal case: CGPA = 4.99 and ResearchScore=131 over the limit" << endl;
			searchthreshold(stuHead, 4.34, 101);
			cout << "-------------------------------------------------" << endl;
			cout << "Illegal case: list not merged, or empty student list" << endl;
			searchthreshold(stuHeadNull, 4.12, 80);
			cout << "-------------------------------------------------" << endl;
			cout << "Finish threshold search" << endl;
			//Part 2-7: Delete head tail of the list
			cout << "-------------------------------------------------" << endl;
			cout << "Starting Delete head and tail function test, press any key to continue..." << endl;
			pause = getchar();;
			cout << "Use delete head and tail continuously on one of the list (stu-international-test in this test) to go through all the normal and corner cases" << endl;
			while (inHead != NULL)
				deleteHeadTail<InternationalStudent>(inHead, inTail);
			cout << "\nIllegal case: Delete head tail in an empty international student list" << endl;
			deleteHeadTail<InternationalStudent>(inHeadNull, inTailNull);
			cout << "Finish head and tail delete" << endl;
			//
			cout << "\nEnd of test unit, exitting program";
			exit(1);
		}
		else
			cout << "Invalid input, try again" << endl;

	}

	////Sort
	//cout << "----------------------------------" << endl;
	//cout << "SORTING STARTED\n";
	//cout << "----------------------------------" << endl;

	////SORT INTERFACE
	//int start = 0;
	//int end = 99;
	//char listselect = '0', sortselect = '0';
	//cout << "Which file would you like to sort? Internationalstudent(i)/DomesticStudent(d):\n";
	//cin >> listselect;
	//if (listselect == 'd')
	//{
	// cout << "You selected to sort DomesticStudent file\n";
	// cout << "Enter sort type: CGPA(c)/firstname(f)/lastname(l)/researchscore(r)/overall(o)";
	// cin >> sortselect;
	// if (sortselect == 'c')
	// CGPASort(DoStu, start, end);
	// else if (sortselect == 'f')
	// firstNameSort(DoStu, start, end);
	// else if (sortselect == 'r')
	// researchScoreSort(DoStu, start, end);
	// else if (sortselect == 'l')
	// lastNameSort(DoStu, start, end);
	// else if (sortselect == 'o')
	// overallSort(DoStu, start, end);
	// else
	// {
	// cout << "Invalid Input, exitting program...\n";
	// exit(1);
	// }
	// for (int i = 0; i <= 99; i++)
	// cout << DoStu[i] << endl;
	//}
	//else if (listselect == 'i')
	//{
	// cout << "You selected to sort InternationalStudent file\n";
	// cout << "Enter sort type: CGPA(c)/firstname(f)/lastname(l)/researchscore(r)/overall(o)";
	// cin >> sortselect;
	// if (sortselect == 'c')
	// CGPASort(InStu, start, end);
	// else if (sortselect == 'f')
	// firstNameSort(InStu, start, end);
	// else if (sortselect == 'r')
	// researchScoreSort(InStu, start, end);
	// else if (sortselect == 'l')
	// lastNameSort(InStu, start, end);
	// else if (sortselect == 'o')
	// {
	// overallSort(InStu, start, end);
	// for (int i = 0; i <= 99; i++)
	// InStu[i].printSorted();
	// }
	// else
	// {
	// cout << "Invalid Input, exitting program...\n";
	// exit(1);
	// }
	// for (int i = 0; i <= 99; i++)
	// InStu[i].print();
	//}
	//else
	// cout << "Invalid Input, exitting program...\n";


	//stuHead = MergeVers2(doHead, inHead);
	//traverserprinter(inHead);

	////Search
	//char listselect = '0';
	//char searchselect = '0';
	//string firstname;
	//string lastname;
	//int target = 0;
	//cout << "----------------------------------" << endl;
	//cout << "SEARCHING STARTED\n";
	//cout << "----------------------------------" << endl;
	//cout << "Which file would you like to search? Internationalstudent(i)/DomesticStudent(d):\n";
	//cin >> listselect;
	//if (listselect == 'd')
	//{
	// cout << "You selected to search DomesticStudent file\n";
	// cout << "Enter search type: CGPA(c)/researchscore(r)/ID(i)/Name(n)";
	// cin >> searchselect;
	// if (searchselect == 'n')
	// {
	// cout << "Enter full name: ";
	// cin >> firstname;
	// cin >> lastname;
	// nameSearch(doHead, doTail, firstname, lastname);
	// }
	// else
	// {
	// cout << "Enter search target: ";
	// cin >> target;
	// }
	// if (searchselect == 'c')
	// CGPASearch(doHead, doTail, target);
	// else if (searchselect == 'r')
	// RScoreSearch(doHead, doTail, target);
	// else if (searchselect == 'i')
	// IdSearch(doHead, doTail, target);
	// else
	// {
	// cout << "Invalid Input, exitting program...\n";
	// exit(1);
	// }
	//}
	//else if (listselect == 'i')
	//{
	// cout << "You selected to search InternationalStudent file\n";
	// cout << "Enter search type: CGPA(c)/researchscore(r)/ID(i)";
	// cin >> searchselect;
	// if (searchselect == 'n')
	// {
	// cout << "Enter full name: ";
	// cin >> firstname;
	// cin >> lastname;
	// nameSearch(inHead, inTail, firstname, lastname);
	// }
	// else
	// {
	// cout << "Enter search target: ";
	// cin >> target;
	// }

	// if (searchselect == 'c')
	// CGPASearch(inHead, inTail, target);
	// else if (searchselect == 'r')
	// RScoreSearch(inHead, inTail, target);
	// else if (searchselect == 'i')
	// IdSearch(inHead, inTail, target);
	// else
	// {
	// cout << "Invalid Input, exitting program...\n";
	// exit(1);
	// }
	// pause = getchar();;
	// return 0;
	//}
	//else
	//{
	// cout << "Invalid Input, exitting program...\n";
	// exit(1);
	//}


	return 0;

}

