//NAIVE APPROACH BY STORING LINKEDLIST ELEMENT IN ARRAY
// T.C:O(N)
// S.C:O(1)

// *****************************************************************

bool isPalindrome(LinkedListNode<int> *head) {
    vector<int> v;
    while(head != NULL){
         int val = head->data;
         v.push_back(val);
         head= head->next;
    }
    
    for(int i=0;i<v.size()/2;i++) 
        if(v[i] != v[v.size()-i-1]) return false;
    return true;

}

// *****************************************************************

//Optimised Approach
// Find the middle element of the linked list. Refer to this article to know the steps 
// Reverse a linked list from the next element of the middle element. 
// Iterate through the new list until the middle element reaches the end of the list.
// Use a dummy node to check if the same element exists in the linked list from the middle element

// Time Complexity: O(N/2)+O(N/2)+O(N/2)
// Space Complexity: O(1)

// *****************************************************************

//Reverse a Linked list
LinkedListNode<int>* reverse(LinkedListNode<int>* head){
     LinkedListNode<int>* prev = NULL , *next = NULL;
     while(head != NULL){
          next = head->next;
          head->next = prev;
          prev = head;
          head = next;
     }
     return prev;
}


bool isPalindrome(LinkedListNode<int> *head) {
  if(head == NULL or head->next == NULL) return true;

   //Finding Middle Elemnt
    LinkedListNode<int>* fast = head , *slow = head;
    while(fast->next != NULL and fast->next->next != NULL){
          fast = fast->next->next;
          slow = slow->next;
    }
    //Now Slow will point to the middle of the linked of list
    //Reversing the right part from middle of the linked list

    slow->next = reverse(slow->next); 

    slow = slow->next;
    
    //Checking left part and reversed right part of the linked list
    while(slow != NULL){
        if(head->data != slow->data) return false;
        head = head->next;
        slow = slow->next;
    }
     return true;
}
