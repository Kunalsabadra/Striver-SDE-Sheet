#include <bits/stdc++.h>
struct Node{
     Node* lists[26];
     bool flag = false;

     bool checkExist(char ch){
         return (lists[ch-'a'] != NULL);
     }
     void put(char ch , Node* node){
         lists[ch-'a'] = node;
     }
     Node* get(char ch){
         return lists[ch-'a'];
     }
     void setEnd(){
         flag = true;
     }
     bool isEnd(){
        return flag;
     }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root =new Node();
    }
    void insert(string &word){
          Node* node = root;
          for (int i = 0; i < word.length(); i++) {
            if (!node->checkExist(word[i])){
                node->put(word[i] , new Node());
            }
            node = node->get(word[i]);
          }
           node->setEnd();
    }

    bool isPrefix(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->checkExist(word[i])){
                node = node->get(word[i]);
               if(node->isEnd() == false) return false; 
            }
            else return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
         Trie  trie;
         for(auto &it:a){
             trie.insert(it);
         }    
         string longest = "";
         
         for(auto &it:a){
             if(trie.isPrefix(it)){
               if (it.length() > longest.length()) {
                 longest = it;
               }

               else if (it.length() == longest.length() and it < longest){
                   longest = it;
               }
             }
         }

         if(longest == "") return "None";
           return longest;
     
    //    map<string , int> mp;
    //    for(auto it:a){
    //        mp[it]++;
    //    }
    //    string ans="";
    //     for(int i=0;i<n; i++){
    //         string s = a[i];
    //         string pre = "";
    //         bool flag = true;
        //     for(int j=0; j<s.length(); j++){
        //          pre += s[j];
        //          if(mp.count(pre)) continue;
        //          else {
        //            flag = false;
        //            break;
        //          }
        //     }
        //     if (flag) {
        //       if (pre.length() > ans.length())
        //         ans = pre;
        //       else if (pre.length() == ans.length() and pre < ans)
        //         ans = pre;
        //     }
        // }
        // if(ans.length() == 0) ans = "None";
        // return ans;
}










