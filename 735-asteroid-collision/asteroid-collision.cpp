class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result = asteroids;
        int i = 0;
        
        while (i < (int)result.size() - 1) {
            int a = result[i];
            int b = result[i + 1];
            
            if (a > 0 && b < 0) {
                if (abs(a) < abs(b)) {
                    result.erase(result.begin() + i);
                    if (i > 0) i--; 
                } 
                else if (abs(a) > abs(b)) {
                    result.erase(result.begin() + i + 1);
                } 
                else {
                    
                    result.erase(result.begin() + i, result.begin() + i + 2);
                    if (i > 0) i--; 
                }
            } else {
                i++;
            }
        }
        
        return result;
    }
};