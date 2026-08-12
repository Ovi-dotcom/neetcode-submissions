class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> look;

        int left = 0;
        int maxi = 0;

        for (int right = 0; right < s.length(); right++) {

            while (look.contains(s[right])) {
                look.erase(s[left]);
                left++;
            }

            look.insert(s[right]);

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};
