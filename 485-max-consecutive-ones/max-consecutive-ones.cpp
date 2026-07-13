class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
       
        int maxCount = 0;
        int CurrentCount = 0;
 
        for(int right = 0;right < nums.size();right++)
        {
            if(nums[right] == 1)
            {
                CurrentCount++;
            }
            else
            {
                maxCount = std::max(maxCount,CurrentCount);
               CurrentCount = 0;
            }
        }
        return std::max(maxCount,CurrentCount);
    }
};