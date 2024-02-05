// function to ceck path is exist or not between nodes of graph
// by running dfs we can easily find

#include<iostream>
#include<list>

using namespace std;

class Graph{
    int V;
    list<int> *adj;

    public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isReachable(int s, int d);

};

Graph:: Graph(int V){
    this->V= V;
    adj = new list<int> [V];
}

void Graph:: addEdge(int v, int w){
    adj[v].push_back(w);
}


bool Graph:: isReachable(int s, int d){
  if(s==d) return true;
   bool *visited = new bool[V];
   for(int i= 0; i<V; i++)
   visited[i] = false;

   list<int> queue;
   visited[s] = true;
   queue.push_back(s);

   list<int>:: iterator i;

   while(!queue.empty()){
    s= queue.front();
    queue.pop_front();
    for(i = adj[s].begin(); i!= adj[s].end(); ++i){
        if(*i == d) return true;

        if(!visited[*i]){
            visited[*i] = true;
            queue.push_back(*i);
        }
    }
   }  return false;
}

//driver code
int main(){
Graph g(4);
g.addEdge(0, 1);
g.addEdge(0, 2);
g.addEdge(1, 2);
g.addEdge(2, 0);
g.addEdge(2, 3);
g.addEdge(3, 3);


cout<<"enter the source and destination vertices: (0-3)";
int u , v;
cin >>u>>v;

if(g.isReachable(u, v))
cout<<"\n path exist" << u << " to" << v;
else
cout <<"\n no path exist from " << u << " to" <<v;

int temp ;
temp = u;
u = v;
v= temp;

if (g.isReachable(u, v))
cout << "\n there is path from " << u << "to "<<v;
else 
cout << "no path from" << u << "to "<< v;

return 0;


}