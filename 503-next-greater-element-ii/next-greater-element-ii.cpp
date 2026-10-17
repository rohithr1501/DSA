class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        stack<int>st;
        vector<int> result(n, -1);

        for (int i = 2 * (n - 1); i >= 0; i--) {
            int num = nums[i % n];

            while(!st.empty() && num >= st.top())
            {
                st.pop();
            }
            if(i < n && !st.empty())
            {
                result[i%n] = st.top();
            }
            st.push(num);
        }
        return result;
    }
};