bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;
    int sz = expression.size();
    for(int i = 0; i < sz; i++)
    {
        if(expression[i] == '[' || expression[i] == '{' || expression[i] == '(')
        {
            st.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
                st.pop();

            else
            {
                return false;
            }
        }

        else if (expression[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
                st.pop();

            else
            {
                return false;
            }
        }

        else if (expression[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
                st.pop();

            else
            {
                return false;
            }
        }
    }
    
    if (!st.empty())
        return false;
    return true;
}
