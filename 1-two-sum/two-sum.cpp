class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<pair<int,int>> result;

        for(int i = 0;i < nums.size();i++)
        {
            result.push_back({nums[i],i});
        }

        sort(result.begin(),result.end());

        int left = 0;
        int right = result.size() - 1;

        while(left < right)
        {
            int sum = result[left].first + result[right].first;

            if(sum == target)
            {
                return {result[left].second,result[right].second};
            }
            else if(sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
         return{};
    }
   
};