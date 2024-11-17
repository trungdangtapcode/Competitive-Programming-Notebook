#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N];
string s, t;
int ktra(int l, int r){
    while(l <= r){
        if(a[l] != a[r]) return 0;
        ++l;    --r;
    }
    return 1;
}
typedef vector<int> vi;
typedef pair<vi,vi> pvi;
pvi f(string s){
    vector<int> v0, v1;
    for (int i = 0; i < n; i++){
        if (s[i]=='1'){
            if (i%2){
                if (v0.size()) v0.pop_back();
                else v1.push_back(v1.size()?v1.back()+2:1);
            } else {
                if (v1.size()) v1.pop_back();
                else v0.push_back(v0.size()?v0.back()+2:0);
            }
        } else {

        }
    }
    //for (int i: v0) cout << i << " "; cout << "\n";
    //for (int i: v1) cout << i << " "; cout<< "\n====\n";
    return {v0,v1};
}

void solve(){
    cin >> n;
    cin >> s >> t;
    auto it1 = f(s), it2 = f(t);
    cout << (it1==it2?"YES\n":"NO\n");



}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    //freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}

