
#include<iostream>
#include<fstream>

using namespace std;

class  student
{
  int roll;
  char name[10];
  public:
       void writedata();
       void readdata();

};


void student::writedata()
{

string s;
fstream fp;

fp.open("a.txt",ios::out);
cout<<"\nEnter the roll number and name:";
cin>>roll>>name;
getline(cin,s);
fp<<"roll no:"<<roll<<endl;
fp<<"name:"<<name;
fp.close();

}
void student::readdata()
{
 char c;
 fstream fp;
fp.open("a.txt",ios::in);

while(!fp.eof())
{

c=fp.get();
cout<<c;

}

fp.close();
}


int main()
{
  student obj;
  obj.writedata();
  obj.readdata();


}

/*
    OUTPUT

[it@localhost ~]$ g++ oopl10.cpp
[it@localhost ~]$ ./a.out

Enter the roll number and name: 207131
RUTIKA
roll no:207131
name:RUTIKA�[it@localhost ~]$ 


*/




