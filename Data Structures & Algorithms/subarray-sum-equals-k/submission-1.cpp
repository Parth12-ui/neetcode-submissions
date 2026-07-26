class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        queue<int> q1;

        int n_sum = 0;

        for(int num : nums){
            if (num == k) n_sum++;
            queue<int> tempq;
            tempq.push(num);
            while (!q1.empty()){
                int fq = q1.front() + num;
                q1.pop();
                if (fq == k) n_sum++;

                tempq.push(fq);
            }           
            q1 = tempq;
        }

        return n_sum;
    }
};