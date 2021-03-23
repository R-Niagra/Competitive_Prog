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
#define F0R(i, a) for (int i = 0; i < a; i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)

#define mp make_pair
#define pb push_back
#define f first
#define s second

// vector<int> Bfs(Tree<int> *t)
// {

//     //visit the tree
//     //Put the children in the queue
//     //pop
//     queue<Tree<int> *> vt;
//     vector<int> ans;

//     if (t == nullptr)
//     {
//         return ans = {};
//     }

//     vt.push(t);

//     while (vt.size() != 0)
//     {
//         cout << "Came in: " << vt.front()->value << endl;
//         ans.push_back((vt.front())->value);

//         if ((vt.front())->left != nullptr)
//         {
//             vt.push((vt.front())->left);
//         }
//         if ((vt.front())->right != nullptr)
//         {
//             vt.push((vt.front())->right);
//         }

//         vt.pop();
//     }
// }
vector<vector<int>> rotateImage(vector<vector<int>> a)
{

    int temp[4];

    int n = a[0].size();
    int layers = n / 2;

    for (int k = 0; k < layers; k++)
    {

        for (int i = k; i < n - 1 - k; i++)
        {
            temp[0] = a[k][i];
            temp[1] = a[i][n - 1 - k];
            temp[2] = a[n - 1 - k][n - 1 - i];
            temp[3] = a[n - 1 - i][k];

            a[i][n - 1 - k] = temp[0];
            a[n - 1 - k][n - 1 - i] = temp[1];
            a[n - 1 - i][k] = temp[2];
            a[k][i] = temp[3];

            //(k,i)       (i,n-1-k)
            //(n-1-i,k)   (n-1-k, n-1-i)
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return a;
}
int main()
{
    vector<vector<int>> a = {{1, 2, 3, 4}, {4, 5, 6, 7}, {9, 10, 11, 12, 13}, {14, 15, 16, 17}};
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < 1; i++)
    {
        rotateImage(a);
    }
    return 0;
}
