class Solution {
public:

    int minDistance(string word1, string word2) {
        
        //sizes of given words
        int s1=word1.size(),s2=word2.size();
        
        //dynamic array to store the no of common subsequence while traversing both strings
        int dp[s1+1][s2+1];
        
        for(int l=0;l<=s1;l++)
        {
            for(int m=0;m<=s2;m++)
            {
                dp[l][m]=0;
            }
        }
    
        for(int i=0;i<=s1;i++)
        {
            for(int j=0;j<=s2;j++)
            {
                //for zero index continue
                if(i==0 || j==0)
                    continue;
                //if the words strings does match add 1 to previous = dp[i-1][j-1]
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                //if words strings dont match take max of above and left numbers
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        cout<<dp[s1][s2];
        //return the total - twice of length of common subsequence
        return s1+s2 - 2*dp[s1][s2];
    }
};