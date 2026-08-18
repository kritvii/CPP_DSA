// LC 1 - Two Sum
// Pattern : HashMap
// Time    : O(n)  |  Space : O(n)

// WHY O(n)?
// single pass through array — map lookup is O(1)
// so n elements × O(1) lookup = O(n) total

// WHY O(n) space?
// map stores at most n elements

// Core idea:
// for every element → check if its complement exists in map
// complement = target - nums[i]
// if found → return both indices
// if not found → store current element in map for future lookups

// WHY HASHMAP?
// brute force → check every pair → O(n²)
// hashmap → store and lookup in O(1) → O(n) ✓

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // map stores {value → index} as key-value pairs
        // key   = nums[i] → the value in the array
        // value = i       → the index in the array
        //
        // example: nums=[2,7,11,15]
        // after i=0: map = {2:0}           → value 2 is at index 0
        // after i=1: map = {2:0, 7:1}      → value 7 is at index 1
        // after i=2: map = {2:0, 7:1, 11:2}
        //
        // map[nums[i]] = i  → stores element as key, index as value
        // map[complement]   → retrieves index of complement
        //
        // unordered_map → uses hashing internally → O(1) lookup
        // ordered map   → uses BST internally     → O(log n) lookup
        // we use unordered_map for faster O(1) access
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++) {

            int first      = nums[i];
            int complement = target - nums[i];  // what we need to find

            // map.find(complement) → searches for complement in map
            // map.end()           → "not found" signal (past last element)
            // != map.end()        → complement EXISTS in map → found!
            if(map.find(complement) != map.end()) {
                return {map[complement], i};  // return both indices
            }

            // complement not found → store current element for future lookups
            map[nums[i]] = i;
        }

        return {};  // no solution (won't reach here per constraints)
    }
};

// DRY RUN 1: nums=[2,7,11,15], target=9
// i=0: first=2, complement=7 → map={} → not found → map={2:0}
// i=1: first=7, complement=2 → map={2:0} → found! → return {0,1} ✓

// DRY RUN 2: nums=[3,2,4], target=6
// i=0: first=3, complement=3 → map={} → not found → map={3:0}
// i=1: first=2, complement=4 → map={3:0} → not found → map={3:0,2:1}
// i=2: first=4, complement=2 → map={3:0,2:1} → found! → return {1,2} ✓

// DRY RUN 3: nums=[3,3], target=6
// i=0: first=3, complement=3 → map={} → not found → map={3:0}
// i=1: first=3, complement=3 → map={3:0} → found! → return {0,1} ✓

// TRAPS:
// ❌ using sorted array + two pointers → loses original indices
// ✅ hashmap preserves original indices
// ❌ checking map AFTER storing → same element used twice for [3,3] case
// ✅ check map BEFORE storing → guarantees different indices