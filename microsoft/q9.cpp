// q9: https://leetcode.com/problems/number-of-pairs-satisfying-inequality/

// sol: https://leetcode.com/problems/number-of-pairs-satisfying-inequality/submissions/872117957/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    ll ans;

    void updateCount(vector<int> &nums, int start, int mid, int end, int d)
    {
        int l = start, r = mid + 1;
        while (l <= mid && r <= end)
        {
            if (nums[l] <= (nums[r] + d))
            {
                ans += (end - r + 1);
                l++;
            }
            else
            {
                r++;
            }
        }

        sort(nums.begin() + start, nums.begin() + end + 1);
        return;
    }
    void mergeSort(vector<int> &nums, int start, int end, int d)
    {
        if (start == end)
            return;

        int mid = (start + end) / 2;
        mergeSort(nums, start, mid, d);
        mergeSort(nums, mid + 1, end, d);

        updateCount(nums, start, mid, end, d);
        return;
    }
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
    {
        int n = nums1.size();
        vector<int> c(n);

        for (int i = 0; i < n; i++)
            c[i] = nums1[i] - nums2[i];
        ans = 0;
        mergeSort(c, 0, n - 1, diff);

        return ans;
    }
};