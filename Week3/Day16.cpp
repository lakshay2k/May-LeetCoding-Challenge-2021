class Solution {
public:

    int ncamera;
    int minCameraCover(TreeNode* root) {
        
        //we will be using dfs to go down to leafs and while returning we will assign the camera at best posn
        //hence it is greedy approach as well

        ncamera =0;
        pair<bool,bool> temp = count_camera(root);
        if(!temp.second)
            ncamera++;
        return ncamera;
    }
    
    pair<bool,bool> count_camera(TreeNode* root)
    {
        //if root is null or it is the lead node then it will not have camera but will be monitored.
        if(root == NULL)
            return {false,true};
        /*
        1. has camera  (if it has camera then it is always monitored)
        2. is monitored , 
        */

        pair<bool,bool> l = count_camera(root->left);
        pair<bool,bool> r = count_camera(root->right);
        
        bool has_cam = false;
        bool monitored = false;
        
        //checking node has camera or not
        if(l.first || r.first)
            monitored = true;
        
        //checking if it is monitored or not , if then increament the camera and assign camera to it.
        if(!l.second || !r.second)
        {
            has_cam = true;
            monitored = true;
            ncamera++;
        }
        
        //return the bool pair telling has camera and is monitored or not 
        return {has_cam,monitored};

    }
};
