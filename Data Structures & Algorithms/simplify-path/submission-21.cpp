class Solution {
public:
    string simplifyPath(string path) {
        stack<char> s;
        vector<string> output;
        
        int i = 0;
        
        while(1){
            // 1. END OF STRING BLOCK
            if (i >= path.size()){
                string temp;
                while(!s.empty()){
                    temp += s.top();
                    s.pop();
                }
                reverse(temp.begin(), temp.end());
                
                if (temp == "/.."){
                    if (!output.empty()) output.pop_back();
                }
                // Ignore "/." and "/" at the end of a string
                else if (temp != "/." && temp != "/" && temp != "") {
                    output.push_back(temp);
                }
                break;
            }

            // 2. MAIN LOOP BLOCK
            if (s.empty() && i < path.size()) {
                s.push(path[i]);
            }
            else if (s.top() == '/' && path[i] != '/') {
                s.push(path[i]);
            }
            else if (s.top() != '/' && path[i] == '/'){
                string temp;
                while(!s.empty()){
                    temp += s.top();
                    s.pop();
                }
                reverse(temp.begin(), temp.end());

                if (temp == "/.."){
                    if (!output.empty()) output.pop_back();
                }
                else if (temp != "/." && temp != "/") {
                    output.push_back(temp);
                }
                
                // FIXED SEGFAULT: Just push the slash, stack is empty here
                s.push(path[i]); 
            }
            else if (path[i] != '/') {
                s.push(path[i]);
            }

            i++;
        }
        
        // 3. RECONSTRUCTION
        string result;
        for(int idx = 0; idx < output.size(); idx++){
            result += output[idx];
        }

        // FIXED EMPTY STRING: return "/" if nothing is left
        if (result.empty()) return "/";
        return result;
    }
};