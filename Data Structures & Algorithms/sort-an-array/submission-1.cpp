class Solution {
   public:
    int partition(int left, int right, vector<int>& nums) {
        int i = left;
        int randPivot = left + (rand() % (right - left + 1));
        swap(nums[randPivot], nums[right]);
        int pivot = right;
        for (int j = left; j < right; j++) {
            if (nums[j] < nums[pivot]) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[pivot]);
        return i;
    }
    void quickSort(int left, int right, vector<int>& nums) {
        if (left < right) {
            int p = partition(left, right, nums);
            quickSort(left, p - 1, nums);
            quickSort(p + 1, right, nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        quickSort(left, right, nums);
        return nums;
    }
};