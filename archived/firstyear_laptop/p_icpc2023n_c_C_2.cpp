#include<bits/stdc++.h>

using namespace std;
int n, a[100005][2], row;
vector<int> res;

void f(int a, int b, int c, int d, int e){
	if (row==0){
		swap(a,b);
		swap(c,d);
	}
	res.push_back(d);
	res.push_back(c);
	res.push_back(e);
	res.push_back(d);
	res.push_back(b);
	res.push_back(e);
	res.push_back(d);
	res.push_back(b);
	res.push_back(e);
	res.push_back(a);
	res.push_back(b);
}
void sim(int x){
	int tmp;
	int x1 = tmp, x2 = tmp;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 2; j++) if (a[i][j]==0) x1 = i, x2 = j;
	}
	for (int i = 1, k = 0; i <= n; i++){
		for (int j = 0; j < 2; j++) if (a[i][j]==x){
			if (x2==j){
				cout << "error!\n";
			}
			swap(a[x1][x2],a[i][j]);
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
		cout << a[i][0] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= n; i++){
		cout << a[i][1] << " ";
	}
	cout << ".\n";
}


int main(){
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i][0];
	for (int i = 1; i <= n; i++) cin >> a[i][1];
	if (n%2==0){
		cout << -1;
		return 0;
	}
	int key = 0;
	for (int i = 1; i <= n; i++){
		if (a[i][0]==0||a[i][1]==0){
			key = a[i][0] + a[i][1];
			if (a[i][0]) row = 0; else row = 1;
		}; 
	}
	for (int i = 1, j = 0; i <= n; i++){
		if (a[i][0]==0||a[i][1]==0) continue;
		if (j!=0){
			f(a[i][0],a[i][1],a[j][0],a[j][1],key);
			j = 0;
			row ^= 1;
		} else j = i;
	}
	if (n/2%2==0) res.push_back(key);
	cout << res.size() << "\n";
	for (int i : res) cout << i << " ";
//	for (int i : res) sim(i);
	
	return 0;
}
