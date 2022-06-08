#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> element;
    
    for(int num : arr)
    {
        element.insert(num);
    }
    
    int streak = 0;
    for(int num : arr)
    {
        if(!element.count(num - 1))
        {
            int temp = num;
            int curr_streak = 1;
            while(element.count(temp + 1))
            {
                temp++;
                curr_streak++;
            }
            streak = max(streak, curr_streak); 
        }
    }
    return streak;
}
