#include<bits/stdc++.h>
using namespace std;


class Edge
{
    public:

    int source, des;
    double weight;
};

bool comparator(cost Edge &a, const Edge &b)
{
    return a.weight <= b.weight;
}


class Graph
{
    int v, e;

    vector<Edge> edges;
    public:

    Graph(int V, int E)
    {
        v = V;
        e = E;
    }

    void AddEdge(int u, int V, int w)
    {
        edges.push_back(Edge(u, V, w));
    }

    vector<Edge> kruskal()
    {
        vector<Edge> result;
        double minweight = 0.0;
        sort(edges.begin(), edges.end(), comparator);

        DisjointSets ds(v);

        for(auto itr = edges.begin(); it != edges.end(); itr++)
        {
            int u = itr->source;
            int V = itr->des;

            int parentU = ds.Find(u), parentV = ds.Find(V);

            if(parentU == parentV)
            {

            }
            else            
            {
                minweight += itr->weight;
                result.push_back(*itr);
                ds.union(u, V);
            }
        }
        return (result, minweight);
    }
}