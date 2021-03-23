#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;

void solveCase(){
    string s;
    cin >>s;
    // cout<<s<<s[0]<<endl;
    int open = 0,num =0;
    string ans = "";

    for(int i=0;i<s.size();i++){
        num = s[i];
        num=num-48;
        if(num >= open){
            for(int j=open;j<num;j++){
                ans += "(";
                open++;
            }
            ans+= to_string(num);
        }else{
            for(int k=open;k>num;k--){
                ans+= ")";
                open--;
            }
            ans+=to_string(num);
        }
    }
    for(int z=0;z<open;z++){
        ans+=")";
    }
    open=0;
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        cout << "Case #" << i+1 << ": ";
        solveCase();
    }

}