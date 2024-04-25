#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "123456789";
    while(next_permutation(s.begin(),s.end())){
        for(int i =1;i<=s.size();i++){
            string x;
            for(int j =0;j<i;j++){
                x +=s[j];
            }
            int k= stoi(x);
            if((k % i) !=0)break;
            else if(i == s.size()) cout<<k;
        }
    }
}