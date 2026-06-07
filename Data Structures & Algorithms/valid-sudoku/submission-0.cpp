class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int c = 0 ; c < 9 ; c++)
        {
            vector <int> pres(10, 0) ; 
            {
                for (int i = 0 ; i < 9 ; i++)
                {

                    if (board[i][c] == '.') continue ; 
                    pres[board[i][c] - '0']++ ; 
                    if (pres[board[i][c] - '0'] > 1)
                    {
                        return false ; 
                    }
                }
            }
        }


        for (int r = 0 ; r < 9 ; r++ )
        {
            vector <int> pres(10 , 0) ; 
            for (int i = 0 ; i < 9 ;i++)
            {
                if (board[r][i] == '.') continue ; 
                pres[board[r][i] - '0']++ ; 
                if (pres[board[r][i] - '0'] > 1)
                {
                    return false ; 
                }
            }
        }

        int sr = 0 ;
        for (sr ; sr < 7 ; sr += 3)
        {
            int sc = 0 ;
            for(sc ; sc < 7 ; sc += 3)
            {
                vector <int> pres(10 , 0) ; 
                for (int i = 0 ; i < 3 ; i++)
                {
                    for (int j = 0 ; j < 3 ; j++)
                    {

                        if (board[sr + i][sc + j]  == '.') continue ; 
                        pres[board[sr + i][sc + j] - '0']++ ; 
                        if (pres[board[sr + i][sc + j] - '0'] > 1)
                        {
                            return false ;  
                        }
                    }
                }
            }
        }

        return true ; 
    }
};
