#include <iostream>
#include <vector>
using namespace std;

// FIND MISSING AND REPEATING VALUES
// given n×n grid with values 1 to n²
// one number appears twice (repeated)
// one number is missing
// find both using frequency array

// APPROACH: FREQUENCY ARRAY
// freq[i] = how many times i appears in grid
// freq[i]==2 → repeated
// freq[i]==0 → missing
// size = n²+1 → because values go from 1 to n²
//              → need index n² to be valid
//              → index 0 ignored

pair<int,int> findMissingRepeating(vector<vector<int>>& grid) {

    int n = grid.size();

    // freq array of size n²+1
    // index = number, value = frequency

    // freq array of size n²+1
    // WHY n²+1?
    // values in grid range from 1 to n²
    // we use value as index → need index n² to be valid
    // vector of size k → valid indices = 0 to k-1
    // need index n² → size must be n²+1
    // eg: n=2, n²=4 → size=5 → indices 0,1,2,3,4 → index 4 valid ✓
    //     size=4 → indices 0,1,2,3 → index 4 missing ❌
    // index 0 is wasted (values start from 1) — that's fine
    // RULE: size = max index needed + 1
    vector<int> freq(n*n + 1, 0);

    // traverse entire grid
    // count frequency of each number
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            freq[grid[i][j]]++;  // increment count at index grid[i][j]
        }
    }
    // WHY freq[grid[i][j]]++?
    // grid[i][j] is the value at current cell
    // we use that value AS THE INDEX into freq array
    // ++ increments the count at that index
    // eg: grid[i][j]=2 → freq[2]++ → freq[2] becomes 1 first time, 2 second time
    // so freq[2]=2 means value 2 appeared twice → repeated!
    // freq[4]=0 means value 4 never appeared → missing!

    int repeated = -1;
    int missing  = -1;

    // check freq array for repeated and missing
    for(int i = 1; i <= n*n; i++) {
        if(freq[i] == 2) repeated = i;  // appeared twice → repeated
        if(freq[i] == 0) missing  = i;  // never appeared → missing
    }

    return {repeated, missing};
}

int main() {

    // test case 1 — expected: repeated=2, missing=4
    vector<vector<int>> grid1 = {
        {1, 3},
        {2, 2}
    };
    pair<int,int> result1 = findMissingRepeating(grid1);
    cout << "Test 1: repeated=" << result1.first << ", missing=" << result1.second << endl;

    // test case 2 — expected: repeated=9, missing=5
    vector<vector<int>> grid2 = {
        {9, 1, 7},
        {8, 9, 2},
        {3, 4, 6}
    };
    pair<int,int> result2 = findMissingRepeating(grid2);
    cout << "Test 2: repeated=" << result2.first << ", missing=" << result2.second << endl;

    // test case 3 — expected: repeated=1, missing=4
    vector<vector<int>> grid3 = {
        {1, 1},
        {3, 2}
    };
    pair<int,int> result3 = findMissingRepeating(grid3);
    cout << "Test 3: repeated=" << result3.first << ", missing=" << result3.second << endl;

    return 0;
}

// DRY RUN: grid=[[1,3],[2,2]], n=2, n²=4
// traverse grid:
// grid[0][0]=1 → freq[1]=1
// grid[0][1]=3 → freq[3]=1
// grid[1][0]=2 → freq[2]=1
// grid[1][1]=2 → freq[2]=2
// freq = [0, 1, 2, 1, 0]
//         0  1  2  3  4
// i=1: freq[1]=1 → skip
// i=2: freq[2]=2 → repeated=2
// i=3: freq[3]=1 → skip
// i=4: freq[4]=0 → missing=4
// return {2, 4} ✓

// COMPLEXITY:
// Time  → O(n²) — traverse grid once + freq array once
// Space → O(n²) — freq array of size n²+1

// WHY FREQ ARRAY OVER HASHMAP?
// values in known range [1,n²] → direct index access → O(1)
// no hashing overhead → simpler and faster