#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ipair;
typedef pair<ll, ll> lpair;

#define p1(a) cout << a << "\n"
#define p2(a, b) cout << a << " " << b << "\n"

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FR(i, a) for (int i = 0; i < a; i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define FRd(i, a) for (int i = (a)-1; i >= 0; i--)

#define mp make_pair
#define pb push_back
#define f first
#define s second

// const ll INF = 1e18;

void solveCase() {
    int n;
    cin >> n;
    vector<int> v;
    v.push_back(-1);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    n++;

    int mx = v[0], count = 0;
    FOR(i, 1, n) {
        if ((i < (n - 1)) && (v[i] > mx) && (v[i] > v[i + 1])) {
            count++;
            mx = v[i];
        } else if ((i == (n - 1)) && (v[i] > mx)) {
            count++;
            mx = v[i];
        }

        if ((v[i] > mx)) {
            mx = v[i];
        }
    }
    cout << count << "\n";
}
// Values inserted in the set is const-> Cannot be changed

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        solveCase();
    }
    return 0;
}
