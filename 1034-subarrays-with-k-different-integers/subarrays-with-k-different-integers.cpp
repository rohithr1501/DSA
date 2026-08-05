class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atMost(nums, k) - atMost(nums, k - 1);
      
    }
    int atMost(vector<int>& nums, int k)
    {
          if (k < 0) return 0;
        int count = 0;
        int left = 0;
        unordered_map<int,int> FreqMap;

        for(int right = 0;right < nums.size();right++)
        {
            FreqMap[nums[right]]++;

            while(FreqMap.size() > k)
            {
                FreqMap[nums[left]]--;

                if(FreqMap[nums[left]] == 0)
                {
                    FreqMap.erase(nums[left]);
                }
                left++;
            }
          
                count += (right - left + 1);
            
        }

        return count;

    }
};