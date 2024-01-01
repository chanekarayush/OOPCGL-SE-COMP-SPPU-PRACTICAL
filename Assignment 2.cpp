//============================================================================
// Name        : Assignments_696969696_2.cpp
// Author      : lol
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Database
{
	friend class Student;
	//Private member variables
	string name, clas, dob, bloodGrp, cAddress;
	int long telephone, dLicense;
	int roll_no;
	char *div;
	//Static Member Variables
	static int number;
	static int count;

//Making Constructor public
public:


	//Default Constructor
	Database()
	{
		name="", clas="", dob="", bloodGrp="", cAddress="";
		telephone=0, dLicense=0;
		roll_no=0;
		// Dyanamic Memory Allocation
		div=new char;
	}


	//Copy Constructor
	Database(Database &obj)
	{
		name=obj.name, clas=obj.clas, dob=obj.dob;
		bloodGrp=obj.bloodGrp, cAddress=obj.cAddress;
		dLicense=obj.dLicense;
		telephone=obj.telephone;
		//  -->  Using this pointer  <--
		roll_no=this->roll_no;
		div=obj.div;
	}


	//Destructor
	~Database()
	{
		delete div;
		// We are creating a 100 objects regardless of no. of students. 
		// This ensures that the amout of obj destroyed message is equal to no. of students entered
		if(count++ < number)
		{
			cout<<"Object Destroyed"<<endl;
		}
	}


	//Assigns Student Data to member variables (Inline Function)
	void studentInput()
	{
		cout<<"Enter Name of the Student"<<endl;
		getline (cin, name);
		cout<<"Enter Roll Number of the Student"<<endl;
		cin>>roll_no;
		cin.ignore(1);
		cout<<"Enter Class of the Student"<<endl;
		getline (cin, clas);
		cout<<"Enter Division of the Student"<<endl;
		cin>>div;
		cin.ignore(1);
		cout<<"Enter Date of Birth of the Student (DD/MM/YYYY) Format"<<endl;
		getline (cin, dob);
		cout<<"Enter Blood Group of the Student"<<endl;
		getline(cin, bloodGrp);
		cout<<"Enter Address of the Student"<<endl;
		getline(cin, cAddress);
		cout<<"Enter Driver's License Number of the Student"<<endl;
		cin>>dLicense;
		cout<<"Enter Student's Telephone Number"<<endl;
		cin>>telephone;
	}


	// Static and Inline function which updates and returns the number of students entered in database
	static inline int getNumber()
	{
		return number++;
	}
};

int Database :: number = 0;
int Database :: count = 0;

class Student
{
public:


	//Inline Function which displays the student details
	void displayStudent(Database obj)
	{
		cout<<"Name - "<<obj.name<<endl;
		cout<<"Roll Number - "<<obj.roll_no<<endl;
		cout<<"Class - "<<obj.clas<<endl;
		cout<<"Division - "<<obj.div<<endl;
		cout<<"Date of Birth - "<<obj.dob<<endl;
		cout<<"Blood Group - "<<obj.dob<<endl;
		cout<<"Address - "<<obj.cAddress<<endl;
		cout<<"Driver's License Number - "<<obj.dLicense<<endl;
		cout<<"Telephone Number - "<<obj.telephone<<endl;
	}
};

int main() {
		Database stud1[100];
	    Student stud2[100];
	    int n=0;
	    char ch;

	    do
	    {
	        stud1[n].studentInput();
	        n++;

			Database::getNumber();
	        cout<<"Do you want to add another student (y/n) : ";
	        cin>>ch;
	        // cin.get();
			cin.ignore(1);
	    } while (ch=='y' || ch=='Y');

	    for(int i=0;i<n;i++)
	    {
	        cout<<"---------------------------------------------------------------"<<endl;
	        stud2[i].displayStudent(stud1[i]);
	    }

	    cout<<"---------------------------------------------------------------"<<endl;
	    cout<<"Total Students : "<<Database::getNumber();
	    cout<<endl<<"---------------------------------------------------------------"<<endl;


	return 0;
}
