#include <bits/stdc++.h> 
int atoi(string s) {
      int l = s.size();
         double num = 0;
         int i=0;

         while( s[i] == ' '){  i++;
         }
         bool positive = s[i] == '+';
         bool negative = s[i] == '-';

         negative == true? i++ :i;
         positive == true? i++ :i;
         while(i < l){

           if ( s[i] >= '0' and s[i] <= '9') {
             num = num * 10 + (s[i] - '0');
             i++;
           }
           else i++;
         }
         
         num = negative ? -num :num;

         num = (num > INT_MAX) ? INT_MAX: num;
         num = (num < INT_MIN)? INT_MIN: num;
         
         return (int)num;
}
