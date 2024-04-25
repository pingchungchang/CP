#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    multiset<int> st;
    for(int i = 0;i<n;i++){
        cin>>v[i];
        st.insert(v[i]);
    }
    int ans =0;
    sort(v.begin(),v.end());
    for(int i = n-1;i>=0;i--){
        auto it = st.upper_bound(v[i]);
        if(it != st.end()){
            st.erase(it);
            ans++;
        }
    }
    cout<<ans;
}
