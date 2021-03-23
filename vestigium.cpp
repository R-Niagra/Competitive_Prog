#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;

void solveCase(){
    int n;
    cin >>n;
    int mat[n][n];
    int transMat [n][n];

    int rowCount=0,colCount=0,trace=0,val=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>val;
            mat[i][j]=val;
            transMat[j][i]=val;
         }
    }

    //Lets loop over the rows

    for(int i=0; i<n;i++){
        trace += mat[i][i];   //This will give the sum of the trace
        sort(mat[i],mat[i]+n);
        for(int j=0;j<n-1;j++){
            if(mat[i][j]==mat[i][j+1]){
                rowCount+=1;
                break;
            }
        }
    }
    //Looping over the transpose mat
    for(int i=0; i<n;i++){
        sort(transMat[i],transMat[i]+n);
        for(int j=0;j<n-1;j++){
            if(transMat[i][j]==transMat[i][j+1]){
                colCount+=1;
                break;
            }
        }
    }

    cout <<trace<<" "<<rowCount<<" "<<colCount << "\n";
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