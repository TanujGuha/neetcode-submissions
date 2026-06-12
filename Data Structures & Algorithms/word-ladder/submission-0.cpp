class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue <string> q ; 
        unordered_set <string> visi;
        int d = 1 ; 
        int l = 1 ; 
        q.push(beginWord) ;
        visi.insert(beginWord) ;    

        int ans = bfs(q , l , d , wordList , endWord, visi) ; 
        if (ans == -1)
        {
            return 0 ; 
        }

        return ans ; 

        
    }

    int bfs(queue <string> &q , int l , int dis ,vector<string> &wordList , string endW , unordered_set <string> &visi)
    {
        if (q.empty())
        {
            return -1 ;
        }

        int na = 0 ; 
        while(l--)
        {
            auto it = q.front() ; 
            q.pop() ; 

            if (it == endW)
            {
                return dis ; 
            }

            vector <string> nei = vn(wordList , it) ; 

            for(auto i : nei)
            {
                if (visi.count(i) == 0)
                {
                    na++ ; 
                    q.push(i) ; 
                    visi.insert(i) ;
                }
            }
        }

        return bfs(q , na , dis + 1 , wordList, endW , visi)  ;
    }    

    vector <string> vn(vector<string>& wordList , string s)
    {
        int n = s.size() ; 

        vector <string> ans ; 

        for (auto it : wordList)
        {
            int cnt = 0 ; 
            for (int i = 0 ; i < n ; i++)
            {
                if (it[i] != s[i])
                {
                    cnt++ ; 
                }
            }

            if (cnt == 1)
            {
                ans.push_back(it) ; 
            }
        }

        return ans ; 
    }
};
