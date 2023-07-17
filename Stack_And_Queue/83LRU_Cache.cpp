#include<bits/stdc++.h>
class LRUCache
{
public:

    class Node{
        public:
         int key;
         int val;
         Node* next;
         Node* prev;   
         Node(int _key ,int _val){
              key = _key;
              val = _val;
         }
    };
     int cap;
     unordered_map<int,Node*> mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity)
    { 
         cap = capacity;
         head->next = tail;
         tail->prev = head;
    }

    void addNode(Node* new_node){
        Node* temp = head->next;
        head->next = new_node;
        new_node->next = temp;
        new_node->prev = head;
        temp->prev = new_node; 
    }

    void deleteNode(Node* delnode){
         Node* delnext = delnode->next;
         Node* delprev = delnode->prev;
         delprev->next = delnext;
         delnext->prev = delprev;
    }

    int get(int key_)
    {   
        if(mp.find(key_) != mp.end()){
           Node* resnode = mp[key_];
           int res = resnode->val;
           mp.erase(key_);
           deleteNode(resnode);
           addNode(resnode);
           mp[key_] = head->next;
           return res;
        }
        return -1;
    }

    void put(int key_, int value){   
         if(mp.find(key_) != mp.end()){
             Node* existingNode = mp[key_];
             mp.erase(key_);
             deleteNode(existingNode);
         }
        if(mp.size() == cap){
          mp.erase(tail->prev->key);
          deleteNode(tail->prev);
        }
        addNode(new Node(key_ , value));
        mp[key_] = head->next;
    }
};
