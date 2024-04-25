#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll a,b;
    cin>>a>>b;
    ll ans =0;
    while(a!=b){
        ans ++;
        if(a>b)a/=2;
        else{
            b/=2;
        }
    }
    cout<<ans;
}


/*#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll b;
ll ans=INT_MAX;
unordered_map<ll,int> m;

void perm(ll a,ll times){
    m[a] = 1;
    //cout<<a<<' ';
    if(a==b){
        ans = min(ans,times);
        return;
    }
    if(a<b&&m.count(a*2)==0){
        m[a*2] = 1;
        perm(a*2,times+1);
    }
    if(m.count(a/2)==0){
        m[a/2] = 1;
        perm(a/2,times+1);
    }
    if(a<b&&m.count(a*2+1) == 0){
        m[a*2+1] = 1;
        perm(a*2+1,times+1);
    }
    return;
}
int main(){
    ll a;
    cin>>a>>b;
    perm(a,0);
    if(ans == INT_MAX)cout<<-1;
    else cout<<ans;
}
*/
