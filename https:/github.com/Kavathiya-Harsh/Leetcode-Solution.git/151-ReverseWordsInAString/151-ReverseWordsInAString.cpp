// Last updated: 11/04/2026, 14:23:47
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> store;
        string word = "";

        // Step 1: Extract words
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else {
                if (word != "") {
                    store.push_back(word);
                    word = "";
                }
            }
        }

        // last word
        if (word != "") {
            store.push_back(word);
        }

        // Step 2: reverse and join
        string result = "";
        for (int i = store.size() - 1; i >= 0; i--) {
            result += store[i];
            if (i != 0) result += " ";
        }

        return result;
    }
};