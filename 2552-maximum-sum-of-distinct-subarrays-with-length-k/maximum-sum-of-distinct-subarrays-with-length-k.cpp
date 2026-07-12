class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long  currentsum = 0;
        long long  maxSum = 0;
        unordered_map<int,int> freqMap;
        int left = 0;


        for(int right = 0;right < nums.size();right++)
        {
            currentsum  += nums[right];
            freqMap[nums[right]]++;

            if((right - left + 1) > k)
            {
                currentsum -= nums[left];
                freqMap[nums[left]]--;

                if(freqMap[nums[left]] == 0)
                {
                    freqMap.erase(nums[left]);
                }
                left++;
            }
             if (right - left + 1 == k && freqMap.size() == k) {
                maxSum = max(maxSum, currentsum);
            }

        }
        return maxSum;
        
    }
};