class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size() ; 

        vector <int> diff(n) ;


        int m = 0 ;
        int ts = 0 ;  
        for (int i = 0 ; i < n ; i++)
        {
            diff[i] = gas[i] - cost[i] ; 
            ts += diff[i] ; 
            m = max(m , diff[i]) ; 
        }


        if (m < 0 || ts < 0)
        {
            return  -1 ; 
        }


        int start = 0 ; 
        int s = 0 ; 
        for (int i = 0 ; i < n ; i++)
        {
            s += diff[i] ; 
            if (s < 0)
            {
                start = i+1 ;
                s = 0 ; 
            }
        }

        return start ;



    }
};
