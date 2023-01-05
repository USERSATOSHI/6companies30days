// q13:https://leetcode.com/problems/airplane-seat-assignment-probability

//  sol : https://leetcode.com/problems/airplane-seat-assignment-probability/submissions/872151899/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double nthPersonGetsNthSeat(int n)
    {
        if (n == 1)
            return 1.00000;
        return 0.50000;
    }
};