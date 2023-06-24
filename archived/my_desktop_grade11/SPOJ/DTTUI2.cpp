#include <bits/stdc++.h>

using namespace std;

int w[105], v[105], a[105];
int n, m;
long long int dp[105][100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >>m;
	
	for (int i = 1; i <= n; i++){
		cin >> w[i] >> v[i] >> a[i];
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < w[i]; j++){
			deque<int> d;
            for (int x = j; x <= m; x += w[i])
            {
                while (!d.empty() && d.front() < x - a[i]*w[i]) d.pop_front();
                while (!d.empty() && dp[i-1][d.back()] + (x - d.back())/w[i]*v[i] <= dp[i-1][x]) d.pop_back();
                d.push_back(x);
                dp[i][x] = max(dp[i-1][x], dp[i-1][d.front()] + (x - d.front())/w[i]*v[i]);
            }
		}
	}

//	for (int i = 1; i <= n; i++){
//		for (int j = 0; j <= m; j++) cout << dp[i][j] << " ";
//		cout << endl;
//	}
	cout << dp[n][m];
	
	return 0;
}


//for (int i = 1; i <= n; i++){
//	for (int j = 0; i < w[i]; j++){
//		//if (j>m) break;
//		deque<int> d;
//		for (int k = 0; k < a[i]; k++){
//			if (j+k*v[i]>m) break;
//			//cout << i << " " << j << " " << k << endl;
//			while (!d.empty()&&d.front()+a[i]*w[i]<j+k*v[i]) d.pop_front();
//			while (!d.empty()&&dp[i-1][d.back()] + (j+k*v[i]-d.back())/w[i]*v[i] <= dp[i-1][j+k*v[i]]) d.pop_back();
//			dp[i][j+k*v[i]] = max(dp[i-1][j+k*v[i]],dp[i-1][d.front()] + (j+k*v[i]-d.front())/w[i]*v[i]);
//		}
//	}
//}

