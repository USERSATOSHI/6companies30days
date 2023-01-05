// q10: https://leetcode.com/problems/shortest-unsorted-continuous-subarray

// sol: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/872134292/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int mini = INT_MAX, maxi = INT_MIN;
// find min and max elements of the array while checking the condition 
        for (int k = 1; k < n; k++)
        {
            if (nums[k] < nums[k - 1])
                mini = min(mini, nums[k]);
        }

        for (int k = 0; k < n - 1; k++)
        {
            if (nums[k] > nums[k + 1])
                maxi = max(maxi, nums[k]);
        }
// if not found return 0 as it is already sorted
        if (mini == INT_MAX && maxi == INT_MIN)
            return 0;
    //  find first element greater than mini
        while (i < n)
        {
            if (nums[i] > mini)
                break;
            i++;
        }
// find first element from end which  is smaller than maxi
        while (j >= 0)
        {
            if (nums[j] < maxi)
                break;
            j--;
        }

        return j - i + 1;
    }
};