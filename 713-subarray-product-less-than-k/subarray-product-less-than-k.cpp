class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int totalCount = 0;

        for(int i = 0;i < nums.size();i++)
        {
            int currentSum = 1;
            for(int j = i;j < nums.size();j++)
            {

                currentSum *= nums[j];

                if(currentSum < k)
                {
                    totalCount++;
                }
                else
                {
                    break;
                }

            }
        }
        return totalCount;
    }
};