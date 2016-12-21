#include<iostream>
#include<vector>
#include<stack>

#define LIM 100

using namespace std;

vector <int> adj[LIM];
bool visited[LIM];

void initialise()
{
    for(int i=0;i<LIM;i++)
    {
    adj[i].clear();
    visited[i]=false;
    }
}

void refresh()
{
    for(int i=0;i<LIM;i++)  visited[i]=false;
}

void process(int val)
{
    cout<<val<<" -> ";
}

void bfs(int start)
{
    stack <int> s;
    int i,val,temp;

    s.push(start);
    visited[start]=true;

    while(!s.empty())
    {
        val=s.top();
        process(val);

        s.pop();

        for(i=0;i<adj[val].size();i++)
        {
            temp = adj[val][i];

            if(visited[temp] == false)
            {
                s.push(temp);
                visited[temp]=true;
            }
        }

    }
}

void insert(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);

}

int main()
{
    int nodes,edges,x,y,i,j;

    cin>>nodes>>edges;

    initialise();

    for(i=0;i<edges;i++)
    {
        cin>>x>>y;
        insert(x,y);
    }


    bfs(1);

    return 0;

}
