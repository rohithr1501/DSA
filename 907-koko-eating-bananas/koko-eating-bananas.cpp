class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;

        auto max = max_element(piles.begin(), piles.end());
        int right = *max;
        int ans;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long hours = 0;
            for (int j = 0; j < piles.size(); j++) {
                hours += (piles[j] + mid - 1) / mid;
            }
            if (hours <= h) {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};