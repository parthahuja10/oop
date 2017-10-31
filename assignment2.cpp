#include<iostream>
#include<string.h>
using namespace std;

class book
{
	private:
               char *title;
               char *author;
               char *publisher;
               float price;
               int stock;
               static int tranctions;//static member
      public:
               book()
               {
                 title =new char[2];
                 author =new char[2];
                 publisher=new char[2];
                 price=0.0;
                 stock=0;
               }
               void accept();
               void display();
               int search(char str[20]);
               void modify();
               void purchase();
               static void fun()
               {
               cout<<"\nnumber of sucess tran"<<tranctions;
               } // static function
};	//class

int book::tranctions;			//static variable defination

void book::accept()
{
	cout<<"enter the title of book";
	cin>>title;
	cout<<"enter the name of author of book";
	cin>>author;
	cout<<"enter the publisher of book";
	cin>>publisher;
	cout<<"enter the price of book";
	cin>>price;
	cout<<"enter the stock of book";
	cin>>stock;
}	// accept
void book::display()
{
	cout<<"\n"<<title<<"\t"<<author<<"\t"<<publisher<<"\t"<<price<<"\t"<<stock;
	
}	//display
int book::search(char key[10])
{
	if(strcmp(title,key)==0)
		return 1;
	else
		return 0;
}
void book::purchase()
{
int count;
cout<<"enter the number of books";
cin>>count;
if(count<=stock)
	{
	stock=stock-count;
	cout<<"\ntotal amount"<<(price)*count;
	tranctions++;
	}
	else
	cout<<"\nsufficient copies are not available";
}
int main()
{
book b[30];
int i,n,ch;
char str[30];
do
{
cout<<"\n\n1.accept\n2.display\n3.search\n4.modify\n5.purchase\n6.number of tranctions\n7.exit";
cout<<"\nEnter the choice";
cin>>ch;
switch(ch)
{
case 1:
	cout<<"\n enter the number of records=";
	cin>>n;
	for(i=0;i<n;i++)
	b[i].accept();
	break;
case 2:
	cout<<"\ntitle\nauthor\npublisher\nprice\nstock";
	for(i=0;i<n;i++)
	b[i].display();
	break;
case 3:
	cout<<"enter the title of book";
	cin>>str;
	for(i=0;i<n;i++)
	{
	if(b[i].search(str))
		{
		cout<<"book found sucessfully";
		break;
		}
	}
	if(i==n)
		cout<<"\nBook not found";
	break;
case 4:
	cout<<"enter the title of book";
	cin>>str;
	for(i=0;i<n;i++)
	{
	if(b[i].search(str))
		{
		cout<<"\nEnter modified data";
		b[i].accept();
		break;
		}
	}
	if(i==n)
		cout<<"\nBook not found";
	break;
case 5:
	cout<<"enter the title of book";
	cin>>str;
	for(i=0;i<n;i++)
	{
	if(b[i].search(str))
		{
		b[i].purchase();
		break;
		}
	}
	if(i==n)
		cout<<"\nBook not found";
	break;
case 6:
	book::fun();
	break;
}
}while(ch<7);
}
/*1.accept
2.display
3.search
4.purchase
5.modify
6.number of tranctions
7.exitenter the choice1

 enter the number of records=2
enter the title of book c
enter the name of author of book kanetkar
enter the publisher of book techmax
enter the price of book 
enter the stock of book11
enter the title of bookc++
enter the name of author of book robert
enter the publisher of book nerali
enter the price of book22
enter the stock of book22


1.accepet
2.display
3.search
4.purchase
5.modify
6.number of tranctions
7.exitenter the choice2

title
author
publisher
price
stock
c	kanetkar	techmax	11	11
c++	robert	nerali	22	22

1.accept
2.display
3.search
4.purchase
5.modify
6.number of tranctions
7.exitenter the choice3
enter the title of bookc++
book found sucessfully

1.accept
2.display
3.search
4.purchase
5.modify
6.number of tranctions
7.exitenter the choice3
enter the title of bookjava

Book not found

1.accept
2.display
3.search
4.purchase
5.modify
6.number of tranctions
7.exitenter the choice5
enter the title of bookc++
enter the number of books25

sufficient copies are not available

1.accept
2.display
3.search
4.purchase
5.modify
6.number of tranctions
7.exitenter the choice5
enter the title of bookc++
enter the number of books10

total amount220

