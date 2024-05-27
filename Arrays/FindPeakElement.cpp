class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int low = 1 , high = n-2;
        while(low<=high){
            int mid = (low+high)/2;
            if( nums[mid]>nums[mid-1] && nums[mid] > nums[mid+1] ){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            
        }
        return -1;
    }
};
// Imagine a graph and your mid on an incline slope or a decline slop and we will adjust the high and low accordingly to get the peak.

// arr[left el] < arr[the el] > arr[right el]. This is a defination of a peak in array terms.

// You check if the mid is on an incline or decline
