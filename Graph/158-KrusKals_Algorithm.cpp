#include <bits/stdc++.h> 

class Disjoint{
	 public:
   
   vector<int> parent , rank;
    Disjoint(int n){
		 parent.resize(n+1);
		 rank.resize(n+1 ,0);

		 for(int i=1; i<=n; i++){
			  parent[i] = i;
		 }
	}

	int find_parent(int node){
		 if(node == parent[node]) return node;
		 return parent[node] = find_parent(parent[node]);
	} 

	void unionByRank(int u , int v){
     int p1 = find_parent(u);
     int p2 = find_parent(v);
    if(rank[p1] < rank[p2]){
       parent[p1] = p2;
    }
  else if(rank[p2] < rank[p1]){
    parent[p2] = p1;
  }
  else{
      parent[p1] = p2;
    rank[p2]++;
  }  
}

};



int kruskalMST(int n, int m, vector<vector<int>> &graph) {    
	vector<pair<int , pair<int , int>>> edges;
		 for(auto it:graph){
			  int u = it[0];
			  int v = it[1];
			  int wt = it[2];
			   
			   edges.push_back({wt , {u , v}});
		 }
	
       
	
	 Disjoint ds(n);
	//Sorting Edges according to thier weight
	 sort(edges.begin() , edges.end());
    //     for(auto it:edges){
	// 	    cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
	//    }


	 int mstWt  = 0;
	 for(auto it:edges){
		  int wt = it.first;
		  int u =  it.second.first;
		  int v = it.second.second;

                  if (ds.find_parent(u) != ds.find_parent(v)) {
                    mstWt += wt;
                    ds.unionByRank(u, v);
                  }
         }
       
	//    for(auto it:ds.parent){
	// 	    cout<<it<<" ";
	//    }

      return mstWt;
}










