struct Node{
     Node* links [2];

     bool containKey(int bit){
           return (links[bit] != NULL);
     }

     void put(int bit , Node* node){
          links[bit] = node;
     }
     Node* get(int bit){
          return links[bit];
     }
};

class trie{
       private: Node* root;
       public: 
       trie(){
            root = new Node();
       }
       public:
       void insert(int num){
           Node* node  = root;
            for(int i=31 ; i>=0; i--){
                 int bit = ( num >> i)&1;              //getting bit of number
                 if(!node -> containKey(bit)){
                     node->put(bit , new Node());
                 }
                 node = node->get(bit);
            }
       }
    public:
       int findMax(int num){
            Node* node = root;
            int maxNum  = 0;
            for(int i=31; i>=0; i--){
                 int bit = (num >> i)&1;
                 if(node->containKey(!bit)){           //checking existing of oppoite of bit existance
                       maxNum = maxNum | (1 << i);
                       node = node->get(!bit); 
                 }
                 else{
                      node = node->get(bit);
                 }
            }
            return maxNum;
       }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
         int n = nums.size();
         trie obj;
         for(int i=0; i<n; i++){
              obj.insert(nums[i]);
         }
         int maxi  =0;
         for(int i=0; i<n; i++){
             maxi = max(maxi , obj.findMax(nums[i]));
         }
         return maxi;
    }
};



