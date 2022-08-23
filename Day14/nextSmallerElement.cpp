#include<stack>
#include<algorithm>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> st;
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }
        
        if(!st.empty())
        {
            ans[i] = st.top();
        }
        else
        {
            ans[i] = -1;
        }
        st.push(arr[i]);
    }
    return ans;
}
