#include<bits/stdc++.h>
using namespace std;

vector<int> dp;
  
int fibo(long long int n)
{
    if(n == 1 || n == 2)
    return dp[n] = 1;
    
    if(dp[n] != -1)
        return dp[n];
    return dp [n] = (fibo(n-1)+fibo(n-2))%1000000007;
}
  
long long int nthFibonacci(long long int n)
{
    dp.resize(n+1, -1);
    return fibo(n);
}

int main()
{

}