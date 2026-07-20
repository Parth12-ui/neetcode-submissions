class Solution {
public:
    

    void merge(vector<int>& arr, int high, int low, int mid){
        vector<int> temp;
        int left = low, right = mid+1;
        
        while(left <= mid && right <= high){
            if (arr[left] <= arr[right]) temp.push_back(arr[left++]);
            else temp.push_back(arr[right++]);
        }

        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        for(int i = 0; i<temp.size(); i++) arr[i+low] = temp[i];
    }

    void mergeSort(vector<int>& arr, int high, int low){
        if (low >= high) return;

        int mid = (low + high) / 2;

        mergeSort(arr, mid, low);
        mergeSort(arr, high, mid+1);

        merge(arr, high, low, mid);
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> sorted_arr = nums;
        mergeSort(sorted_arr, nums.size()-1, 0);
        return sorted_arr;
    }
};