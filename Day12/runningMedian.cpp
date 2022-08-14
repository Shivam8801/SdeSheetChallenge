#include<queue>

int signum(int a, int b)
{
    if(a == b) return 0;
    else if(a > b) return 1;
    else return -1;
}

void callMed(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int &median)    // O(log k)
{
    switch(signum(maxi.size(), mini.size()) )
    {
        case 0 :
            if(element > median)
            {
                mini.push(element);
                median = mini.top();
            }
            else
            {
                maxi.push(element);
                median = maxi.top();
            }
            break;
        case 1:
            if(element > median)
            {
                mini.push(element);
                median = (maxi.top() + mini.top())/2;
            }
            
            else
            {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
                median = (maxi.top() + mini.top())/2;
            }
            break;
        case -1:
            if(element > median)
            {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
                median = (maxi.top() + mini.top())/2;
            }
            else
            {
                maxi.push(element);
                median = (maxi.top() + mini.top())/2;
            }
            break;
    }
}

void findMedian(int *arr, int n)
{
    // Write your code here 
    vector<int> ans;     
    // make a min heap and max heap
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;    // O(k)
    int median = -1;
    
    for(int i = 0; i < n; i++)  // O(n log k)
    {
        int element = arr[i];
        callMed(element, maxHeap, minHeap, median);
        ans.push_back(median);
    }
    for(int i : ans)
    {
        cout << i << " ";
    }
}
