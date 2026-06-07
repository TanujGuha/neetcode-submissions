class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map <int, set <int>> row , col  ;
        map <pair<int,int> , set <int>> sq ; 

        for (int i = 0 ; i < 9 ; i++)
        {
            for (int j = 0 ; j < 9 ; j++)
            {
                if (board[i][j] != '.')
                {
                    int x = board[i][j] - '0' ; 
                    if (row[i].count(x) > 0)
                    {
                        return false ; 
                    }
                    else
                    {
                        row[i].insert(x) ;
                    }
                    if (col[j].count(x) > 0)
                    {
                        return false ; 
                    }
                    else
                    {
                        col[j].insert(x) ; 
                    }

                    if (sq[{i/3 , j/3}].count(x) > 0)
                    {
                        return false ; 
                    }
                    else
                    {
                        sq[{i/3 , j/3}].insert(x) ;
                    }
                }
            }
        }

        return true ;
         
    }
};
