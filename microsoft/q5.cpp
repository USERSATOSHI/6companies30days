// q5: https://leetcode.com/problems/largest-divisible-subset/

// Sol:https://leetcode.com/problems/largest-divisible-subset/submissions/872070724/
#include <bits/stdc++.h>

using namespace std;
vector<int> largestDivisibleSubset(vector<int> &nums)
{

    int n = nums.size();
    if (n == 0 || n == 1)
        return nums;
    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);
    int maxi = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] % nums[j] == 0)
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        if (dp[i] > maxi)
            maxi = dp[i];
    }

    vector<int> v;

    for (int i = n - 1; i >= 0; i--)
    {
        if (dp[i] == maxi)
        {
            if (v.size())
            {
                if (!(v[v.size() - 1] % nums[i]))
                {
                    v.push_back(nums[i]);
                    maxi--;
                }
            }
            else
            {
                v.push_back(nums[i]);
                maxi--;
            }
        }
    }

    return v;
}
int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> ans = largestDivisibleSubset(nums);
    for(auto i : ans) {
        cout << i << ", ";
     }
     cout << endl;
     return 0;
}