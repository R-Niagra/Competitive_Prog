#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;

#define p1(a) cout<<a<<"\n"
#define p2(a,b) cout<<a<<" "<<b<<"\n"

void PrintVect(vector< pair<int,char> > v){  
    cout<<"Printing vect"<<"\n";
    for(int i=0;i<v.size();i++){
    cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    cout<<"\n";
}

bool sortrev(const pair<int,char> &a,  const pair<int,char> &b){ 
  return (a.first > b.first); 
}

void solveCase(){
   int n;
   cin>>n;

string party= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector< pair<int,char> > vec; 
vector<int> test;
    int sum=0;
    for(int i=0;i<n;i++){   
        int num;
        cin>>num;
        sum+=num;
        vec.push_back(make_pair(num,party[i]));
        // vec.push_back(make_pair(num,party[i]));
        // test.push_back(num);
    }
    // PrintVect(vec);
    while(sum>0){
        sort(vec.begin(),vec.end(),sortrev);
        // PrintVect(vec);
        if(sum==3){
            cout<<vec[0].second<<" ";
            vec[0].first-=1;
            sum-=1;
            continue;
        }

        if(vec[0].first>vec[1].first+1){   //pick both from the first
            cout<<vec[0].second<<vec[0].second<<" ";
            vec[0].first-=2;
            sum-=2;
        }else{
            cout<<vec[0].second<<vec[1].second<<" ";
            vec[0].first-=1;
            vec[1].first-=1;
            sum-=2;
        }
    }

    cout<<"\n";

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