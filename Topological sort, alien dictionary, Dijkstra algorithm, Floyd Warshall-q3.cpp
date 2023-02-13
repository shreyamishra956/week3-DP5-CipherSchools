#include <bits/stdc++.h>
using namespace std;
struct Edge{
  int vertex;
  int wt;
  Edge(int d,int w){
    vertex = d;
    wt = w;
  }
};
struct Compare{
  bool operator()(Edge &e1,Edge &e2){
    return (e1.wt < e2.wt)? false:true ;
  }
};
struct Graph{
  int V;
  vector<Edge> *edges;
  Graph(int V){
    this->V = V;
    edges = new vector<Edge>[V];
  }
  void addEdge(int u,int v,int wt){
    edges[u].push_back(Edge(v,wt));
    edges[v].push_back(Edge(u,wt));
  }
  int *dijkstras(int src){
    int *dist = new int[V];
    bool visited[V];
    for(int i=0;i<V;i++){
      dist[i] = INT_MAX;
      visited[i] = false;
    }
    dist[src] = 0;
    priority_queue<Edge,vector<Edge>,Compare> pq;
    pq.push(Edge(src,dist[src]));
    while(!pq.empty()){
      Edge curr = pq.top();
      pq.pop();
      if(!visited[curr.vertex])
        visited[curr.vertex] = true;
      else
        continue;
      for(Edge e : edges[curr.vertex]){
        if(!visited[e.vertex]){
          if((curr.wt + e.wt) < dist[e.vertex]){
            dist[e.vertex] = curr.wt + e.wt;
            pq.push(Edge(e.vertex,dist[e.vertex]));
          }
        }
      }
    }
    return dist;
  }
};
