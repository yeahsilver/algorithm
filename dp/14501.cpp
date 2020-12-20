#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 16

int N;
int P[MAX];
int T[MAX];
int dp[MAX];

void find_max_cost()
{
    for (int i = N; i > 0; i--)
    {
        if (i + T[i] > N + 1) // 일을 할 수 없게되면
        {
            dp[i] = dp[i + 1]; // 전날의 임금과 동일해야함.
        }
        else // 일을 할 수 있다면?
        {
            // 댜음날의 임금
            dp[i] = max(dp[i + 1], dp[i + T[i]] + P[i]); // 다음 날의 임금이 더 큰지를 비교
            //arr[i].second + dp[next_day]: 일을 하게되면 얻을 수 있는 이익.
            // dp[i+1]: 일을 하지 않을 때의 이익
        }
    }
    cout << dp[1] << '\n';
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

    find_max_cost();
}