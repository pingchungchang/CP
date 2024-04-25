#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        if(s == "-1") return 0;
        string ans;
        if(s.size()<=2||s[1]!='x'){
            int n = stoi(s);
            while(n>0){
                int temp = 0;
                int twos = 1;
                for(int i = 0;i<4;i++){
                    if(n&1)temp += twos;
                    twos*=2;
                    n=n>>1;
                }
                if(temp>=10) ans = (char)('A'+temp-10)+ans;
                else ans = (char)('0'+temp)+ans;
            }
            cout<<"0x"<<ans<<endl;
        }
        else{
            int n = 0;
            int sixteens = 1;
            for(int i = s.size()-1;i>=2;i--){
                if(s[i]>='A'&&s[i]<='H'){
                    n += (s[i]-'A'+10)*sixteens;
                }
                else{
                    n += (s[i]-'0')*sixteens;
                }
                sixteens *=16;
            }
            cout<<n<<endl;
        }

    }
}