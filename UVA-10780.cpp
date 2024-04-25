#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> factorof(int a){
    unordered_map<int,int> m;
    vector<pair<int,int>> v;
    for(int i =2;i<=sqrt(a);i++){
        if(a%i == 0){
            if(m.count(i) == 0){
                m[i] = v.size();
                v.push_back(make_pair(i,0));
            }
            v[m[i]].second++;
            a = a/i;
            i = 1;
        }
    }
    if(a != 1){
        if(m.count(a) == 0){
            m[a] = v.size();
            v.push_back(make_pair(a,0));
        }
        v[m[a]].second++;
    }
    return v;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        vector<pair<int,int>> fa = factorof(a);
        int biggest = INT_MAX;
        for(int j =0;j<fa.size();j++){
            int k = fa[j].first;
            int now = 0;
            int times =0;
            while(k<=b){
                times++;
                int x = b/k;
                now += x;
                k *= fa[j].first;
            }
            biggest = min(biggest,now/fa[j].second);
        }
        printf("Case %d:\n",i+1);
        if(biggest == 0)printf("Impossible to divide");
        else printf("%d",biggest);
        if(i != n-1)printf("\n");
    }
}