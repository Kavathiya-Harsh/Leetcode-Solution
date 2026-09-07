// Last updated: 9/7/2026, 1:39:43 PM
class Solution {
public:
    vector<int> resultArray(vector<int>& n) {
        vector<int> a{n[0]}, b{n[1]};
        
        for(int i=2;i<n.size();i++)
            (a.back()>b.back()?a:b).push_back(n[i]);
        
        a.insert(a.end(),b.begin(),b.end());
        return a;
    }
};