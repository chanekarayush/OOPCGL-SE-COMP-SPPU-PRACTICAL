//============================================================================
// Name        : Assignments_696969696.cpp
// Author      : lol
// Version     : 1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

class Complex
{
	int real, img;
	public:
	Complex()
	{
		real = 0, img = 0;
	}
	Complex(int x,int y){
		real = x,img = y;
	}

	Complex(Complex& cpy_obj) //Copy Constructor
	{
		real = cpy_obj.real;
		img = cpy_obj.img;
	}

	Complex operator+(Complex c1)
	{
		Complex c;
		c.real = real + c1.real;
		c.img = img + c1.img;
		return c;
	}
    Complex operator*(Complex c)
    {
        Complex temp;
        temp.real = (real*(c.real) - img*(c.img));
        temp.img = (real*(c.img) +(img*c.real));
        return temp;
    }
// Display Complex Number from the user 
    Complex operator<<(Complex c)
    {
        cout<<c.real<<" "<<c.img<<"i"<<endl;
    }

// Reading a Complex Number from User 
    Complex operator>>(Complex c)
    {
        cin>>c.real>>c.img;
        real = c.real, img = c.img;
    }
    
};

int main()
{
	int a1, a2, b1, b2;
	cout<<"----------------------------------------------------------------------------------- \n"
    "Enter an Imaginary Number in the form a + bi"<<endl;
	cin>>a1>>b1;

    Complex ob1;
    Complex ob2(a1,b1);
    int i;

    inner_loop:
    {

    }
    cout<<"---------------------------------------------------------------------------------- \n"
    "Enter 1 for Sum of imaginary numbers "
    "\n Enter 2 for Product of Imaginary Numbers "
    "\n Enter 3 to Input a complex number"
    "\n Enter 4 to Display Complex Number"
    "\n Enter 5 to Exit"<<endl;
    cin>>i;
    switch (i)
    {
    case 1:
    {
        Complex c;
        c = (ob1+ob2);
        c.operator<<(c);
        goto inner_loop;

    }
    case 2:
    {
        Complex c;
        c = (ob1*(ob2));
        c<<(c);
        goto inner_loop;
    }
    case 3:
    {
        ob1>>(ob1);
        goto inner_loop;
    }
    case 4:
    {
        ob1<<(ob1);   
        goto inner_loop;
    }
    case 5:
    {
        goto Outer_loop;
        // goto inner_loop;
    }
    default:
    {
        cout<<"Invalid Input"<<endl;
        goto inner_loop;
    }
        
    }

    Outer_loop:
    {
        cout<<"Exited Program"<<endl;
    }

}




