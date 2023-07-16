/*
    Time complexity: O(N + KlogN)
    Space complexity: O(N)

    Where ‘N’ is the size of the given array and K is given integer.
*/
#include <queue>

vector<int> kthSmallLarge(vector<int> &nums, int n, int k)
{ 
	vector<int> result;
	priority_queue<int> pq2;
   priority_queue<int , vector<int> , greater<int> > pq;  //min heap
    
        int ans;
        // int n = nums.size();
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
            if(pq.size() > k){
             
                pq.pop();
            }
        }
        ans = pq.top();

        

          int ans2;
        // int n = nums.size();
        for(int i=0; i<n; i++){
            pq2.push(nums[i]);
            if(pq2.size() > k){
             
                pq2.pop();
            }
        }
        ans2 = pq2.top();

        result.push_back(ans2);
         result.push_back(ans);
    
    return result;
}
