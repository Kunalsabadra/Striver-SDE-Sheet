//Naive Solution using third list and merging both lists in thst
//T.C:O(N+ M)               WHERE N and M are size of lists l1 and l2 respectively
// S.C:O(N+M)

Node<int> *sortTwoLists(Node<int> *l1, Node<int> *l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

     Node<int> *l3 = new Node<int>(-1);
     Node<int>*head = l3;
     while(l1 and l2){
        
        if(l1->data <= l2->data){
             l3->next = new Node<int>(l1->data);
             l1 = l1->next;
             l3 = l3->next;
        }

        else{
            l3->next = new Node<int>(l2->data);
            l2 = l2->next;
            l3 = l3->next;
        }
     }
      
      while(l1){
             l3->next = new Node<int>(l1->data);
             l1 = l1->next;
             l3 = l3->next;
      }
      while(l2){
             l3->next = new Node<int>(l2->data);
            l2 = l2->next;
            l3 = l3->next;
      }
  return head->next;
}
//-------------------------------------------------------------------------------------------------
//Optimised Approach  Using Inplace method and withot using extra space
// T.C:O(N) 
// S.C: O(1)

Node<int>* sortTwoLists(Node<int>* l1, Node<int>* l2)
{
     if(l1 == NULL) return l2;     
     if(l2 == NULL) return l1;
     if(l1->data > l2->data) swap(l1, l2);
      Node<int>* res = l1;
     while(l1 and l2){
           Node<int> *temp =NULL;

           while (l1 and l1->data <= l2->data) {
             temp = l1;
             l1 = l1->next;
           }
           temp->next = l2;
           swap(l1, l2);
     }
      return res
        }
// ---------------------------------------------------------------------------------------
