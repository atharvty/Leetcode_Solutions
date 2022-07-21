class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
   
        vector<int> ans(nums.size(), -1); 
        
        stack<int> s; //make a stack 
        
        for(int i = 0; i < 2*nums.size()-1; i++) { 
            
            while(!s.empty() && nums[s.top()] < nums[i%nums.size()]) {
                
                ans[s.top()] = nums[i%nums.size()];
                s.pop();//pop the elements which are smaller 
            }
            s.push(i%nums.size()); 
        }
        return ans;
    }
};