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

void solveCase(){
   ll n,p;
   cin>>n>>p;

    if(p>=n){
        cout<<0<<" "<<0<<"\n";
        return;
    }
    vector< pair<ll ,ll> > v;   //distance and repetition

    for(int i=0;i<p;i++){   //against every person  
        if(i==0){
            //Check for the even and the odd
            if(n%2==1){
                ll a= (n-1)/2;
                        if(i==p-1){
                    cout<<a<<" "<<a<<"\n";
                    break;    
                    } 
                v.push_back(make_pair(a,2));
            }else{
                ll a = (n-1)/2;
                ll b = n/2;

                    if(i==p-1){
                    cout<<b<<" "<<a<<"\n";
                    break;    
                    } 
                // p2(a,b);
                v.push_back(make_pair(a,1));
                v.push_back(make_pair(b,1));
            }
        }else{

        sort(v.begin(),v.end(),sortrev);   //Sorted the vector

            if(v[0].first%2==1){
                //break the element into 2 first

                ll a= (v[0].first-1)/2;
                if(i==p-1){
                cout<<a<<" "<<a<<"\n";
                break;    
                } 


                bool found=false;
                for (auto &elem : v){
                        if (elem.first==a)
                        {
                            elem.second +=2;
                            // p2("printing elem second: ",elem.second);
                            found = true;
                            break;
                        }
                    }
                    if(!found) v.push_back(make_pair(a,2)); 

            }else{
                ll a= (v[0].first-1)/2;
                ll b= (v[0].first)/2;
                    if(i==p-1){
                    cout<<b<<" "<<a<<"\n";
                    break;    
                    } 

                 bool found=false;
                for (auto &elem : v){
                        if (elem.first==a)
                        {
                            elem.second +=1;
                            found = true;
                            break;
                        }
                    }
                    if(!found) v.push_back(make_pair(a,1));

                found=false;
                for (auto &elem : v){
                        if (elem.first==b)
                        {
                            elem.second +=1;
                            found = true;
                            break;
                        }
                    }
                    if(!found) v.push_back(make_pair(b,1));

            }

            if(v[0].second ==1) v.erase(v.begin());
            else v[0].second-=1; 


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