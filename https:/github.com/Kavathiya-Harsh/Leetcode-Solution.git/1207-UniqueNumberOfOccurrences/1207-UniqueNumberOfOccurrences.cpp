// Last updated: 9/7/2026, 1:42:55 PM
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> freq;

        for (int value : arr) {
            freq[value]++;
        }

        // unique element
        unordered_set<int> count;
        for (auto& it : freq) {
            count.insert(it.second);
        }
        return freq.size() == count.size();
    }
};