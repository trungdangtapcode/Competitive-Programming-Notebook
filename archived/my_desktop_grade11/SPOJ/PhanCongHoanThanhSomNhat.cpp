#include <bits/stdc++.h>

using namespace std;

int n;
long long int a[205][205], t;
int trace[205], my[205], mx[205];

int findPath(){
	memset(trace,-1,sizeof(trace));
	queue<int> q;
	for (int i = 0; i < n; i++) if (mx[i]==-1) q.push(i);
	while (!q.empty()){
		int i = q.front();
		q.pop();
		for (int j = 0; j < n; j++) if (a[i][j]<=t&&trace[j]==-1){
			trace[j] = i;
			if (my[j]==-1) return j;
			q.push(my[j]);
		}
	}
	return -1;
}
void enlarge(int j){
	while (j!=-1){
		int i = trace[j];
		int jNext = mx[i];
		mx[i] = j; my[j] = i;
		j = jNext;
	}
	return;
}
bool check(){
	memset(mx,-1,sizeof(mx));
	memset(my,-1,sizeof(my));
	
	int j;
	do {
		j = findPath();
		if (j!=-1) enlarge(j);
//		else break;
	} while (j!=-1);
 	
	for (int i = 0; i < n; i++) if (mx[i]==-1) return false;
	return true;
}


int main(){
	memset(a,1,sizeof(a));
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	long long int l = -1e10, h = 1e10, m, res = 0;
//	cout << a[100][100];
	while (l<=h){
		m = (l+h)/2;
//		cout << l << " " << m << " " << h << endl;
		t = m; //input of check()
		if (check()){ //ok, giam thoi
			h = m-1;
			res = m;
		} else {
			l = m+1;
		}
	}
	cout << res;
	
	return 0;
}
