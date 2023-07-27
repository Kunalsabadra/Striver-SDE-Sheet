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
      
	  queue<int> q;
	  q.push(0);
	  vector<int> color(n, -1);
	  color[0] = 0;
	  while(!q.empty()){
		   int node = q.front();
		   q.pop();
            for(auto it:graph[node]){
				 if(color[it] == color[node]) return false;
				 else if(color[it] == -1){
					  color[it] = !color[node];
					  q.push(it);
				 }
			}

	  } 
	  return true;
}
