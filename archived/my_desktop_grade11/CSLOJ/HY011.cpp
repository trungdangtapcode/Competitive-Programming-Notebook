#include <bits/stdc++.h>

using namespace std;
int n, a[10005];

void cauC(){
	int x[105][105];
	int dem = 0;
	for (int i = 0; i < n/2; i++){
		for (int j = i; j < n-i-1; j++) x[i][j] = a[dem++];
		for (int j = i; j < n-i-1; j++) x[j][n-1-i] = a[dem++];
		for (int j = i; j < n-i-1; j++) x[n-1-i][n-1-j] = a[dem++];
		for (int j = i; j < n-i-1; j++) x[n-1-j][i] = a[dem++];
		//break;
	}
	if (n%2==1) x[n/2][n/2] = a[dem++];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) cout << x[i][j] << " ";
		cout << '\n';
	}
}
void cauB(){
	int x[105][105];
	int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
	for (int i = 0, be, en, dem = 0; i < n; i++){
		if (i%2==0){
			be = 0;
			en = n-1;
			for (int j = be; j <= en; j++) x[n-1-j][n-1-i] = a[dem++];
		} else {
			be = n-1;
			en = 0;
			for (int j = be; j >= en; j--) x[n-1-j][n-1-i] = a[dem++];
		}
	}	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) cout << x[i][j] << " ";
		cout << '\n';
	}
}
void cauD(){
	int x[105][105];
	int dem = 0, hang = 0;
	for (int i = 0; i < n; i++, hang++){
		if (hang%2==0){
			for (int j = 0; j <= i; j++) x[i-j][j] = a[dem++];
		} else {
			for (int j = i; j >= 0; j--) x[i-j][j] = a[dem++];
		}
	}
	for (int i = n-2; i >= 0; i--, hang++){ 
		if (hang%2==0){
			for (int j = 0; j <= i; j++) x[n-1-j][n-1-i+j] = a[dem++];
		} else {
			for (int j = i; j >= 0; j--) x[n-1-j][n-1-i+j] = a[dem++];
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) cout << x[i][j] << " ";
		cout << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n*n; i++) cin >> a[i];
	sort(a,a+n*n);
//	for (int i = 0; i < n*n; i++) x[i/n][i%n] = a[i];

	//cau a
	for (int i = 0, be, en; i < n; i++){
		if (i%2==0){
			be = i*n;
			en = i*n + n-1;
			for (int j = be; j <= en; j++) cout << a[j] << " ";
		} else {
			be = i*n + n-1;
			en = i*n;
			for (int j = be; j >= en; j--) cout << a[j] << " ";
		}
		cout << '\n';
	}	
	//cau b
	cauB();
	//cau c
	cauC();
	cauD();
	return 0;
}

/*
for (int i = 0, be, en; i < n; i++){
	be = n*n-1-i;
	en = n-1-i;
	for (int j = be, j0 = 0; j >= en; j -= (j0%2==0?(2*n-1-2*i):(2*i+1)),j0++) cout << a[j] << " ";
	cout << '\n';
}
*/	
/*
	int x[105][105];
	int dx[2] = {1,-1}, dy[2] = {-1,1}; //[][]
	int huongdi = 1, dem = 0;
	for (int i = 0, xpos = 0, ypos = 0; i < n*n; i++){
		x[xpos][ypos] = a[dem++];
		if ((xpos==0&&huongdi==1)||(xpos==n-1&&huongdi==0)){
			ypos++;
			huongdi = (huongdi+1)%2;
		} else if ((ypos==0&&huongdi==||ypos==n-1) {
			xpos++;
			huongdi = (huongdi+1)%2;
		} else {
			
		}
	}
*/
