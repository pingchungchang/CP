#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        string original = s;
        int times = 0;
        int done = 0;
        while(times<=100){
            int nowsum = 0;
            for(int i = 0;i<s.size();i++){
                nowsum += (s[i]-'0')*(s[i]-'0');
            }
            if(nowsum == 1){
                done = 1;
                cout<<original<<" is a happy number\n";
                break;
            }
            s = to_string(nowsum);
            times++;
        }
        if(done == 0)cout<<original<<" is an unhappy number\n";
    }
}