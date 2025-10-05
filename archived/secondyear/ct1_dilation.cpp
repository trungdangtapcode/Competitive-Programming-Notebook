#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e3+5;
typedef pair<int,int> ii;
int img[maxN][maxN];

void solve(){
    int m, n, k;
    cin >> m >> n >> k;
    
    vector<ii> white;
    
    // Read image and find white pixels
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> img[i][j];
            if(img[i][j] == 1){
                white.push_back(ii(i, j));
            }
        }
    }
    
    // Initialize result to all black
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            img[i][j] = 0;
        }
    }
    
    for(int idx = 0; idx < white.size(); idx++){
        int wi = white[idx].first;
        int wj = white[idx].second;
        
        int i_min = max(0, wi - k);
        int i_max = min(m - 1, wi + k);
        int j_min = max(0, wj - k);
        int j_max = min(n - 1, wj + k);
        
        for(int i = i_min; i <= i_max; i++){
            for(int j = j_min; j <= j_max; j++){
                img[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << img[i][j];
            if(j < n - 1) cout << " ";
        }
        cout << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef JESSIE
    freopen("input.txt","r",stdin);
    #endif
        solve();
}
