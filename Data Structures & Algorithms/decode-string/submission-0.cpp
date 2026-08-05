class Solution {
public:
    string decodeString(string s) {
        string decoded_str;
        int i = 0;
        
        stack<int> num_s;
        stack<char> char_s;
        
        string cur_num;
        while(1){
            if (i >= s.size()) break;

            if (s[i] >= '0' && s[i] <= '9') cur_num += s[i];
            
            else{
                if (cur_num.size() > 0){
                    int itr = stoi(cur_num);
                    num_s.push(itr);

                    cur_num = "";
                }

                if (s[i] == ']'){
                    int itr = num_s.top();
                    num_s.pop();

                    string word;
                    while(!char_s.empty()){
                        if (char_s.top() == '['){
                            char_s.pop();
                            break;
                        }

                        word += char_s.top();
                        char_s.pop();
                    }
                    
                    reverse(word.begin(), word.end());
                    
                    for(int idx = 0; idx < itr; idx++){
                        for(int p = 0; p < word.size(); p++){
                            char_s.push(word[p]);
                        }
                    }
                }

                else char_s.push(s[i]);
            }

            i++;
        }
        
        while(!char_s.empty()){
            decoded_str += char_s.top();
            char_s.pop();
        }

        reverse(decoded_str.begin(), decoded_str.end());
        return decoded_str;
    }
};