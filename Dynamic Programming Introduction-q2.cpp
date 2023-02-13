#include<bits/stdc++.h>
using namespace std;

long ncr(long N, long R)
{
    vector<vector<long>> C(N+1, vector<long>(R+1, 0));

    for(int n = 1; n <= N; n++)
    {
        for(int r = 0; r <= min(n, r); r++)
        {
            if(n==1||r == 0)
            {
                C[n][r] = n;
            }
            else
            
            {
                C[n][r] = C[n-1]C[r-1] + C[n-1][r];
            }
        }
    }
    return C[n][r];
}

int main()
{
    
}