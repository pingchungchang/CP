#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    scanf("%d %d\n",&r,&c);
    vector<vector<int>> v(r+2,vector<int>(c+2,0));
    int bombs = 0;
    for(int i =1;i<=r;i++){
        for(int j =1;j<=c;j++){
            int k;
            scanf("%d",&k);
            if(k == 1)bombs++;
            v[i][j] = k;
        }
    }
    vector<pair<int,int>> dirs;
    for(int i =1;i>=-1;i--){
        for(int j =1;j>=-1;j--){
            if(i!=0||j!=0){
                dirs.push_back(make_pair(i,j));
            }
        }
    }
    int found = 0;
    for(int i =1;i<=r;i++){
        for(int j =1;j<=c;j++){
            if(v[i][j] == 5){
                int meddles = 0;
                for(int l =0;l<dirs.size();l++){
                    if(v[i+dirs[l].first][j+dirs[l].second] ==5){
                        meddles = 1;
                    }
                }
                if(meddles == 0){
                    for(int l =0;l<dirs.size();l++){
                        if(v[i+dirs[l].first][j+dirs[l].second]==1){
                            v[i+dirs[l].first][j+dirs[l].second] = 0;
                            bombs--;
                            found++;
                        }
                    }
                }
            }
        }
    }
    printf("%d %d",found,bombs);
    
}