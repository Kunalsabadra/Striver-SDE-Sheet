//Optimal Approach Using prefix_max_array and suffix_max_array
//rain water trapped at index i = min(pref[i] , suff[i]) - height[i]
//T.C: O(N) + O(N) + O(N) = O (3*N)
//S.C : O(N) + O(N) = O(2*N)
// --------------------------------------------------------------------------------------------
    int trap(vector<int>& arr) {
        int n = arr.size();
             vector<long long> pref , suff(n);
      long long pref_max = 0 , suff_max = 0;
      for(int i=0; i<n;i++){
           if(arr[i] > pref_max){
                pref.push_back(arr[i]);
                pref_max = arr[i];
           }
           else pref.push_back(pref_max);
      }
      for(int i=n-1; i>=0; i--){
           if(arr[i] > suff_max){
               suff[i] = arr[i];
               suff_max = arr[i];
           }
           else suff[i] = suff_max;
      }
      long long  ans = 0;
      for(int i=0;i<n; i++){
           long long mini = min(pref[i] , suff[i]);
      
           long long diff = mini-arr[i];
           ans += max((long long)0 , diff);
      }
     return ans;
    }
// -------------------------------------------------------------------------------------------------
//Optimised Approach Using two pointers left and right
// T.C:O(N)
// S.C:O(1)

long long getTrappedWater(long long* arr, int n) {
      int left  =0 , right = n-1;
       int ans = 0 ;
       int left_max =0 , right_max = 0;
       while(left <= right){
            if(arr[left] <= arr[right]){
                 if(arr[left] >= left_max)  left_max = arr[left];
                 
                 else ans += left_max - arr[left];
                
                 left++;
            }
            else{
                if(arr[right] >= right_max)  right_max = arr[right];
                 else ans += right_max - arr[right];
                 right--;
            }
       }
      return ans;
}
     
