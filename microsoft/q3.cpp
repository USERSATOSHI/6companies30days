// Q3. https://leetcode.com/problems/bulls-and-cows/

// Sol: https://leetcode.com/problems/bulls-and-cows/submissions/872021991/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

string getHint(string secret, string guess)
{
    int n = guess.length();
    map<char, int> a, b;
    int bulls = 0, crows = 0;
    for (int i = 0; i < n; i++)
    {
        if (secret[i] == guess[i])
        {
            bulls++;
        }
        else {
            a[secret[i]]++;
            b[guess[i]]++;
        }
    }

    for(auto bc : b) {
        if(a.count(bc.first) != 0) {
            crows += min(a[bc.first], bc.second);
        }
    }
    string ans = to_string(bulls) + 'A' + to_string(crows) + 'B';
    return ans;
}

int main()
{
    string s = "1807", g = "7810";
    string a = "1123", b = "0111";
    cout << getHint(s, g) << endl;
    cout << getHint(a, b) << endl;
    return 0;
}