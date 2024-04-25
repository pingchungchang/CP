#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    int k = 0;
    for(int i =0;i<s.size();i++){
        k += s[i]-'0';
    }
    k*= n;
    s = to_string(k);
    while(s.size() != 1){
        int w = 0;
        for(int i =0;i<s.size();i++){
            w += s[i]-'0';
        }
        s = to_string(w);
    }
    cout<<s;
    return 0;
}
