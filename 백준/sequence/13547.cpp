#include <iostream>
#include <algorithm>

#define PII pair<int, int>
#define PIII pair<PII, int>

using namespace std;

const int N = 100005, M = 100005, SQRT_N = 300;
PII query[N];
PIII order[N];

int cnt[M];
int a[N];
int n, q;
int an;
int ans[M];

