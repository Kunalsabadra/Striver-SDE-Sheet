#include <bits/stdc++.h> 

void dfs(int i , vector<vector<int>>graph , vector<int> &indegree , vector<int>&ans , vector<int> &vis){

     ans.push_back(i);
     vis[i] = 1;
     for(auto it:graph[i]){
          indegree[it]--;
           if(indegree[it] == 0 and vis[it] == 0) {
                dfs(it , graph , indegree ,ans , vis);
           }
     }
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
      vector<vector<int>> graph(v);
      vector<int> indegree(v , 0);

      for(auto it:edges){
           graph[it[0]].push_back(it[1]);
           indegree[it[1]]++;
      }
      vector<int> ans;
      vector<int> vis(v ,0);
      for (int i = 0; i < v; i++) {
          if(indegree[i] == 0 and !vis[i])
        dfs(i, graph, indegree, ans , vis);
      }
      return ans;
}
