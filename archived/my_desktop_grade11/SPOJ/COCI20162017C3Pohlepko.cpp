#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> toado;
int n, m;
char a[3000][3000];
bool c[3000][3000];
toado trace[3000][3000];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(a,'z'+1,sizeof(a));
	cin >> n >> m;
	//for (int i = 0; i <n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	for (int i = 0; i < n; i++) cin >> a[i];
	
	queue<toado> q2;
	char myMin = a[0][0];
	q2.push({0,0});
	for (int step = 1; step < m + n; step++){
		//q1.clear();
		queue<toado> q1;
		//toado toadoMin = *(min_element(q2.begin(), q2.end()));
		cout << myMin;
		while (!q2.empty()){
			if (myMin == a[q2.front().first][q2.front().second]) q1.push(q2.front());
			q2.pop();
		}
		myMin = (char)126;
		//q2.clear();	
		while (!q1.empty()){
			toado x= q1.front();
			q1.pop(); 
			cout << x.first << " " << x.second << " " << step <<endl;
			if (x.first<n-1) q2.push({x.first+1,x.second});
			myMin = min(myMin,a[x.first+1][x.second]);
			//trace[x.first+1][x.second] = {x.first,x.second};
			if (x.second<m-1) q2.push({x.first,x.second+1});
			myMin = min(myMin,a[x.first][x.second+1]);
			//trace[x.first+1][x.second] = {x.first,x.second};
//			if (x.first>=n-1||x.second>=m-1) continue;
//			if (a[x.first+1][x.second]==a[x.first][x.second+1]){
//				q2.push({x.first+1,x.second});
//				q2.push({x.first,x.second+1});
//			} else
//			if (a[x.first+1][x.second]<a[x.first][x.second+1]) q2.push({x.first,x.second+1});
//			else q2.push({x.first,x.second+1});
		}
	}
//	for (int i = 0; i <n; i++) {
//		for (int j = 0; j < m; j++) cout <<  a[i][j] << " ";
//		cout << endl;
//	}
	return 0;
}
