#include <bits/stdc++.h>
using namespace std;

long long int d[5005],ss[5005];

void init()
{
	for(int i=0;i<5005;i++)
	{
		d[i]=0;
		ss[i]=0;
		
	}
}


int main() 
{

	bool ok=true;
	string s;

	while(1)
	{
	cin>>s;

	if(s!="0")
	{
	init();

	int x,y,i;

	d[1]=0;
	ss[1]=1;

	for(i=0;i<s.length();i++)
	{
	x=s[i]-'0';

	y=-1;

	if(i>0) 
	{
	  y=s[i-1]-'0';
	  y=y*10;
	  y=y+x;
	}

	if(x==0 && (y>26 || y<10))
	{
	  ok=false;
	  break;
	}


	if(i>0)
	{
		if(x!=0)
		{
		if(y<=26 && y>=10) 
			d[i+1] = ss[i];
		
		ss[i+1]=d[i]+ss[i];
		}
		else {
			ss[i+1]=ss[i];
			d[i+1]=0;
		}
	}

	//    cout<<d[i+1]<<" "<<ss[i+1]<<endl;

	}

	if(ok==true) cout<<d[i]+ss[i];
	else cout<<0;

	cout<<endl;
	}

	else break;

	}

	return 0;
}
