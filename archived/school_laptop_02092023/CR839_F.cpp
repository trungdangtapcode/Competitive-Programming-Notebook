#include<bits/stdc++.h>
//permu
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
int n , m, k, cnt[105], p[105];
vector<iii> res;
string a[105][35];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//int t; cin >> t;
	int t = 1;
	while (t--){
		cin >> n >> m >> k;
		for (int i = 0; i <= k; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
		for (int idx = 0; idx <= k; idx++){
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
				bool check = true;
				for (int d = 0; d < 4; d++){
					int ii = i + dx[d], jj = j + dy[d];
					if (ii<0||ii>=n||jj<0|jj>=m) continue; 
					if (a[idx][i][j]==a[idx][ii][jj]) check = false;
				}
				if (check) cnt[idx]++;
			}
		}
		iota(p,p+k+1,0);
		sort(p,p+k+1,[&cnt](int a, int b){
			return (cnt[a]>cnt[b]);
		});
		cout << p[0]+1 << "\n";
		for (int idx = 0; idx < k; idx++){
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[p[idx]][i][j]!=a[p[idx+1]][i][j]) res.push_back({1,{i+1,j+1}});
			res.push_back({2,{p[idx+1]+1,-1}});  
		}
		cout << res.size() << "\n";
		for (auto it: res){
			cout << it.first << " " << it.second.first << " ";
			if (it.first==1) cout << it.second.second << " ";
			cout << "\n";
		}
	}
	
	
	return 0;
}
