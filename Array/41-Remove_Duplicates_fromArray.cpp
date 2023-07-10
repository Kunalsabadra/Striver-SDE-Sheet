//Brute force Approach Using Set
// Time complexity: O(n*log(n))+O(n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
int removeDuplicates(vector<int> &arr, int n) {
	  set<int> s;
      for(int i=0; i<n; i++){
		   s.insert(arr[i]);
	  }
       return s.size();
}
// ----------------------------------------------------------------------------

//Optimised Approach using two pointers
// Time Complexity: O(N)
// Space Complexity: O(1)

int removeDuplicates(vector<int> &arr, int n) {
	 int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}
