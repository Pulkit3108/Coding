// Problem Statement
// Given an unsorted array `nums`, reorder it in-place such that:
// nums[0] <= nums[1] >= nums[2] <= nums[3]...

// Constraints:
// - There may be multiple valid answers; you only need to consider one of the possibilities.
// - Sort the array in place without defining additional arrays.

// Examples:

// Example 1:
// Input: [3, 5, 2, 1, 6, 4]
// Output: [1, 6, 2, 5, 3, 4]
// Explanation: This question may have multiple answers, and [2, 6, 1, 5, 3, 4] is also valid.

// Example 2:
// Input: [1, 2, 3, 4]
// Output: [1, 4, 2, 3]

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) || 
                (i % 2 == 0 && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};
