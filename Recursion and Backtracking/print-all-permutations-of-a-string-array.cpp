    void allPermutation(int idx, vector<int> &nums, vector<vector<int>> &res){
        
        if(idx == nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            allPermutation(idx+1, nums, res);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        allPermutation(0, nums, res);
        return res;
    }
