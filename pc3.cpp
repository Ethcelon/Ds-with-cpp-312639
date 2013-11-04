//TIME!!!
//AUTHOR : Om Bhallamudi
//CONSULTANT: Pranav Pabbati
//OBLIGATORY COPYLEFT
#include<iostream>
#include<stdlib.h>
using namespace std;

class timeclass
{
	private:
		int h,m,s;
	public:
		void set()
		{
		cout<<"\nType the time in h m s (24h convention):";
		cin>>h>>m>>s;
		
		}
		timeclass add(timeclass t1,timeclass t2)
		{
			timeclass t3;
			t3.h = t1.h + t2.h;
			t3.m = t1.m + t2.m;
			t3.s = t1.s + t2.s;
			//we need to do some calculations
			if(t3.s >= 60)
				{	
					t3.m = t3.m+t3.s/60;
					t3.s = t3.s%60;
				}
			if(t3.m >= 60)
				{
					t3.h = t3.h + t3.m/60;
					t3.m = t3.m%60;
				}
			if(t3.h >= 24)
				{
					t3.h = t3.h%24;
				}
			return t3;
		}
		void put()
		{
		cout<<"\nThe time is:"<<h<<":"<<m<<":"<<s;
		}
		void check()
		{
			try
			{
			
			if( s > 60 || m > 60 )
				{
					throw 1;
				}
			if(s<0 || m<0 || h<0)
				{
					throw 1.0;
				}
			}
			catch(int)
				{

					cout<<"\nDUDE PLEASE! ENTER THE TIME WITH MIN AND SEC LESS THAN 60 -__-\n";
					exit(0);
					
				}		
			catch(double)
				{
					cout<<"\nSINCE WHEN DID TIME GO BACKWARDS! OR DID U GET A TIMEMACHINE?\n";
					exit(0);
				}
		}
};		

int main()
{
	timeclass t1,t2,t;
	t1.set();
	t1.check();
	t2.set();
	t2.check();
	t = t.add(t1,t2);
	t.put();
	cout<<endl;
}
