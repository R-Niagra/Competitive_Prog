#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;

#define p1(a) cout<<a<<"\n"
#define p2(a,b) cout<<a<<" "<<b<<"\n"

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

// const ll INF = 1e18;

void solveCase(){

   string path;

   int x,y;
   cin>>x>>y>>path;


   int dist= abs(x)+abs(y);

    for(int i=0;i<path.size();i++){

        if(path[i]=='S'){
            y--;

        }else if(path[i]=='N'){
            y++;

        }else if(path[i]=='E'){
            x++;

        }else{
            x--;

        }
         dist= abs(x)+abs(y);

        if(dist<=i+1){
            cout<<i+1<<"\n";
            return;
        }
    }
   cout<<"IMPOSSIBLE"<<"\n";
  
}
//Values inserted in the set is const-> Cannot be changed


int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        cout << "Case #" << i+1 << ": ";
        solveCase();
    }
    return 0;
}