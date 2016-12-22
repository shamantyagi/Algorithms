/*
SEGMENT TREE - insertion and search only
*/
#include <iostream>
#include <queue>
#include <math.h>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi segtree,v;

void init_segtree(int n)
{
    int length=(int)(2*pow( 2 , ceil(log2(n)) )) - 1;        /*  2*2^ceil(log(n))-1  */
    
    segtree.resize(length,0);

}

/* build starts : int node stores 1-based values */
void build_segtree( int node, int b, int e)
{   
    if(b==e){
        segtree[node-1]=v[b];
        return;
    } 
    
    int mid= (b+e) /2;
    
    /* traversing both nodes */
    build_segtree(2*node,b,mid);
    build_segtree(2*node+1,mid+1,e);
    
    /* using result from both nodes 0-based index*/
    segtree[node-1]= segtree[2*node-1]+segtree[2*node];
    
}
/* build ends here*/

/* query starts : int node stores 1-based values */
int query_segtree(int node, int i, int j, int b, int e)
{
    int mid=(b+e)/2;
 
    if(b==i && e==j)        /* if conditon satisfy purrrfectly */
    { 
        return segtree[node-1];
    }
    else if(i>=b && j<=mid)        /* left tree */
    {
        return query_segtree(2*node,i,j,b,mid);
    }
    else if(i>=mid+1 && j<=e)       /* right tree */
    {
        return query_segtree(2*node+1,i,j,mid+1,e);
    }
    else if(i<=mid && j>=mid+1) /* dividing according to the condition */
    {     
        return query_segtree(2*node,i,mid,b,mid) + query_segtree(2*node+1,mid+1,j,mid+1,e);
    }

}

int main() {

    int i,n,x,b,e;
    
    /* number of elements */
    cin>>n;

    init_segtree(n);
    
    /* input elements */
    while(n--)
    {
        cin>>x;
        v.push_back(x);
    }
    
    build_segtree(1,0,v.size()-1);
    
    /* taking range input in 1-based */
    cin>>b>>e;

    /* making query in 0-based */
    cout<<query_segtree(1, b-1, e-1, 0, v.size()-1);
    
//    for(i=0;i<segtree.size();i++) cout<<segtree[i]<<" ";

    	return 0;
}
