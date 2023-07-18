//Brute Force Using Doubly Linked List
#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
       vector<int> ans;
       for(int i=1;i<=n;i++){
            int maxi =INT_MIN;
            deque<int> dq;
            for(int j=0; j<a.size();j++){
                 if(!dq.empty() and dq.front() == j-i) dq.pop_front();

                 while(!dq.empty() and a[dq.back()] > a[j]) dq.pop_back();

                 dq.push_back(j);
                 if(j >= i-1) maxi = max(maxi , a[dq.front()]);
            }
            ans.push_back(maxi);
       }
         return ans;
}

//Optimised Approach Using Stack
#include <bits/stdc++.h> 

vector<int> maxMinWindow(vector<int> a, int n) {
         stack<int> st ,t;
         vector<int> left(n,-1);
         vector<int> right(n,n);
         
         for(int i=0;i<n; i++){
              while(!st.empty() and a[st.top()] >= a[i]) st.pop();
              
              if(!st.empty()){
                   left[i] = st.top();
              }
              st.push(i);
         }
             
            for(int i=n-1;i>=0;i--){
                 while(!t.empty() and a[t.top()] >= a[i]) t.pop();
              
              if(!t.empty()){
                   right[i] = t.top();
              }
              t.push(i);
            }
            vector<int> answer(n, INT_MIN);
              for (int i = 0; i < n; i++) 
    {
        // Length of the window in which a[i] is minimum
        int length = right[i] - left[i] - 1;

        // Update the answer[length-1] ( 0 based indexing )  with a[i]
        answer[length - 1] = max(answer[length - 1], a[i]);
    }

	// Some entries in answer[] may not be filled yet.
	// We fill them by taking maximum element from suffix starting from 'i'.
    for (int i = n - 2; i >= 0; i--) 
    {
        answer[i] = max(answer[i], answer[i + 1]);
    }

    return answer;
}
