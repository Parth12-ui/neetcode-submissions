class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int count = 0, left = 0, right = people.size()-1;
        while(left <= right){
            if (left == right){
                count++;
                break;
            }

            int cur_weight = people[left] + people[right];
            if (cur_weight > limit){
                count++;
                right--;
            }
            else{
                count++;
                left++;
                right--;
            }
        }

        return count;       
    }
};