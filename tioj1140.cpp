#include <bits/stdc++.h>
using namespace std;
#define ld long double
int main(){
    int n;
    cin>>n;
    ld arr[n][n][3];
    for(int i= 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<3;k++)cin>>arr[i][j][k];
        }
    }
    ld total = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            ld tmp[] = {arr[i][j][0],arr[i][j][1],arr[i][j][2]};
            ld R = tmp[0],G = tmp[1],B = tmp[2];
            ld X = 0.5149 * R + 0.3244 * G + 0.1607 * B;
            ld Y = 0.2654 * R + 0.6704 * G + 0.0642 * B;
            ld Z = 0.0248 * R + 0.1248 * G + 0.8504 * B;
            total += Y;
            arr[i][j][0] = X,arr[i][j][1] = Y,arr[i][j][2] = Z;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<3;k++)cout<<fixed<<setprecision(4)<<arr[i][j][k]<<' ';
            cout<<'\n';
        }
    }
    cout<<"The average of Y is "<<fixed<<setprecision(4)<<total/(n*n);
    return 0;
}
