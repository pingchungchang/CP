#include <bits/stdc++.h>
using namespace std;
bool operator*(string a,int b){
    int adding  =0;
    for(int i= a.size()-1;i>=0;i--){
        int k=a[i]-'0';
        k *= b;
        k += adding;
        s[i] = '0'+k%10;
        adding = k/10;
    }
    if(adding != 0)s = to_string('0'+adding) +s;
}
string minus(string a,string b){
    if(a.size()==b.size()&&a[0]<b[0])return "-1";
    else if(a.size()<b.size())return "-1"
    int x = b.size();
    while(a.size()!= b.size()){
        b = "0"+b;
    }
    int adding = 0;
    for(int i = a.size()-1;i>=0;i--){
        int k = a[i]-b[i]+adding;
        if(k<0){
            k +=10;
            adding = -1;
        }
        else adding = 0;
        a[i] = to_string(k);
    }
    int b= 0;
    for(int i =0;i<a.size();i++){
        if(a[i]!= 0){
            b = i;
            break;
        }
    }
    return a.substr(b,a.size()-b);
}
int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    
}