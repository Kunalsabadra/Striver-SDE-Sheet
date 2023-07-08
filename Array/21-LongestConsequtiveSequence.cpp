//Optimal Approach using Sorting
//T.C:O(nlogn)
//S.C:O(1);

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) { 
    sort(arr.begin() , arr.end());
    int count = 0 , cnt = 1;
    for(int i=0; i<n-1;i++){
        if(arr[i] == arr[i+1]-1) cnt++;
        else if(arr[i] == arr[i+1]) continue;
        else{
             
             cnt = 1;
        }
        count = max(count , cnt);
    }
    count = max(count , cnt);
    return count;

}

//////////////////////////////////////
//Optimised Approach using HashSet
//T.C:O(N)
//S.C:O(N)

#include<bits/stdc++.h>

using namespace std;
int longestConsecutive(vector < int > & nums) {
  set < int > hashSet;
  for (int num: nums) {
    hashSet.insert(num);
  }

  int longestStreak = 0;

  for (int num: nums) {
    if (!hashSet.count(num - 1)) {
      int currentNum = num;
      int currentStreak = 1;

      while (hashSet.count(currentNum + 1)) {
        currentNum += 1;
        currentStreak += 1;
      }

      longestStreak = max(longestStreak, currentStreak);
    }
  }

  return longestStreak;
}















