#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> v;
    v.insert('a');v.insert('e');v.insert('i');v.insert('o');v.insert('u');
    string s;
    cin>>s;
    char pre = 'n';
    for(int i = 0;i<s.size();i++){
        if(pre == 'n'){
            pre = s[i];
            continue;
        }
        else if(v.find(s[i]) == v.end()&&v.find(pre) == v.end()){
            cout<<"NO\n";
            return 0;
        }
        else{
            pre = s[i];
            continue;
        }
    }
    if(*s.rbegin() != 'n'&&v.find(*s.rbegin()) == v.end()){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    return 0;
}
