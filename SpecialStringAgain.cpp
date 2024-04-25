#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a;
    string s;
    int ans = 0;
    cin>>a>>s;
    vector<int> l;
    vector<int> c;
    l.push_back(1);
    c.push_back(s[0]);
    for(int i =1;i<s.size();i++){
        if(s[i] == s[i-1]){
            l[l.size()-1] ++;
        }
        else{
            l.push_back(1);
            c.push_back(s[i]);
    //        cout<<"in else"<<endl;
        }
    }
    for(int i =0;i<l.size();i++){
        ans += ((l[i]+1)*l[i]) /2;
        //cout<<((l[i]+1)*l[i]) /2<<endl;
    }
    for(int i =1;i<l.size()-1;i++){
        if(l[i] == 1 &&c[i-1] == c[i+1]){
            ans += min(l[i-1],l[i+1]);
        }
    }
    cout<<ans;
    return 0;
}

