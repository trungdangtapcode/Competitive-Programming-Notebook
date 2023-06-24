#include <bits/stdc++.h>
#define MIN(x, y) if (x > y) x = y;
#define MAX(x, y) if (x < y) x = y;
#define PB push_back
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 1007
 
using namespace std;
 
int n, m, k, a[maxn][maxn];
long long s[maxn][maxn];
 
long long f(int u, int v, int p, int q)
{
  return s[p][q] - s[u-1][q] - s[p][v-1] + s[u-1][v-1];
}
void full()
{
  for (int i = 1; i <= k; i++)
  {
    int x, y, u, v; 
    scanf("%d %d %d %d", &x, &y, &u, &v);
    long long result = 1e18;
    int l = x, h = u;
    if (h - l == 1) result = min(result, abs(f(x, y, l, v) - f(h, y, u, v)));
    while (h - l > 1)
    {
      int mid = (h + l)/2;
      long long s1 = f(x, y, mid, v);
      long long s2 = f(mid+1, y, u, v);
      result = min(result, abs(s1 - s2));
      if (s1 > s2) h = mid; else l = mid;
      if (h - l == 1) result = min(result, abs(f(x, y, l, v) - f(h, y, u, v)));
    }
    l = y, h = v;
    if (h - l == 1) result = min(result, abs(f(x, y, u, l) - f(x, h, u, v)));
    while (h - l > 1)
    {
      int mid = (h + l)/2;
      long long s1 = f(x, y, u, mid);
      long long s2 = f(x, mid+1, u, v);
      result = min(result, abs(s1 - s2));
      if (s1 > s2) h = mid; else l = mid;
      if (h - l == 1) result = min(result, abs(f(x, y, u, l) - f(x, h, u, v)));
    }
    cout << result << endl;
  }
 
}
int main()
{
  //freopen("INP.TXT", "r", stdin);
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
      scanf("%d", &a[i][j]);
      s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
    }
   full();
}
 
