#include <bits/stdc++.h>
using namespace std;


bool isint(char c){
    if(c>='0'&&c<='9')return true;
    else return false;
}
int main(){
    string s;
    string k;
    while(getline(cin,k)){
        s += k;
    }
    string a,b;
    for(int i = 0;i<s.size();i++){
        if(isint(s[i])){
            string ss;
            while(i<s.size()&&isint(s[i])){
                ss += s[i];
                i++;
            }
            if(a.size() == 0)a = ss;
            else b = ss;
        }
    }
    cout<<a<<' '<<b<<' '<<stoll(a)+stoll(b);
}
