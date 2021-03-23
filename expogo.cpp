#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > ipair;
typedef pair < ll, ll > lpair;

const int maxInd = 31;
char val[4] = {'N','S','E','W'};

bool ValidCord(int x, int y, int i){
    
    while(i<maxInd){
        ll num = 1LL << i;
        //  if ((x==0) && (y==0)){
        //      break;
        //  }
        if((num> x) && (num> y)){
            break;
        }
        if ((x & num) ^ (y & num)){
            continue;
        }else{
            return false;
        }
    i++;
    }

    return true;
}

string ValidatePoints(int x, int y, int i, string ans){
    //Base case
    ll num = 1LL << i;

    if(x==0 && y==0){
        return ans;
    }else if((num> x) && (num> y)){
            // cout<<"IMPOSSIBLE"<<"\n";
        return "IMPOSSIBLE";
    }else if(!((x & num) ^ (y & num))){
        //Same bits are on
        return "IMPOSSIBLE";
    }

    string ans1,ans2;
    if(x& num){
     ans1 =  ValidatePoints(x-num,y,i+1,ans+val[2]);
     ans2 = ValidatePoints(x+num,y,i+1,ans+val[3]);
    }else if(y& num){
    ans1 = ValidatePoints(x,y-num,i+1,ans+val[0]);   
    ans2 = ValidatePoints(x,y+num,i+1,ans+val[1]);   
    }
    
    if (ans1!= "IMPOSSIBLE")
     return ans1;
    else return ans2;
}

void solveCase() {
    int x, y;
    cin >> x >> y;

    if ((abs(x) + abs(y)) % 2 == 0) {
        cout << "IMPOSSIBLE" << "\n";
        return;
    }
    
    bool negx = false,negy = false;

    if(x <0)
        negx = true;
    if(y<0)
        negy = true;
    


    x = abs(x);
    y = abs(y);

    string ans = "";
    ans = ValidatePoints(x,y,0,"");
    // cout<<"ans before: "<<ans<<"\n";

    if (ans != "IMPOSSIBLE"){
        if (negx){
            for(int i = 0;i<ans.size();i++){
                if (ans[i]==val[2])
                    ans[i]=val[3];
                else if(ans[i]==val[3])
                    ans[i]=val[2];
                }
            }
        if (negy){
            for(int i = 0;i<ans.size();i++){
                if (ans[i]==val[0])
                    ans[i]=val[1];
                else if(ans[i]==val[1])
                    ans[i]=val[0];
                }
            }
    }

    // int i = 0;
    // bool negx = false,negy = false;

    // if(x <0)
    //     negx = true;
    // if(y<0)
    //     negy = true;
    

    // while (i<=maxInd) { //Change this condition later
    //     //Check for the both of the values
    //     ll num = 1LL << i;

    //     if ((x==0) && (y==0)){
    //         cout<<"\n";
    //     }else if((num> x) && (num> y)){
    //         cout<<"IMPOSSIBLE"<<"\n";
    //         return;
    //     }

    //     if ((x & num) ^ (y & num)){   //Either of x or y bit should be set
    //         if(x& num){
    //             if(ValidCord(x-num,y,i)){
    //                 x = x-num;
    //                 if (negx)
    //                 ans += val[2];
    //                 else ans += val[3];
    //             }else{
    //                 x = x+num;
    //                 if (negx)
    //                 ans += val[3];
    //                 else ans += val[2];
    //             }
    //         }else{
    //             if (ValidCord(x,y-num,i)){
    //                 y -= num;
    //                 if (negy)
    //                 ans+= val[1];
    //                 else ans += val[0];

    //             }else{
    //                 y += num;
    //                 if (negy)
    //                 ans+= val[0];
    //                 else ans += val[1];
    //                 // ans += val[1];
    //             }
    //         }


    //     } else {
    //         cout << "IMPOSSIBLE" << "\n";
    //         return;
    //     }

    // i++;
    // }   
     cout<<ans<<"\n";
}



int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        solveCase();
    }
    return 0;
}
