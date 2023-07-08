///Brute Force Approach
//Calculate the no of nodes in the linked list and written the middle node by traversing linked list using for loop till n/2

//T.C: O(N)+O(N/2)        //O(N)--> FOR COUNTING NO OF NODES
                          //O(N/2)-->For reaching the middle node

Node *findMiddle(Node *head) {
    Node* temp = head;
    int n=0;
    while (temp) {
      n++;
      temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < n / 2; i++){
          temp = temp->next;
}
return temp;
}

//Optimised Approach Using Tortoise-Hare-Approach
//We will keep two pointers slow and fast. slow will traverse one by one whereas fast will traverse living one node i.e +2
//At the end we will have fast at the last node or at Null pointer whereas slow will be in the middle at trhe same time

//T.C: O(N)
// S.C:O(1)

Node *findMiddle(Node *head) {
    Node* slow = head;
    Node* fast  = head;
    while(fast and fast->next){
         slow = slow->next;
         fast = fast->next->next;
    }
    return slow;
}
///////////////////////////////////////////////////////////////////////////////////////
