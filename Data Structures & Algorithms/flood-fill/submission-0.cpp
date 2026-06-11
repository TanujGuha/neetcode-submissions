class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int nr = image.size() ; 
        int nc = image[0].size() ; 


        int tar = image[sr][sc] ; 
        dfs(image , sr ,sc , tar) ; 
        image[sr][sc] = color ; 


        for(int i = 0 ; i < nr ; i++)
        {
            for(int j = 0 ; j < nc ; j++)
            {
                if (image[i][j] == -1)
                {
                    image[i][j] = color ; 
                }
            }
        }

        return image ; 

    }


    void dfs(vector<vector<int>>& image , int x , int y , int tar)
    {

        int nr = image.size() ; 
        int nc = image[0].size() ; 

        if ( x >= nr|| y >= nc || x <0 || y <0 || image[x][y] != tar )
        {
            return ; 
        }
        image[x][y] = -1 ; 
        dfs(image , x+1 , y , tar) ; 
        dfs(image , x , y+1 , tar) ; 
        dfs(image , x-1 , y, tar) ; 
        dfs(image , x , y-1 , tar ) ;
    }
};