class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            // 3,4,5,1,2
            if(nums[low] <= nums[high]){
                ans = min(ans, nums[low]);
                break;
            }
            if(nums[low]<=nums[mid]){
                ans = min(ans, nums[low]);
                low = mid+1;

            }
            else{
                high = mid-1;
                ans = min(ans , nums[mid]);

            }
        }
        return ans;
    }
};
// [3->low , 4 , 5->mid, 1 , 2->high]`

// Sorted left half we have arr[low]≤arr[mid] True

// When the left half is sorted go for it and pick up the minimum which is arr[low].

// `[7->low , 8 , 1 , 2->mid , 3 , 4 , 5 , 6->high]`

// arr[low]≤arr[mid] False in this case
// But when the left half is not sorted you have to get the other part of the array and move the high = mid-1 to focus on the left part of the array

// and store the arr[mid] as the minimum for now.

// This will eventually give you the minium number you are looking for.
