// q14: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible

// sol: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/submissions/872162323/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        // sorted nums array so that if we find the min element we can just output its index
        sort(nums.begin(), nums.end());
        if (nums[0] == 1)
            return 0;
        int g = numsDivide[0];
        int n1 = nums.size();
        int n2 = numsDivide.size();
        int mini = INT_MAX;
        // find gcd anf min element in numsDivide
        for (int i = 0; i < n2; i++)
        {
            g = __gcd(g, numsDivide[i]);
            mini = min(mini, numsDivide[i]);
        }
        cout << g << endl;
        // gcd is 1 then numsDivide is not divisible by any element
        if (g == 1)
            return -1;
            // remainder array
        vector<int> r(n1);
        for (int i = 0; i < n1; i++)
        {
            if (g > nums[i])
            {
                r[i] = g % nums[i];
            }
            else
            {
                r[i] = nums[i] % g;
            }
        }
        // first element with 0 remainder is ans if not found then -1;
        for (int i = 0; i < n1; i++)
        {
            if (!r[i])
            {
                if (mini < nums[i])
                    return -1;
                else
                    return i;
            }
        }
        return -1;
    }
};