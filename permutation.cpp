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

// const ll INF = 1e18;

vector<int> permutation;
int n = 4;
bool chosen[4];

void mySearch()
{
    if (permutation.size() == n)
    {
        // process permutation
        cout << "one permutation done. Printing..." << endl;

        for (auto x : permutation)
        {
            cout << x << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (chosen[i])
                continue;
            chosen[i] = true;
            permutation.push_back(i);
            mySearch();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

vector<int> chessBishopDream(vector<int> boardSize, vector<int> initPosition, vector<int> initDirection, int k) {
vector<int> d = initDirection;
int x = initPosition[0],y = initPosition[1];
int count = 0, reflected = 0;
bool xRef = false, yRef = false;

    while(count<k){
      //checking the current direction with the move
      if( ((x+d[0]) < 0) || ((x+d[0]) > (boardSize[0]-1))){
          //reflect
            d[0] = d[0]* (-1);
            reflected = 1;
            // cout<<"x ref"<<endl;
            xRef = true;
      }
      
      if(((y+d[1] < 0) || (y+d[1] > (boardSize[1]-1)))){
          //reflect
          d[1] = d[1] * -1;
          reflected = 1;
        //   cout<<"y ref"<<endl;
          yRef = true;
      }
      
        if(xRef==true && yRef==true){   //Reflection moves
            count++;
        }else if(xRef==true){
            y += d[1]; 
            count++;
        }else if(yRef==true){
            x += d[0];
            count++;
        }else{
            x += d[0];      //unreflected moves
            y += d[1];    
            count++;
        }
      xRef = false;
      yRef = false;
    }
    
vector<int> ans{x,y};
return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    int t;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        mySearch();
    }
    return 0;
}