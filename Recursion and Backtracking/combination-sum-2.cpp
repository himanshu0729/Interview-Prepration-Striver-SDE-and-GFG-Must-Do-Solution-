    void allCombination(int idx, vector<int> &nums, int target, vector<vector<int>> &res, vector<int> &temp){
        
        if(target == 0){
            res.push_back(temp);
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            if(target >= nums[i] && (i == idx || nums[i] != nums[i-1])){
                temp.push_back(nums[i]);
                allCombination(i+1, nums, target-nums[i], res, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        allCombination(0, candidates, target, res, temp);
        return res;
    }
