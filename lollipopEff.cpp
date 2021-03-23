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
#define FoR(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FoRd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

// const ll INF = 1e18;
void PrintVect(vector< pair<int,int> > v){
    for(int i=0;i<v.size();i++){
        cout<<"v"<<v[i].f<<" "<<v[i].s<<"\n";
    }
}


void solveCase(){
   int n;
   cin>>n;
    set< pair<int,int> > v;   //rep,num
    FoR(i,n){
        v.insert(mp(0,i));
    }

    FoR(i,n){
    //selling the lollipop
    int pn = 0;
    cin>>pn;
    if(pn<=0){
        cout<<-1<<endl;
        continue;
    }
    set<int>flavors;

        FoR(j,pn){
            int fla;
            cin>>fla;
            flavors.insert(fla);

                // if(rmv.find(fla)!=rmv.end()){  //If lollipop has been sold
                    
                // }else{  //Sell it

                    for(auto &it: v){
                        if(it.second==fla){
                            it.first +=1;
                        }

                    }
                    // for(int i=0;i<v.size();i++){
                    //     if(v[i].second==fla){
                    //         v[i].first +=1;
                    //     }
                    // }
                    // PrintVect(v);
        }
        bool sold= 0;
        // sort(v.begin(),v.end());
        FOR(autp &it : v){
            if( it.first!=0  && flavors.find(it.second)!= flavors.end()){
                sold=1;
                cout<<v[i].second<<endl;
                v[i].first-=1;
                if(v[i].first==0){
                    v.erase(v.begin()+i);
                    // n--;
                }
            }
        }
        if(sold==0){
            cout<<-1<<endl;
        }
        // cout<< "After "<<"\n";
        // PrintVect(v);
        //Sell the first least popolar


    }

}


int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        // cout << "Case #" << i+1 << ": ";
        solveCase();
    }
    return 0;
}