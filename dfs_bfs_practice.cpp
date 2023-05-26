#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<bool> &visitedDfs,vector<vector<int>> &graph){
  visitedDfs[node]=true;
  cout<<node<<" ";

  for(int neighbour: graph[node]){
    if(!visitedDfs[neighbour]){
         dfs(neighbour,visitedDfs,graph);
    }
  }

}

void bfs(vector<vector<int>> &graph, vector<bool> &visitedBfs, queue<int> &q){
    if(q.empty()){
      return;
    }
    int current = q.front();
  q.pop();
  visitedBfs[current] = true;
  cout << current << " ";

  for (int neighbor : graph[current]) {
    if (!visitedBfs[neighbor]) {
      q.push(neighbor);
      visitedBfs[neighbor] = true;
    }
  }

  bfs(graph, visitedBfs, q);
}


void bfsRecursive(int node,vector<bool> &visitedBfs,vector<vector<int>> &graph){
   
    queue<int>q;
    q.push(node); 
    visitedBfs[node]=true;

    bfs(graph, visitedBfs, q);
}


int main(){

  vector<vector<int>>graph;
  int n;
  cout<<"Enter no of vertices: ";
  cin>>n;

  for(int i=0;i<n;i++){
    int e;
    cout<<"Enter no of edges of "<<i<<":";
    cin>>e;
    vector<int>edges;
    while(e--){
        int e;
        cout<<i<<"-->";
        cin>>e;
        edges.push_back(e);
    }
    graph.push_back(edges);
  }

  int start;
  cout<<"Enter start vertex: ";
  cin>>start;

  vector<bool>visitedDfs(n,false);
  cout<<"\nDFS:";
  dfs(start,visitedDfs,graph);

  vector<bool>visitedBfs(n,false);
  cout<<"\nBFS:";
  bfsRecursive(start,visitedBfs,graph);

    return 0;
}