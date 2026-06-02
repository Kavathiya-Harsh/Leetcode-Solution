// Last updated: 6/2/2026, 9:46:01 AM
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<int>st;

        for(int i = 0 ; i< n; i++){
          while(!st.empty()&& temperatures[i] > temperatures[st.top()]){
            int prevIndex = st.top();
            st.pop();
            ans[prevIndex] = i - prevIndex;

          }
          st.push(i);
        }
        return ans;
    }
};

//OR

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> ans(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {

            for (int j = i + 1; j < temperatures.size(); j++) {

                if (temperatures[j] > temperatures[i]) {

                    ans[i] = j - i;

                    break;
                }
            }
        }

        return ans;
    }
};
