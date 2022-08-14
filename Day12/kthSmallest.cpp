class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i = 0; i < k; i++)
        {
            minHeap.push(nums[i]);
        }
        
        for(int i = k; i < nums.size(); i++)
        {
            int element = nums[i];
            if(element > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(element);
            }
        }
        
        int ans = minHeap.top();
        return ans;
    }
};
