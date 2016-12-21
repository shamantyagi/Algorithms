/*
problem link : http://codeforces.com/contest/749/problem/C
*/
#include <iostream>
#include<queue>

using namespace std;

int main() {

string s;
int i,x,y,n;

queue<int> d,r;

cin>>n>>s;

for(i=0;i<s.length();i++)
{
if(s[i]=='D')
    d.push(i);
else
    r.push(i);
}

i=0;
while(!r.empty() && !d.empty())
{
    for(i=0;i<s.length();i++)
    {
     if(r.empty()==true || d.empty()==true) break;
     else if(s[i]=='R')
        {
            x=d.front();
            s[x]='x';
            d.pop();
            
            x=r.front();
            r.pop();
            r.push(x);
        }
        else if(s[i]=='D')
        {
            x=r.front();
            s[x]='x';
            r.pop();
            
            x=d.front();
            d.pop();
            d.push(x);
        }

    }
}

if(r.empty())
        cout<<"D";
else    cout<<"R";

	return 0;
}
