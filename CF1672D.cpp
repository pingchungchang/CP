#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> v1(n),v2(n);
    for(int i = 0;i<n;i++)cin>>v1[i];
    for(int i = 0;i<n;i++)cin>>v2[i];
    int p1 = n-1,p2 = n-1;
    multiset<int>st;
    while(p2 != -1&&p1 != -1){
        if(p2 == -1&&st.find(v1[p1]) == st.end()){
            cout<<"NO\n";
            return;
        }
        else if(p2 == -1){
            st.erase(st.find(v1[p1--]));
        }
        else if(v1[p1] == v2[p2]){
            p1--,p2--;
        }
        else if(p2 != n-1&&v2[p2]== v2[p2+1]){
            st.insert(v2[p2--]);
        }
        else if(st.find(v1[p1]) != st.end()){
            st.erase(st.find(v1[p1--]));
        }
        else{
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
