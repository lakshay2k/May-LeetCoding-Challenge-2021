class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vec;
		// Inititally filling all with '.' as we have to mark Q
        vector<string> board(n,string(n,'.')); 
        backtrack(vec,board,0,n);
        return vec;
    }
    void backtrack(vector<vector<string>> &vec,vector<string> & board,int row,int &n) 
    {        
	    // Base case
        if(row == n)
        {
            vec.push_back(board);
            return;
        }
		// Filling columns one by one
        for(int col=0;col<n;++col) 
        {
            if(isValid(board,row,col,n))
            {
                board[row][col] = 'Q';
				// Recursing row by row
                backtrack(vec,board,row+1,n); 
				// Backtracking by removing queen from the cell to explore other choices
                board[row][col] = '.'; 
            }
        }
    }
    bool isValid(vector<string> &board,int row,int col,int n)
    {    
	    // If column has queen already
        for(int i=row-1;i>=0;i--) 
        {
            if(board[i][col] == 'Q')
                return false;
        } 
	    // Diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        // Antidiagonal
        for(int i=row-1,j=col+1;i>=0 && j<board.size();i--,j++)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        
		// We are not checking for rows as we are filling them one after the other
        return true;
    }
};