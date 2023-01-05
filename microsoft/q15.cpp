// q15: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

// sol: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/872167595/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int ans = 0, j = 0, n = s.length();
        map<char, int> m;
        for (int i = 0; i < n; i++)
        {
            m[s[i]]++;
            while (m['a'] && m['b'] && m['c'])
            {
                ans += n - i;
                m[s[j]]--;
                j++;
            }
        }

        return ans;
    }
};