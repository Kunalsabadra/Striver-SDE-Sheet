/*
    Time Complexity : O(N *log max(N, maxDeadline))
    Space Complexity : O(maxDeadline)

    Where 'N' is size of the array "jobs" and 
    'maxDeadline' is the maximum among all the deadlines.
*/

#include <algorithm>
#include <set>

// Custom Comparator function to sort the jobs in the decreasing order of their profit.
bool compare(vector<int> &job1, vector<int> &job2)
{
    return job1[1] > job2[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{

    sort(jobs.begin(), jobs.end(), compare);

    int maxProfit = 0;
    int maxDeadline = 0;

    // Find the maximum deadline among all the jobs.
    for (int i = 0; i < jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }

    // Create a set "slots".
    set<int, greater<int>> slots;

    // Insert all the elements from maxDeadline to 1 into the set.
    for (int i = maxDeadline; i > 0; i--)
    {
        slots.insert(i);
    }

    for (int i = 0; i < jobs.size(); i++)
    {

        // If the set is empty or the deadline is less than the last element of the set, then ignore this job.
        if (slots.size() == 0 || jobs[i][0] < *slots.rbegin())
        {
            continue;
        }

        int availableSlot = *slots.lower_bound(jobs[i][0]);
        maxProfit = maxProfit + jobs[i][1];
        slots.erase(availableSlot);
    }

    return maxProfit;
}










// Time Complexity: O(N log N) + O(N*M).

// O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are iterating through all N jobs and for every job we are checking from the last deadline, say M deadlines in the worst case.

// Space Complexity: O(M) for an array that keeps track on which day which job is performed if M is the maximum deadline available.

#include<bits/stdc++.h>
using namespace std;
// A structure to represent a job 
struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
   //Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(Job arr[], int n) {

      sort(arr, arr + n, comparison);
      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, arr[i].dead);
      }

      int slot[maxi + 1];

      for (int i = 0; i <= maxi; i++)
         slot[i] = -1;

      int countJobs = 0, jobProfit = 0;

      for (int i = 0; i < n; i++) {
         for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
               break;
            }
         }
      }

      return make_pair(countJobs, jobProfit);
   }
};
int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
} 


//Simple Approach with Code 
//T.C: O(N*logN)
//S.C: O(N)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
   static  bool comp(pair<int , int> &a , pair<int , int> &b){
           return a.second < b.second;
     }
    
    int maxMeetings(int start[], int end[], int n)
    {
         
         vector<pair<int , int>> v(n);
         
         for(int i=0; i<n;i++){
               v[i].first = start[i];
               v[i].second = end[i];
         }
         
         sort(v.begin() , v.end() , comp);
         
//   std::sort(v.begin(), v.end(), [](auto &left, auto &right) {
//     return left.second < right.second;
// });
         
        //  for(int i=0; i<n;i++){
        //       cout<<v[i].first<<" "<<v[i].second<<endl;
        //  }
          int cnt = 0;
          int j = 0;
        for(int i=1;i<n;i++){
             if(v[i].first > v[j].second){
                 cnt++;
                  j=i;   
             }
             
        }
         
         return cnt+1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends











