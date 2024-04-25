#include <bits/stdc++.h>
using namespace std;

int main(){
    int b1,b2,b3,g1,g2,g3,c1,c2,c3;
    while(scanf("%d %d %d %d %d %d %d %d %d",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3) != EOF){
        int s = b1+g1+c1+b3+g3+c3+b2+g2+c2;
        int ans = INT_MAX;
        unordered_map<int,string> m;
        m[0] = "B";
        m[1] = "C";
        m[2] = "G";
        int a[3] = {b1,c1,g1};
        string word;
        int b[3] = {b2,c2,g2};
        int c[3] = {b3,c3,g3};
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(j == i)continue;
                for(int k =0;k<3;k++){
                    if(k == j)continue;
                    if(k == i)continue;
                    if(ans>s-a[i]-b[j]-c[k]){
                        ans = s-a[i]-b[j]-c[k];
                        word = m[i]+m[j]+m[k];
                    }
                }
            }
        }
        word +=' ';
        cout<<word<<ans<<"\n";
    }
}