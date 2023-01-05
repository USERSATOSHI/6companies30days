// q12:https://leetcode.com/problems/longest-happy-prefix

//  sol: https://leetcode.com/problems/longest-happy-prefix/submissions/872148253/

/*
Here we apply KMP algo 
*/
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = s.length();
        vector<int> pos(n);
        int i = 0;
        int j = 1;
        while (j < n)
        {
            if (s[i] == s[j])
            {
                pos[j] = i + 1;
                i++;
                j++;
            }
            else if (i)
            {
                i = pos[i - 1];
            }
            else
            {
                j++;
            }
        }

        return s.substr(0, i);
    }
};