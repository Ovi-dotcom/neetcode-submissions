class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) return false;

        int need[26] = {};
        int window[26] = {};

        for (char ch : s1) {
            need[ch - 'a']++;
        }

        int len = s1.length();

        for (int i = 0; i < len; i++) {
            window[s2[i] - 'a']++;
        }

        bool match = true;

        for (int i = 0; i < 26; i++) {
            if (need[i] != window[i]) {
                match = false;
                break;
            }
        }

        if (match) return true;

        for (int right = len; right < s2.length(); right++) {

            window[s2[right] - 'a']++;

            window[s2[right - len] - 'a']--;

            match = true;

            for (int i = 0; i < 26; i++) {
                if (need[i] != window[i]) {
                    match = false;
                    break;
                }
            }

            if (match) return true;
        }

        return false;
    }
};