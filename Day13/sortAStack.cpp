void place_correct_position(stack<int> &st, int x)
{
    if(st.size() == 0 || st.top() < x)
        st.push(x);
    
   else
   {
       int a = st.top();
       st.pop();
       place_correct_position(st, x); // same element x has to be placed
       st.push(a);    
   }    
}

void reverse(stack<int> &st)
{
    if(st.size() > 0)
    {
        int a = st.top();
        st.pop();
        reverse(st);
        place_correct_position(st, a);
    }
}

void sortStack(stack<int> &stack)
{
	// Write your code here
    reverse(stack);
}
