#include<iostream>
#include<vector>
#include<queue>

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
queue <int> q;
int i,val,temp;

q.push(start);
visited[start]=true;

while(!q.empty())
{
	val=q.front();
	process(val);

	q.pop();
	
	for(i=0;i<adj[val].size();i++)
	{
		temp = adj[val][i];
		
		if(visited[temp] == false)
		{
			q.push(temp);
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