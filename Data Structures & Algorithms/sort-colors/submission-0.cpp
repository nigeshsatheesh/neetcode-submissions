class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(3,0);
        vector<int> res(n);
        for(int i=0; i<n; i++){
            count[nums[i]]++;
        }
        for(int i=1; i<3; i++){
            count[i] = count[i] + count[i-1];
        }
        for(int i=n-1; i>=0; i--){
            res[--count[nums[i]]] = nums[i];
        }
        for(int i=0; i<n; i++){
            nums[i] = res[i];
        }
        return;
    }
};