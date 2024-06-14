#include<bits/stdc++.h>

using namespace std;
int n, a[100005][2], row, key, b[100005][2];
vector<int> res, pos;
void transk(int i){
	int x = a[i][0], y = a[i][1];
	cout << x << " " << y << " " <<row << "\n";
	if (row) swap(x,y);
	res.push_back(x);
	res.push_back(y);
	res.push_back(key);
	res.push_back(x);
	res.push_back(y);
	row ^= 1;
}
void trans(int i, int j){
	res.push_back(a[i][0]);
	res.push_back(a[j][1]);
	res.push_back(a[j][0]);
	res.push_back(a[i][1]);
	res.push_back(a[j][1]);
	res.push_back(a[j][0]);
	res.push_back(a[i][0]);
}
void sim(int x){
	int tmp;
	int x1 = tmp, x2 = tmp;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 2; j++) if (b[i][j]==0) x1 = i, x2 = j;
	}
	for (int i = 1, k = 0; i <= n; i++){
		for (int j = 0; j < 2; j++) if (b[i][j]==x){
			swap(b[x1][x2],b[i][j]);
			k = 1;
//			cout << i << "," << j << " = " << x << "\n";
			break;
		}
		if (k) break;
	}
//	cout << x<< "\n";
//	swap(x1,x2);
	cout << "\n";
	for (int i = 1; i <= n; i++){
		cout << b[i][0] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= n; i++){
		cout << b[i][1] << " ";
	}
	cout << ".\n";
}

int main(){
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i][0];
	for (int i = 1; i <= n; i++) cin >> a[i][1];
	for (int i = 1; i <= n; i++){
		b[i][0] = a[i][0];
		b[i][1] = a[i][1];
	}
	if (n==2){
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; i++){
		if (a[i][0]==0||a[i][1]==0){
			if (a[i][0]!=0){
				key = a[i][0];
				row = 0;
			} else {
				key = a[i][1];
				row = 1;
			}
		}; 
	}
	for (int i = 1, j = 0; i <= n; i++){
		if (a[i][0]==0||a[i][1]==0) continue;
		pos.push_back(i);
	}
	int cur = row^1;
	for (int i = (int)pos.size()-1; i >= 0; i--){
		cur ^= 1;
		res.push_back(a[pos[i]][cur]);
	}
	res.push_back(key);
	row ^= 1;
	cur = row^1;
	for (int i = (int)pos.size()-1; i >= 0; i--){
		cur ^= 1;
		res.push_back(a[pos[i]][cur]);
		swap(a[pos[i]][0],a[pos[i]][1]);
	}
	for (int i = 0; i < pos.size(); i++){
		transk(pos[i]);
	}
	cout << res.size() << "\n";	
	for (int i : res) cout << i << " ";
	for (int i : res) sim(i);
	
	return 0;
}
