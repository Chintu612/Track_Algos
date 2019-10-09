//Finiding k connected components of an undirected graph
#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int V;
	list<int>* adj;
	void DFSUtil(int v,bool visited[]);
	public:
		Graph(int V);
		void addEdge(int u, int v);
		void connectedComponents();		
};
void Graph::connectedComponents()
{
	//Inintialising all vertices as not visited
	bool* visited=new bool[V];
	for(int v=0;v<V;v++)
		visited[v]=false;
	for(int v=0;v<V;v++)
	{
		if(visited[v]==false)
		{
			//Doing DFS traversal from given vertex
			DFSUtil(v, visited);
			cout<<"\n";
		}
	}
}
void Graph::DFSUtil(int v, bool visited[])
{
	visited[v]=true;
	cout<<v<<" ";
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();++i)
	{
		if(!visited[*i])
		{
			DFSUtil(*i, visited);
		}
	}
}
Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
}
void Graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(3, 4);
	g.addEdge(2, 0);
	cout<<"Following are the connected components \n";
	g.connectedComponents();
	return 0;
}
