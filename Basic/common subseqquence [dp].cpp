#include <bits/stdc++.h>
using namespace std;

int dp[103][103];


int main() {
	int t,m,n,i,j;
	
	cin>>t;
	
	while(t--)
	{
	    cin>>m>>n;
	    
	    string a,b;
	    
	    cin>>a>>b;
	    
	    m=a.length();
	    n=b.length();

        memset(dp,0,sizeof(dp));
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                
                if(a[i] == b[j])
                {
                    dp[i+1][j+1]=1+dp[i][j];
                }
                else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
                
                
            }
        }
        cout<<dp[m][n]<<endl;
	}
	
	return 0;
}

/*link - http://www.practice.geeksforgeeks.org/problem-page.php?pid=152*/