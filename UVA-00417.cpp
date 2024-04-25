#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    string farthest = "a";
    unordered_map<string,int> m;
    m[farthest] = 1;
    while(cin>>s){
        if(m.count(s) == 0){
            string now = farthest;
            while(m.count(s) == 0){
                if(now[now.size()-1] == 'z'){
                    for(int i = now.size()-1;i>=0;i--){

                    }
                }
            }
        }
    }
}//give up