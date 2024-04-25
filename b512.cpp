#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    unordered_map<int,int> v;
    while(scanf("%d:%d",&a,&b)!= EOF){
        if(a == 0&&b==0)break;
        v[a] = b;
    }
    int ans = 0;
    while(scanf("%d:%d",&a,&b)!= EOF){
        if(a == 0&&b==0)break;
        if(v.count(a)!= 0)ans += v[a]*b;
    }
    printf("%d",ans);
}