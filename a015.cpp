#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    while(scanf("%d %d\n",&r,&c)!=EOF){
        vector<vector<int>> v(r,vector<int>(c,0));
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                int k;
                scanf("%d",&k);
                if(j != c-1)scanf(" ");
                else scanf("\n");
                v[i][j] = k;
            }
        }
        for(int i = 0;i<c;i++){
            for(int j = 0;j<r;j++){
                printf("%d",v[j][i]);
                if(j != r-1)printf(" ");
                else printf("\n");
            }
        }
    }
}