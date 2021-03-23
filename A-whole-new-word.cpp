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
   int n,l;
   cin>>n>>l;

    string ans="-";
    set<string> vals;
    F0R(i,n) {
        string s;
        cin>>s;
        vals.insert(s);
    }

    int itl=0;
    while(itl<l){
        int ind=0;

        while(ind<n){
            auto it =vals.begin();
            advance(it, ind);            
            string bs  = *it;

            auto it2 = vals.begin();
            advance(it2, ind);
            for(int i=ind;i<n;i++){

                string cs1 = *it2;

                if(bs[itl]!= cs1[itl]){
                    string newStr = bs.substr(0,itl) + cs1.substr(itl,1)+ bs.substr(itl+1);
                    if(vals.insert(newStr).second==true){
                        // ans = newStr;
                        cout<<newStr<<"\n";
                        return;
                    }
                }

                it2++;
            }
            ind++;
        }
    itl++;
    }
cout<<"-"<<"\n";

}


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