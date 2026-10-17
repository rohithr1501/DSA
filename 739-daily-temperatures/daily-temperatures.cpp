class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> result(temperatures.size(), 0);
        stack<int> st;

        for (int i = temperatures.size() - 1; i >= 0; i--) {
           
           while(!st.empty() && temperatures[i] >= temperatures[st.top()])
           {
              st.pop();
           }
           if(!st.empty())
           {
               result[i] = st.top() - i;
           }
           st.push(i);
        }
        return result;
    }
};