#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int times =1;
    cin>>s;
    while(cin>>s){
        printf("Case %d: ",times);
        times++;
        // if(s.size()==1){
        //     if((s[0]-'0')%3==0)cout<<"S\n";
        //     else cout<<"T\n";
        //     continue;
        // }
        vector<int> v(3,0);
        int sum = 0;
        for(int i = 0;i<s.size();i++){
            v[(s[i]-'0')%3]++;
            sum+=s[i]-'0';
        }
        if(v[sum%3]!=0){
            v[sum%3]--;
            if(v[0]%2 == 0){
                cout<<"S\n";
            }
            else cout<<"T\n";
        }
        else{
            cout<<"T\n";
        }

    }
}