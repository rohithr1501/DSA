class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {

        int low  =  1;
        int high = 1e7;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValidSpeed(dist, hour, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    bool isValidSpeed(vector<int> distance, double hour, int speed) {
        double currentHour = 0;
        for (int i = 0; i < distance.size() - 1; i++) {
            currentHour += (distance[i] + speed - 1) / speed;
        }
        currentHour += double(distance[distance.size() - 1]) / speed;
        if (currentHour <= hour) {
            return true;
        }
        return false;
    }
};