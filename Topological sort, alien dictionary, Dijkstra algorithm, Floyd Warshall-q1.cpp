#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> result;
        if (V == 0)
        {
            return result;
        }

        vector<int> degreeArr = vector<int>(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto j = adj[i].begin(); j != adj[i].end(); j++)
            {
                degreeArr[*j]++;
            }
        }

        queue<int> zeroDegreeQ;
        for (int i = 0; i < V; i++)
        {
            if (degreeArr[i] == 0)
            {
                zeroDegreeQ.push(i);
            }
        }

        while (!zeroDegreeQ.empty())
        {
            int curNode = zeroDegreeQ.front();
            zeroDegreeQ.pop();
            result.push_back(curNode);

            for (auto i = adj[curNode].begin(); i != adj[curNode].end(); i++)
            {
                --degreeArr[*i];
                if (degreeArr[*i] == 0)
                {
                    zeroDegreeQ.push(*i);
                }
            }
        }

        return result;
    }
};

int main()
{
    
}