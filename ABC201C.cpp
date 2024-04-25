#include <bits/stdc++.h>
using namespace std;


string tmp;
int main(){
    string s;
    cin>>s;
    int ans = 0;
    for(char i = '0';i<='9';i++){
        for(char j = '0';j<='9';j++){
            for(char k = '0';k<='9';k++){
                for(char l = '0';l<='9';l++){
                    set<char> st;
                    st.insert(i);st.insert(j);st.insert(l);st.insert(k);
                    bool flag = true;
                    for(int t = 0;t<10;t++){
                        if(s[t] == 'o'&&st.find('0'+t) == st.end())flag = false;
                        if(s[t] == 'x'&&st.find('0'+t) != st.end())flag = false;
                    }
                    if(flag)ans++;
                }
            }
        }
    }
    cout<<ans;
}