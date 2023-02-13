#include<bits/stdc++.h>
using namespace std;


int mem(string s1, string s2, int **output){
    int m = s1.size();
    int n = s2.size();
    if(m == 0 || n== 0){
        return max(m,n);
    }
    int ans ;
    if(output[m][n] != -1){
        return output[m][n];
    }
    if(s1[0] == s2[0]){
        ans  = mem(s1.substr(1),s2.substr(1),output);
    }
    else{
        int x = mem(s1,s2.substr(1),output)+1;
        int y = mem(s1.substr(1),s2,output)+1;
        int z = mem(s1.substr(1),s2.substr(1),output)+1;
        ans = min(x,min(y,z));
    }
    output[m][n] = ans;
    return ans;
}
int minDistance(string word1, string word2) 
{
    int m = word1.size();
    int n = word2.size();
    int **output = new int*[m+1];
    for(int i = 0; i<=m; i++){
        output[i] = new int[n+1];
            for(int j =0; j<=n;j++){
                output[i][j] = -1;
            }
    }
    return mem(word1,word2,output);
}





int main()
{

}