class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector <int> size(n , 0) ; 
        vector <int> parent(n ) ; 
        for (int i = 0 ; i < n ; i++)
        {
            parent[i] = i ;
        }


        int e = edges.size() ; 

        for(int i = 0 ; i < e ; i++)
        {
            int u = edges[i][0] ; 
            int v = edges[i][1] ;

            ur(u , v , parent , size) ; 
        }

        set <int> up ; 
        for (int i = 0 ; i < n ;i++)
        {

            parent[i] = fP(i , parent) ;
            up.insert(parent[i]) ; 
        }


        return up.size() ; 

        // return n - count(size.begin() , size.end() , 0) ; 

    }


    int fP(int u , vector<int> &parent) 
    {
        if (u == parent[u])
        {
            return u ; 
        }
        return parent[u] = fP(parent[u] , parent) ; 
    }


    void ur(int u , int v , vector <int> &parent , vector<int> &rank)
    {
        int up = fP(u , parent) ; 
        int vp = fP(v , parent) ; 

        if (up == vp)
        {
            return ; 
        }

        int ru = rank[up] ; 
        int rv = rank[vp] ; 

        if (ru < rv)
        {
            parent[up] = vp ; 
            rank[vp]++ ; 
        }
        else if (ru > rv)
        {
            parent[vp] = up ; 
            rank[up]++ ;
        }
        else
        {
            parent[up] = vp ; 
        }

        return ; 

    }
};
