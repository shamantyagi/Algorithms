#include <iostream>
using namespace std;

int main() {
    
    int t,n,i,j;
    
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int arr[n];
        int lis[n];
        
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            lis[i]=1;
        }
        
        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(arr[j]<arr[i] && lis[i]<(lis[j]+1) )
                    lis[i]=lis[j]+1;
            }
        }
        
        int max=-10;
        for(i=0;i<n;i++)
        {//cout<<lis[i]<<" ";
            if(max<lis[i]) max=lis[i];
        }    
        cout<<max<<endl; 
    }

	return 0;
}

/*link: http://www.practice.geeksforgeeks.org/problem-page.php?pid=134*/