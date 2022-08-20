#include<stack>

class Queue {
    // Define the data members(if any) here.
    stack<int> s1;
    stack<int> s2;
    int N;
    public:
    Queue() {
        // Initialize your data structure here.
        N = 0;
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s1.push(val);
        N++;
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(N == 0) return -1;
        int temp;
        if (!s2.empty())
        {
            temp = s2.top();
            s2.pop();
        }


        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            
           temp = s2.top();
            s2.pop();
        }
        N--;
        return temp;
    }    

    int peek() {
        // Implement the peek() function here.
        if(N == 0) return -1;
       if (!s2.empty())
            return s2.top();

        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();  
    }

    bool isEmpty() {
        if(N == 0) return true;
        return false;
        // Implement the isEmpty() function here.
    }
};
