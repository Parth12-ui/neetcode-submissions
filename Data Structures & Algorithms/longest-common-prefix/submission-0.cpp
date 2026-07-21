class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];
        for(string s : strs){
            string ms;
            int length = (s.size() > result.size()) ? result.size() : s.size();
            for(int i = 0; i<length; i++){
                if (result[i] == s[i]){
                    ms += result[i];
                }
                else break;
            }

            result = ms;
        }

        return result;
    }
};