#include <bits/stdc++.h> 
/* Optimal Approach:
 T.C:    O(N*logN) + O(N), where N = the size of the given array.
Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are just using a single loop 
that runs for N times. So, the time complexity will be O(N).
S.C:O(N) 
*/
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
      int n = intervals.size();
      sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans;
      for(int i=0; i<n; i++){

          if(ans.empty() or intervals[i][0] > ans.back()[1]){
               ans.push_back(intervals[i]);
          }
          else{
                ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
          }
      }
      return ans;
}
