//Optimised Approach Using Sliding Window
// T.C:O(N)
// S.C: O(1)

int longestSubSeg(vector<int> &nums , int n, int k){
    // int n= nums.size();
        int i=0, j=0, maxLength=0;
        int countZero=0;
        while(j < n)
        {
            if(nums[j]==0)
            countZero++;

            while(countZero>k)
            {
                if(nums[i]==0)
                countZero--;
                i++;
            }
            maxLength = max(maxLength, j-i+1);
            j++;
        }
        return maxLength;        
}
