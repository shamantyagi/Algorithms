#include <bits/stdc++.h>
using namespace std;

int main() {

    int t,n,i,j,a[110],x[110];
    
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        for(i=0;i<n;i++)
            cin>>a[i];
            
        memset(x,10000,sizeof(x));
        

        if(a[0]==0) x[0]=10000;
        else x[0]=0;
        
        for(i=0;i<n;i++)
        {
            if(x[i]==10000) {x[n-1]=-1;break;}
            for(j=1;j<=a[i]&&i+j<n;j++)
            {
                x[i+j]=min(x[i+j],x[i]+1);
            }
        }
        

    cout<<x[n-1]<<endl;
    }
	return 0;
}


/*link - http://www.practice.geeksforgeeks.org/problem-page.php?pid=153*/