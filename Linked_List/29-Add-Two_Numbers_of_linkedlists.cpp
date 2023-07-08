// Optimised Approach 
// Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.

// Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.

Node *addTwoNumbers(Node *l1, Node *l2)
{
      
   Node* l3 = new Node(0);
   Node* head = l3;
   int carry  = 0 , value = 0;
   while(l1 and l2){
     value = l1->data + l2->data + carry;
     carry  = value/10;
     l3->next = new Node(value%10);
     l3 = l3->next;
     l2 = l2->next;
     l1 = l1->next;
   }
   value = 0;
 while(l1){ 
       value = l1->data + carry;
       carry = value/10;
       l3->next = new Node(value%10);
       l3 = l3->next;
       l1 = l1->next;
 }
  while(l2){ 
       value = l2->data + carry;
       carry = value/10;
       l3->next = new Node(value%10);
       l3 = l3->next;
       l2 = l2->next;
 }
 if(carry)
 l3->next = new Node(carry%10);
 
 return head->next;

}
