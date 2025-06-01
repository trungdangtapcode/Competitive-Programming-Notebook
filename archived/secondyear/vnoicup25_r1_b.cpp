#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

// Factorize a number into prime factors and their exponents
vector<pair<ll, int> > factorize(ll n) {
    vector<pair<ll, int> > factors;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            factors.push_back({i, cnt});
        }
    }
    if (n > 1) factors.push_back({n, 1});
    return factors;
}

// Generate all divisors <= m using the prime factors with max exponents from m
vector<ll> generate_divisors(const vector<pair<ll, int> >& primes, ll m) {
    vector<ll> divisors;
    int k = primes.size();
    vector<int> max_exp(k);
    for (int i = 0; i < k; i++) max_exp[i] = primes[i].second;
    
    function<void(ll, int)> backtrack = [&](ll current, int index) {
        if (current > m) return;
        if (index == k) {
            divisors.push_back(current);
            return;
        }
        ll p = primes[index].first;
        ll power = 1;
        for (int e = 0; e <= max_exp[index]; e++) {
            if (current * power > m) break;
            backtrack(current * power, index + 1);
            power *= p;
        }
    };
    backtrack(1, 0);
    return divisors;
}

// BFS to find the shortest sequence of operations
vector<ll> bfs(const vector<pair<ll, int> >& primes_n, const vector<pair<ll, int> >& primes_m, ll m, const vector<ll>& D) {
    int k = primes_n.size();
    vector<int> start(k), target(k);
    for (int i = 0; i < k; i++) {
        start[i] = primes_n[i].second;
        target[i] = primes_m[i].second;
    }
    queue<pair<vector<int>, vector<ll> > > q;
    set<vector<int> > visited;
    q.push({start, {}});
    visited.insert(start);
    
    while (!q.empty()) {
        pair<vector<int>, vector<ll> > front = q.front();
        vector<int> current = front.first;
        vector<ll> path = front.second;
        q.pop();
        if (current == target) return path;
        
        for (ll d : D) {
            vector<int> next = current;
            bool valid = true;
            ll temp = d;
            for (int i = 0; i < k; i++) {
                ll p = primes_n[i].first;
                int f = 0;
                while (temp % p == 0) {
                    temp /= p;
                    f++;
                }
                if (f > current[i]) {
                    valid = false;
                    break;
                }
                next[i] += f;
                if (next[i] > target[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid && visited.find(next) == visited.end()) {
                visited.insert(next);
                vector<ll> new_path = path;
                new_path.push_back(d);
                q.push({next, new_path});
            }
        }
    }
    return {};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        ll n, m;
        cin >> n >> m;
        
        // Special case: n == m
        if (n == m) {
            cout << "0" << endl;
            continue;
        }
        
        // Factorize n and m
        vector<pair<ll, int> > factors_n = factorize(n);
        vector<pair<ll, int> > factors_m = factorize(m);
        
        // Check if prime factors match
        set<ll> primes_n, primes_m;
        for (auto p : factors_n) primes_n.insert(p.first);
        for (auto p : factors_m) primes_m.insert(p.first);
        if (primes_n != primes_m) {
            cout << -1 << endl;
            continue;
        }
        
        // Check if n divides m (exponents in m >= those in n)
        bool possible = true;
        for (auto p : factors_n) {
            auto it = find_if(factors_m.begin(), factors_m.end(), 
                [&](const pair<ll, int>& pe) { return pe.first == p.first; });
            int e_m = it->second;
            if (e_m < p.second) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            cout << -1 << endl;
            continue;
        }
        
        // Prepare prime list with max exponents from m
        vector<pair<ll, int> > primes;
        for (auto p : factors_n) {
            auto it = find_if(factors_m.begin(), factors_m.end(), 
                [&](const pair<ll, int>& pe) { return pe.first == p.first; });
            int e_m = it->second;
            primes.push_back({p.first, e_m});
        }
        
        // Generate divisors and find solution
        vector<ll> D = generate_divisors(primes, m);
        vector<ll> path = bfs(factors_n, factors_m, m, D);
        
        if (path.empty()) {
            cout << -1 << endl;
        } else {
            cout << path.size();
            for (ll x : path) cout << " " << x;
            cout << endl;
        }
    }
    return 0;
}
