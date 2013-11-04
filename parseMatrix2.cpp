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
		void append(const term<T> &s)
		{
			row=s.row;
			col=s.col;
			val=s.val;
		}
		void readTerm();
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

		void readSparse();
		sparse<T> operator ~();
		sparse<T> operator +(sparse<T>);
};

	template<class T>
void sparse<T>::setsparse(const int a[5][5], int r, int c)
{
	nrows =	r;
	ncols = c;
	int count = 0;

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
	template<class T>
void sparse<T>::readSparse()
{
	cout<<"Enter number of columns, number of rows, and number of terms:";
	cin>>ncols>>nrows>>Not;
	cout<<"Enter individual terms of sparse matrix\n";
	for(int i=0; i<Not;i++)
		element[i].readTerm();
}
	template<class T>
void term<T>::readTerm()
{
	cout<<"Enter row number, col number, values:";
	cin>>row>>col>>val;
}
	template<class T>
sparse<T> sparse<T>::operator ~()
{
	sparse<T> res(maxsize);
	res.nrows=ncols;
	res.ncols=nrows;
	res.Not = 0;
	for(int i=0; i<ncols;i++)
		for(int j=0;j<Not;j++)
			if(element[j].col == i)
			{
				res.element[res.Not].append(element[j].col,element[j].row,element[j].val);
				res.Not++;
			}
	return res;
}

template<class T>
sparse<T> sparse<T>::operator +(sparse<T> s2)
{	
	sparse<T> s3(20);
	s3.ncols = ncols;
	s3.nrows = nrows;
        s3.Not = 0;
	if(nrows = s2.nrows && 	ncols == s2.ncols)
	{	
		
		int j=0;
		int k=0;
		for(int i=0;i<nrows;i++)
		{
			while(j<Not && k<s2.Not)
			{
				if(element[j].row == i && s2.element[k].row == i)
				{
					if(element[j].col == s2.element[k].col)
					{
						s3.element[s3.Not++].append(element[j].row,element[j].col,element[j].val + s2.element[k].val);
 						j++;
						k++;
					} 
					else if(element[j].col < s2.element[k].col)
					{
						s3.element[s3.Not++].append(element[j++]);
					}

					else if(s2.element[k].col < element[j].col)
					{
						s3.element[s3.Not++].append(s2.element[k++]);
				
					}
					
				}		
				else if(element[j].row == i)
					s3.element[s3.Not++].append(element[j++]);
				else if(s2.element[k].row == i)
					s3.element[s3.Not++].append(s2.element[k++]);
				else
					i++;
			}
			for(;j<Not;j++)
				s3.element[s3.Not++].append(element[j]);
			for(;k<s2.Not;k++)
				s3.element[s3.Not++].append(s2.element[k]);

		}
	
	}	
	return s3;
	
}



int main()
{
	int arr[5][5] = {0,2,0,0,0 ,0,0,0,10,0 ,0,0,0,0,7 ,0,2,0,0,1, 2,0,0,0,0};
	sparse<int> s1(10);
	s1.setsparse(arr,5,5);	
	cout<<"The set sparse matrix is:\n"; 
	s1.display();
	cout<<endl;
	sparse<int> s2(10);
	s2.readSparse();
	cout<<"You entered :\n";
	s2.display();
	cout<<endl;
	sparse<int> s3(10);
	sparse<int> s4(20);
	s3 = ~s2;
	cout<<"The transposed matrix is:\n";
	s3.display();
	cout<<"\nTrying to add the 2:\n";
	s4=s3+s2;
	s4.display();



	return 0;
	
}
