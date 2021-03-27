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
    int n, q;
    cin >> n >> q;
    vector<int> locks;

    FR(i, n - 1) {
        int dif;
        cin >> dif;
        locks.push_back(dif);
    }
    // vector<vector<int>> cache(100005);

    FR(i, q) {
        int start, toFind;
        cin >> start >> toFind;
        // cout << "start: " << start << toFind << endl;

        // if (cache[start].size() > 0) {
        //     cout << (cache[start])[toFind - 1] << " ";
        //     // cout << "from cache" << endl;
        //     continue;
        // }
        int left = start - 2, right = start - 1, count = 0;  //set of left and right lock index
        vector<int> ans;
        ans.push_back(start);
        while (count < (n - 1)) {


            if ((left >= 0) && ((right >= locks.size()) || (locks[left] <= locks[right]))) {

                ans.push_back(left + 1);
                left--;
            } else if (right < locks.size() && ((left < 0) || (locks[right] < locks[left]))) {

                ans.push_back(right + 2);
                right++;
            }
            count++;
            if (count >= (toFind - 1)) {
                break;
            }
        }
       
        cout << ans[toFind - 1] << " ";
        // cache[start] = ans;
    }
    cout << '\n';
}
//Values inserted in the set is const-> Cannot be changed

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