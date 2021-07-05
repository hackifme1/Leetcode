// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 

Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:

Input: nums = [1,2,3,4]
Output: false

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109

*/


Cpp code :

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    // map<int, bool> ump;
    unordered_map<int, bool> ump;
    for (auto& num: nums) {
        if (ump[num] == true)
            return true;
        else
            ump[num] = true;
    }
        
    return false;
}
};
