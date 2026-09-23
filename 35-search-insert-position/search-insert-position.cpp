class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        long left = 0;
        long right = nums.size() - 1;

        while (left <= right) {
            long mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return (int)mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return (int)left;
    }
};