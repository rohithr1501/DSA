class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k < 0) return 0;
        int totalCount = 0;
        int left = 0;
        int currentProduct = 1;
        for(int right = 0;right < nums.size();right++)
        {
            currentProduct *= nums[right];

            while(currentProduct >= k && left <= right)
            {
                currentProduct  /= nums[left];
                left++;
            }
            totalCount += (right - left + 1);

        }
        return totalCount;
    }
};