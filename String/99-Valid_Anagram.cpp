bool isAnagram(string str1, string str2) {
         map<char , int> mp1;
    map<char , int> mp2;

     for(int i=0; i<str1.length();i++){
           mp1[str1[i]]++;
     }

     for(int j=0; j<str2.length();j++){
          mp2[str2[j]]++;
     }

     if(mp1 == mp2) return true;
     return false;
    }
