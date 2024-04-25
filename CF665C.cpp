#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    string alpha = "abcde";
    for(int i =1;i<s.size();i++){
        if(s[i] == s[i-1]){
            if(i == s.size()-1){
                if(s[i-1] == 'a')s[i] = 'b';
                else s[i] = 'a';
            }
            for(int j =0;j<5;j++){
                if(alpha[j]!= s[i-1]&&alpha[j]!= s[i+1])s[i] = alpha[j];
            }
        }
    }
    cout<<s;
}
