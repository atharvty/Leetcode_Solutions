class Solution {
    
public:
    void recurPermute(int index , vector <int> &nums , vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums); //pushing the permutations
            return ;
            
        }
        
        for(int i = index ; i<nums.size();i++){
            swap(nums[index], nums[i]); //swapping the main guys 
            recurPermute(index+1 , nums, ans); // the main recursion call
            swap(nums[index], nums[i]); //back-tracking
            
        }
        
        
    }    
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector<int>> ans;
        recurPermute(0 , nums , ans);
        return ans;
        
    }
};