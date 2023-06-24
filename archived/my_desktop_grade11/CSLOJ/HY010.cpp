#include <bits/stdc++.h>
//dung them mang prv[] hay nxt[] co the giam dpt thanh O(n)

using namespace std;
int x[105], p[105], pos, n;
bool choosed[105];
int main(){
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for (int i = n; i >= 1; i--){
		pos = i-1-p[i]+1;
		for (int j = 1, dem = 0; j <= n; j++) {
			if (!choosed[j]) dem++;
			if (dem==pos){
				x[i] = j;
				choosed[j] = true;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << x[i] << " ";
	
	return 0;
}
