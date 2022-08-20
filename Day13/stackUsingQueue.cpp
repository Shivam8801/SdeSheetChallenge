#include <queue>

class Stack {
	// Define the data members.
    queue<int> q1;
    queue<int> q2;
    int N;
   public:
    Stack() {
        // Implement the Constructor.
        N = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return N;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(N == 0) return true;
        return false;
    }

    void push(int element) {
        // Implement the push() function.
        q2.push(element);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop() {
        // Implement the pop() function.
        if(N == 0) return -1;
        N--;
        int res = q1.front();
        q1.pop();
        return res;
    }

    int top() {
        // Implement the top() function.
        if(N == 0) return -1;
        return q1.front();
    }
};
