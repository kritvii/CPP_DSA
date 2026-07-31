// LC 1910 - Remove All Occurrences of a Substring
// Pattern : String Manipulation
// Time    : O(n × m)  |  Space : O(1)

// WHY O(n × m)?
// each iteration → find() scans entire string O(n)
//                → erase() shifts characters O(n)
// worst case → part removed one character at a time → O(m) iterations
// total → O(n × m)

// Core idea:
// keep finding leftmost occurrence of part and erasing it
// until part no longer exists in s

// KEY FUNCTIONS:
// s.find(part)        → returns index of first occurrence of part
//                     → returns string::npos if not found
// s.erase(idx, len)   → removes len characters starting at idx
// string::npos        → special constant meaning "not found"
//                     → largest possible size_t value
//                     → always > s.length() → loop stops automatically

class Solution {
public:
    string removeOccurrences(string s, string part) {

        // loop condition:
        // s.length() > 0       → string is not empty
        // s.find(part)<s.length() → part exists in s
        // when part not found → find() returns npos (huge number)
        // npos > s.length() → condition false → loop stops
        while(s.length() > 0 && s.find(part) < s.length()) {

            // find leftmost occurrence and erase it
            // s.find(part)   → index of first occurrence
            // part.length()  → number of characters to remove
            s.erase(s.find(part), part.length());
        }

        return s;
    }
};

// DRY RUN: s="daabcbaabcbc", part="abc"
// find("abc")=2 → erase(2,3) → s="dabaabcbc"
// find("abc")=4 → erase(4,3) → s="dababc"  (wait let me recheck)
// find("abc")=3 → erase(3,3) → s="dab"
// find("abc")=npos → npos > 3 → loop stops
// return "dab" ✓

// DRY RUN: s="axxxxyyyyb", part="xy"
// find("xy")=4 → erase(4,2) → s="axxxyyyb"
// find("xy")=3 → erase(3,2) → s="axxyyb"
// find("xy")=2 → erase(2,2) → s="axyb"
// find("xy")=1 → erase(1,2) → s="ab"
// find("xy")=npos → loop stops
// return "ab" ✓

// TRAPS:
// ❌ while(s.length()>0) alone → infinite loop when part not found
// ✅ also check s.find(part)<s.length() → stops when part not found
// ❌ s.length missing () → compiler error
// ✅ s.length() with parentheses
// ❌ missing return s → function returns nothing
// ✅ return s after loop