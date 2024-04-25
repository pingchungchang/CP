#include <bits/stdc++.h>
using namespace std;

int main(){
    int w,h;
    cin>>w>>h;
    vector<vector<int>> v(h,vector<int>(w,0));
    for(int i = 0;i<h;i++){
        for(int j = 0;j<2*w-1;j++){
            char k;
            cin>>k;
            if(j%2 ==1){
                if(k == '-'){
                    v[i][(j-1)/2] = 1;
                    v[i][(j+1)/2] = -1;
                }
            }
        }
    }
    for(int i = 0;i<w;i++){
        int x = i;
        for(int j = 0;j<h;j++){
            if(v[j][x] !=0){
                x += v[j][x];
            }
        }
        cout<<x+1<<' ';
    }
}
