class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
            int i = 0;
        string prefix = "";
        bool flag = true;
        if(strs[0].size() == 0){
            return prefix;
        }
        if(strs.size() == 1){
            return strs[0];
        }
        while (true) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[0][i] != strs[j][i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
            prefix += strs[0][i];
            i++;
            if (i >= strs[0].size()) {
                break;
            }
        }
        return prefix;
    }
};