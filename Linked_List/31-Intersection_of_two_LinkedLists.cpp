//Approach1 : Brute Force


//Approach2: Optimal Approach(Using unordered set(hashing))


//Approach3 : Using Difference Length


//Approach4:  Most Optimised Approach
// T.C: O(2*Max(len(l1) , len(l2))
//S.C:O(1)
Node* findIntersection(Node *node1, Node *node2)
{    
     if(node1 == NULL or node2 == NULL) return NULL;
     Node* a = node1;
     Node* b = node2;

     while(a != b){
          a = (a==NULL)?node2 : a->next;
          b = (b==NULL)?node1 : b->next;
     }
    return a;
}
