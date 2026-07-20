class Solution {
public:
    bool validPalindrome(string s) {
    
        int fp = 0, bp = s.size()-1;
        while(fp <= bp){
            if (s[fp] != s[bp]) {
                return (comparison(s, fp+1, bp) || comparison(s, fp, bp-1));
            }

            fp++;
            bp--;
        }

        return 1;
    }

private:
    bool comparison(string s, int i, int j){
        while (i <= j){
            if (s[i] != s[j]) return 0;
            i++;
            j--;
        }

        return 1;
    }
};