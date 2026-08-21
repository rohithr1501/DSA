class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> result(n, 1);

        for(int i = 1;i < nums.size();i++)
        {
            result[i] = nums[i - 1] * result[i - 1];
        }

        int rightProduct = 1;

        for(int i = nums.size() - 1;i >= 0;i--)
        {
            result[i] = rightProduct * result[i];
            rightProduct *= nums[i];
        }
        return result;
    }
};