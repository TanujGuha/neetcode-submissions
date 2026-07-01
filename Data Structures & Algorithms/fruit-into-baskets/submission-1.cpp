class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // need to find the longest subarray whihc has at max two 
        // types of fruits
        // max subarray with at most two unique elements


        unordered_set <int>  ms ; 
        int l = 0 ; 
        int r = 0 ; 
        while(r < fruits.size() && ms.size() <= 2 )
        {
            if (ms.count(fruits[r])) r++ ; 
            else 
            {
                if (ms.size() == 2) break ; 
                else ms.insert(fruits[r]) ; 
                r++ ; 
            }
        }
        

        if (r == fruits.size()) return fruits.size() ; 
        // otherwise r points to a spot where a new element if found

        unordered_map<int,int> freq ; 
        for(int i = 0 ; i < r ; i++)
        {
            freq[fruits[i]]++ ; 
        }
        int ml = 0 ;
        int nz = 2 ; 
        for(r ; r < fruits.size() ; r++)
        {
            if (!ms.count(fruits[r]) && ms.size() == 2)
            {
                ml = max(ml , r - l) ; 
                // advancing l

                while(nz == 2)
                {
                    freq[fruits[l]]-- ; 
                    if (freq[fruits[l]] == 0) nz-- ; 
                    else l++ ; 
                }
                ms.erase(fruits[l]) ; 
                l++ ; 
                freq[fruits[r]]++ ; 
                nz++ ;  
                ms.insert(fruits[r]) ; 
            }
            else if (ms.count(fruits[r]))
            {
                ml = max(ml , r - l + 1)  ;
                freq[fruits[r]]++ ; 
            }
            

        }

        return ml ; 


    }
};