//Return_Substes_withSumk
/*
    Time Complexity : O(N * (2 ^ N))
    Space Complexity :  O(N * (2 ^ N))

    Where 'N' denotes the number of elements in the array.
*/

 void solve(int ind , int n , int k , vector<int> &arr , vector<int> temp , vector<vector<int>> &ans){
         if(ind == n){
             if(k == 0 and temp.size() != 0){
                  ans.push_back(temp);
             }
             return;
         }
         solve(ind+1 , n , k , arr , temp , ans);
         temp.push_back(arr[ind]);
         solve(ind+1 , n , k-arr[ind] , arr , temp , ans);
         return;
 }
 
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
     
      vector<vector<int>> ans;
      vector<int> temp;
      solve(0 , n , k ,arr , temp , ans);
      return ans;
}
