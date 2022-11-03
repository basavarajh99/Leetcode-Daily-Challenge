/*You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.

 */

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        //stores the count of palindromes formed
        vector<vector<int>> hash(26, vector<int>(26));
        int len = 0;
        
        for(string& w : words){
            int i = w[0]-'a'; //subscript value of the character between 0-25
            int j = w[1]-'a';
            
            if(hash[j][i]){
                len += 4; //pallindrome formed
                hash[j][i]--;
            }
            
           else hash[i][j]++;
        }
        
        //repeated values
        for(int i = 0; i < 26; i++)
            if(hash[i][i]) return len+2;
        
        return len;
    }
};
