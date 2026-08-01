// LC 151 - Reverse Words in a String
// Pattern : String Manipulation / Reverse
// Time    : O(n)  |  Space : O(n)

// WHY O(n)?
// reverse entire string → O(n)
// for loop visits each character once → O(n)
// total → O(n)

// Core idea: 3 steps
// step 1: reverse entire string
// step 2: extract each word, reverse it, add to answer
// step 3: remove leading space using substr(1)

// WHY THIS APPROACH?
// reversing entire string brings words in correct order but backwards
// reversing each word individually fixes them back to original
// handles extra spaces elegantly — empty word skipped by if(word.length()>0)


// METHOD 1: stringstream (direct approach)
        // stringstream handles multiple/leading/trailing spaces automatically
        // >> operator extracts one word at a time, skips all spaces
        // store words in vector → build result in reverse order

        // stringstream ss(s);
        // string word;
        // vector<string> words;
        // while(ss >> word) words.push_back(word);
        // string ans = "";
        // for(int i = words.size()-1; i >= 0; i--) {
        //     if(!ans.empty()) ans += " ";
        //     ans += words[i];
        // }
        // return ans;


// METHOD 2: reverse approach (optimal — no extra library)
        // step 1: reverse entire string → brings words in correct order but backwards
        // step 2: extract each word, reverse it back → fixes each word
        // step 3: substr(1) removes leading space added before every word
class Solution {
public:
    string reverseWords(string s) {

        int n      = s.length();
        string ans = "";  // empty — NOT " " (space)

        // step 1: reverse entire string
        // "the sky is blue" → "eulb si yks eht"
        reverse(s.begin(), s.end());

        for(int i = 0; i < n; i++) {
            string word = "";  // reset word for each iteration

            // collect characters until space or end of string
            // i++ inside while → moves forward character by character
            // WITHOUT i++ here → infinite loop (for loop's i++ never reached)
            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;   // must increment here — not relying on for loop's i++
            }

            // reverse the collected word back to original
            // "eulb" → "blue"
            reverse(word.begin(), word.end());

            // add to answer only if word is not empty
            // handles multiple/leading/trailing spaces — empty word skipped
            if(word.length() > 0) {
                ans += ' ' + word;  // += appends, = would overwrite
            }
        }

        // every word added with leading space → ans = " blue is sky the"
        // substr(1) removes first character → "blue is sky the" ✓
        return ans.substr(1);
    }
};

// DRY RUN: "the sky is blue"
// step 1: reverse → "eulb si yks eht"
// i=0: word="eulb" → reverse → "blue"  → ans=" blue"
// i=5: word="si"   → reverse → "is"    → ans=" blue is"
// i=8: word="yks"  → reverse → "sky"   → ans=" blue is sky"
// i=12: word="eht" → reverse → "the"   → ans=" blue is sky the"
// substr(1) → "blue is sky the" ✓

// DRY RUN: "  hello   world  "
// step 1: reverse → "  dlrow   olleh  "
// i=0: s[0]=' ' → while never runs → word="" → skipped
// i=1: s[1]=' ' → skipped
// i=2: word="dlrow" → reverse → "world" → ans=" world"
// i=8,9,10: spaces → skipped
// i=11: word="olleh" → reverse → "hello" → ans=" world hello"
// substr(1) → "world hello" ✓

// TRAPS:
// ❌ ans = " "  → starts with space → substr(1) gives wrong result
// ✅ ans = ""   → start empty
// ❌ no i++ in while → infinite loop → TLE
// ✅ i++ inside while → moves forward independently of for loop
// ❌ ans = ' '+word  → overwrites previous words
// ✅ ans += ' '+word → appends to existing answer
// ❌ no substr(1) → leading space in output
// ✅ substr(1) removes leading space added before every word