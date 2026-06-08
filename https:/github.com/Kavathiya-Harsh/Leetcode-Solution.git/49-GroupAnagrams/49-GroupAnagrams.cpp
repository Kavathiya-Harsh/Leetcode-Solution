// Last updated: 6/8/2026, 9:14:07 PM
1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4
5        unordered_map<string, vector<string>> mp;
6
7        for(string str : strs) {
8
9            string key = str;
10
11            sort(key.begin(), key.end());
12
13            mp[key].push_back(str);
14        }
15
16        vector<vector<string>> result;
17
18        for(auto &it : mp) {
19            result.push_back(it.second);
20        }
21
22        return result;
23    }
24};