

//Program to get marks and average

#include<iostream>
using namespace std;
class student
{
	private:
		int sno,m1,m2,m3;
		char sname[20],address[100];
		
	public:
		
		void getdata()
		{
			cout<<"enter sno,name,address,m1,m2,m3:";
			cin>>sno>>sname>>address>>m1>>m2>>m3;
		}
		float findavg()
		{
			float avg=(m1+m2+m3)/3.0;
			return avg;
		}
		void putdata()
		{
			cout<<"student number:"<<sno<<"\nStudent name:"<<sname<<"\nAddress:"<<address<<"\nmarks of 3 subjects:"<<m1<<" "<<m2<<" "<<m3<<"\nAverage:"<<findavg();
		}
};

int main()
{
	student st;
	st.getdata();
	st.putdata();
	return 0;
}
			
