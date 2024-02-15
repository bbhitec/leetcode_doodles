/**
    @author [mst]
    @brief  leetcode series
    3_longest_non_repeating_substr
    Given a string s, find the length of the longest substring without repeating characters.

    gains:
    -


    @version 0.1 2023.04
*/



////////////////// LIBS



////////////////// DECL_IMPL


// sliding window approach: run across the string once while keeping a window/range from last occured char
// return the maximal window size once the string is traversed
//
// sub: 73 79
var lengthOfLongestSubstring = function(x) {
    let res = 0;
    let window = new Set();     // [demo] set is a collection of UNIQE values - perfect to hold chars in the sliding window
    let left = 0;               // sliding window left side

    // sliding window right side
    for (let right = 0; right < x.length; right++) {
        const char = x[right];

        // if the character was encountered, it is in the window
        // - we have to move the window and update charatcers in it
        while (window.has(char)) {  // 'has' runs at O(1)
            window.delete(x[left]);
            left++;
        }
        window.add(char);
        res = Math.max(res, right-left+1);
    }

    return res
}


// initial solutionwhere a substring is produced over last duplicate,
// this returns the longest substring, but fails on: "anviaj" (returns 4 stead 5)
var lengthOfLongestSubstring1 = function(str) {
    if (str.length == 1) return str.length;

    let longest = 0;
    let validSubstr = '';
    let prev;

    for (let i = 0; i < str.length; i++) {
        const char = str[i];
        if (validSubstr.includes(char)){
            // repeating char
            longest = (validSubstr.length > longest) ? validSubstr.length : longest;
            // consider step-back to previous char
            if (prev === char){
                validSubstr = char;
            }
            else {
                validSubstr = prev;
                i--;
            }
        }
        else {
            // legal char
            validSubstr += char;
            prev = char;
        }
    }
    // must have one last check!
    longest = (validSubstr.length > longest) ? validSubstr.length : longest;
    return longest;
};




////////////////// DRIVER
console.log("[mst] leetcode doodles")

// console.log(lengthOfLongestSubstring1("ABCDDDDEFGHIJK"))
console.log(lengthOfLongestSubstring("ABCDDDDEFGHIJK"))
console.log(lengthOfLongestSubstring("anviaj"))
