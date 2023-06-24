#include <bits/stdc++.h>

using namespace std;
int n, m;
long int myMax;
int **a = new int*[2001];
long int tanso[5001];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	for (int i = 0; i < 2001; i++) a[i] = new int[2001];
	memset(tanso,0,sizeof(tanso));
	cin >> m >> n;
	for (int i = 0; i < m; i++) 
		for (int j = 0; j <  n; j++) cin >> a[i][j];// cout << a << " "<<tanso[a]<< endl;
		
	for (int i = 0; i < m; i++) 
		for (int j = 0; j <  n; j++){
			//cout << a[1][0];
			int x = a[i][j];
			if (i > 0) x += a[i-1][j];//, cout << "1- "<<x <<"+" <<a[i-1][j] << " | ";
			if (j > 0) x += a[i][j-1];//, cout << "2- " <<x<<"+" <<a[i][j-1] << " | ";
			if (i < m-1) x += a[i+1][j];//, cout << "3- "<<x<<"+" <<a[i+1][j] << " | ";
			if (j < n-1) x += a[i][j+1];//, cout << "4- " <<x<<"+" <<a[i][j+1] << " | ";
			tanso[x]++;
			//cout << i << " "<<j << " -> "<<a[i][j] <<","<<x << " " << tanso[x] << endl;
		}
	int result = 0; myMax = -1;
	//for (int i = 0; i < 1001; i++) cout << i << " " << tanso[i] << endl;
	for (int i = 0; i < 5001; i++) if (myMax <= tanso[i]) myMax = tanso[i], result = i; 
	cout << result;
	
	return 0;
}
