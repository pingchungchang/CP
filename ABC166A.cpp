#include <bits/stdc++.h>
using namespace std;

int main(){
    set<string>st;
    st.insert("ABC");
    st.insert("ARC");
    string s;
    cin>>s;
    st.erase(s);
    cout<<*st.begin();
}
