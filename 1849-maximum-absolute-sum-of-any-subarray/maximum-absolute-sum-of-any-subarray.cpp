class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int maxSum = nums[0];
        int currentMax = 0;

        int MinSum = nums[0];
        int currentMin = 0;

        for(int i = 0;i < nums.size();i++)
        {
            currentMax  = max(nums[i],currentMax + nums[i]);
            maxSum = max(maxSum , currentMax);

            currentMin  = min(nums[i],currentMin + nums[i]);
            MinSum = min(MinSum , currentMin);
        }
        
        return max(maxSum,abs(MinSum));
    }
};