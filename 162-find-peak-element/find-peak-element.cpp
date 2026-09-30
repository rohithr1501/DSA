class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int MaxValue = nums[0];


        int currentIndex = 0;

        for(int i  = 0;i < nums.size();i++)
        {
            if(nums[i] > MaxValue)
            {
                MaxValue = nums[i];
                currentIndex = i;
            }
        }
        return currentIndex;
    }
};