#include<iostream>
#include<string>
#include<cctype>   // for isalnum(), tolower()
using namespace std;

// VALID PALINDROME
// skip special characters and spaces, ignore case sensitivity
// two pointers from both ends — compare inward

// isalnum() → returns true if character is letter or digit
// tolower() → converts character to lowercase

bool isPalindrome(string s) {

    int st  = 0;
    int end = s.length() - 1;

    while(st <= end) {

        // skip non-alphanumeric from left
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

        // both alphanumeric — compare case insensitively
        // tolower() handles 'A' == 'a'
        if(tolower(s[st]) != tolower(s[end])) {
            return false;  // mismatch → not a palindrome
        }

        // match → move both pointers inward
        st++;
        end--;
    }

    // pointers met → all characters matched → palindrome
    return true;
}

int main(){

    // test case 1 — expected: true (1)
    cout << isPalindrome("A man, a plan, a canal: Panama") << endl;

    // test case 2 — expected: false (0)
    cout << isPalindrome("race a car") << endl;

    // test case 3 — empty string — expected: true (1)
    cout << isPalindrome("  ") << endl;

    // test case 4 — single character — expected: true (1)
    cout << isPalindrome("a") << endl;

    // test case 5 — expected: true (1)
    cout << isPalindrome("racecar") << endl;

    return 0;
}

// DRY RUN: "A man, a plan, a canal: Panama"
// st=0(A), end=29(a) → match → st=1, end=28
// st=1(' ') → not alnum → skip → st=2
// st=2(m), end=28(m) → match → st=3, end=27
// ... keeps matching until pointers meet → return true ✓

// DRY RUN: "race a car"
// st=0(r), end=9(r) → match → st=1, end=8
// st=1(a), end=8(a) → match → st=2, end=7
// st=2(c), end=7(' ') → skip end → end=6
// st=2(c), end=6(c) → match → st=3, end=5
// st=3(e), end=5(a) → mismatch → return false ✓

// COMPLEXITY:
// Time  → O(n) — single pass, each character visited at most once
// Space → O(1) — no extra memory

// TRAPS:
// ❌ else if for second if → misses case when st skips but end needs checking
// ✅ separate if with continue → ensures both pointers valid before comparing
// ❌ comparing without tolower → 'A' != 'a' → wrong answer
// ✅ always tolower() before comparing
// ❌ not skipping non-alphanumeric → spaces, commas affect result
// ✅ isalnum() filters letters and digits only