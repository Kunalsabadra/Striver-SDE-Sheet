
 bool dfs(int node,vector<vector<int>> &graph , vector<int> &color , int col){
	     color[node] = col;
		for(auto it:graph[node]){
			
			  if(color[it] == -1){
				 if(dfs(it , graph , color  , !color[node]) == false) return false;
			 }
			 else  if(color[it] == color[node]) return false;
		}
		return true;
 }

#include<bits/stdc++.h>
bool isGraphBirpatite(vector<vector<int>> &edges) {
	  int n = edges.size();
	 vector<vector<int>> graph(n);

	 for(int i=0; i<n; i++){
		 for(int j=0; j<n; j++){
			  if(edges[i][j] == 1){
				   graph[i].push_back(j);
				   graph[j].push_back(i);
			  }
		 }
	 }
       vector<int> color(n, -1);
	 for(int i=0; i<n; i++){
		   if(color[i] == -1){
			 
			  if(!dfs(i , graph , color ,0)) return false;
		   }
	 }
	 return true;
}
