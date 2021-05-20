class Solution {
public:
    bool ispalindrome(string s)
    {
        //it is to check palindrome
        int start =0;
        int end = s.size()-1;
        while(start<end)
        {
            if(s[start] != s[end])
                return false;
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }
    
    int superpalindromesInRange(string left, string right) {
        
        //creating vector for all palindromes in given range
        vector<long> pno;
        long lno = stol(left);
        long rno = stol(right);
        
        int count = 0;
        
        //numbers from 1 to 10 are palindromes so adding them directly
        for(long i=1; i<10;i++)
        {
            pno.push_back(i);
        }
        
        for(long i=1; i<10000; i++)
        {
            string lp = to_string(i);
            string temp = lp;
            reverse(temp.begin(),temp.end());
            string rp = temp;
            
            //two ways to generate a palindrome
            //1.
            pno.push_back(stol(lp+rp));
            
            for(int digit = 0; digit<10;digit++)
            {
                //2.
                pno.push_back(stol(lp + to_string(digit) + rp));
            }
        }
        
        //checking using condition in created vector of palindromes
        for(long no : pno)
        {
            long sqno = no*no;
            
            //if sqno no. is satisfy the range of left and right ans is palindrome then it is super palindrome
            if(lno <= sqno && rno >= sqno && ispalindrome(to_string(sqno)))
                count++;
        }
        
        return count;
    }
    
    
};