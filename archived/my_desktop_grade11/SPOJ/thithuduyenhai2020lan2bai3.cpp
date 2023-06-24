#include <bits/stdc++.h>

using namespace std;

bool checkVolume (int a, int b, int c, int d, int e, int f){
    long int M = a * a * d * d * (b * b + e * e + c * c + f * f - a * a - d * d);
    long int N = b * b * e * e * (a * a + d * d + c * c + f * f - b * b - e * e);
    long int P = c * c * f * f * (a * a + d * d + b * b + e * e - c * c - f * f);
    long int Q = a * a * b * b * c * c + a * a * e * e * f * f + b * b * d * d * f * f + c * c * d * d * e * e;
    //cout << sqrt(M+N+P-Q)/12 << endl;
	return (M + N + P - Q > 0);
}
bool check(int a, int b, int c){
    return (a + b > c) && (b + c > a) && (c + a > b);
}

bool solve(){
    int a[6];
    for (int i = 0; i < 6; i++){
        cin >> a[i];
		if (a[i] <= 0) return false;
	}
	sort(a,a+6);
	//cout <<a[0] << " "<<a[1] <<" "<<a[2] <<" "<<a[3] <<" "<<a[4]<<" "<<a[5] <<" ";
    do{
    	//cout <<a[0] << " "<<a[1] <<" "<<a[2] <<" "<<a[3] <<" "<<a[4]<<" "<<a[5] <<" " << (checkVolume(a[0],a[1],a[2],a[3],a[4],a[5]))<< endl;
    	//cout << "              " << ((check(a[0],a[1],a[2])) && (check(a[0],a[3],a[4])) && (check(a[1],a[4],a[5])) && (check(a[2],a[5],a[3]))) << endl;
     	if ((checkVolume(a[0],a[1],a[2],a[3],a[4],a[5]))&&(check(a[0],a[1],a[2])) && (check(a[0],a[4],a[5])) && (check(a[1],a[5],a[3])) && (check(a[2],a[3],a[4]))) return true;
		//if ((checkVolume(a[0],a[1],a[2],a[3],a[4],a[5]))&&(check(a[1],a[3],a[5])) && (check(a[0],a[1],a[2])) && (check(a[2],a[3],a[4])) && (check(a[4],a[5],a[0]))) return true;
	} while (next_permutation(a, a + 6));
    return false;
}

int main()
{
    int n;
    cin >> n;

    for (int i= 0; i < n; i++){
    	if (solve()) cout << "Yes" << '\n'; else cout << "No" << '\n';
	}
    return 0;
}
