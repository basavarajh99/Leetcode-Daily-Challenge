/*
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Input: s = "hello"
Output: "holle"

Input: s = "leetcode"
Output: "leotcede"

Input: s = "aA"
Output: "Aa"
*/

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length()-1;
        set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while(i < j){
            if((st.count(s[i]) > 0) && (st.count(s[j]) > 0)){
                swap(s[i], s[j]);
                i++, j--;
            }

            else if(st.count(s[i]) == 0)
                i++;
            else if(st.count(s[j]) == 0)
                j--;
        }

        return s;
    }
};
