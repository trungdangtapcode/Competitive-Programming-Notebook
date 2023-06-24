#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;
using namespace std;

int **a = new int*[3005];
int **f = new int*[3005]; 
int h, r, w, c, need;
void init(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	for (int i = 0 ; i < 3005 ; i++) {
    	a[i] = new int[3005];
    	f[i] = new int[3005];
    }
	for (int i = 0; i < 3005; i++){
		f[i][0] = 0;
		f[0][i] = 0;
	}
}

bool isHave(int m){
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++){
			f[i][j] = (a[i][j]>=m);
			//cout << f[i][j];
			//fix;
			f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
		}
	//fix;
	//for (int i = 1; i <= r; i++){
	//	for (int j = 1; j <= c; j++) cout << f[i][j] << " ";
	//	cout << endl;
	//}
	for (int i = 1; i <= r-h+1; i++)
		//for (int j = 1; j <= r-w+1; j++) HOW THE FUCK I WROTE THIS???
		for (int j = 1; j <= r-w+1; j++)
			if (f[i+h-1][j+w-1]-f[i-1][j+w-1]-f[i+h-1][j-1]+f[i-1][j-1]>=need) return true;
	return false;
}

int main(){
	init();
	cin >> r >> c >> h >> w;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> a[i][j];
	need = (h*w+1)/2;
	//if (h*w%2 == 1) need++;
			
	int low = 1, high = r*c, m, result;
	while (low<=high){
		m = (low+high)/2;
		//cout << m << " = "<<isHave << endl;
		if (isHave(m)){
			result = m;
			low = m+1;
		} else {
			high = m-1;
		}
	}
	cout << result << endl;
	//cout << isHave(22);
}
