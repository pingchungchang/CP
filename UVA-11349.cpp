#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        printf("Test #%d: ",i+1);
        string c;
        int m;
        cin>>c;
        cin>>c;
        cin>>m;
        int done = 1;
        vector<vector<long long>> matrix(m,vector<long long>(m,0));
        for(int j = 0;j<m;j++){
            for(int k = 0;k<m;k++){
                long long x;
                cin>>x;
      //          cout<<x<<' ';
                if(x<0)done = 0;
                matrix[j][k] = x;
            }
    //        cout<<endl;
        }
        for(int j = 0;j<m;j++){
            for(int k = 0;k<m;k++){
                if(matrix[j][k] != matrix[m-1-j][m-1-k])done = 0;
                if(done == 0) break;
            }
            if(done == 0) break;
        }
        if(done == 0){
            cout<<"Non-symmetric.\n";
        }
        else cout<<"Symmetric.\n";
    }
}
