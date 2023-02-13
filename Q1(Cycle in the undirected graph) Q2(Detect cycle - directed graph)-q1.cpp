#include<bits/stdc++.h>
using namespace std;

void iscycle(int source,int parent, bool *visited)
    {
        visited[source] = true;

        for(auto itr = adj[source].begin(); itr != adj[source].end(); itr++)
        {
            if(visited[*itr] == false)
            {
                if(iscycle(*itr, source, visited))
                {
                    return true;
                }
            }
            else
            {
                if(*itr != parent)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool Iscycle()
    {
        vector<int> result;
        bool* visited = new bool [v];

        for(int i = 0; i < v; i++)
        {
            visited[i] = false;
        }

        for(int i = 0; i < v; i++)
        {
            if(!visited[i])
            {
                if(iscycle(i, -1, visited)
                    return true;
            }
        }

        return false;
    }