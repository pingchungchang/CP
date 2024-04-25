#include <bits/stdc++.h>
using namespace std;

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> v(n+2,0),rev(n+2,0);
    for(int i = 1;i<=n;i++){
        cin>>v[i];
        rev[v[i]] = i;
    }
    v[n+1] = n+1;
    rev[n+1] = n+1;
    int ans = 1;
    for(int i = 1;i<=n;i++){
        if(rev[i]<rev[i-1])ans++;
    }
    //for(auto it:rev)cout<<it<<' ';cout<<endl;
    for(int i = 0;i<q;i++){
        int a,b;
        cin>>a>>b;
        int aa = v[a];
        int bb = v[b];
        if(aa>bb)swap(aa,bb);
        if(rev[aa]>rev[aa+1])ans--;
        if(rev[aa-1]>rev[aa])ans--;
        if(rev[bb]>rev[bb+1])ans--;
        if(bb-aa!= 1&&rev[bb-1]>rev[bb])ans--;
        //cout<<aa<<' '<<bb<<' '<<ans<<endl;
        swap(v[a],v[b]);
        swap(rev[aa],rev[bb]);
        if(aa>bb)swap(aa,bb);
        if(rev[aa]>rev[aa+1])ans++;
        if(rev[aa-1]>rev[aa])ans++;
        if(rev[bb]>rev[bb+1])ans++;
        if(bb-aa!= 1&&rev[bb-1]>rev[bb])ans++;
        //for(auto it:v)cout<<it<<' ';cout<<endl;
        //for(auto it:rev)cout<<it<<' ';cout<<endl;
        cout<<ans<<'\n';
    }
    return 0;
}

/*

5 3
4 2 1 5 3
2 3
1 5
2 3

20 200000
14 2 3 10 8 9 1 19 4 15 5 17 13 16 7 11 6 12 18 20
13 13
10 1
12 20
4 15
8 6
11 20
15 20
9 7
18 3
17 20
19 2
3 14
20 2
1 7
7 4
10 7
15 19
11 1
20 11
14 19
*/
