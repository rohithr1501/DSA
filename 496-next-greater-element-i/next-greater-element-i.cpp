class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        std::unordered_map<int, int> mapnextGreater;

        std::stack<int> st;

        std::vector<int> result(nums1.size(), -1);

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }

            if (!st.empty()) {
                mapnextGreater[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {

            if (mapnextGreater[nums1[i]] == 0) {
                result[i] = -1;
            } else {
                result[i] = mapnextGreater[nums1[i]];
            }
        }
        return result;
    }
};