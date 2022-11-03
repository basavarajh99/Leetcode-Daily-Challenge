/*
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined 
as one single character changed in the gene string.
For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. 
A gene must be in bank to make it a valid gene string.
Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to 
mutate from startGene to endGene. If there is no such a mutation, return -1.
Note that the starting point is assumed to be valid, so it might not be included in the bank.
*/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        //using a set to keep track of partially matched valid genes
        unordered_set<string> st(bank.begin(), bank.end());
        
        vector<char> geneChars = {'A', 'C', 'G', 'T'};
        
        int changes = 0; //number of changes done to reach end string
        
        //BFS traversal
        queue<string> q;
        
        q.push(start);
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                string s = q.front();
                q.pop();
                
                if(s == end) return changes;
                
                //Trying all the possible gene chars each place of current string in queue 
                for(int i = 0; i < 8; i++){
                    for(int j = 0; j < 4; j++){
                        if(geneChars[j] != s[i]){
                            char ch = s[i];
                            s[i] = geneChars[j];
                            
                            if(st.count(s)){
                                st.erase(s);
                                q.push(s);
                            }
                            s[i] = ch;
                        }      
                    }
                }
            }
            
            changes++;
        }
        
        return -1;
    }
};