#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 16

int N;
int P[MAX];
int T[MAX];
int dp[MAX];

int find_max_cost()
{
    for (int i = N; i > 0; i--)
    {
        if (i + T[i] > N + 1)
        {
            dp[i] = dp[i + 1];
        }
        else
        {

            dp[i] = max(dp[i + 1], dp[i + T[i]] + P[i]);
        }
    }
    return dp[1];
}

int main(void)
{
    cin.tie(NULL), cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }

    cout << find_max_cost() << '\n';
}