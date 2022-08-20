// Stack class.

class Stack {
    int *arr;
    int Top;
    int cap;
public:
    Stack(int capacity) {
        // Write your code here.
        cap = capacity;
        arr = new int[capacity];
        Top = -1;
    }
    //right
    void push(int num) {
        // Write your code here.
        if(Top == cap - 1) return;
        Top++;
        arr[Top] = num;
    }
    //right
    int pop() {
        // Write your code here.
        if(Top == -1) return -1;
        int temp = Top;
        Top--;
        return arr[temp]; 
    }
    //right
    int top() {
        // Write your code here.
        if(Top == -1) return -1;
        return arr[Top];
    }
    
    int isEmpty() {
        // Write your code here.
        if(Top == -1) return 1;
        return 0;
    }
    
    int isFull() {
        // Write your code here.'
        if(Top == cap - 1) return 1;
        return 0;
    }
    
};
