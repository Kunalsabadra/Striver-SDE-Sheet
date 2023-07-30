struct Node{
     Node *links[26];
     bool flag;
       
        Node() {
        flag = false;            // when the word is complete (mark that node as true)
        memset(links, 0, sizeof(links)); // for 26 possible Childrens (for next letter)
    }

     bool containKey(char ch){
          return (links[ch-'a'] != NULL);
     }

     void put(char ch , Node* node){
            links[ch-'a'] = node;
     }
      
      Node* get(char ch){
           return links[ch-'a'];
      }

      void setEnd(){
          flag = true;
      }

      bool isEnd(){
           return flag;
      }
};


class Trie {
public:
   Node* root;
    Trie() {
         root = new Node;
    }
    
    void insert(string word) {
          Node* node = root;
          for(int i=0; i<word.length(); i++){
                int idx = word[i] - 'a';
                if(node->links[idx] == NULL){
                    node->put(word[i] , new Node());
                }

                node = node->get(word[i]);
          }
          node->setEnd();
    }
    
    bool search(string word) {
         Node* node = root;
         for(int i=0; i<word.length(); i++){
             if(!node->containKey(word[i])){
                    return false;
             }
             node = node->get(word[i]);
         }
         return node->isEnd();
    } 
    
    bool startsWith(string prefix) {
            Node* node = root;
            for(int i=0; i<prefix.length(); i++){
                  if(!node->containKey(prefix[i])){
                      return false;
                  }
                  node= node->get(prefix[i]);
            }
            return true;
    }
};
