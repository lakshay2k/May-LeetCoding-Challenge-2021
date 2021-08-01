class Solution {
public:

    int jump(vector<int>& nums) {
        
        // initialising the first jump which we take from first index so no. of jumps is default = 1
        int jumps = 1, n = nums.size();
        
        //if first index value is zero which means we cannot jump and id size is one which means jumps to be taken are zero
        if(n == 1 || nums[0] == 0)
            return 0;
        
        //we set the curr posn to value at first index as we will go to that index at first jump
        // and we set the farthest to nums[0] because that is the farthest we can jump
        int farthest = nums[0], curr = nums[0];
        
        for(int i=1; i<n; i++)
        {
            //if come at last index , we return the no. of jumps encountered
            if(i==n-1)
                return jumps;
            //we check between i to i+nums[i] that can we find any farthest jump using indexes in b/w
            farthest = max(farthest,  i + nums[i]);
            if(i == curr)
            {
                // when we encounter curr posn then we increament jump which means that we have done one farthest jump and is checking for next farthest jump by chnging curr to farthest
                jumps++;
                curr = farthest;
            }
        }

        return jumps;
    }
};
