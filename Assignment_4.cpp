//============================================================================
// Name        : 696969696_Assignment_4.cpp
// Author      : lol
// Version     :
// Copyright   : Your copyright notice
// Description : Write a C++ program that creates an output file, writes information to it, closes the
//				 file and open it again as an input file and read the information from the file.
//============================================================================

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class GetFields
{
private:
	string name, designation, address;
	long int salary, phno;
public:
	GetFields()
	{
		name="", designation="", address="";
		salary=0, phno=0;
	}
	void inputInfo()
	{
		//input code later
	}
};


int main()
{
	cout<<"Enter Filename"<<endl;
	string filename;
	getline(cin, filename);
	cin.ignore(1);
	fstream f;
	f.open(filename, ios::in|ios::out);
	if(!f)
	{
		cout<<"F1 does not exist"<<endl;
	}
	while(true)
	{
		
		int ch;
		cout<<"Enter 1 to write data"<<endl<<"Enter 2 to read data"<<endl<<"Enter 3 to exit"<<endl;
		cin>>ch;

		if(ch==1)
		{
			string info;
			cout<<"Enter some information"<<endl;
			getline(cin, info);
			f<<"Hello This is Class SE3";
			f.seekg(0,ios::beg);
		}
		else if(ch==2)
		{
			char x;
			while(true)
			{
				x = f.get();
				if(f.eof())break;
				cout<<x;
			}

		}
		else if(ch ==3)
		{
			break;
		}
		else
		{
			cout<<"Please Renter correct choice"<<endl;
		}
		f.close();
	}
	return 0;
}
