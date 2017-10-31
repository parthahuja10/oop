#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Student
{
	private:
		int roll;
		char name[20];
	public:
		Student()
		{
			roll=0;
		}
		void accept()
		{
			cout<<"\nEnter Rol No : ";
			cin>>roll;
			cout<<"\nEnter Name : ";
			cin>>name;
		}
		void display()
		{
			cout<<"\n"<<roll<<"\t"<<name;
		}
		int getRoll()
		{
			return roll;
		}
};


void create()
{
	Student S;
	char ch='y';
	ofstream fp;
	fp.open("records.txt");
	while(ch == 'y')
	{
		S.accept();
		fp.write(reinterpret_cast<char *>(&S),sizeof(S));
		cout<<"\nDo you want to add more ? (y/n) : ";
		cin>>ch;
	}
}

void display()
{
	Student S;
	ifstream fp;
	fp.open("records.txt",ios::in);
	fp.read(reinterpret_cast<char *>(&S),sizeof(S));
	cout<<"\nRollNo\tName";
	while(!fp.eof())
	{
		S.display();
		fp.read(reinterpret_cast<char *>(&S),sizeof(S));
	}
}

void add()
{
	Student S;
	char ch='y';
	ofstream fp;
	fp.open("records.txt",ios::app);
	while(ch == 'y')
	{
		S.accept();
		fp.write(reinterpret_cast<char *>(&S),sizeof(S));
		cout<<"\nDo you want to add more ? (y/n) : ";
		cin>>ch;
	}
}

void search()
{
	Student S;
	int roll,flag=0;
	ifstream fp;
	fp.open("records.txt",ios::in);
	fp.read(reinterpret_cast<char *>(&S),sizeof(S));
	cout<<"\nEnter Roll no to search : ";
	cin>>roll;
	while(!fp.eof())
	{
		if(S.getRoll() == roll)
		{
			cout<<"\nRecord Found";
			cout<<"\nRollNo\tName";
			S.display();
			flag =1;
		}
		fp.read(reinterpret_cast<char *>(&S),sizeof(S));
	}
	if(flag == 0)
	{
		cout<<"\nRecord not found.";
	}
}

void modify()
{	
	Student S;
	int roll,flag;
	ifstream fpr;
	ofstream fpw;
	cout<<"\nEnter Roll No to modify : ";
	cin>>roll;
	fpr.open("records.txt",ios::in);
	fpw.open("temp.txt");
	fpr.read(reinterpret_cast<char *>(&S),sizeof(S));
	while(!fpr.eof())
	{
		if(S.getRoll() == roll)
		{
			S.accept();
			fpw.write(reinterpret_cast<char *>(&S),sizeof(S));
			flag =1;
		}
		else
		{
			fpw.write(reinterpret_cast<char *>(&S),sizeof(S));
		}
		fpr.read(reinterpret_cast<char *>(&S),sizeof(S));
	}
	if(flag == 0)
	{
		cout<<"\nRecord not found.";
	}
	remove("records.txt");
	rename("temp.txt","records.txt");
}

void delete_record()
{
	Student S;
	int roll,flag;
	ifstream fpr;
	ofstream fpw;
	cout<<"\nEnter Roll No to delete : ";
	cin>>roll;
	fpr.open("records.txt",ios::in);
	fpw.open("temp.txt");
	fpr.read(reinterpret_cast<char *>(&S),sizeof(S));
	while(!fpr.eof())
	{
		if(S.getRoll() == roll)
		{
			flag =1;
		}
		else
		{
			fpw.write(reinterpret_cast<char *>(&S),sizeof(S));
		}
		fpr.read(reinterpret_cast<char *>(&S),sizeof(S));
	}
	if(flag == 0)
	{
		cout<<"\nRecord not found.";
	}
	remove("records.txt");
	rename("temp.txt","records.txt");
}

int main()
{
	int ch;
	while(true)
	{
		cout<<"\n1. Create\t2. Add\n3. Modify\t4. Delete\n5. Search\t6. Display\n7. Exit";
		cout<<"\nEnter Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: create();
				break;
				
			case 2: add();
				break;
				
			case 3: modify();
				break;
				
			case 4: delete_record();
				break;
				
			case 5: search();
				break;
				
			case 6: display();
				break;
				
			case 7: return 1;
			default: cout<<"\nInvalid Choice.";
		}
	}
}


/*
[it@localhost ~]$ g++ oopl8.cpp
[it@localhost ~]$ ./a.out

1. Create	2. Add
3. Modify	4. Delete
5. Search	6. Display
7. Exit
Enter Choice : 1

Enter Rol No : 207131

Enter Name : RUTIKA

Do you want to add more ? (y/n) : Y

1. Create	2. Add
3. Modify	4. Delete
5. Search	6. Display
7. Exit
Enter Choice : 2

Enter Rol No : 207111

Enter Name : AKSHATA

Do you want to add more ? (y/n) : Y

1. Create	2. Add
3. Modify	4. Delete
5. Search	6. Display
7. Exit
Enter Choice : 2     

Enter Rol No : 207138

Enter Name : SIDDHI

Do you want to add more ? (y/n) : Y

1. Create	2. Add
3. Modify	4. Delete
5. Search	6. Display
7. Exit
Enter Choice : 6

RollNo	Name
207131	RUTIKA
207111	AKSHATA
207138	SIDDHI
1. Create	2. Add
3. Modify	4. Delete
5. Search	6. Display
7. Exit
Enter Choice : 3

Enter Roll No to modify : 207138

Enter Rol No : 207104

Enter Name : YASH

1. Create	2. Add
3. Modify	4. Delete
5. Search	6. Display
7. Exit
Enter Choice : 6

RollNo	Name
207131	RUTIKA
207111	AKSHATA
207104	YASH
1. Create	2. Add
3. Modify	4. Delete
5. Search	6. Display
7. Exit
Enter Choice : 4

Enter Roll No to delete : 207104

1. Create	2. Add
3. Modify	4. Delete
5. Search	6. Display
7. Exit
Enter Choice : 6

RollNo	Name
207131	RUTIKA
207111	AKSHATA
1. Create	2. Add
3. Modify	4. Delete
5. Search	6. Display
7. Exit
Enter Choice : 5

Enter Roll no to search : 207131

Record Found
RollNo	Name
207131	RUTIKA
1. Create	2. Add
3. Modify	4. Delete
5. Search	6. Display
7. Exit
Enter Choice : 6

RollNo	Name
207131	RUTIKA
207111	AKSHATA
1. Create	2. Add
3. Modify	4. Delete
5. Search	6. Display
7. Exit
Enter Choice : 7
[it@localhost ~]$ 

*/
