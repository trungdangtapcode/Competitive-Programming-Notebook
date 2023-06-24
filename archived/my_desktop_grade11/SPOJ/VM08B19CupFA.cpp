#include <bits/stdc++.h>

using namespace std;

int n, t;
double dp[300][10];
double a[300][300];

int getPos(int rank, int i){
	int pos = (i >> rank);
	if (pos%2==0){
		pos++;
		return (pos << rank);
	} else {
		pos--;
		return (pos << rank);		
	}
}

bool myfunc(pair<double,int> a, pair<double,int> b){
	if (a.first==b.first){
		return (a.second<b.second);
	}
	return (a.first>b.first);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	t = (1<<n);
	//cout << t;
	for (int i = 0; i < t; i++) for (int j = 0; j < t; j++){
		cin >> a[i][j];
		a[i][j] /= 100;
	}
	
	for (int i = 0; i < t; i++) dp[i][0] = 1;
	for (int rank = 1; rank <= n; rank++){ //rank = n (vong thu n) => champion
		for (int i = 0; i < t; i++){
			dp[i][rank] = 0;
			//cout << rank << " " << i << "   " << getPos(rank-1,i) << " "<< getPos(rank-1,i)+(1<<(rank-1))<< endl;
			for (int j = getPos(rank-1,i); j < getPos(rank-1,i)+(1<<(rank-1)); j++){
				dp[i][rank] += dp[i][rank-1]*dp[j][rank-1]*a[i][j];
				//cout << rank << " " << i << " " << j << " - " <<dp[i][rank-1]<<"*"<<dp[j][rank-1]<<"*"<<a[i][j] <<endl;
			}
		}
	}
	
//	for (int rank = 0; rank <= n; rank++) {
//		for (int i = 0; i < t; i++) cout << dp[i][rank] << " ";
//		cout << endl;
//	}
	vector <pair<double,int>> v;
	for (int i = 0; i < t; i++) v.push_back({dp[i][n],i});
	sort(v.begin(),v.end(),myfunc);
	for (auto& i: v){
		cout << i.second+1 << endl;
	}
	
	return 0;
}

//int getPos(int rank, int i){
//	int cha = (i >> rank);
//	int con = (i >> (rank-1));
//	if (con%2==0){
//		con++;
//		return (con << (rank-1));
//	} else {
//		con--;
//		return (con << (rank-1));		
//	}
//}

