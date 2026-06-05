// Last updated: 6/5/2026, 2:41:13 PM
1class Solution {
2public:
3    string removeDuplicates(string s) {
4        
5        // Line 1: Create an empty string that will act like a stack
6        string result = "";   
7        
8        // Line 2: Loop through every character in the input string 's'
9        for(char c : s) {     
10            
11            // Line 3: Check two conditions:
12            //   1. Is result empty? (if yes, we cannot compare)
13            //   2. Is the last character of result same as current character 'c'?
14            if(!result.empty() && result.back() == c) {
15                
16                // Line 4: If both above are true → remove the last character
17                // This removes the adjacent duplicate pair
18                result.pop_back();   
19            }
20            else {
21                // Line 5: Otherwise, just add the current character to result
22                result.push_back(c); 
23            }
24        }
25        
26        // Line 6: After processing all characters, return the final result
27        return result;
28    }
29};