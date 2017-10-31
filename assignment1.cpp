#include<iostream>
using namespace std;
class wreport
{
	private:
	int day,ht,lt,rain,snow;
	public:
	wreport()
	{
		day=0;
		ht=0;
		lt=0;
		rain=0;
		snow=0;
	}//default constructor
	wreport(int a,int b,int c, int d, int e)
	{
		day=a;
		ht=b;
		lt=c;
		rain=d;
		snow=e;

	}//parameterised constructor
	wreport(wreport &w)
	{
		day=w.day;
		ht=w.ht;
		lt=w.lt;
		rain=w.rain;
		snow=w.snow;
	}//copy constructor

	void getdata()
	{
		cout<<"\nEnter the day\n";
		cin>>day;
		cout<<"\nEnter High temperature\n";
		cin>>ht;
		cout<<"\nEnter low temperature\n";
		cin>>lt;
		cout<<"\nEnter Rainfall\n";
		cin>>rain;
		cout<<"\nEnter Snowfall\n";
		cin>>snow;
	}
	void display ()
	{
		cout<<"\n"<<day<<"\t"<<ht<<"\t"<<lt<<"\t"<<rain<<"\t"<<snow;
	}
	static void average(int n,wreport *w)
	{	
		int i,aht,alt,arain,asnow,sht,slt,srain,ssnow;
		aht=alt=arain=asnow=sht=slt=srain=ssnow=0;
		for (i=0;i<n;i++)
			{	
				sht+=w[i].ht;
				slt+=w[i].lt;
				srain+=w[i].rain;
				ssnow+=w[i].snow;
			}
			aht=sht/n;
			alt=slt/n;
			arain=srain/n;
			asnow=ssnow/n;
			cout<<"\nAvg high temp\tAvg low temp\tAvg rainfall\tAvg snowfall\n";
			cout<<"\n"<<aht<<"\t\t"<<alt<<"\t\t"<<arain<<"\t\t"<<asnow;
	}
};
int main()
{	
	int choice,i,n;
	

	wreport wa;					//default constuctor get called
	wreport wb(1,2,3,4,5);			//parameterized constuctor get called
	wreport wc(wb);				//copy constuctor get called
	//wa.display();				0,0,0,0,0
	//wb.display();				1,2,3,4,5
	//wc.display();				1,2,3,4,5
	wreport w[31];

do
{
	cout<<"\nEnter choice:\n(1)Store data \n(2)Display Data\n(3)Exit\n";
	cin>>choice;
switch (choice)	
{
	case 1:
			cout<<"Enter number of days\n";
			cin>>n;
			cout<<"Enter data\n";
			for (i=0;i<n;i++)
			{
				w[i].getdata();
				
			}
			break;
	case 2:
			cout<<"\nday\thtemp\tltemp\train\tsnow";
			for (i=0;i<n;i++)
			{	
				w[i].display();
				
			}
			w[0].average(n,w);
}	
}while(choice!=3);
}
/*
OUTPUT
[it@localhost ~]$ g++ wreport.cpp
[it@localhost ~]$ ./a.out
Enter choice:
(1)Store data 
(2)Display Data
(3)Exit
1
Enter number of days
3
Enter data
Enter the day
1
Enter High temperature
1
Enter low temperature
1
Enter Rainfall
1
Enter Snowfall
1
Enter the day
2
Enter High temperature
2
Enter low temperature
2
Enter Rainfall
2
Enter Snowfall
2
Enter the day
3
Enter High temperature
3
Enter low temperature
3
Enter Rainfall
3
Enter Snowfall
3
Enter choice:
(1)Store data 
(2)Display Data
(3)Exit
2
day	htemp	ltemp	rain	snow
1	1	1	1	1
2	2	2	2	2
3	3	3	3	3
Avg high temp	Avg low temp	Avg rainfall	Avg snowfall
2    		2		2		2
Enter choice:
(1)Store data 
(2)Display Data
(3)Exit
3
*/
