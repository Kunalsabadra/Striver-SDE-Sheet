#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<pair<int, int>> activity(n);

    for (int i = 0; i < n; i++) {
        activity[i].first = finish[i];
        activity[i].second = start[i];
    }

    // Sort the meetings according to their Finishing Time.
    sort(activity.begin(), activity.end());

    int maxActivity = 1;
    int currentTime = activity[0].first;

    for (int i = 1; i < n; i++) {

        // Find the next meeting available.
        if (activity[i].second >= currentTime) {
            maxActivity++;
            currentTime = activity[i].first;
        }
    }
    return maxActivity;
}

//----------------------------------------------------------------------------------------------------------------------------------------------
//Maximum number of meetings in room my simple code
class Solution
{
    public:
  
bool static comp(pair<int , int> &a , pair<int , int> &b){
           return a.second < b.second;
     }
    

int maxMeetings(int start[], int end[], int n)
    {
         vector<pair<int , int>> v(n);
          
          for(int i=0; i<n;i++){
               v[i].first = start[i];
                v[i].second = end[i];
          }
          
          sort(v.begin() , v.end(), comp);
          
          
          int cnt  = 1;
          int j=0;
          for(int i=1; i<n;i++){
               if(v[j].second < v[i].first){
                  j=i;  
               cnt++;
               }
          }
         return cnt;
    }
};











