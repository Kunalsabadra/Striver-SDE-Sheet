#include<bits/stdc++.h>
class Stack {
	// Define the data members.
    queue<int>q;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        if(q.size() == 0) return true;
        return false;
    }

    void push(int element) {
         int s= q.size();
         q.push(element);
         for(int i=0; i<s;i++){
         q.push(q.front());
         q.pop();
         }
    }

    int pop() {
        if(q.size() == 0) return -1;
        int n = q.front();
        q.pop();
        return n;
    }

    int top() {
        if(q.size() == 0) return -1;
       return q.front();
    }
};
