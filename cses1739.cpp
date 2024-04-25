#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bit(1010,vector<int>(1010,0));
int n;
vector<vector<char>> v(1010,vector<char>(1010));
int lowbit(int a){
    return a&(-a);
}
void modify(int x,int y,int val){
    while(x <=n){
        int tmp = y;
        while(tmp<=n){
            bit[x][tmp]+= val;
            tmp += lowbit(tmp);
        }
        x += lowbit(x);
    }
    return;
}
int getval(int x,int y){
    int sum = 0;
    while(x>0){
        int tmp = y;
        while(tmp>0){
            sum += bit[x][tmp];
            tmp -= lowbit(tmp);
        }
        x -= lowbit(x);
    }
    return sum;
}
int main(){
    int m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>v[i][j];
            if(v[i][j] == '*')modify(i,j,1);
        }
    }
    for(int i = 0;i<m;i++){
        int t;
        cin>>t;
        if(t == 1){
            int x,y;
            cin>>x>>y;
            if(v[x][y] == '*'){
                v[x][y] = '.';
                modify(x,y,-1);
            }
            else{
                v[x][y] = '*';
                modify(x,y,1);
            }
        }
        else{
            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<getval(x2,y2)+getval(x1-1,y1-1)-getval(x1-1,y2)-getval(x2,y1-1)<<'\n';
        }
    }
}
