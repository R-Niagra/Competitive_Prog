#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;

#define p1(a) cout<<a<<"\n"
#define p2(a,b) cout<<a<<" "<<b<<"\n"

const int c=0,b=1,sh=-1;

int query(int val){

    cout<<val<<endl;
    string s;
    cin>>s;
    if(s=="CORRECT"){
        return c;
    }else if(s=="TOO_BIG"){
        return b;
    }else if(s=="TOO_SMALL"){
        return sh;
    }else{
        return -6;
    }

}

void solveCase(){
   int n;
   int a,b;
   cin>>a>>b;
    cin>>n;

    int low=a+1 , hi =b ;
    int count=0;
    //Implement binary search 
    while(true){
        if(count>n) return;

        int mid = (low+hi)/2;
        int ans = query(mid);
        if(ans==0){  //ANs is correct
            return;
        }else if(ans==1){
            hi = mid-1;
        }else if(ans == -1)
         low=mid+1;
        else return;

    count++;
    }
return;

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