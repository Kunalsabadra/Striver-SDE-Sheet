#include<bits/stdc++.h>
  vector<int> findMedian(vector<int> &arr, int n){

        vector<int> ans;
       priority_queue<int> max_heap;
	   priority_queue<int , vector<int> , greater<int>> min_heap;   	
	    
        max_heap.push(arr[0]);
		ans.push_back(arr[0]);

	   for(int i=1; i<n;i++){

		   if(max_heap.size() > min_heap.size()){
			    if(arr[i] < max_heap.top()){
					  min_heap.push(max_heap.top());
					  max_heap.pop();
					  max_heap.push(arr[i]);
				}
				else min_heap.push(arr[i]);

				if(max_heap.size() == min_heap.size()){
					 ans.push_back((max_heap.top() + min_heap.top())/2);
				}
				else ans.push_back(max_heap.top());
		   }
		   else{
			    if(arr[i] < max_heap.top()){
					 max_heap.push(arr[i]);
				}
				else{
					 min_heap.push(arr[i]);
					 max_heap.push(min_heap.top());
					 min_heap.pop();
				}
				if(max_heap.size() > min_heap.size()){
					ans.push_back(max_heap.top());
				}
		   }	       

	   }
         return ans;
}
