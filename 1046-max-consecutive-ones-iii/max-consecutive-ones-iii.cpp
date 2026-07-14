class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int maxOnes = 0;
        int ZeroCount = 0;
        int left = 0;

        for(int right = 0;right < nums.size();right++)
        {
            if(nums[right] == 0)
            {
                ZeroCount++;
            }

            while(ZeroCount > k)
            {
                if(nums[left] == 0)
                {
                    ZeroCount--;
                }
                left++;
            }
            maxOnes = std::max(maxOnes,right-left+1);
        }
        return maxOnes;
    }
};