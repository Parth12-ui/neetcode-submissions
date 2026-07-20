class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged;
        int p1 = 0, p2 = 0, i = 0;
        
        while(p1 < word1.size() || p2 < word2.size()){
            if (i % 2 == 0 && p1 < word1.size()){
                merged += word1[p1];
                p1++;
            }
            else if (p2 < word2.size()){
                merged += word2[p2];
                p2++;
            }
            
            i++;
        }

        return merged;
    }
};