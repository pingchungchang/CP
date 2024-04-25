#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    stack<char> st;
    for(int i = 0;i<n;i++){
        if(s[i] == 'x'&&st.size()>=2){
            char c1 = '%',c2 = '#';
            c2 = st.top();
            st.pop();
            c1 = st.top();
            st.pop();
            if(c1 == 'f'&&c2 == 'o'){
                continue;
            }
            else{
                st.push(c1);st.push(c2);st.push(s[i]);
            }
        }
        else{
            st.push(s[i]);
        }
    }
    cout<<st.size();
}
