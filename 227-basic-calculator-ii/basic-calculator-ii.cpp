class Solution {
public:
    int calculate(string s) {
        vector<long long> nums;
        vector<char> op;
        long long currentNumber = 0;
        
   
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            }
            
            if ((!isdigit(c) && !isspace(c)) || i == s.length() - 1) {
                nums.push_back(currentNumber);
                if (i != s.length() - 1) {
                    op.push_back(c);
                }
                currentNumber = 0;
            }
        }
        
  
        for (int i = 0; i < op.size(); ) {
            if (op[i] == '*' || op[i] == '/') {
                if (op[i] == '*') {
                    nums[i] = nums[i] * nums[i + 1];
                } else {
                    nums[i] = nums[i] / nums[i + 1];
                }
              
                nums.erase(nums.begin() + i + 1);
                op.erase(op.begin() + i);
            } else {
                i++;
            }
        }
        
       
        long long result = nums[0];
        for (size_t i = 0; i < op.size(); i++) {
            if (op[i] == '+') {
                result += nums[i + 1];
            } else if (op[i] == '-') {
                result -= nums[i + 1];
            }
        }
        
        return result;
    }
};