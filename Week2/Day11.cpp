class Solution {
public:

    int maxScore(vector<int>& cardPoints, int k) {
        
        //while moving sliding window we will sum it in total and store the maxn result in best
        int total = 0,best;
        
        //sliding window will be of k size and initially from 0 to k 
        for(int i=0;i<k;i++)
        {
            total = total + cardPoints[i];
        }
        
        //intitally for first k size window best is the total obtained.
        best=total;
        
        // we will eliminate from leftmost of remaining elements and add the right most of remaining element
        //this is because if we are not selecting from starting i.e left then we will select from right i.e end

        for(int i=k-1,j=cardPoints.size()-1;~i;i--,j--)
        {
            /*
            I|P = [1,2,3,4,5,6,1]  total is 1+2+3 = best (6)
            total = 6 + 1(last) - 3, then 4 + 6(2nd last) -2, then 8 + 5(3rd last) - 1 
            */
            total = total + cardPoints[j] - cardPoints[i];
            
            //updating best everytime we get maximum of total
            best = max(best,total);
        }
        
        //return the best maximum score.
      return best;
    }
};
