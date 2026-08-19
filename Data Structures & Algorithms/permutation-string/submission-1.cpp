class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> lookup;

        for(char ch:s1){
            lookup[ch]++;
        }
        
        for(int i = 0; i < s2.length() ; i++){
            unordered_map<char,int> fr;
            if(lookup.contains(s2[i])){
                fr[s2[i]]++;
                int j = 1;
                while(j<s1.length() && i + j < s2.length()){
                    fr[s2[i + j]]++;
                    j++;
                }
                if(lookup == fr){
                    return true;
                }
            }
        }

        return false;
    }
};
