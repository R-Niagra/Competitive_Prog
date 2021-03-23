#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;

#define p1(a) cout<<"p1: "<<a<<"\n"
#define p2(a,b) cout<<"p2 "<<a<<" "<<b<<"\n"

bool sortrev(const pair<int,char> &a,  const pair<int,char> &b){ 
  return (a.first > b.first); 
}

void insertIntoMap(map<ll,ll> &m,ll key,ll value){
    auto it = m.find(key);
    if(it!=m.end()){
        it->second +=value;
    }else{
        m.insert(pair<ll,ll>(key,value));
    }
}

void delIntoMap(map<ll,ll> &m,ll key,ll value){
    auto it = m.find(key);
    if(it!=m.end()){
        if(it->second <= value){
            m.erase(key);
            return;
        }

        it->second -=value;
    }
}

bool findIntoMap(map<ll,ll> &m,ll key){
    auto it = m.find(key);
    if(it!=m.end()){
        return true;
    }else{
        return false;
    }
}





void solveCase(){
   ll n,p;
   cin>>n>>p;

    if(p>=n){
        cout<<0<<" "<<0<<"\n";
        return;
    }
    set<ll,greater<int> > v;   //distance and repetition
    map<ll,ll> m;

    for(int i=0;i<p;i++){   //against every person  
        if(i==0){
            //Check for the even and the odd
            if(n%2==1){
                ll a= (n-1)/2;
                        if(i==p-1){
                    cout<<a<<" "<<a<<"\n";
                    break;    
                    } 
                v.insert(a);
                insertIntoMap(m,a,2);
            }else{
                ll a = (n-1)/2;
                ll b = n/2;

                    if(i==p-1){
                    cout<<b<<" "<<a<<"\n";
                    break;    
                    } 
                // p2(a,b);
                v.insert(a);
                insertIntoMap(m,a,1);
                v.insert(b);
                insertIntoMap(m,b,1);
            }
        }else{

            if(*(v.begin())%2==1){
                //break the element into 2 first

                ll a= (*(v.begin())-1)/2;
                if(i==p-1){
                cout<<a<<" "<<a<<"\n";
                break;    
                } 

                insertIntoMap(m,a,2);
                v.insert(a);

            }else{
                ll a= (*(v.begin())-1)/2;
                ll b= (*(v.begin()))/2;
                    if(i==p-1){
                    cout<<b<<" "<<a<<"\n";
                    break;    
                    } 

                insertIntoMap(m,a,1);
               
                v.insert(a);

                insertIntoMap(m,b,1);
                
                v.insert(b);

            }

            delIntoMap(m,*(v.begin()),1); 
            if(!findIntoMap(m,*(v.begin()))) v.erase(v.begin());


        }   

    }


  
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