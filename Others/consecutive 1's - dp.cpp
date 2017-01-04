/*
link - http://www.practice.geeksforgeeks.org/problem-page.php?pid=252
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main()
{
    
    
    int t,n;
    
    long long int z[71],o[71];
    z[0]=1;
    o[0]=1;
    
    for(int i=1;i<71;i++)
    {
        z[i]=z[i-1]+o[i-1];
        o[i]=z[i-1];
    }
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        cout<<(z[n-1]+o[n-1])%MOD<<endl;
    }
    
    	
    return 0;
}


