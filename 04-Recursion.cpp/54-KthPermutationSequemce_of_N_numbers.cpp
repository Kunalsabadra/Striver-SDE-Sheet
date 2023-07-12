//Recursive Approach
Time complexity: O(N! * N) +O(N! Log N!)
/*
Reason:  The recursion takes O(N!)  time because we generate every possible permutation and another O(N)  time is required to make a deep copy 
and store every sequence in the data structure. Also, O(N! Log N!)  time required to sort the data structure

Space complexity: O(N) 
Reason: Result stored in a vector, we are auxiliary space taken by recursion
*/

#include<bits/stdc++.h>
void solve(string &s , int index ,vector<string>&res){
    if(index == s.size()){
        res.push_back(s);
        return;
    }
    for(int i=index; i<s.size();i++){
         swap(s[i] , s[index]);
         solve(s,index+1,res);
         swap(s[i] , s[index]);
    }
    return;
}

string kthPermutation(int n, int k) {
   string s;
   vector<string> res;
   
   for(int i=1; i<=n; i++){
       s.push_back(i+'0');
   }
   solve(s,0,res);
   sort(res.begin() , res.end());
   auto it = res.begin() + (k-1);
   return *it;
}

//Optimised Approach Using Formula
//T.C:O(N)*O(N) = O(N^2)
//S.C:O(1)
string kthPermutation(int n, int k) {
      int fact = 1;
    vector<int> nums;

    //finding factorial of n-1 numbers and creating vector of n numbers
    for(int i=1;i<n; i++){
         fact = fact*i;
         nums.push_back(i);
    }
    nums.push_back(n);
    string ans ="";
    k = k-1;
    while(true){
         ans += to_string(nums[k/fact]);
         nums.erase(nums.begin() + k/fact);
        if(nums.size() == 0) break;
        k = k%fact;
        fact = fact/nums.size();
    }
    return ans;
}
