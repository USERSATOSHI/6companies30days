// q4: https://leetcode.com/problems/rotate-function/

// Sol:https://leetcode.com/problems/rotate-function/submissions/872036420/

#include <bits/stdc++.h>

using namespace std;

/*
    Idea:
     F(0) => 0a + 1b + 2c + 3d
     F(1) => 1a + 2b + 3c + 0d
     F(2) => 2a + 3b + 0c + 1d
     F(3) => 3a + 0b + 1c + 2d

     F(1) - F(0) => 1a + 1b + 1c -3d => (1a + 1b + 1c + 1d) - 4d
     F(2) - F(0) => 1a + 1b - 3c + 1d => (1a + 1b + 1c + 1d) - 4c

     F(1) = F(0) + (1a + 1b + 1c + 1d) - 4*d
     => F(k) = F(k-1) + sum -n*(first element after k rotations)
*/
int maxRotateFunction(vector<int> &nums)
{
    int fk = 0;
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        fk += i * nums[i];
        sum += nums[i];
    }
    int maxi = fk;
    for (int i = n - 1; i > 0; i--)
    {
        fk += sum - n * nums[i];
        maxi = max(maxi, fk);
    }
    return maxi;
}

int main() {
    return 0;
}