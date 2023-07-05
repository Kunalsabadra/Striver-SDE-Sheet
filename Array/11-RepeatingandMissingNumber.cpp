//Brute Force Approach 
// T.C: O(N)+O(N)
// S.C:O(N)
#include <bits/stdc++.h>
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	  vector<int> freq(n , 0);

	  for(int i=0; i<n; i++){
		   freq[arr[i]-1]++;
	  }
	    int m ,  r;
	   for(int i=0;  i<n; i++){
             if(freq[i] == 0) m = i+1;
			 else if(freq[i] == 2) r = i+1;
	   }
	   pair<int , int> ans;
	   ans.first = m;
	   ans.second = r;
	return ans;
}
