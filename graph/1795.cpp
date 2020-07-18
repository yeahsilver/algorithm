#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
char arr[51][51] = { 0 };
pair<int, int> visit1[51][51];
pair<int, int> visit2[51][51];
int dn[8] = { -2,-2,2,2,-1,1,-1,1 };
int dm[8] = { -1,1,-1,1,-2,-2,2,2 };
int main() {
    int n, m, k = 0, temp = 1000000000;
    cin >> n >> m;
    
    // 입력을 모두 arr 배열에 저장하는 코드
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            arr[i][j + 1] = str[j];
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // arr배열에서 '.'이 아닌 숫자가 나올경우
            // BFS로 그 말이 움직일 수 있는 모든위치와 그 위치로 움직일때 걸리는 횟수 모두 계산함.
            // visit의 첫번째 인자는 각각의 말이 그 위치에 방문할때 ++ 해줌.
            // ex)말이 3개일 경우 visit의 첫번째 인자가 3이어야 모든 말이 놓일 수 있음.
            // visit의 두번째 인자는 각각의 말이 그 위치에 놓일때 최소 이동횟수를 더해줌.
            // ex)visit[2][2].second는 말들이 2,2 위치에 놓일때 말1이 2,2위치에 놓이기위해 3번움직여야하고 말 2가 2번 움직어야하면 값은 (3/1)+(2/2)임.(말의 이동횟수와 k말이 한번에 최대한 움직일수 있는 거리를 나눈 값)
            // 결국 visit의 첫번째인자가 체스판위의 모든 말의 개수와 같고 두번째 인자가 최소일때의 두번째 인자의 값이 출력임.
            // visit2는 각각의 말마다 계속 초기화된다.
            // visit1은 모든 말들이 공유하는것이고 visit2는 각각의 말마다 하나씩 주어진다고 보면 됨.
            // visit2의 첫번째 인자는 말이 방문한 곳을 체크하고 두번째 인자는 그 위치까지 움직인 횟수를 계산한다.
            if (arr[i][j] != '.') // '.'이 아닌 입력이 들어왔으므로 그 말으로 계산을 시작함.
            {
                k++; // k는 체스판위의 모든 말의 개수를 계산하기 위한 변수.
                int num = arr[i][j] - '0';
                queue<pair<int, int>> q;
                q.push(make_pair(i, j)); // 말이 갈수있는 모든 위치를 구하기 위해 BFS를 쓰기위해 queue 사용.
                visit1[i][j].first++; // 말이 i,j위치에 방문했으므로 visit[i][j]의 값을 ++ 해줌.(visit[i][j].first 는 각각의 말이 방문했을때 1씩 증가함.)
                visit2[i][j].first = 1; // 말이 i,j위치에 방문했으므로 visit2의 first를 1으로 체크하면서 들렀다는것을 표시.(안하면 BFS를 하면서 무한루프에 빠짐)
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int p = 0; p < 8; p++)
                    {
                        // 큐에 들어온 위치에서 움직일수 있는 위치가 범위 밖이면 넘어감.
                        if (x + dn[p] < 1 || x + dn[p] > n || y + dm[p] < 1 || y + dm[p] > m)
                            continue;
                        //
                        
                        // 말이 움직일 수 있는 곳이고 방문한 곳이 아니라면 방문함.
                        else if (visit2[x + dn[p]][y + dm[p]].first == 0)
                        {
                            q.push(make_pair(x + dn[p], y + dm[p]));
                            
                            // 말이 들렀다는것을 체크하기위해 visit2의 first를 1로바꾸어 표시함.
                            visit2[x + dn[p]][y + dm[p]].first = 1;
                            //
                            
                            // 말이 몇번 움직여서 방문했는지 계산하기위해 visit2의 움직인 위치에 다가 원래위치의 움직인 거리+1 을 넣음.
                            visit2[x + dn[p]][y + dm[p]].second = visit2[x][y].second + 1;
                            //
                            
                            // visit1 의 첫번째인자를 ++ 해주면서 그 위치에 말이 방문했다는것을 표시함.
                            visit1[x + dn[p]][y + dm[p]].first++;
                            //
                            
                            // visit1의 두번째인자를 계산하기위해 visit2의 두번째 인자와 몇번째 말인지 계산하여 visit1의 두번째인자를 갱신함.
                            if (visit2[x + dn[p]][y + dm[p]].second % num != 0)
                                
                                visit1[x + dn[p]][y + dm[p]].second += (visit2[x + dn[p]][y + dm[p]].second / num) + 1;
                            
                            else
                                visit1[x + dn[p]][y + dm[p]].second += (visit2[x + dn[p]][y + dm[p]].second / num);
                            //
                        }
                    }
                }
            }
            // 하나의 말의 계산이 끝날때마다 visit2의 모든 pair를 00으로 초기화 해줌.
            fill(&visit2[0][0], &visit2[0][0] + 51 * 51, make_pair(0, 0));
        }
    }
    
    // visit1을 모두 탐색하면서 모든 말이 방문할수있는 곳에서의 이동 횟수의 최솟값을 temp에 갱신함.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (visit1[i][j].first == k) // visit1의 첫번째 인자가 k와 같을때 두번째인자가 최소인 값을 temp에 갱신.
                temp = min(temp, visit1[i][j].second);
            else
                continue;
        }
    }
    if (temp != 1000000000) // 모든말이 한 곳에 모일 수 없을때
        cout << temp;
    else
        cout << -1;
}