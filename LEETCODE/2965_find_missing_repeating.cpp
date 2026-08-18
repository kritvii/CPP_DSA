// LC 2965 - Find Missing and Repeated Values
// Pattern : Frequency Array
// Time    : O(n²)  |  Space : O(n²)

// WHY O(n²)?
// traverse entire n×n grid once → O(n²)
// scan freq array of size n² once → O(n²)
// total → O(n²)

// Core idea:
// values in grid should be 1 to n² — each appearing exactly once
// one value appears twice (repeated) → freq[i]==2
// one value is missing             → freq[i]==0
// use value as index into freq array → direct O(1) access

// WHY FREQ ARRAY OVER HASHMAP?
// values in known range [1,n²] → direct index access → O(1)
// no hashing overhead → simpler and faster

// WHY SIZE n²+1?
// values range from 1 to n² → need index n² to be valid
// vector of size k → valid indices = 0 to k-1
// need index n² → size must be n²+1
// index 0 is wasted (values start from 1) → that's fine
// RULE: size = max index needed + 1

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();
        /*
        Create frequency array.

        Index = number
        Value = frequency/count of that number

        For n = 3:
        n² = 9
        We need indices 0 to 9, so size = n² + 1.

        The 0 initializes every element to 0.

        index:  0  1  2  3  4  5  6  7  8  9
        value:  0  0  0  0  0  0  0  0  0  0
        */
        vector<int> freq(n*n + 1, 0);

        // traverse grid — count frequency of each value
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // use grid value as index → increment its count
                // grid[i][j]=2 → freq[2]++ → freq[2]=2 means seen twice
                freq[grid[i][j]]++;
            }
        }

        int repeated = -1;  // placeholder — not found yet
        int missing  = -1;  // placeholder — not found yet

        // scan freq array to find repeated and missing
        // Check every possible number from 1 to n²
        for(int i = 1; i <= n*n; i++) {
            if(freq[i] == 2) repeated = i;  // seen twice → repeated
            if(freq[i] == 0) missing  = i;  // never seen → missing
        }

        return {repeated, missing};
    }
};

// DRY RUN 1: grid=[[1,3],[2,2]], n=2, n²=4
// traverse:
// grid[0][0]=1 → freq[1]=1
// grid[0][1]=3 → freq[3]=1
// grid[1][0]=2 → freq[2]=1
// grid[1][1]=2 → freq[2]=2
// freq = [0, 1, 2, 1, 0]
//         0  1  2  3  4
// i=2: freq[2]=2 → repeated=2
// i=4: freq[4]=0 → missing=4
// return [2, 4] ✓

// DRY RUN 2: grid=[[9,1,7],[8,9,2],[3,4,6]], n=3, n²=9
// freq[9]=2 → repeated=9
// freq[5]=0 → missing=5
// return [9, 5] ✓

// TRAPS:
// ❌ size = n²   → index n² out of bounds
// ✅ size = n²+1 → index n² valid
// ❌ init repeated/missing without -1 → garbage values if not found
// ✅ init to -1  → safe default, values always in range [1,n²]