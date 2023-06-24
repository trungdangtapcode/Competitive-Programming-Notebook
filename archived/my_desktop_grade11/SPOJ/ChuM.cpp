#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, a[50005];
ii b[50005];
int valUp[5][100005], valDown[5][100005], f[100005][5];


//void reset(){
//	memset(val,0,sizeof(val));
//}
int getMax(int x, int index, int upXdown){ //0: up, 1: down
	int res = 0; //-1e6;
	if (x==0) return res;
	if (upXdown) while (x>0){
		res = max(res,valDown[index][x]);
		x -= (x&-x);
	} else while (x<=1e5){
		res = max(res,valUp[index][x]);
		x += (x&-x);
	}
	return res;
}
void update(int x, int v, int index){ //int update() gay LTE
	int x0 = x;
	while (x<=1e5){
		valDown[index][x] = max(valDown[index][x],v);
		x += (x&-x);
	}
	x = x0;
	while (x>0){
		valUp[index][x] = max(valUp[index][x],v);
		x -= (x&-x);
	}
};

const int UP = 0;
const int DOWN = 1;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> b[i].first, b[i].second = i;
	sort(b+1,b+n+1);
	b[0].first = -1e6;
	for (int i = 1, dem = 0; i <= n; i++){
		if (b[i-1].first<b[i].first) dem++;
		a[b[i].second] = dem;
	}
//	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	for (int i = 1, x, y; i <= n; i++){
		//1
		f[i][1] = getMax(a[i]-1,1,DOWN) + 1;
		//2
		x = getMax(a[i]+1,1,UP); y = getMax(a[i]+1,2,UP);
		if (x<=1) f[i][2] = 0;
		else f[i][2] = max(x,y)+1;
		//3
		x = getMax(a[i]-1,2,DOWN); y = getMax(a[i]-1,3,DOWN);
		if (x==0) f[i][3] = 0;
		else f[i][3] = max(x,y)+1;
		//4
		x = getMax(a[i]+1,3,UP); y = getMax(a[i]+1,4,UP);
		if (x==0) f[i][4] = 0;
		else f[i][4] = max(x,y)+1;
		//update
		for (int j = 1; j <= 4; j++) update(a[i],f[i][j],j);
	}
//	for (int j = 1; j <= 4; j++){
//		cout << j << ": \n";
//		for (int i = 1; i <= n; i++) cout << f[i][j] << " ";
//		cout << endl;
//	}
	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res,f[i][4]);
	cout << res;
	return 0;
}

/*
		for (int j = 1; j <= 4; j++){
			if (j==1){
				f[i][1] = getMax(a[i]-1,1) + 1;
				continue;	
			} 
//			cout << i << " " << j << endl;
			int x = getMax(a[i]-1,j-1), y = getMax(a[i]-1,j);
			if ((x<=1&&j==2)||(x==0&&j>2)) f[i][j] = 0;
			else f[i][j] = max(x,y) + 1;
		}
		
*/


/*
int getMax(int x, int index){
	int res = 0; //-1e6;
	if (x==0) return res;
	if (index%2) while (x>0){
		res = max(res,val[index][x]);
		x -= (x&-x);
	} else while (x<=1e5){
		res = max(res,val[index][x]);
		x += (x&-x);
	}
	return res;
}
int update(int x, int v, int index){
	if (index%2) while (x<=1e6){
		val[index][x] = max(val[index][x],v);
		x += (x&-x);
	} else while (x>0){
		val[index][x] = max(val[index][x],v);
		x -= (x&-x);
	}
}
*/
