class Solution {
public:


    int fP(int u , vector <int> &parent)
    {
        if (u == parent[u]) return u ; 
        return parent[u] = fP(parent[u] , parent) ; 
    }


    int ur(int u , int v , vector <int> &parent , vector <int> &rank)
    {
        int up = fP(u , parent) ;
        int vp = fP(v , parent) ; 

        if(up == vp)
        {
            return 0 ; 
        }


        int ru = rank[up] ;
        int rv = rank[vp] ;

        if (ru < rv)
        {
            parent[up] = vp ; 
        }
        else if(ru >  rv)
        {
            parent[vp] = up ; 
        }
        else
        {
            parent[up] = vp ;
            rank[vp]++ ;
        }

 
        return 1 ; 


    }
    int findCircleNum(vector<vector<int>>& ic) {
        int r = ic.size() ; 
        int c = ic[0].size() ; 


        vector <int> parent(r) ; 
        vector <int> rank(r , 0 ) ; 
        for (int i = 0 ; i < r ; i++) parent[i] = i ; 

        int pr = r ; 

        for (int i = 0 ; i < r ; i++)
        {
            for(int j = 0 ; j < c ; j++)
            {
                if (ic[i][j])
                {
                    pr -= ur(i , j , parent , rank) ; 
                }
            }
        }

        return pr ; 

    }
};