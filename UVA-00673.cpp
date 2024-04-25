#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin.ignore();
    getline(cin,s);
    while(getline(cin,s)){
        int done = 0;
        stack<char> frontpars;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '('||s[i]== '['||s[i] == '{'){
                frontpars.push(s[i]);
            }
            else if(frontpars.empty()){
                done = 1;
                break;
            }
            else if(frontpars.top()== '('&&s[i] == ')'){
                frontpars.pop();
            }
            else if(frontpars.top()== '['&&s[i] == ']'){
                frontpars.pop();
            }
            else if(frontpars.top()== '{'&&s[i] == '}'){
                frontpars.pop();
            }
            else{
                done = 1;
                break;
            }
        }
        if(!frontpars.empty()) done = 1;
        if(s.size()==0) done = 0;
        if(done == 1)cout<<"No\n";
        else cout<<"Yes\n";
    }

}