//============================================================================
// Name        : Assignment_3_696969696.cpp
// Author      : lol
// Version     :
// Copyright   : Your copyright notice
// Description :Imagine a publishing company which does marketing for book and audio cassette versions.
// 				Create a class publication that stores the title (a string) and price (type
// 						float) of publications.
// 				From this class derive two classes:
// 													book which adds a page count (type int)
// 													and tape which adds a playing time in minutes (type float).
// 				Write a program that instantiates the book and tape class, allows user to enter data and
// 				displays the data members.
// 				If an exception is caught, replace all the data member values with zero values.
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;


class Publication
{
protected:
	int x;		//This variable is used to handle the exceptions in the child classes
	string title;
	float price;
public:
	static int count;
	void get_ref()
	{
		cout<<"Enter the Title of the Book"<<endl;
		getline(cin,title);
		cout<<"Enter the Price of the Book"<<endl;
		cin>>price;
		try
		{
			if(price < 0)
				throw x;
			}
		catch(int x)
		{
			price = 0;
		}
	}

	static int counter()
	{
		return ++count;
	}

};

int Publication :: count = 0;


class Book : private Publication
{
private:
	int page_count;
public:
	void get_page()
	{
		get_ref();
		cout<<"Enter the Page count of "<<title<<endl;
		cin>>page_count;
		try
		{
			if(page_count < 0)
				throw x;
			}
		catch(int x)
		{
			page_count = 0;
		}
	}

	void show()
	{
		cout<<"--------------------------------------------------------------------------"<<endl;
		cout<<"Book title - "<<title<<endl;
		cout<<"Book price - "<<price<<endl;
		cout<<"Page Count - "<<page_count<<endl;
	}
};

class Tape : private Publication
{
private:
	int play_time;
public:
	void get_time()
	{
		cout<<"Enter the Playing time of "<<title<<" in minutes."<<endl;
		cin>>play_time;
		try
		{
			if(play_time < 0)
				throw x;
			}
		catch(int x)
		{
			play_time = 0;
		}

	}
	void show()
	{
		cout<<"Playing time - "<<play_time<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
	}
};

int main() {
	Book data1[100];
	Tape data2[100];
	int i = 0;
	char ch;
	do
	{
		data1[i].get_page();
		data2[i].get_time();
		cout<<"Is there another book you wish to add? \n Enter \"y\" or \"n\" "<<endl;
		cin>>ch;
		cin.ignore(1);
		Publication::counter();
		i++;
	}while(ch == 'y' || ch == 'Y');

	Publication :: count--;
	cout<<"Total Count of books - "<<Publication::counter()<<endl;

	for(int j=0; j<Publication::count; j++)
	{
		data1[j].show();
		data2[j].show();
	}


	return 0;
}
