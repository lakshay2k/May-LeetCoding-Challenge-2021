class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        //answer to be returned is the vector of vectors
        vector<vector<int>> ans;
        
        //if the binary tree given is null
        if (!root) return ans;
        
        //creating queue to access elements stored first
        deque<TreeNode*> queue;
        
        //initially starting with the root node and passing it to queue
        queue.push_back(root);
        
        //check queue is empty or not
        while (!queue.empty()) {
            
            //as we have to go by visiting every nodes left adn right child so store queue size
            int qlen = queue.size();
            
            //because loop will continue as much children a node has(pushing row at once in ans)
            vector<int> row;
            
            //qlen can be maximum of 2(L & R) 1(L or R) or 0(no children)
            for (int i = 0; i < qlen; i++) {
                
                //accessing first node means left child of root node first
                TreeNode* curr = queue.front();
                
                //removing it and checking if it has left or right child if then add L first
                queue.pop_front();
                row.push_back(curr->val); //pushing value of root then left then right
                if (curr->left) queue.push_back(curr->left);
                if (curr->right) queue.push_back(curr->right);
            }
            
            //copying row each time that is level wise
            ans.push_back(row);
        }
        
        //return the vectors of vectors having levels of BT
        return ans;
    }
};