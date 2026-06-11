// Last updated: 6/11/2026, 8:12:13 AM
class Solution {
public:
    string removeDuplicates(string s) {
        
        // Line 1: Create an empty string that will act like a stack
        string result = "";   
        
        // Line 2: Loop through every character in the input string 's'
        for(char c : s) {     
            
            // Line 3: Check two conditions:
            //   1. Is result empty? (if yes, we cannot compare)
            //   2. Is the last character of result same as current character 'c'?
            if(!result.empty() && result.back() == c) {
                
                // Line 4: If both above are true → remove the last character
                // This removes the adjacent duplicate pair
                result.pop_back();   
            }
            else {
                // Line 5: Otherwise, just add the current character to result
                result.push_back(c); 
            }
        }
        
        // Line 6: After processing all characters, return the final result
        return result;
    }
};