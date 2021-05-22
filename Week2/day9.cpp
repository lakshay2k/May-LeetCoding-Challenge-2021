class Solution {
public:

    bool isPossible(vector<int>& target) {
        
        //using the top to bottom aaproach i.e dividing the given array to [1,1,1]
        //creating priortiy queue to store the given vector and keep the largest element at top
        priority_queue<int> mypq;
        unsigned int total = 0;
        
        for(int n : target)
        {
            //calculating total to check the remainder at initital case 
            total = total + n;
            mypq.push(n);
        }
        
        while(mypq.top()!=1)
        {
            //taking the first largest element i.e on top
            int a = mypq.top();
            mypq.pop();
            
            //removing that from sum to take modulus from the rest sum
            total = total-a;
            
            //if the num is less than the total or total becomes 0 then return false
            if(a<=total || total < 1)
                return false;
            
            //retrieving the previous value by taking % with rest sum
            a = a%total;
            
            //adding the remainder to sum and to the priority queue
            total=total+a;
            mypq.push(a);
        }
        
        //while loop ends only if a==1 and we get the array [1,1,1], hence return true
        return true;
    }
};