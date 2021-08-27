class Solution {
public:

    int minPartitions(string n) {
        
        //the minimum number of trun to return a decibinary number is the max at that position
        char maximum_number = '0';
        
        //iteration over every number of given digit
        for(auto &c : n)
        {
            if(c>maximum_number)
                maximum_number = c;
        }
        
        //returning the max number
        return maximum_number-'0';

    }
};
