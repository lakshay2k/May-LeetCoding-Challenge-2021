class NumMatrix {
public:
    
    //creating the dp vector to store the dynamic result of sum of previous rectangle of matrices
    vector<vector<long>> dp;
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        int r = matrix.size()+1 , c = matrix[0].size()+1;
        dp = vector<vector<long>>(r, vector<long>(c,0));
        
        for(int i = 1; i<r ; i++)
        {
            for(int j =1; j<c ;j++)
            {
                //column rectangle sum + row RS + matrix value at that place minus the values of previous sum

                dp[i][j] = dp[i-1][j] + dp[i][j-1] + matrix[i-1][j-1] - dp[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        
        // whole sum till last r2,c2 - row rect sum - col rect sum + values subtracted twice.
        return (int)(dp[r2+1][c2+1] - dp[r2+1][c1] - dp[r1][c2+1] + dp[r1][c1]);     
    }
};
