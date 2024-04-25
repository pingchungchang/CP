#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int x = 0;x<n;x++){
        printf("Case %d: ",x+1);
        string s;
        cin>>s;
        for(int i = 0;i<s.size();i++){
            char c = s[i];
            string t;
            for(int j = i+1;j<s.size();j++){
                if(s[j]-'0'>=0&&'9'-s[j]>=0){
                    t +=s[j];
                }
                else break;
            }
            int ten = 1;
            int times = 0;
            for(int j = 0;j<t.size();j++){
                times += ten * (t[t.size()-j-1]-'0');
                ten *=10;
            }
            i += t.size();
            for(int j = 0;j<times;j++){
                cout<<c;
            }
            //cout<<times;
        }
        cout<<endl;
    }
}
