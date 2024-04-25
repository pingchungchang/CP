#include <bits/stdc++.h>
using namespace std;
void tranverse(vector<vector<int>> &b){
    for(int i = 0;i<b.size()/2;i++){
        for(int j = 0;j<b[0].size();j++){
            int k = b[i][j];
            b[i][j] = b[b.size()-1-i][j];
            b[b.size()-1-i][j] = k;
        }
    }
}
void rotate(vector<vector<int>> &b){
    vector<vector<int>> now(b[0].size(),vector<int>(b.size(),0));
    for(int i = 0;i<b.size();i++){
        for(int j = 0;j<b[0].size();j++){
            now[now.size()-1-j][i] = b[i][j];
        }
    }
    b = now;
}
int main(){
    int r,c,n;
    while(cin>>r>>c>>n){
        vector<vector<int>> b(r,vector<int>(c,0));
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                int k;
                cin>>k;
                b[i][j] = k;
            }
        }
        vector<int> v(n,0);
        for(int i = 0;i<n;i++){
            int k;
            cin>>k;
            v[v.size()-i-1] = k;
        }
        for(int i = 0;i<v.size();i++){
            if(v[i] == 1){
                tranverse(b);
            }
            else{
                rotate(b);
            }
        }
        printf("%d %d\n",b.size(),b[0].size());
        for(int i = 0;i<b.size();i++){
            for(int j = 0;j<b[0].size();j++){
                printf("%d",b[i][j]);
                if(j != b[0].size()-1)printf(" ");
            }
            printf("\n");
        }
    }
}