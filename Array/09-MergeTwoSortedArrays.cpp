#include <bits/stdc++.h>

//Optimal Approach:
//T.C:O(n+m)
//S.C:O(1)
vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
	   int p1 = m-1 , p2 = n-1 , i = m+n-1;
        while(p2 >= 0){
            if(p1 >=0 and nums1[p1] > nums2[p2]){
                nums1[i--] = nums1[p1--];
            }
            else{
                nums1[i--] = nums2[p2--];
            }
        }
    return nums1;
}
