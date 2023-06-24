#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> toado;
int n, m;
char a[2005][2005];
bool c[2005][2005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(c,false,sizeof(c));
	memset(a,'z'+1,sizeof(a));
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	queue<toado> q2;
	char myMin = a[0][0];
	q2.push({0,0});
	for (int step = 1; step < m + n  -1; step++){
		queue<toado> q1;
		cout << myMin;
		while (!q2.empty()){
			if (myMin == a[q2.front().first][q2.front().second]) q1.push(q2.front());
			q2.pop();
		}
		
		myMin = (char)126;
		while (!q1.empty()){
			toado x= q1.front();
			q1.pop(); 
			//cout << x.first << " " << x.second << " " << step <<endl;
			if (x.first<n-1&&!c[x.first+1][x.second]){
				//cout << x.first << " < " << n-1 << endl;
				q2.push({x.first+1,x.second});
				c[x.first+1][x.second] = true;
				myMin = min(myMin,a[x.first+1][x.second]);
			}
			if (x.second<m-1&&!c[x.first][x.second+1]){
				q2.push({x.first,x.second+1});
				c[x.first][x.second+1] = true;
				myMin = min(myMin,a[x.first][x.second+1]);
			}
			//if ((x.second==m-2&&x.first==n-1)||(x.second==m-1&&x.first==n-2)) myMin = min(myMin,a[n-1][m-1]);	
		}
	}
	cout << a[n-1][m-1];
	return 0;
}
