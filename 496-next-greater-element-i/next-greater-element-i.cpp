#include <vector>
#include <unordered_map>
#include <stack>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> nextGreater;
        std::stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }


        std::vector<int> result;
        result.reserve(nums1.size());
        for (int num : nums1) {
            if (nextGreater.count(num)) {
                result.push_back(nextGreater[num]);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};