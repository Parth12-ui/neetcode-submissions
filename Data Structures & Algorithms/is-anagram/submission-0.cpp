class Solution {
public:
    bool isAnagram(string s, string t) {
        // if size is different, one of the string contain an additional character.
        if (s.size() != t.size()) return 0;

        //hashmap to track elements in each string in O[1] time and space complexity.
        unordered_map<char, int> hash1;
        unordered_map<char, int> hash2;

        
        for(char h : s){
            if (hash1.count(h) == 0){
                hash1[h] = 1;
            }
            else hash1[h]++;
        }

        for(char h : t){
            if (hash2.count(h) == 0){
                hash2[h] = 1;
            }
            else hash2[h]++;
        }

        for(auto& pair : hash1){
            if (hash1[pair.first] != hash2[pair.first]) return 0;
        }

        return 1;
    }
};
