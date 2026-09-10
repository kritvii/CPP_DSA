// LC 560 - Subarray Sum Equals K
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

// WHY handle prefixSum[j]==k separately?
// if prefixSum[j]==k → entire subarray from 0 to j has sum k
// this case handled by if(prefixSum[j]==k) count++
// no need for map[0]=1 initialization — more explicit this way

// WHY map[prefixSum[j]]++ AFTER checking?
// if updated before → same index used as both start and end
// always check first, then update map

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n     = nums.size();
        int count = 0;

        // prefix sum array
        // prefixSum[i] = sum of all elements from index 0 to i
        // eg: nums=[1,2,3] → prefixSum=[1,3,6]
        vector<int> prefixSum(n, 0);

        prefixSum[0] = nums[0];  // first element is itself
        for(int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];  // add current to previous sum
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
            // map[x]++ → creates with 0 if not exists, then increments
            //           → if exists → increments by 1
            map[prefixSum[j]]++;
        }

        return count;
    }
};

// DRY RUN 1: nums=[1,1,1], k=2
// prefixSum=[1,2,3], map={}
// j=0: 1==2? NO, val=-1 → not found → map={1:1}
// j=1: 2==2? YES → count=1, val=0 → not found → map={1:1,2:1}
// j=2: 3==2? NO, val=1 → found! count+=1=2 → map={1:1,2:1,3:1}
// return 2 ✓

// DRY RUN 2: nums=[1,2,3], k=3
// prefixSum=[1,3,6], map={}
// j=0: 1==3? NO, val=-2 → not found → map={1:1}
// j=1: 3==3? YES → count=1, val=0 → not found → map={1:1,3:1}
// j=2: 6==3? NO, val=3 → found! count+=1=2 → map={1:1,3:1,6:1}
// return 2 ✓

// TRAPS:
// ❌ not handling prefixSum[j]==k → misses subarrays from index 0
// ✅ if(prefixSum[j]==k) count++ handles this explicitly
// ❌ count not initialized → garbage value
// ✅ int count = 0
// ❌ updating map before checking → same index used twice
// ✅ check first, then map[prefixSum[j]]++