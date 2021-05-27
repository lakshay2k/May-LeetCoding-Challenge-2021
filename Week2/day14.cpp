class Solution {
public:
    void flatten(TreeNode* root) {
        
        //if root is null means no binary tree 
        if(root == NULL)
            return;
        
        //we will be creating stack to keep track of the nodes
        stack<TreeNode*> mystack;
        
        //intitially pushing the root node
        mystack.push(root);
        
        while(!mystack.empty())
        {
            /*
            we add the curr node and store the right element first in stack then the left elemrnt
            because LIFO so we put left at last to add left node before right node
            */
            TreeNode* curr = mystack.top();
            mystack.pop();
            
            //adding right node first to stack
            if(curr->right!=NULL)
                mystack.push(curr->right);\
                
            //then addding left node to stack
            if(curr->left != NULL)
                mystack.push(curr->left);
            
            //now adding the top of stack that is left node is added to curr node acc to preorder traversal
            if(!mystack.empty())
                curr->right = mystack.top();
            curr->left = NULL;
        }
    }
};