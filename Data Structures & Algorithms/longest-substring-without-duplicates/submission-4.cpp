class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashMap;
        int max_ccount = 0;

        int left = 0, right = 0, string_count = 0;
        while(left <= right && right < s.size()){
            char ch = s[right];
            
            if (hashMap.count(ch) == 0){
                hashMap.insert(ch);
                int count = right - left + 1;
                if (count > max_ccount) max_ccount = count;
                right++;
            }
            else{
                hashMap.erase(s[left]);
                left++;
            }
        }

        return max_ccount;
    }
};
