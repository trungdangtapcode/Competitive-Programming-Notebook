#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
int n, m;
void print(vvi v){
	cout << "\n";
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) cout << v[i][j] << " ";
		cout << "\n";
	}
}
set<vvi> fw[11], bw[11];
void solve(){
	cin >> n >> m;
	vvi x = vvi(n, vi(m));
	vvi y = vvi(n, vi(m));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> x[i][j];
			y[i][j] = i*m+j+1;	
		}
	}	
	if (x==y){
		cout << 0 << "\n";
		return;
	}
	fw[0].insert(x);
	for (int t = 1; t <= 10; t++){
		for (auto it: fw[t-1]){
			vvi v = it;
			for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++){
				for (int ii = i; ii < i+n/2; ii++) for (int jj = j; jj < j+m-1; jj++){
					swap(v[ii][jj],v[i+n-2-(ii-i)][j+m-2-(jj-j)]);
					if ((ii-i)*(m-1)+jj-j+1>=(n-1)*(m-1)/2) break;
				}
				
				if (v==y){
					cout << t << "\n";
					return;
				}
				if (!fw[t-1].count(v)&&(t==1||!fw[t-2].count(v))) fw[t].insert(v);
				
				
				for (int ii = i; ii < i+n/2; ii++) for (int jj = j; jj < j+m-1; jj++){
					swap(v[ii][jj],v[i+n-2-(ii-i)][j+m-2-(jj-j)]);
					if ((ii-i)*(m-1)+jj-j+1>=(n-1)*(m-1)/2) break;
				}
				
			}
		}
	}
	bw[0].insert(y);
	for (int t = 1; t <= 10; t++){
		for (auto it: bw[t-1]){
			vvi v = it;
			for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++){
//				cout << i << " " << j << ": \n";
				for (int ii = i; ii < i+n/2; ii++) for (int jj = j; jj < j+m-1; jj++){
//					cout << "\t" << ii << " " << jj << " vs " << i+n-2-(ii-i) << " " << j+m-2-(jj-j)<< "\n";
					swap(v[ii][jj],v[i+n-2-(ii-i)][j+m-2-(jj-j)]);
					if ((ii-i)*(m-1)+jj-j+1>=(n-1)*(m-1)/2) break;
				}
				
				if (fw[10].count(v)){
					cout << t+10 << "\n";
					return;
				}
				if (t<10&&!bw[t-1].count(v)&&(t==1||!bw[t-2].count(v))) bw[t].insert(v);
				
				
				for (int ii = i; ii < i+n/2; ii++) for (int jj = j; jj < j+m-1; jj++){
					swap(v[ii][jj],v[i+n-2-(ii-i)][j+m-2-(jj-j)]);
					if ((ii-i)*(m-1)+jj-j+1>=(n-1)*(m-1)/2) break;
				}
				
			}
		}
	}
	
	cout << -1 << "\n";
	
//	cout << bw[9].size() << "\n";
//	print(y);
//	for (auto it: bw[1]){
//		print(it);
//	}
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

