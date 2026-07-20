class Solution {
public:
    bool isValid(string s) {
        stack<int> stac;
        int pointer = 0;
        while (pointer < s.size()){
            if (s[pointer] == '(') stac.push(1);
            
            else if (s[pointer] == '{') stac.push(2);
            
            else if (s[pointer] == '[') stac.push(3);
            
            else if (s[pointer] == ')'){
                if (!stac.empty() && stac.top() == 1) stac.pop();
                else return 0;
            }
            else if (s[pointer] == '}'){
                if (!stac.empty() && stac.top() == 2) stac.pop();
                else return 0;
            }
            else if (s[pointer] == ']'){
                if (!stac.empty() && stac.top() == 3) stac.pop();
                else return 0;
            }

            pointer++;
        }

        if (stac.empty()) return 1;
        else return 0;
    }
};
