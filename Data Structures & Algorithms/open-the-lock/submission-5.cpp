class Solution {
public:

    // BFS based solution
    int openLock(vector<string>& deadends, string target) {
        queue <string> q ; 
        unordered_set <string> visi ;
        visi.insert("0000") ; 
        q.push("0000") ; 
        int l = 1 ; 
        int dist = 0 ; 

        auto check = find(deadends.begin() , deadends.end() , "0000") ; 
        if (check != deadends.end())
        {
            return -1 ; 
        }

        int ans = bfs(q , deadends , l , dist , target , visi) ; 
        if (ans == -1)
        {
            return -1 ; 
        }

        return ans ; 
    }


    int bfs( queue <string> &q, vector<string>& deadends ,int l , int dis ,string target, unordered_set <string> &visi )
    {


        if (q.empty())
        {
            return -1 ;
        }

        int na = 0 ; 
        while(l--)
        {
            auto it = q.front() ; // it is a string
            q.pop() ;
            if (it == target)
            {
                return dis ;
            }



            for (int i = 0 ; i < 4 ; i++)
            {

                char ori = it[i] ;  
                char c1 = (it[i]  - '0' + 1) % 10  + '0'; 
                char c2 = (it[i] - '0' - 1 + 10) % 10 + '0' ; 


                it[i] = c1 ; 
                auto f  = find(deadends.begin() , deadends.end() , it) ;
                // auto f1 = find(visi.begin() , visi.end() , it) ; 
                if (f == deadends.end() && visi.count(it) == 0 )
                {
                    na++ ; 
                    q.push(it) ; 
                    visi.insert(it) ; 
                }
                it[i] = c2 ; 
                f =  find(deadends.begin() , deadends.end() , it) ;
                // f1 = find(visi.begin() , visi.end() , it) ; 
                if (f == deadends.end()&&visi.count(it) == 0 )
                {
                    na++ ; 
                    q.push(it) ; 
                    visi.insert(it) ; 
                }

                it[i] = ori ; 
            }

        }

        return bfs(q , deadends , na , dis + 1 , target,  visi) ; 
    }
};