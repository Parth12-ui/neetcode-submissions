class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for(string str : strs){
            for (char h : str){
                encoded_string += h + 20;
            }

            encoded_string += '.' + 20;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decodedStrs;
        string word;
        for(char h : s){
            if (h == '.' + 20){
                decodedStrs.push_back(word);
                word = "";
            }

            else word += h - 20;
        }
        return decodedStrs;
    }  
};
