class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        while (tokens.size() > 1) {
            for (int i = 2; i < tokens.size(); i++) {
                string token = tokens[i];
                if (token == "+" || token == "-" || token == "*" || token == "/") {
                   
                    int a = stoi(tokens[i - 1]); 
                    int b = stoi(tokens[i - 2]); 
                    int calculatedValue = 0;
                    
                    if (token == "+") calculatedValue = b + a;
                    else if (token == "-") calculatedValue = b - a;
                    else if (token == "*") calculatedValue = b * a;
                    else if (token == "/") calculatedValue = b / a;

                    tokens[i - 2] = to_string(calculatedValue);
                    tokens.erase(tokens.begin() + i - 1, tokens.begin() + i + 1);
                    break;
                }
            }
        }
        return stoi(tokens[0]);
    }
};