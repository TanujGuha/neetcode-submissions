class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0} ; 
        int col[9] = {0} ; 
        int sq[9] = {0} ; 

        for(int i = 0 ; i < 9 ; i++)
        {
            for (int j = 0 ; j < 9 ; j++)
            {
                if (board[i][j] == '.') continue; 

                int v = (board[i][j] - '0') - 1 ; 
                int pos = (1 << v) ; 
                if (((row[i] & pos) != 0) || ((col[j] & pos) != 0) || ((sq[((i/3)*3 + j/3)] & pos) != 0)) 
                {
                    return false ; 
                }


                row[i] |= pos; 
                col[j] |= pos ; 
                sq[((i/3)*3 + j/3)] |= pos ; 


            }
        }

        return true ; 
         
    }
};
