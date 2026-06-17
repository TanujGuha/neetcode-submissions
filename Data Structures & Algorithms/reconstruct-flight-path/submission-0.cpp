class Solution {
public:

    unordered_map <string , vector<string>> adj ; 
    map<pair<string,string> , int> count ; 
    vector <string> route ;  


    void dfs(string at){

        for (auto neigh : adj[at])
        {
            if (count[{at , neigh}] > 0)
            {
                count[{at , neigh}]-- ; 
                dfs(neigh) ; 
            }
        }

        route.push_back(at) ; 

    } 

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        sort(tickets.begin() , tickets.end()) ; 

        for(auto it : tickets)
        {
            string u = it[0] ; 
            string v = it[1] ; 

            adj[u].push_back(v) ; 
            count[{u,v}]++ ; 
        }
        

        dfs("JFK") ; 
        reverse(route.begin(), route.end());
        return route ; 
    }
};
