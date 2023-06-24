#include <bits/stdc++.h>

//0 = 1 0 0 0
//1 = 0 1 0 0
//2 = 0 0 1 0
//3 = 0 0 0 1
//4 = 1 0 0 1
//5 = 1 0 1 0
//6 = 0 1 0 1
//7 = 0 0 0 0
//0 -> 1 2 3 6
//1 -> 0 2 3 4 5
//2 -> 0 1 3 4 6
//3 -> 0 1 2 5
//4 -> 1 2
//5 -> 1 3 6
//6 -> 0 2 5
//7 -> 0 1 2 3 4 5 6  7 //(cr7 for all moi dung, thu lai cai AC luon :]])

using namespace std;
int n, a[10005][4];
long long int dp[10005][8], INF = 1e15;
bool mau[8][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1},{1,0,0,1},{1,0,1,0},{0,1,0,1},{0,0,0,0}};
vector <int> phuhop[] = {{1,2,3,6,7},{0,2,3,4,5,7},{0,1,3,4,6,7},{0,1,2,5,7},{1,2,7},{1,3,6,7},{0,2,5,7},{0,1,2,3,4,5,6,7}};

int cal(int x, int y){
	int res = 0;
	for (int i = 0; i < 4; i++){
		res += a[x][i]*mau[y][i];
	}
	return res;
}

int main(){
	cin >> n;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < n; j++){
			cin >> a[j][i];
		}
	}
	
	for (int i = 0; i < 8; i++) {
		dp[0][i] = cal(0,i);
	}
	for (int i = 1; i < n; i++){
		for (int j = 0; j < 8; j++){
			long long int res = -INF; 
			for (auto& it: phuhop[j]){
				res = max(res,dp[i-1][it]);
			}
			//cout << i<< " "<< j << "  "<< res << endl;
			dp[i][j] = res + cal(i,j);
		}
	}
//	for (int i = 0; i < 8; i++){
//		for (int j = 0 ; j < n; j++)
//			cout << dp[j][i] << " ";
//		cout << endl;
//	}
	long long int res = -INF;
	for (int i = 0; i < 8; i++) res = max(res,dp[n-1][i]);
	if (res!=0){
		cout << res;
	} else {
		res =  -INF;
		for (int i = 0; i < n; i++) for (int j = 0; j < 4; j++) res = max(res,(long long int)a[i][j]);
		cout << res;
	}
	
	return 0;
}

//#include <bits/stdc++.h>
//
////0 = 1 0 0 0
////1 = 0 1 0 0
////2 = 0 0 1 0
////3 = 0 0 0 1
////4 = 1 0 0 1
////5 = 1 0 1 0
////6 = 0 1 0 1
////0 -> 1 2 3 6
////1 -> 0 2 3 4 5
////2 -> 0 1 3 4 6
////3 -> 0 1 2 5
////4 -> 1 2
////5 -> 1 3 6
////6 -> 0 2 5
//
//using namespace std;
//int n, a[10005][10005];
//long long int dp[10005][7];
//bool mau[7][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1},{1,0,0,1},{1,0,1,0},{0,1,0,1}};
//vector <int> phuhop[] = {{1,2,3,6},{0,2,3,4,5},{0,1,3,4,6},{0,1,2,5},{1,2},{1,3,6},{0,2,5}};
//
//int cal(int x, int y){
//	int res = 0;
//	for (int i = 0; i < 4; i++){
//		res += a[x][i]*mau[y][i];
//	}
//	return res;
//}
//
//int main(){
//	cin >> n;
//	for (int i = 0; i < 4; i++){
//		for (int j = 0; j < n; j++){
//			cin >> a[j][i];
//		}
//	}
//	
//	for (int i = 0; i < 7; i++) {
//		dp[0][i] = 0;
//		//for (int j = 0; j < 4; j++) dp[0][i] += mau[i][j]*a[0][j];
//		dp[0][i] = cal(0,i);
//	}
////	for (int i = 0; i < 7; i++){
////		cout << dp[0][i] << endl;
////	}
//	for (int i = 1; i < n; i++){
//		for (int j = 0; j < 7; j++){
//			long long int res = 0; //truong hop -1: khong chon gi ca
//			for (auto& it: phuhop[j]){
//				//res = max(res,cal(i-1,it));
//				res = max(res,dp[i-1][it]);
//			}
//			//cout << i<< " "<< j << "  "<< res << endl;
//			dp[i][j] = res + cal(i,j);
//		}
//	}
////	for (int i = 0; i < 7; i++){
////		for (int j = 0 ; j < n; j++)
////			cout << dp[j][i] << " ";
////		cout << endl;
////	}
//	long long int res = 0;
//	for (int i = 0; i < 7; i++) res = max(res,dp[n-1][i]);
//	cout << res;
//	
//	return 0;
//}
