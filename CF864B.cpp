#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    char pre = '#';
    string ss;
    for(auto i:s){
        if(pre == i)continue;
        ss += i;
        pre = i;
    }
    s = ss;
    int ans = 0;
    set<char> st;
    for(auto i:s){
        if(i>='A'&&i<='Z'){
            st.clear();
        }
        else if(st.find(i) == st.end()){
            st.insert(i);
        }
        ans = max(ans,(int) st.size());
    }
    cout<<ans;
}
