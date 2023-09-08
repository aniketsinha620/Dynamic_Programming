#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001
#define MOD 1000000007

// Your task is to count the number of ways to construct sum n
//  by throwing a dice one or more times. Each throw produces an outcome between 1
//  and 6
// .For example, if n=3
// , there are 4
//  ways:
// 1+1+1
// 1+2
// 2+1
// ans=3
int answer(int n, vector<int> &dp)
{

    if (dp[n] != 0)
        return dp[n];

    for (int i = 1; i <= 6; i++)
    {
        if (n - i >= 0)
            dp[n] += answer(n - i, dp);
        dp[n] %= MOD;
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    cout << answer(n, dp);
}