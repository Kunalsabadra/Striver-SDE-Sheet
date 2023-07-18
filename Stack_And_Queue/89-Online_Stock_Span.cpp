#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
       vector<int> ans;
       int n = price.size();
        stack<pair<int,int>> st;
       for(int i=0; i<n;i++){
            int res = 1;
          while(!st.empty() and st.top().first <= price[i]){
               res += st.top().second;
               st.pop();
               
          }
          ans.push_back(res);
          st.push({price[i] ,res});
       }
        return ans;
}
