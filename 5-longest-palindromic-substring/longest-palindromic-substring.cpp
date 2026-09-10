class Solution {
public:
    bool isValidPalindrome(string& s, int left, int right) {

        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    string longestPalindrome(string s) {

        string result = "";

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {

                bool isValid = isValidPalindrome(s, i, j);

                if (isValid) {
                    int currentLenght = j - i + 1;
                    if (currentLenght > result.size()) {
                        result = s.substr(i, currentLenght);
                    }
                }
            }
        }
        return result;
    }
};