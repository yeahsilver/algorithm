#include <iostream>
#include <string.h>

using namespace std;

#define MAX 12

int dp[MAX] = {
    0,
};

int find_add_count(int N)
{

    if (N < 0)
        return 0;
    if (N <= 1)
        return 1;

    if (dp[N])
        return dp[N];

    return dp[N] = find_add_count(N - 3) + find_add_count(N - 2) + find_add_count(N - 1);
}

int main(void)
{
    cin.tie(NULL), cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        int N;
        cin >> N;

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        cout << find_add_count(N) << '\n';

        memset(dp, 0, sizeof(dp));
    }
}