#include <iostream>
#include <vector>
using namespace std;
//long int n;
//long int a[100005];
//long long int sum[100005], myMin[100005];
//mang tinh la hung thu khien bai nay ko AC >:(
int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n+1);
    vector<int> s(2*n+1);
    vector<int> m(2*n+1);
    s[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    for (long int i = n+1; i <= 2*n; i++){
		s[i] = s[n] + s[i-n];
	}

    m[n] = s[n];
    for (int i=n-1; i>=1; i--) {
        m[i] = min(m[i+1], s[i]);
    }

    m[n+1] = s[n+1];
    for (int i=n+1; i<=2*n; i++) {
        m[i] = min(m[i-1], s[i]);
    }

    int count = 0;
    for (int i=1; i<=n; i++) count += (s[i-1] < min(m[i+n-1],m[i]));
    cout << count;

    return 0;
}
