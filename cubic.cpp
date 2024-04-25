#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!= EOF){
        vector<vector<vector<int>>> cube(n,vector<vector<int>>(n,vector<int>(n,0)));
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                cube[0][i][j]++;
                cube[n-1][i][j]++;
                cube[i][j][0]++;
                cube[i][j][n-1]++;
                cube[i][n-1][j]++;
                cube[i][0][j]++;
            }
        }
        vector<int> sides(4);
        for(int i =0;i<=n-1;i++){
            for(int j =0;j<=n-1;j++){
                for(int k =0;k<=n-1;k++){
                    sides[cube[i][j][k]]++;
                }
            }
        }
        int sums = 0;
        for(int i =0;i<4;i++){
            printf("%d: %d,",i,sides[i]);
            sums += sides[i];
        }
        printf("total: %d\n",sums);
    }
}