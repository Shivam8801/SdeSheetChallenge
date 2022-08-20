#define n 10000

class Queue {
    int *arr;
    int Front;
    int back;
public:
    Queue() {
        // Implement the Constructor
        arr = new int[n];
        Front = -1;
        back = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if (Front == -1 || Front > back)
        {
            return true;
        }

        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        
        if (back == n - 1)
        {
            return;
        }
        back++;
        arr[back] = data;

        if (Front == -1)
            Front++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if (Front == -1 || Front > back)
        {
            return -1;
        }
        
        return arr[Front++];
        
    }

    int front() {
        // Implement the front() function
        if (Front == -1 || Front > back)
        {
            return -1;
        }

        return arr[Front];
    }
};
