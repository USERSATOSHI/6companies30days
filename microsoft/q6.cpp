// q1 : https://leetcode.com/problems/perfect-rectangle/

// sol: https://leetcode.com/problems/perfect-rectangle/submissions/872084282/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        if (rectangles.size() == 1)
            return true;
        map<pair<int, int>, int> m;
        for (auto &r : rectangles)
        {
            m[{r[0], r[1]}]++;
            m[{r[2], r[3]}]++;
            m[{r[0], r[3]}]--;
            m[{r[2], r[1]}]--;
        }
        int count = 0;
        for (auto mp : m)
        {
            if (mp.second != 0)
            {
                if (mp.second != 1 && mp.second != -1)
                    return false;
                count++;
            }
        }
        return count == 4;
    }
};

