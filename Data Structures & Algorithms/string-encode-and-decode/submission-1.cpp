class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for (const string &i : strs) {
            
            res += to_string(i.size()) + "#";

            for (const char &ch : i) {

                if (isupper(ch)) {
                    res += 'Z' - (ch - 'A');
                } else if (islower(ch)) {
                    res += 'z' - (ch - 'a');
                } else {
                    res += ch;
                }

            }

        }
        return res;
    }


    vector<string> decode(string s) {
        vector<string> final;
        
        int i=0;

        while(i<s.size()){

            int j=i;

            while(s[j] != '#'){
                j++;
            }

            int len = stoi(s.substr(i,j-i));
            
            j++;
            
            string str="";
            
            for(int k=0;k<len;k++){

                char ch = s[j + k];

                if (isupper(ch)) {
                    str += 'A' + ('Z' - ch);
                }
                else if (islower(ch)) {
                    str += 'a' + ('z' - ch);
                }
                else {
                    str += ch;
                }

            }

            final.push_back(str);

            i = j+len;

        }

        return final;
    }
};