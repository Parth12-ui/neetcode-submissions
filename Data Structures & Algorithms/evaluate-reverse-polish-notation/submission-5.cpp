class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string& op : tokens){
            if (op == "+"){
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();

                s.push(n1 + n2);
            }

            else if (op == "-"){
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();

                s.push(n2 - n1);
            }

            else if (op == "*"){
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();

                s.push(n1 * n2);
            }

            else if (op == "/"){
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();

                s.push(n2 / n1);
            }

            else s.push(stoi(op));
        }

        return s.top();
    }
};
