    void allCombination(int idx, vector<int> &temp, vector<vector<int>> &res, vector<int> &nums, int target){
        
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }
        
        if(idx == nums.size())
            return;
        
        if(target >= nums[idx]){
            temp.push_back(nums[idx]);
            allCombination(idx, temp, res, nums, target-nums[idx]);
            temp.pop_back();
        }
        
        allCombination(idx+1, temp, res, nums, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        allCombination(0, temp, res, candidates, target);
        return res;
    }
