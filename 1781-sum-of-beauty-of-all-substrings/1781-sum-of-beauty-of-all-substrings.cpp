class Solution {
public:
    int beautySum(string s) {
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            map<char, int> mpp;
            for (int j = i; j < s.size(); j++) {
                mpp[s[j]]++;
                int maxi = 0;
                int mini = INT_MAX;
                for (auto it : mpp) {
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }
                ans += ((long long)maxi - (long long)mini);
            }
        }
        return ans;
    }
};