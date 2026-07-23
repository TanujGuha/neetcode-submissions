class Solution {
public:
    // vector <int> tribo((1<<31)) ; 
    int tribonacci(int n) {
        // tribo[0] = 0 ; 
        // tribo[1]  = 1 ; 
        // tribo[2] = 1 ;

        int t0 = 0 ; 
        int t1 = 1 ; 
        int t2 = 1 ; 



        if (n == 0) return 0 ;
        if (n == 1) return 1 ; 
        if ( n == 2) return 1 ;
    
        int tj = 0 ; 
        for (int j = 3 ; j <= n ; j++)
        {
            tj = t0 + t1 + t2 ;
            t0 = t1 ; 
            t1 = t2 ; 
            t2 = tj ;  
        }

        return tj ;
        
    }
};