#include<bits/stdc++.h>
 int smallest(vector<string> &arr , int n){
	   int small = INT_MAX;
	   int idx = 0;
	   for(int i=0; i<n;i++){
		    int len = arr[i].length();
			if(len < small) {
				 small = len;
                 idx = i;
			}
	   }

	   return idx;
 }


string commonPrefix(vector<string>& strs,int n){
	   string result = "";
      
        int shortest_index = smallest(strs,n);
        while(strs[shortest_index].length() > 0){
            
            int count =0;
            for(int i=0; i<n; i++){
                if(strs[i].find(strs[shortest_index]) == 0){
                    count++;
                }
            }
            if(count == n){
                result =  strs[shortest_index];
                break;
            }
//if the smallest string of the array is not present in all the string of array as a prefix then we will pop out last character            
            strs[shortest_index].pop_back();
        }
         if(result.length()) return result;
		 else{
			  result = "-1";
			  return result;
		 }
}
