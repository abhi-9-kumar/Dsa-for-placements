vector<int>inorder;
        TreeNode* cur=root;
        while(cur!=nullptr){

            if(cur->left==nullptr)
            {
                inorder.push_back(cur->val);
                cur=cur->right;
            }
            else{
                //find the rightmost node inr the left subtree
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur)
                {
                    prev=prev->right;
                }
                //last node found;
                if(prev->right==nullptr){
                    prev->right=cur;  //threading
                    cur=cur->left;   
                }
                else{ //already threaded
                    prev->right=nullptr;   //cut the thread
                    inorder.push_back(cur->val);
                    cur=cur->right;
                }

            }
        }
        return inorder;