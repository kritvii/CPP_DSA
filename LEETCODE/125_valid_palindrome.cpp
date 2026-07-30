// LC 125 - Valid Palindrome
// Pattern : Two Pointers / Strings
// Time    : O(n)  |  Space : O(1)

// WHY O(n)?
// single pass — each character visited at most once

// Core idea: two pointers from both ends
// skip non-alphanumeric characters
// compare characters case-insensitively
// if mismatch → not palindrome
// if pointers meet → palindrome ✓

class Solution {
public:
    bool isPalindrome(string s) {

        int st  = 0;
        int end = s.length() - 1;

        while(st <= end) {

            // skip non-alphanumeric from left
            // isalnum() → returns true if character is a letter or digit
            if(!isalnum(s[st])) {
                st++;
                continue;
            }

            // skip non-alphanumeric from right
            // NOT else if — if first if is true it skips via continue
            // so second if only runs when s[st] is alphanumeric
            if(!isalnum(s[end])) {
                end--;
                continue;
            }

            // both s[st] and s[end] are alphanumeric here
            // tolower() converts to lowercase before comparing
            // handles case insensitivity → 'A' == 'a'
            if(tolower(s[st]) != tolower(s[end])) {
                return false;  // mismatch → not a palindrome
            }

            // characters match → move both pointers inward
            st++;
            end--;
        }

        // pointers met → all characters matched → palindrome
        return true;
    }
};

// DRY RUN: "A man, a plan, a canal: Panama"
// st=0(A), end=29(a) → tolower match → st=1, end=28
// st=1(' ') → skip → st=2
// st=2(m), end=28(m) → match → st=3, end=27
// ... keeps matching until pointers meet
// return true ✓

// DRY RUN: "race a car"
// st=0(r), end=9(r) → match → st=1, end=8
// st=1(a), end=8(a) → match → st=2, end=7
// st=2(c), end=7(' ') → skip end → end=6
// st=2(c), end=6(c) → match → st=3, end=5
// st=3(e), end=5(a) → mismatch → return false ✓

// TRAPS:
// ❌ using else if for second if → misses case when st skips but end needs checking
// ✅ use separate if with continue → ensures both pointers are valid before comparing
// ❌ comparing without tolower → 'A' != 'a' → wrong answer
// ✅ always tolower() before comparing
// ❌ not skipping non-alphanumeric → spaces, commas affect result
// ✅ isalnum() filters letters and digits only