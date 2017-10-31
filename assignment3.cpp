#include<iostream>
using namespace std;
class complex
{
 private:
 	int real,img;
 public:
      complex()
      	{
      	 real=0;
      	 img=0;
      	}// default constructer
      void accept();
      void display();
      friend complex operator+(complex,complex);
      friend complex operator-(complex,complex);
      complex operator*(complex c2);
      complex operator/(complex c2);
      complex(int a,int b)
         {
          real=a;
          img=b;
         }//parametarised constructor
};
  void complex::accept()
  {
  	cout<<"\nenter the real and img number:";
  	cin>>real>>img;
  }
  void complex::display()
  {
   cout<<"\n"<<real<<"+"<<img<<"i";
  }
  complex operator+(complex c1,complex c2)
  {
  	complex c3;
  	c3.real=c1.real+c2.real;
  	c3.img=c1.img+c2.img;
  	return c3;
  }
   complex operator-(complex c1,complex c2)
  {
  	complex c3;
  	c3.real=c1.real-c2.real;
  	c3.img=c1.img-c2.img;
  	return c3;
  }
  complex complex::operator*(complex c2)
  {
   complex c3;
   c3.real=(real*c2.real)-(img*c2.img);
   c3.img=(real*c2.img)+(img*c2.real);
   return c3;
   }
   complex complex::operator/(complex c2)
   {
   complex c3;
   c3.real=((real*c2.real)+(img*c2.img));
   c3.img=((img*c2.real)+(real*c2.img));
   return c3;
   }
   int main()
 {
   complex c1,c2,c3;
   int ch;
   c1.accept();
 c2.accept();
 c1.display();
 c2.display();
do
{
 cout<<"\n1:add\n2:sub\n3:mul\n4:div";
 cout<<"\nENTER YOUR CHOICE:";
 cin>>ch;
 
 switch(ch)
   {
     case 1:
         c3=c1+c2;
         c3.display();
         break;
     case 2:
         c3=c1-c2;
         c3.display();
         break;
     case 3:
         c3=c1*c2;
         c3.accept();
         c3.display();
         break;
     case 4:
         c3=c1/c2;
         c3.display();
         break;
     }    
     }while(ch<5);
     } 
/*[it@localhost ~]$ g++ complex.cpp
[it@localhost ~]$ ./a.out

enter the real and img number:5 
6

enter the real and img number:7
2

5+6i
7+2i
1:add
2:sub
3:mul
4:div
ENTER YOUR CHOICE:1

12+8i
1:add
2:sub
3:mul
4:div
ENTER YOUR CHOICE:
2

-2+4i
1:add
2:sub
3:mul
4:div
ENTER YOUR CHOICE:3

enter the real and img number:4

*/
