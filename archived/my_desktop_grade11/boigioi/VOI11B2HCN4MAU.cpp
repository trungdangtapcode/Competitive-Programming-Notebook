#include <bits/stdc++.h>
//A B C D (A->B: clockwise, C->D: reverse)
//(1 2) (3 4)
//(3 2) (1 4)
//(4 2) (3 1)

using namespace std;
int n;
int m[405][405];
int a, b, c;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(m,0,sizeof(m));
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a >> b >> c;
		m[a+200][b+200] = c;
	}
	long long int res = 0;
	for (int i = 0; i <= 400; i++){
		for (int j = i+1; j <= 400; j++){
			a = 0; b = 0;
			for (int k = 0; k <= 400; k++){
				if ((m[i][k] == 1 && m[j][k] == 2)||(m[i][k] == 2 && m[j][k] == 1)) a++;
				if ((m[i][k] == 3 && m[j][k] == 4)||(m[i][k] == 4 && m[j][k] == 3)) b++;
			}
			res += a*b;
			a = 0; b = 0;
			for (int k = 0; k <= 400; k++){
				if ((m[i][k] == 3 && m[j][k] == 2)||(m[i][k] == 2 && m[j][k] == 3)) a++;
				if ((m[i][k] == 1 && m[j][k] == 4)||(m[i][k] == 4 && m[j][k] == 1)) b++;
			}
			res += a*b;
			a = 0; b = 0;
			for (int k = 0; k <= 400; k++){
				if ((m[i][k] == 4 && m[j][k] == 2)||(m[i][k] == 2 && m[j][k] == 4)) a++;
				if ((m[i][k] == 3 && m[j][k] == 1)||(m[i][k] == 1 && m[j][k] == 3)) b++;
			}
			res += a*b;
			
		}
	}
	cout << res;
	
	return 0;
}
