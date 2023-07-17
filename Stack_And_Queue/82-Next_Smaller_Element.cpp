#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans;
    for(int i=n-1; i>=0; i--){
        if(st.empty()){
          ans.push_back(-1);
          st.push(arr[i]);
        }
        else if(st.top() < arr[i]){
            ans.push_back(st.top());
            st.push(arr[i]);
        }
        else{
            while(!st.empty() and st.top() >= arr[i]){
                st.pop();
            }
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
            st.push(arr[i]);
        }
    }
    reverse(ans.begin() , ans.end());
    return ans;
}
