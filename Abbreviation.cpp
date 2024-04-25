#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
        int p = 0;
        int y = 0;
        for(int j=0;j<s1.size();j++){
            if(p != s2.size()){
                if(s1[j]-'a' == s2[p]-'A'||s1[j] == s2[p]){
                    p++;
                }
                else if(s1[j]-'a'<0){
                    p = -1;
                    break;
                }
            }
            else{
                if(s1[j] - 'a'<0){
                    p = -1;
                    break;
                }
            }
        }
        if(p == s2.size()){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}
