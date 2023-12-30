// Description
// Given an unsorted array nums, reorder it in-place such that

// nums[0] <= nums[1] >= nums[2] <= nums[3]....
// There may have multiple answers for a question, you only need to consider one of the possibilities.

// Input: [3, 5, 2, 1, 6, 4]
// Output: [1, 6, 2, 5, 3, 4]
// Explanation: This question may have multiple answers, and [2, 6, 1, 5, 3, 4] is also ok.

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int n=nums.size();
        for(int i=1;i<n;++i){
            if((i&1) && nums[i] < nums[i-1])
                swap(nums[i-1],nums[i]);
            if(!(i&1) && nums[i] > nums[i-1])
                swap(nums[i-1],nums[i]);
        }
    }
};
