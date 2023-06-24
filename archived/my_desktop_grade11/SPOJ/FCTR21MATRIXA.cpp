#include <bits/stdc++.h>

using namespace std;
const int INF = 1e7;
int rowI[305], rowJ[305];
int colNow[305]; //now: i+1->j-1
int numRow, numCol, min_begin, res = -INF;
int a[305][305];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> numRow >> numCol;
	for (int i = 1; i <= numRow; i++) for (int j = 1; j <= numCol; j++) cin >> a[i][j];
	for (int i = 1; i <= numRow; i++){
		rowI[0] = colNow[0] = 0;
		for (int j = 1; j <= numCol; j++){
			colNow[j] = 0; //init colNow (begin: i+1)
			rowI[j] = rowI[j-1]+a[i][j]; //calc rowI
		}
		for (int j = i+1; j <= numRow; j++){
			rowJ[0] = 0;
			for (int k = 1; k <= numCol; k++) rowJ[k] = rowJ[k-1] + a[j][k]; //calc rowJ
			
			min_begin = INF;
			for (int k = 1; k <= numCol; k++){
				res = max(res,rowI[k]+rowJ[k]+colNow[k]-min_begin); //max_end_here
				min_begin = min(min_begin,rowI[k-1]+rowJ[k-1]-colNow[k]);
			}
			
			for (int k = 1; k <= numCol; k++) colNow[k] = colNow[k] + a[j][k]; //update colNow (end: j-1)
		}
	}
	
	cout << res;
	return 0;
}
