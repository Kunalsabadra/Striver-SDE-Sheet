#include<bits/stdc++.h>
bool isCycle(int src , vector<vector<int>> &graph  , vector<bool> &vis , int n){
      vis[src] = 1;
      queue<pair<int ,int>> q;
      q.push({src, -1});
      while(!q.empty()){
          auto it = q.front();
          int node = it.first;
          int parent = it.second;
          q.pop();

          for(auto adjnode: graph[node]){
               if(!vis[adjnode]){
                    vis[adjnode] = 1;
                    q.push({adjnode , node});
               }
               else if (adjnode != parent) return true;
          }
      }
      return false;
}
 
 
 
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> graph(n+1);

    //Creating adjecancy matrix
    for(auto it:edges){
         graph[it[0]].push_back(it[1]);
         graph[it[1]].push_back(it[0]);
    }
    
    vector<bool> vis(n+1 , false);

   //For Different No of Components
      for(int i=1;i<=n;i++){
        if (!vis[i]) {
          if (isCycle(1, graph, vis, n))
            return "Yes";
        }
      }
       
          return "No";
}
