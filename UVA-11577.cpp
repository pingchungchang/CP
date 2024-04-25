#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    getline(cin,a);
    int times = stoi(a);
    for(int i =0;i<times;i++){
        string s;
        getline(cin,s);
        unordered_map<char,int> m;
        unordered_map<int,string> t;
        int biggest = 0;
        for(int j =0;j<s.size();j++){
            if(s[j]>'z'||s[j]<'A'||(s[j]>'Z'&&s[j]<'a'))continue;
            if(s[j]<'a')s[j] = (char)(s[j]-'A'+'a');
            if(m.count(s[j]) ==0){
                m[s[j]] = 0;
            }
            m[s[j]]++;
            t[m[s[j]]]+=s[j];
            biggest = max(biggest,m[s[j]]);
        }
        sort(t[biggest].begin(),t[biggest].end());
        cout<<t[biggest];
        if(i != times-1)cout<<endl;
    }
}