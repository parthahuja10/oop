#include<iostream>
using namespace std;
class personal
{
    public:
    char nm[10];
    char dob[10];
};
class academic:virtual public personal
{
    public:
    char qual[10];
    char clgnm[10];
};
class professional:virtual public personal
{
    public:
    int empid,salary;
    char cmpnm[10];
    char post[10];
};
class biodata:public academic,public professional
{
    public:
    void accept();
    void display();
    int search(int key);
    int add(biodata *b,int n);
    int del(int i,biodata *b,int n);
};
void biodata::accept()
{
cout<<"\nEnter data(nm,dob,qual,clgnm,cmpnm,post,salary,empid)\n";
cin>>nm>>dob>>qual>>clgnm>>cmpnm>>post>>salary>>empid;
}
void biodata::display()
{
cout<<"\n"<<nm<<"\t"<<dob<<"\t"<<qual<<"\t"<<clgnm<<"\t"<<cmpnm<<"\t"<<post<<"\t"<<salary<<"\t"<<empid;
}
int biodata::search(int key)
{
	if (key==empid)
	return 1;
	else
	return 0;
	
}
int biodata::add(biodata *b,int n)
{
	biodata bnew;
	bnew.accept();
	b[n]=bnew;
	return ++n;
}
int biodata::del(int i,biodata *b ,int n)
{
	for (i;i<n;i++)
	b[i]=b[i+1];
	return --n;
}
int main(void)
{
 int i,n,choice,key;
 biodata b[50];

do
{	cout<<"\n******menu******\n";
	cout<<"1.accept\n2.display\n3.search\n4.modify\n5.add\n6.delete\n7.Exit\n";
	cin>>choice;
	switch (choice)
	{
	 case 1: 
		cout<<"Enter number of records\n";
		 cin>>n;
		 for(i=0;i<n;i++)
		  {
		   b[i].accept();
		  }
		break;
	 case 2:		
		 cout<<"\nName\tDOB\tQual\tClgnm\tCmpnm\tPost\tSalary\tEmpid";
		 for(i=0;i<n;i++)
		  {
		   b[i].display();
		  }
		  break;
	case 3:
		cout<<"Enter Employee id to Search:\n";
		cin>>key;
		 for(i=0;i<n;i++)
       		 {
			if (b[i].search(key))
			{	cout<<"Record Found\n";
				 cout<<"\nName\tDOB\tQual\tClgnm\tCmpnm\tPost\tSalary\tEmpid";
			 	 b[i].display();
				 break;
			}
		}
		if(i==n)
		cout<<"Record not found\n";
		break;
	case 4:
		cout<<"Enter Employee id to Search:\n";
		cin>>key;
		 for(i=0;i<n;i++)
       		 {
			if (b[i].search(key))
			{	cout<<"Record Found\n";
				 b[i].accept();
				 break;
			}
		}
		if(i==n)
		cout<<"Record not found\n";
		break;
	case 5:
		n=b[0].add(b,n);
		break;
	case 6:
		cout<<"Enter Employee id to Delete:\n";
		cin>>key;
		 for(i=0;i<n;i++)
       		 {
			if (b[i].search(key))
			{	
			 	 n=b[i++].del(i,b,n);
				cout<<"\nSuccessfully deleted\n";
				 break;
			}
		}
		if(i==n)
		cout<<"Record not found\n";
		break;
		
	}		
}while(choice!=7);
}

/*output

******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
1
Enter number of records
2

Enter data(nm,dob,qual,clgnm,cmpnm,post,salary,empid)
xyz 1 1 1 1 1 1 1          

Enter data(nm,dob,qual,clgnm,cmpnm,post,salary,empid)
abc 2 2 2 2 2 2 2 

******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
2

Name	DOB	Qual	Clgnm	Cmpnm	Post	Salary	Empid
xyz	1	1	1	1	1	1	1
abc	2	2	2	2	2	2	2
******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
3
Enter Employee id to Search:
2
Record Found

Name	DOB	Qual	Clgnm	Cmpnm	Post	Salary	Empid
abc	2	2	2	2	2	2	2
******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
4
Enter Employee id to Search:
1
Record Found

Enter data(nm,dob,qual,clgnm,cmpnm,post,salary,empid)
name 3 3 3 3 3 3 3

******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
2

Name	DOB	Qual	Clgnm	Cmpnm	Post	Salary	Empid
name	3	3	3	3	3	3	3
abc	2	2	2	2	2	2	2
******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
5

Enter data(nm,dob,qual,clgnm,cmpnm,post,salary,empid)
lmn 6 6 6 6 6 6 6

******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
2

Name	DOB	Qual	Clgnm	Cmpnm	Post	Salary	Empid
name	3	3	3	3	3	3	3
abc	2	2	2	2	2	2	2
lmn	6	6	6	6	6	6	6
******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
6
Enter Employee id to Delete:
2

Successfully deleted
Record not found

******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
2

Name	DOB	Qual	Clgnm	Cmpnm	Post	Salary	Empid
name	3	3	3	3	3	3	3
abc	2	2	2	2	2	2	2
******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
7

******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
1
Enter number of records
2

Enter data(nm,dob,qual,clgnm,cmpnm,post,salary,empid)
xyz 1 1 1 1 1 1 1          

Enter data(nm,dob,qual,clgnm,cmpnm,post,salary,empid)
abc 2 2 2 2 2 2 2 

******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
2

Name	DOB	Qual	Clgnm	Cmpnm	Post	Salary	Empid
xyz	1	1	1	1	1	1	1
abc	2	2	2	2	2	2	2
******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
3
Enter Employee id to Search:
2
Record Found

Name	DOB	Qual	Clgnm	Cmpnm	Post	Salary	Empid
abc	2	2	2	2	2	2	2
******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
4
Enter Employee id to Search:
1
Record Found

Enter data(nm,dob,qual,clgnm,cmpnm,post,salary,empid)
name 3 3 3 3 3 3 3

******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
2

Name	DOB	Qual	Clgnm	Cmpnm	Post	Salary	Empid
name	3	3	3	3	3	3	3
abc	2	2	2	2	2	2	2
******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
5

Enter data(nm,dob,qual,clgnm,cmpnm,post,salary,empid)
lmn 6 6 6 6 6 6 6

******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
2

Name	DOB	Qual	Clgnm	Cmpnm	Post	Salary	Empid
name	3	3	3	3	3	3	3
abc	2	2	2	2	2	2	2
lmn	6	6	6	6	6	6	6
******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
6
Enter Employee id to Delete:
2

Successfully deleted

******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
2

Name	DOB	Qual	Clgnm	Cmpnm	Post	Salary	Empid
name	3	3	3	3	3	3	3
abc	2	2	2	2	2	2	2
******menu******
1.accept
2.display
3.search
4.modify
5.add
6.delete
7.Exit
7


*/

