class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int e = pre.size() ; //  number of edges in my graph model

        vector <vector<int>> adjl(numCourses) ;  //  adjacency list
        vector <int> idg(numCourses)  ; // To keep track of indegree


        for (int i = 0 ; i < e ; i++){
            auto it = pre[i] ; 
            adjl[it[1]].push_back(it[0]) ; 
            idg[it[0]]++ ;
        }


        queue <int> q ; 
        for (int i = 0 ; i < numCourses ; i++)
        {
            if (idg[i] == 0)
            {
                q.push(i) ; 
            }
        }
        int l = q.size() ; 
        //  visited vector  ?? 

        vector <int> ans ; 
        
        auto ch = bfs(q , l , idg , adjl , ans  )  ; 
           
        if(ch.size() != numCourses)
        {
            return {} ;
        }
        else
        {
            return ans ; 
        }
    }

    vector <int> bfs(queue <int> &q , int l , vector <int> &idg , vector<vector<int>> &adjl , vector<int> &ans)
    {
        if (q.empty())
        {
            return ans ; 
        }


        int na = 0 ; 
        while(l--)
        {
            int i = q.front() ; 
            q.pop() ; 


            ans.push_back(i) ; 

            for (auto j : adjl[i])
            {
                idg[j]-- ; 
                if (idg[j] == 0)
                {
                    na++ ; 
                    q.push(j) ; 
                }
            }

        }  


        return bfs(q , na , idg , adjl , ans) ;  
    }     
};
