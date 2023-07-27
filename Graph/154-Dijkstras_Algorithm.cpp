#include <bits/stdc++.h> 

vector<int> dijkstra(vector<vector<int>> &vec, int n, int edges, int source) {
      
      vector<vector<int>> adj[n];
      for(auto it:vec){
           int u = it[0];
           int v = it[1];
           int w = it[2];
           vector<int> t1 , t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
      }

    priority_queue<pair<int , int> , vector<pair<int,int>> , greater<pair<int, int>>>pq;
    pq.push({0 , source});
    vector<int> dist(n , 1e14);
     dist[source] = 0;
     while(!pq.empty()){
          auto it = pq.top();
          pq.pop();
          int curr_dist = it.first;
          int node = it.second;

          for(auto it:adj[node]){
               int node_dist = it[1];
               int adj_node = it[0];
               if(curr_dist + node_dist < dist[adj_node]){
                    dist[adj_node] =   curr_dist+ node_dist;
                    pq.push({node_dist+curr_dist , adj_node});
               }   
          } 
     }
     return dist;
}
