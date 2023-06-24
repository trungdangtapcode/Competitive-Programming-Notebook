#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e4 + 5;

int n, m, a[MAXN], prv[MAXN], nxt[MAXN];
int dp[MAXN], pos;

void infix(){
	for (int i = 1; i <= n; i++) cout << i << " "; cout << endl;
    for (int i = 1; i <= n; i++) cout << nxt[i] << " "; cout << endl;
    for (int i = 1; i <= n; i++) cout << prv[i] << " "; cout << endl;
    for (int i = 1; i <= n; i++) cout << dp[i] << " "; cout << endl;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prv[i] = i - 1; nxt[i] = i + 1;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
    	//infix();
        dp[i] = dp[i - 1] + 1; pos = i - 1;
        for (int j = 1; j * j <= i; j++) {
            if (a[i] == a[pos])     {
            	cout <<  i<<" " << pos << "   - "<< a[i]<< endl;
                int before = prv[pos], after = nxt[pos];
                prv[after] = before;
                nxt[before] = after;
                pos = prv[pos];
                dp[i] = min(dp[i], dp[pos] + j * j);
                if (pos == 0) break;
                pos = prv[pos];
            }
            else {
            	cout <<  i<<" " << pos << "   - "<< a[pos]<< endl;
                dp[i] = min(dp[i], dp[pos] + j * j);
                if (pos == 0) break;
                pos = prv[pos];
            }
        }
    }
    
    for (int i = 1; i <= n; i++) cout << i << " "; cout << endl;
    for (int i = 1; i <= n; i++) cout << nxt[i] << " "; cout << endl;
    for (int i = 1; i <= n; i++) cout << prv[i] << " "; cout << endl;
    for (int i = 1; i <= n; i++) cout << dp[i] << " "; cout << endl;
    cout << dp[n];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
}
