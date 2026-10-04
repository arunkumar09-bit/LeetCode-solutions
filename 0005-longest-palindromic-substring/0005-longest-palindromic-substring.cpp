class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        string ans = "";
        for (int i = 1; i < s.size(); i++) {
            int low = i;
            int high = i;
            while (low >= 0 && high < s.size()) {
                if (s[low] == s[high]) {
                    low--;
                    high++;
                } else
                    break;
            }
            string palindrome = s.substr(low + 1, high - low - 1);
            if (palindrome.length() > ans.length()) {
                ans = palindrome;
            }
            low = i - 1;
            high = i;
            while (low >= 0 && high < s.size()) {
                if (s[low] == s[high]) {
                    low--;
                    high++;
                } else
                    break;
            }
            palindrome = s.substr(low + 1, high - low - 1);
            if (palindrome.length() > ans.length()) {
                ans = palindrome;
            }
        }
        return ans;
    }
};