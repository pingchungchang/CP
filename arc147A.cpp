#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
    int n;
    cin>>n;
    multiset<int> st;
    for(int i = 0;i<n;i++){
        int tmp;
        cin>>tmp;
        st.insert(tmp);
    }
    int ans= 0;
    while(st.size()>1){
        ans++;
        int a = *st.begin(),b = *st.rbegin();
        st.erase(st.find(b));
        b %= a;
        if(b != 0)st.insert(b);
    }
    cout<<ans;
}

