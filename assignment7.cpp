#include<iostream>
using namespace std;
template <class T> class matrix
  {
	T m[10][10];
	int row,col;
     public:
	matrix(int a ,int b)
	{
		row=a;col=b;
	}
	void accept();
	void display();
	matrix addition(matrix);
	matrix sub(matrix);
	matrix trans();
	matrix mul(matrix);
  };
template<class T>void matrix<T>::accept()
{
	for(int i=0;i<row;i++)
	   for(int j=0;j<col;j++)
		cin>>m[i][j];
}
template<class T>void matrix<T>::display()
{
	for(int i=0;i<row;i++)
	   {	cout<<"\n";
		for(int j=0;j<col;j++)
		   cout<<"\t"<<m[i][j];
	   }
}
template<class T>matrix<T> matrix<T>::addition(matrix<T> B)
{
	matrix<T> C(row,col);
	for(int i=0;i<row;i++)
	   for(int j=0;j<col;j++)
		C.m[i][j]=m[i][j]+B.m[i][j];
	return C;
}
template<class T>matrix<T> matrix<T>::sub(matrix<T> B)
{
	matrix<T> C(row,col);
	for(int i=0;i<row;i++)
	   for(int j=0;j<col;j++)
		C.m[i][j]=m[i][j]-B.m[i][j];
	return C;
}
template<class T>matrix<T> matrix<T>::trans()
{
	matrix<T> C(row,col);
	for(int i=0;i<row;i++)
	   for(int j=0;j<col;j++)
		C.m[i][j]=m[j][i];
	return C;
}
template<class T>matrix<T> matrix<T>::mul(matrix<T> B)
{
	matrix<T> C(row,col);
	for(int i=0;i<row;i++)
	{
	   for(int j=0;j<col;j++)
	   {
		C.m[i][j]=0;
              for(int k=0;k<row;k++)
	         {
		C.m[i][j]=C.m[i][j]+(m[i][k]*B.m[k][j]);
	         }
	   }
	}
	return C;
}
int main()
   {
	int r,c,choice;
	do{
	cout<<"\n1.Integer\n2.Float\n3.Exit\n";
	cin>>choice;
	cout<<"\nEnter matrix Size(row&col): ";
		cin>>r>>c;
	if (choice==1)
	{
	matrix<int> A(r,c),B(r,c),C(r,c);
	cout<<"\nEnter matrix1 Elements";
	A.accept();
	cout<<"\nEnter matrix2 Elements";
	B.accept();
	cout<<"\nMatrix1 is: \n";
		A.display();
	cout<<"\nMatrix2 is: \n";
		B.display();
	C=A.addition(B);
	cout<<"\nMatrix Addition is: \n";
	C.display();
		C=A.sub(B);
	cout<<"\nMatrix subtraction is: \n";
	C.display();
		C=A.trans();
	cout<<"\nMatrix transposition is: \n";
	C.display();
		C=A.mul(B);
	cout<<"\nMatrix multiplication is: \n";
	C.display();
	}
	else
	{
	matrix<float> A(r,c),B(r,c),C(r,c);
	cout<<"\nEnter matrix1 Elements";
	A.accept();
	cout<<"\nEnter matrix2 Elements";
	B.accept();
	cout<<"\nMatrix1 is: \n";
		A.display();
	cout<<"\nMatrix2 is: \n";
		B.display();
	C=A.addition(B);
	cout<<"\nMatrix Addition is: \n";
	C.display();
		C=A.sub(B);
	cout<<"\nMatrix subtraction is: \n";
	C.display();
		C=A.trans();
	cout<<"\nMatrix transposition is: \n";
	C.display();
		C=A.mul(B);
	cout<<"\nMatrix multiplication is: \n";
	C.display();
	}	
   }while(choice!=3);
}
/*output
1.Integer
2.Float
3.Exit
1

Enter matrix Size(row&col): 3
3

Enter matrix1 Elements1
2
3
4
5
6
7
8
9

Enter matrix2 Elements9
8
7
6
5
4
3
2
1

Matrix1 is: 

	1	2	3
	4	5	6
	7	8	9
Matrix2 is: 

	9	8	7
	6	5	4
	3	2	1
Matrix Addition is: 

	10	10	10
	10	10	10
	10	10	10
Matrix subtraction is: 

	-8	-6	-4
	-2	0	2
	4	6	8
Matrix transposition is: 

	1	4	7
	2	5	8
	3	6	9
Matrix multiplication is: 

	30	24	18
	84	69	54
	138	114	90
1.Integer
2.Float
3.Exit
2

Enter matrix Size(row&col): 3
3

Enter matrix1 Elements1.1
2.2
3.3
4.4
5.5
6.6
7.7
8.8
9.9

Enter matrix2 Elements9.9
8.8
7.7
6.6
5.5
4.4
3.3
2.2
1.1

Matrix1 is: 

	1.1	2.2	3.3
	4.4	5.5	6.6
	7.7	8.8	9.9
Matrix2 is: 

	9.9	8.8	7.7
	6.6	5.5	4.4
	3.3	2.2	1.1
Matrix Addition is: 

	11	11	11
	11	11	11
	11	11	11
Matrix subtraction is: 

	-8.8	-6.6	-4.4
	-2.2	0	2.2
	4.4	6.6	8.8
Matrix transposition is: 

	1.1	4.4	7.7
	2.2	5.5	8.8
	3.3	6.6	9.9
Matrix multiplication is: 

	36.3	29.04	21.78
	101.64	83.49	65.34
	166.98	137.94	108.9
1.Integer
2.Float
3.Exit
3
*/
