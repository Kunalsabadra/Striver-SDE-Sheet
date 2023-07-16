//Optimised Approach Using Binary Searcg
//T.C:O(Mlog(k))
//S.C:O(1)

#include <bits/stdc++.h> 
 bool isPossible(long long mid, int n , int m , vector<int> time){
	   long long day = 1,timei = 0;
	   for(int i=0; i<m; i++){
		     if(timei + time[i] <= mid){
				  timei += time[i];
			 }
			 else{
				 day++;
                 timei = time[i];
			 }
	   }
	   if(day <= n) return true;
	   else return false;
 }

long long ayushGivesNinjatest(int n, int m, vector<int> &time) 
{	  

	  long long low = *max_element(time.begin() , time.end());
	//   long long high = accumlate(time.begin() , time.end() ,0);

	long long high = 0;
	for(int i=0;i<m; i++){
		high += time[i];
	}
      long long ans = 0;  
	  while(low <= high){
            long long mid = low + (high-low)/2;

            if (isPossible(mid, n, m, time)) {
              ans = mid;
              high = mid - 1;
            } else
              low = mid + 1;
          }
	  return ans;
}
