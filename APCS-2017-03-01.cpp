#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int sum1=0;
    int sum2=0;
    for(int i =0;i<s.size();i+=2){
        sum1 += s[i]-'0';
    }
    for(int i =1;i<s.size();i+=2){
        sum2 += s[i] -'0';
    }
    int ans = sum1-sum2;
    if(ans<0){
        ans = 0-ans;
    }
    cout<<ans;
}
