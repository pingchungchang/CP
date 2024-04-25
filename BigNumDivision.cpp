#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
string multiply(string s, string k){
    for(int i = k.size()-1;i>=0;i--){

    }
}
string minuses(string a,string b){
    while(a.size()!=50){
        a= "0"+a;
    }
    while(b.size() !=50){
        b = "0"+b;
    }
    string ans;
    for(int i =49;i>0;i--){
        if(b[i]>a[i]){
            a[i-1]-=1;
            ans = ('0'+10-b[i]+a[i])+ans;
        }
        else{
            ans = a[i]-b[i];
        }
    }
    if(a[0]<b[0]){
        return "-1";
    }
    else{
        ans = ('0'+a[0]-b[0])+ans;
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    string k;
    cin>>k;
    for(int i =0;i<s.size()-k.size();i++){
    }
}
