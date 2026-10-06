class Solution {
public:
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int left = 1;
        int right = position[position.size() - 1] - left;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValidGap(position, m, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    bool isValidGap(vector<int> position, int m, int gap) {
        int lastVisited = position[0];
        int ballInserted = 1;

        for (int i = 0; i < position.size(); i++) {
            if (position[i] - lastVisited >= gap) {
                ballInserted++;
                lastVisited = position[i];
            }
        }
        if (ballInserted >= m) {
            return true;
        } else {
            return false;
        }
    }
};