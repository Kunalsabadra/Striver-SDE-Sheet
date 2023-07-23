 Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            if(n == 0) return root;
            while(n > 0){
                Node* temp;
                if(n > 1){
                   temp = q.front();
                    q.pop();
                    Node* newn = q.front();
                    temp->next = newn;
                    
                }
                else{ 
                temp = q.front();
                    q.pop();      
                }
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                n--;
            }
        }
        return root;
    } 
