#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> *adj;

public:
    Graph(int V)
    {
        v = V;
        adj = new list<int>[v];
    }

    void AddEdges(int u, int v)
    {
        adj[u].push_back(v);

        adj[v].push_back(u);
    }

    Void RemoveEdge(int u, int v)
    {
        adj[u]->erase(v);
        adj[v]->erase(u);
    }

    void dfs(int source, bool *visited, vector<int> &result)
    {
        visited[source] = true;
        result.push_back(source);

        for(auto itr = adj[source].begin(); itr != adj[source].end(); itr++)
        {
            if(!visited[*itr])
            {
                Dfs(*itr, visited, result);
            }
        }
    }

    vector<int> DFS()
    {
        vector<int> result;
        bool* visited = new bool [v];

        for(int i = 0; i < v; i++)
        {
            visited[i] = false;
        }

        int count = 0;
        for(int i = 0; i < v; i++)
        {
            if(!visited[i])
            {
                count++;
                Dfs(i, visited);
            }
        }
    }

    vector<int> BFS()
    {
        vector<int> result;
        bool *visited = new bool[v];

        for(int i = 0; i < v; i++)
        {
            visited[i] = false;
        }

        list<int> Q;
        int source = 0;

        visited[source] = true;
        Q.push_back(source);

        while(!Q.empty())
        {
            source = Q.front;
            Q.pop_front();

            result.push_back(source);

            for(auto itr = adj[source].begin(); itr != adj[source].end(); itr++)
            {
                if(!visited[*itr])
                {
                    visited[*itr] = true;
                    Q.push_back(*itr);
                }
            }

        }
        return result;
    }


};