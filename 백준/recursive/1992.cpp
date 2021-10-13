#include <iostream>
#include <string>

using namespace std;

#define MAX 64

int graph[MAX][MAX];

void find_quadrant(int N, int x, int y)
{
    if (N == 1)
    {
        cout << graph[x][y];
        return;
    }

    bool zero = true;
    bool one = true;

    for (int i = x; i < x + N; i++)
    {
        for (int j = y; j < y + N; j++)
        {
            if (graph[i][j])
            {
                zero = false;
            }
            else
            {
                one = false;
            }
        }
    }

    if (one)
    {
        cout << '1';
    }
    else if (zero)
    {
        cout << '0';
    }
    else
    {
        cout << '(';
        find_quadrant(N / 2, x, y);

        find_quadrant(N / 2, x, y + (N / 2));
        find_quadrant(N / 2, x + (N / 2), y);
        find_quadrant(N / 2, x + (N / 2), y + (N / 2));
        cout << ')';
    }
}

int main(void)
{
    cin.tie(NULL), cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++)
        {
            graph[i][j] = s[j] - '0';
        }
    }

    find_quadrant(N, 0, 0);
}