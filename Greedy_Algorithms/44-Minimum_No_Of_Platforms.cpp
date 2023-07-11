// Optimised Approach
// Time Complexity: O(nlogn) Sorting takes O(nlogn) and traversal of arrays takes O(n) so overall time complexity is O(nlogn).
// Space complexity: O(1)  (No extra space used).

int calculateMinPatforms(int at[], int dt[], int n) {
     int plat  = 1 , i =1 , j= 0 , result = 1;
     sort(at , at+n);
     sort(dt , dt+n);

     while(i < n and j < n){
          if(at[i] <= dt[j]){
               plat++;
               i++;
          }
          else if(at[i] > dt[j]){
               plat--;
               j++;
          }
          if(result < plat){
               result = plat;
          }
     }
      return result;
}
