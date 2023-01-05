// q7: https://leetcode.com/problems/course-schedule/

// sol: https://leetcode.com/problems/course-schedule/submissions/872088602/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int i, vector<int> &v, vector<int> &v1, vector<int> adj[])
    {
        v[i] = 1;
        v1[i] = 1;
        for (auto it : adj[i])
        {
            if (!v[it])
            {
                if (dfs(it, v, v1, adj))
                {
                    return true;
                }
            }
            else if (v1[it])
            {
                return true;
            }
        }
        v1[i] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<int> adj[numCourses];
        vector<int> v(numCourses), v1(numCourses);
        for (auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (!v[i])
            {
                if (dfs(i, v, v1, adj))
                {
                    return false;
                }
            }
        }
        return true;
    }
};