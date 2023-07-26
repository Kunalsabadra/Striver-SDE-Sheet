#include<bits/stdc++.h>
bool isCycle(int src, vector<vector<int>> &graph, vector<bool> &vis, int n,int parent) {
      vis[src] = true;

      for(auto it:graph[src]){
            if(!vis[it]){
                  if(isCycle(it , graph , vis , n ,src) == true) return true;
            }
            else if(it != parent) return true;
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
          if (isCycle(1, graph, vis, n,-1))
            return "Yes";
        }
      }
       
          return "No";
}
