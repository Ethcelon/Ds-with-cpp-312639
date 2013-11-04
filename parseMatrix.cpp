#include<iostream>
//#define r  5
//#define c  5
using namespace std;


template<class T>
class sparse;


template<class T>
class term
{
private:
	int row,col;
	T val;
public:
	friend class sparse<T>;
	term(){}
	term(int r, int c, T v)
	{
		row = r;
		col = c;
		val = v;
	}
	void append(int r, int c, T v)
	{
		row = r;
		col = c;
		val = v;
	}	
	void display()		
	{
		cout<<"\n"<<row<<"\t"<<col<<"\t"<<val;
	}
};

template<class T>
class sparse
{
	private:
		int maxsize;	
		int Not;
		int nrows;
		int ncols;
		term<T> *element;
	public:
		sparse(int size)
		{
			maxsize = size;
			Not=nrows=ncols=0;
			element = new term<T>[maxsize];
		}
	void setsparse(const int a[5][5], int r, int c);
	void display();
};

template<class T>
void sparse<T>::setsparse(const int a[5][5], int r, int c)
{
	nrows =	r;
	ncols = c;
	int count = 0;
	cout<<"The sparse matrix is:\n";
	cout<<"Row"<<"\tCol"<<"\tElement"<<endl;
	for(int i=0; i<r; i++)
		for(int j=0; j<c;j++)
			if(a[i][j]!=0)
				element[count++].append(i,j,a[i][j]);
	Not = count;
}

template<class T>
void sparse<T>::display()
{
	cout<<"number of rows:"<<nrows<<"\nnumber of columns: "<<ncols<<"\nNumber of terms: "<<Not<<endl;
	cout<<"The sparse matrix is:\n";
	cout<<"Row"<<"\tCol"<<"\tElement"<<endl;
	for(int i=0; i<Not; i++)
		element[i].display();
	cout<<endl;
}



int main()
{
	int arr[5][5] = {0,2,0,0,0 ,0,0,0,10,0 ,0,0,0,0,7 ,0,2,0,0,1, 2,0,0,0,0};
	sparse<int> s1(10);
	s1.setsparse(arr,5,5);	 
	s1.display();
	return 0;
}
