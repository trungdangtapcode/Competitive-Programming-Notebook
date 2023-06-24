#include<bits/stdc++.h>

using namespace std;

int x, a[105], b[105];
int solve(){
	cin >> x;
	x *= 2;
	int carry = 0;
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	stack<int> st;
	for (int i = 0; i < 30; i++){
		int c = (x>>i&1), nc = (x>>(i+1)&1);
		//nc = 0 => equal, c is sum
		if (nc==0&&c==1){
			if (carry==0) return 0;
			else if (carry==1){
				st.push(i);
				carry = -1;
			} else { //carry = -1
				int pos = st.top(); st.pop();
				a[pos] = 1; b[pos] = 1;
				carry = -1;
			}
//			carry = -1;
		} else if (nc==0&&c==0){
			if (carry==1){				
				return 0;
			} else { ////////////////////////vcl quen push neu carry = -1
				st.push(i);
				carry = -1;
			}
			carry = -1;
		} else if (nc==1&&c==0){
			if (carry==0) return 0;
			else if (carry==1){
				a[i] = 1; b[i] = 0;
				carry = 1;
			} else {
				int pos = st.top(); st.pop();
				a[pos] = 1; b[pos] = 1;
				a[i] = 1; b[i] = 0;
				carry = 1;
			}
		} else if (nc==1&&c==1){
			if (carry==0){
				a[i] = 1; b[i] = 0;
				carry = 0;
			} else if (carry==1){
				return 0;
			}
		}
	}
	int res =0;
	for (int i = 30; i >= 0; i--) if (a[i]==1) res = 2*res+1; else res = res*2;
	cout << res << " ";
//	cout << "\n";
	res =0;
	for (int i = 30; i >= 0; i--) if (b[i]==1) res = 2*res+1; else res = res*2;
	cout << res << "\n";
	return 1;
}
	
int main(){
	int t; cin >> t;
	while (t--){
		if (!solve()) cout << "-1\n";
	}
	
	return 0;
}
