#include <bits/stdc++.h>
using namespace std;
struct node{
    int value;
    vector<int> befores;
    vector<int> afters;
    int totalvalue;
};
int findlongest(int now,vector<node>& v){
    if(v[now].totalvalue != -1)return v[now].totalvalue;
    int k = 0;
    for(int i = 0;i<v[now].befores.size();i++){
        k = max(k,findlongest(v[now].befores[i],v));
    }
    v[now].totalvalue = k+v[now].value;
    return v[now].totalvalue;
}
int main(){
    int d;
    scanf("%d",&d);
    for(int x = 0;x<d;x++){
        int n;
        scanf("%d",&n);
        vector<node> v(n);
        vector<int> ends;
        for(int i =0;i<n;i++){
            int k;
            int m;
            scanf("%d %d",&k,&m);
            v[i].value = k;
            v[i].totalvalue = -1;
            if(m == 0)ends.push_back(i);
            for(int j =0;j<m;j++){
                scanf("%d",&k);
                v[i].afters.push_back(k-1);
                v[k-1].befores.push_back(i);
            }
        }
        int ans = 0;
        for(int i = 0;i<ends.size();i++){
            ans =max(ans,findlongest(ends[i],v));
        }
        printf("%d",ans);
        if(x != d-1)printf("\n");
    }
}