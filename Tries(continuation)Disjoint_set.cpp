#include<bits/stdc++.h>
using namespace std;

class Disjoint
{
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

public:
    Disjoint(int n)
    {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1); 

        for(int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int u)
    {
        if(u == parent[u])
            return u;

        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int ultp_u = findParent(u);
        int ultp_v = findParent(v);

        if(ultp_u == ultp_v)
            return;
        
        else if(rank[ultp_u] < rank[ultp_v])
        {
            parent[ultp_u] = ultp_v;
        }

        else if(rank[ultp_v] < rank[ultp_u])
        {
            parent[ultp_v] = ultp_u;
        }

        else
        {
            parent[ultp_u] = ultp_v;
            rank[ultp_v]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ultp_u = findParent(u);
        int ultp_v = findParent(v);

        if(ultp_u == ultp_v)
            return;
            
        else if (size[ultp_u] < size[ultp_v])
        {
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        }
        else
        {
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        }
    }               
};


int main()
{
    Disjoint d(6);

    d.unionBySize(1, 2);
    d.unionBySize(2, 3);
    d.unionBySize(3, 4);
    d.unionBySize(6, 7);
    d.unionBySize(1, 6);
    if(d.findParent(1) == d.findParent(6))
        cout << "same";
    else
        cout << "not same";
}