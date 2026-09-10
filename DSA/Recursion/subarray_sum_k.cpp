#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// SUBARRAY SUM EQUALS K
// Pattern : Prefix Sum + HashMap
// Time    : O(n)  |  Space : O(n)

// WHY O(n)?
// single pass — map lookup is O(1)
// so n elements × O(1) = O(n) total

// Core idea:
// prefixSum[i] - prefixSum[j] = k
// → prefixSum[j] = prefixSum[i] - k
// for every j → check how many times (prefixSum[j]-k) appeared before
// that count = subarrays ending at j with sum k

// WHY map[prefixSum[j]]++ AFTER checking?
// if updated before → same index used as both start and end
// always check first, then update map

int subarraySum(vector<int>& nums, int k) {

    int n     = nums.size();
    int count = 0;

    // prefix sum array
    // prefixSum[i] = sum of all elements from index 0 to i
    // eg: nums=[1,2,3] → prefixSum=[1,3,6]
    vector<int> prefixSum(n, 0);

    prefixSum[0] = nums[0];  // first element is itself
    for(int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i];  // add current to previous
    }

    // map stores {prefixSum → frequency}
    // frequency = how many times this prefix sum appeared before
    unordered_map<int, int> map;

    for(int j = 0; j < n; j++) {

        // if current prefix sum == k
        // entire subarray from index 0 to j has sum k → count it
        if(prefixSum[j] == k) count++;

        // need earlier prefix sum such that:
        // prefixSum[j] - previousPrefixSum = k
        // → previousPrefixSum = prefixSum[j] - k
        int val = prefixSum[j] - k;

        // if this prefix sum appeared before →
        // each occurrence gives one valid subarray ending at j
        if(map.find(val) != map.end()) {
            count += map[val];  // add frequency of val
        }

        // store current prefix sum AFTER checking
        // map[x]++ → creates with 0 if not exists, then increments to 1
        //           → if exists → increments by 1
        map[prefixSum[j]]++;
    }

    return count;
}

int main() {

    // test case 1 — expected: 2
    // subarrays: [1,1] at 0-1 and [1,1] at 1-2
    vector<int> nums1 = {1, 1, 1};
    cout << "Test 1: " << subarraySum(nums1, 2) << endl;

    // test case 2 — expected: 2
    // subarrays: [3] and [1,2]
    vector<int> nums2 = {1, 2, 3};
    cout << "Test 2: " << subarraySum(nums2, 3) << endl;

    // test case 3 — expected: 3
    // subarrays: [1], [1], [1]
    vector<int> nums3 = {1, 1, 1};
    cout << "Test 3: " << subarraySum(nums3, 1) << endl;

    // test case 4 — negative numbers — expected: 3
    vector<int> nums4 = {1, -1, 1, -1, 1};
    cout << "Test 4: " << subarraySum(nums4, 0) << endl;

    return 0;
}

// DRY RUN: nums=[1,1,1], k=2
// prefixSum=[1,2,3], map={}
// j=0: 1==2? NO, val=-1 → not found → map={1:1}
// j=1: 2==2? YES → count=1, val=0 → not found → map={1:1,2:1}
// j=2: 3==2? NO, val=1 → found! count+=map[1]=1 → count=2 → map={1:1,2:1,3:1}
// return 2 ✓

// DRY RUN: nums=[1,-1,1], k=1
// prefixSum=[1,0,1], map={}
// j=0: 1==1? YES → count=1, val=1-1=0 → not found → map={1:1}
// j=1: 0==1? NO → val=0-1=-1 → not found → map={1:1,0:1}
// j=2: 1==1? YES → count=2, val=1-1=0 → found! ,count+=map[0]=1 → count=3 → map={1:2,0:1}
// return 3 ✓

// TRAPS:
// ❌ not handling prefixSum[j]==k → misses subarrays from index 0
// ✅ if(prefixSum[j]==k) count++ handles this explicitly
// ❌ count not initialized → garbage value
// ✅ int count = 0
// ❌ updating map before checking → same index used twice
// ✅ check first, then map[prefixSum[j]]++