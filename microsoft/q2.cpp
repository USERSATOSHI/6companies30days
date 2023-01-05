// Q2. https://leetcode.com/problems/combination-sum-iii/

// Sol: https://leetcode.com/problems/combination-sum-iii/submissions/872014158/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
void recur(int i, vector<vector<int>> &ans, vector<int> &ds, int target, int k)
{
    if (i >= nums.size())
    {
        if (ds.size() == k and target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if (nums[i] <= target)
    {
        ds.push_back(nums[i]);
        recur(i + 1, ans, ds, target - nums[i], k);
        ds.pop_back();
    }
    recur(i + 1, ans, ds, target, k);
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> distinctNumSequences;

    recur(0, ans, distinctNumSequences, n, k);
    return ans;
}

int main() {
    int n = 9, k = 3;
    vector<vector<int>> a = combinationSum3(k, n);

    for (auto b : a) {
        cout << "[ ";
        for(auto c : b) {
            cout << c << ", ";
        }
        cout << "]" << endl;
    }
        return 0;
}