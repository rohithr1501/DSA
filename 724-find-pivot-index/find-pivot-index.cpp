class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        
        for(int i =0;i < nums.size();i++)
        {
            int right = i;
            int left = i;
            int leftsum = 0;
            int rightsum = 0;

            while(left >= 0)
            {
                leftsum += nums[left];
                left--;
            }
            while(right < nums.size())
            {
                rightsum += nums[right];
                right++;
            }
            if(leftsum == rightsum)
            {
                return i;
            }

        }
        return -1;
    } 
};