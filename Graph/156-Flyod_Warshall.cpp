int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
      
      vector<vector<int>> matrix(n+1,vector<int>(n+1 , 1e9));

      for(auto it:edges){
            int n = it[0];
            int m = it[1];
            int weight = it[2];
            
            matrix[n][m] = weight;
      }


      for(int i=1; i<=n;i++){
           for(int j=1;j<=n;j++){
                  if(i == j) matrix[i][j] = 0;
           }
      }
      
   for(int k=1; k<=n;k++){ 
      for(int i=1; i<=n; i++){
         for(int j=1; j<=n; j++){
              if(matrix[i][k] != 1e9 and matrix[k][j] != 1e9)
              matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);                  
           }
      }
}

 return matrix[src][dest];

}
