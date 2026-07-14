class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int minimumLength = INT_MAX;
        int currentSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            currentSum += nums[right];

            while (currentSum >= target) {
                minimumLength = std::min(minimumLength, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
           
        }

        return (minimumLength == INT_MAX) ? 0 : minimumLength;
    }
};