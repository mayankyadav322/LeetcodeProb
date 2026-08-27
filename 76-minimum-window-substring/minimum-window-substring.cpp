class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        int m = s.length();
        int n = t.length();

        if (n > m) return "";

        for (int i = 0; i < n; i++) {
            mp[t[i]]++;
        }

        int left = 0;
        int right = 0;
        int count = 0;
        int minlen = INT_MAX;
        int sindex = -1;

        while (right < m) {

            if (mp[s[right]] > 0) {
                count++;
            }

            mp[s[right]]--;

            while (count == n) {

                if (right - left + 1 < minlen) {
                    minlen = right - left + 1;
                    sindex = left;
                }

                mp[s[left]]++;

                if (mp[s[left]] > 0) {
                    count--;
                }

                left++;
            }

            right++;
        }

        if (sindex == -1) {
            return "";
        }

        return s.substr(sindex, minlen);
    }
};