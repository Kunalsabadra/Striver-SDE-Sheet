#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	 string ans = "1";
        
        for(int i= 2; i<=n; i++){
            string org = ans;
            int len = ans.size();
            int j =0;
            ans = "";
            while(j< len){
                int cnt= j;
                while( j < len and org[j] == org[cnt]){
                    cnt++;
                }
                ans += to_string(cnt-j)+org[j];
                j = cnt;
            }
        }
        return ans;
}
