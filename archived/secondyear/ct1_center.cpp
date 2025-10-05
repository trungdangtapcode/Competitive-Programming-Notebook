#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7, maxK = 15, maxN = 2e5+5;
// dp[j][rx][ry] = number of ways to choose j points 
// with sum_x % k = rx, sum_y % k = ry
//int dp[maxN][maxK][maxK];

void solve(){
    int n, k;
    cin >> n >> k;

	vector<vector<vector<long long>>> dp(k+1, vector<vector<long long>>(k, vector<long long>(k, 0)));
    dp[0][0][0] = 1; // base case
    
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x %= k; // take r
        y %= k;
        
        for(int j = min(i, k-1); j >= 0; j--){
            for(int rx = 0; rx < k; rx++){
                for(int ry = 0; ry < k; ry++){
                    if(dp[j][rx][ry] > 0){
                        int new_rx = (rx + x) % k;
                        int new_ry = (ry + y) % k;
                        dp[j+1][new_rx][new_ry] = (dp[j+1][new_rx][new_ry] + dp[j][rx][ry]) % mod;
                    }
                }
            }
        }
    }
    
    cout << dp[k][0][0] << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef JESSIE
    freopen("input.txt","r",stdin);
    #endif
//    int t; cin >> t;
//    while (t--)
        solve();
}
