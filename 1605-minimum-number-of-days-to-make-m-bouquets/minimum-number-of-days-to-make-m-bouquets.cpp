class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        int low = 0;
        int high = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            low = std::min(low, bloomDay[i]);
            high = std::max(high, bloomDay[i]);
        }
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValidDay(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;

            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    bool isValidDay(vector<int> bloomDay, int bouq, int flower, int day) {
        int flowerCount = 0;
        int bouqcount = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                flowerCount++;
                if (flowerCount == flower) {
                    bouqcount++;
                    flowerCount = 0;
                }
            } else {
                flowerCount = 0;
            }
        }
        if (bouqcount >= bouq) {
            return true;
        }
        return false;
    }
};