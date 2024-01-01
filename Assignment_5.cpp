//============================================================================
// Name        : 696969696_Assignment_4.cpp
// Author      : lol
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// Write a function template selection sort. Write a program that
// inputs, sorts and outputs an integer array and a float array.
//============================================================================

#include <iostream>
using namespace std;


template <class T>
void showarr(T arr[], int n)
{
	for(int i=0; i<n; i++)
	{	
		if(i == (n-1)) cout<<arr[i]<<endl;
		
		else cout<<arr[i]<<", ";
	}
}

template <class T>
void selection_sort(T arr[], int n)
{
	T temp;

	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j= i+1; j<n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	showarr(arr, n);

}
template <class T>
void insertion_sort(T arr[], int n)
{
	T key;
	for (int i = 1; i<n; i++)
	{
		key = arr[i];
		int j = i-1;
		while(j >= 0 && key < arr[j])
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	showarr(arr, n);
}



int main()
{
	int n;
	again:
	{

	}
	while(true)
	{
		cout<<"Enter size of array"<<endl;
		cin>>n;
		float arr[n];
		cout<<"Enter Elements of array"<<endl;
		for(int i=0; i<n; i++)
		{
			cin>>arr[i];
		}
		cout<<"Enter \n1 for Selection Sort \n2 for Insertion Sort \n3 to exit"<<endl;
		int ch;
		cin>>ch;
		switch (ch)
		{
		case 1:
			cout<<"-------------------------------------------------------------------"<<endl;
			cout<<"Selection Sort"<<endl;
			cout<<"Unsorted Array ->";
			showarr(arr, n);
			cout<<"Sorted Array ->";
			selection_sort(arr, n);
			break;
		case 2:
			cout<<"-------------------------------------------------------------------"<<endl;
			cout<<"Insertion Sort"<<endl;
			cout<<"Unsorted Array ->";
			showarr(arr, n);
			cout<<"Sorted Array ->";
			selection_sort(arr, n);
			break;
		case 3:
			cout<<"Program Exited"<<endl;
			exit(0);
		
		default:
			break;
		}
	}
	return 0;
}
