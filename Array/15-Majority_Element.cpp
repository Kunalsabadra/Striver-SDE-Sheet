//Optimised Approach Using Moores Voting Algorithm
//T.C:O(N);
//S.C:O(1)
#include <bits/stdc++.h>
//Moore Voting Algorithm
int findMajorityElement(int arr[], int n) {
	 int count  = 0 ,candidate = -1;
	 for(int i=0; i<n; i++){
           if (count == 0) {
             candidate = arr[i];
             count = 1;
           } else if (arr[i] == candidate)
             count++;
           else
             count--;
	
	 } 
	 int cnt1 = 0;

	 for(int i=0; i<n; i++){
		 if(arr[i] == candidate) cnt1++;
	 }
	 if(cnt1 > n/2) return candidate;
	 else return -1;
}
