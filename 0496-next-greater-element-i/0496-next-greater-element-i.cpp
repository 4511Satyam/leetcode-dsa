
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {
        unordered_map<int, int> nge;
        stack<int> st;

        for (int x : nums2) {
            while (!st.empty() && st.top() < x) {
                nge[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        vector<int> ans;

        for (int x : nums1)
            ans.push_back(nge.count(x) ? nge[x] : -1);

        return ans;
    }
};
