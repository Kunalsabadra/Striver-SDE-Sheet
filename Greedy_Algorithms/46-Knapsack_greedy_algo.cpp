//Optimised Approach
// Time Complexity: O(n log n + n). O(n log n) to sort the items and O(n) to iterate through all the items for calculating the answer.
// Space Complexity: O(1), no additional data structure has been used.

#include <bits/stdc++.h> 
     struct data{
          int weight;
          int value;
          double per;
     };

   bool cmp(struct data a1 , data a2){
        return (a1.per > a2.per);
   }

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
        //   sort(items.begin() , items.end() , cmp);
        //   for(auto it:items){
        //        cout<<it.second<<endl;
        //   }
             
       struct  data per_value[n];
       for(int i=0; i<n; i++){
            per_value[i].weight = items[i].first;
            per_value[i].value = items[i].second;
            per_value[i].per = double( items[i].second)/double( items[i].first);
       }

         sort(per_value , per_value+n , cmp);
         double ans = 0;
        //    for(int i=0; i<n; i++){
        //       cout<<per_value[i].weight<<" ";
        //    }
           cout<<endl;
           int currWeight = 0;
          for(int i=0; i<n; i++){
               if( currWeight+ per_value[i].weight <= w){
                    ans += per_value[i].value;
                    currWeight += per_value[i].weight;
               }
               else{
                    // cout<<ans<<" ";
                    double remain = (double)w - currWeight;
                    ans += per_value[i].per*remain;
                    break;
               }
          }

          
          return ans;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//My Own Easy and Understandable Code


struct Item{
    int value;
    int weight;
};


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
     
     bool static comp(pair<double , int> &a , pair<double , int> &b){
           return a.first > b.first;
     }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
          vector<pair<double , int>> per(n);
          for(int i=0; i<n;i++){
                per[i].first = (double)(arr[i].value) / (double)(arr[i].weight);
                per[i].second   =  arr[i].weight; 
          }
          
          sort(per.begin() , per.end() , comp);
           double ans;
          for(auto it:per){
                // cout<<it.first<<" "<<it.second<<endl;
                if(it.second <=W){
                      ans += it.first * (it.second);
                    //   cout<<ans<<" ";
                      W -= it.second;
                }
                else if(W == 0) break;
                else{
                     ans += it.first*(double)(W);
                    //  cout<<ans<<" ";
                     W -= W; 
                }
          }
        
             
          
        return ans;  
    }
        
};

















