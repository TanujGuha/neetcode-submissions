class Solution {
public:
    bool can_deliver(vector<int>& weights, int days, int capa) {   
        int days_needed = 1; // Start at Day 1
        int current_weight = 0; 
        
        for (int i = 0; i < weights.size(); i++) {
            // If a single package is heavier than the capacity, 
            // it's impossible to ship it (handled by setting capa_min correctly too)
            if (weights[i] > capa) return false;

            if (current_weight + weights[i] <= capa) {
                current_weight += weights[i]; 
            } else {
                // Move to the next day and put this package on it
                days_needed++; 
                current_weight = weights[i]; 

                if (days_needed > days) return false; 
            }
        }
        return true; 
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int capa_min = 0; 
        int capa_max = 0; 

        // Set optimal boundaries based on the input array
        for (int w : weights) {
            capa_min = max(capa_min, w); // Must be at least as large as the heaviest item
            capa_max += w;               // Maximum is loading everything on Day 1
        }

        while (capa_min < capa_max) {
            int capa_mid = capa_min + (capa_max - capa_min) / 2; 
            
            if (can_deliver(weights, days, capa_mid)) {
                capa_max = capa_mid; // Mid works, let's try to squeeze it lower
            } else {
                capa_min = capa_mid + 1; // Too small, must step up capacity
            }
        }

        return capa_max; 
    }
};