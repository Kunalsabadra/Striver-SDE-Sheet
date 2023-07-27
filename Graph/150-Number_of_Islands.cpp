
void dfs(int** arr ,int r , int c ,int n , int m , vector<vector<int>> &vis){
      
      vis[r][c] = 1;
       int dr[8] = {0,0,+1,-1,1,1,-1,-1};
       int dc[8] = {+1,-1,0,0,1,-1,+1,-1};
       for(int i=0; i<8;i++){
          int nr = r+dr[i];
          int nc = c+dc[i];

          if(nr >=0 and nr < n and nc >= 0 and nc  < m and arr[nr][nc] == 1 and vis[nr][nc] == 0){
               dfs(arr , nr , nc , n , m ,vis);
          } 
       }

}

int getTotalIslands(int** arr, int n, int m)
{         
   int cnt  =0;
      vector<vector<int>> vis( n , vector<int>(m , 0));

          for(int i=0; i<n; i++){
              for(int j=0; j<m;j++){
                  if(arr[i][j] == 1 and vis[i][j] == 0){
                      dfs(arr ,i,j, n , m ,vis);
                      cnt++;
                  }
              }
          }   
         return cnt;
}
