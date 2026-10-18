class Solution {
public:
    int partition(vector<int> &nums, int left, int right){
        int i = left;
        int pivot = right;
        for(int j = left; j < right; j++){
            if(nums[j] < nums[pivot]){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[pivot]);
        return i;
    }

    void quickSort(vector<int> &nums, int left, int right){
        if(left < right){
            int p = partition(nums, left, right);
            quickSort(nums, left, p-1);
            quickSort(nums, p+1, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};