class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int maxLen = 0;
    int left = 0;
    int zerosCount = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) {
            zerosCount++;
        }

        while (zerosCount > k) {
            if (nums[left] == 0) {
                zerosCount--;
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
    }
};