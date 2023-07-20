vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int , multiset<int> > > mp;
        queue<pair<TreeNode* , pair<int , int>>>q;
        vector<vector<int>> ans;
        //queue<pair<Node* , pair<vectical , level >>>
        q.push({root , {0 , 0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
           TreeNode* node = p.first;
           
//             x->vertical , y->level
            int x = p.second.first , y = p.second.second;
            mp[x][y].insert(node->val);
            if(node->left != NULL){
                q.push({node->left , {x-1 , y+1}});
            }
            if(node->right != NULL){
                q.push({node->right , {x+1 , y+1}});
            }
        }
        for(auto p: mp){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end() , q.second.begin() , q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
