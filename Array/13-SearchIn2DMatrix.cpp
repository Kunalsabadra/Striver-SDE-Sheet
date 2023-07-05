//Brute Force Approach: Linaer Traversal
// T.C:O(N^2)
//S.C:O(1)

bool searchMatrix(vector<vector<int>>& mat, int target) {
         int n = mat.size();
         int m = mat[0].size();
         for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                 if(mat[i][j] == target) return true;
            }
         }
         return false;
}



//Optimised Approach: Using Binary Search
//T.C:O(logN)
//S.C:O(1)

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;

        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0 , high =n*m-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(matrix[mid/m][mid%m] == target) return true;
            if(matrix[mid/m][mid%m] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
}
