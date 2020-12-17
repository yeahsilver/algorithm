#include <iostream>

using namespace std;

#define MAX 1000001

int minimum(int a, int b)
{
    return a > b ? b : a;
}

int main(void)
{
    cin.tie(NULL), cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    int dp[MAX];

    cin >> N;

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;

        if (dp[i] % 3 == 0)
        {
            dp[i] = minimum(dp[i], dp[i / 3] + 1);
        }

        if (dp[i] % 2 == 0)
        {
            dp[i] = minimum(dp[i], dp[i / 2] + 1);
        }
    }
    cout << dp[N] << '\n';
}
