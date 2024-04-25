#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int r,c;
        cin>>r>>c;
        vector<vector<int>> v(r,vector<int>(c,0));
        for(int j = 0;j<r;j++){
            for(int l = 0;l<c;l++){
                int k;
                cin>>k;
                v[j][l] =k;
            }
        }
        int done = 1;
        for(int j = 0;j<r;j++){
            for(int l = 0;l<c;l++){
                if(v[j][l] != v[r-j-1][c-l-1]){
                    done = 0;
                    break;
                }
            }
            if(done == 0) break;
        }
        if(done == 0)printf("keep defending\n");
        else printf("go forward\n");
    }
}