#include <bits/stdc++.h>
using namespace std;
string topological(unordered_map<char,vector<char>> &g){
  unordered_map<char,int> indegree;
  for(auto i:g){
    for(auto j:i.second){
      indegree[j]++;
    }
  }
  queue<char> q;
  string ans;
  for(auto i : g){
    if(indegree.find(i.first) == indegree.end()) q.push(i.first);
  }
  while(!q.empty()){
    char curr = q.front();
    q.pop();
    ans.push_back(curr);
    for(auto i : g[curr]){
      indegree[i]--;
      if(indegree[i] == 0) q.push(i);
    }
  }
  return ans;
}
string findOrder(string dict[], int N, int K) {
  unordered_map<char,vector<char>> g;
  string ans;
  for(int i=0;i<N-1;i++){
    string s1 = dict[i];
    string s2 = dict[i+1];
    int index = 0;
    while(index < s1.size() && index < s2.size() && s1[index] == s2[index]) index++;
    g[s1[index]].push_back(s2[index]);
  }
  return topological(g);
}