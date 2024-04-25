#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        int a = 0;
        int b = 0;
        for(int j = 0;j<s1.size();j++){
            a = a<<1;
            if(s1[j] == '1') a+=1;
        }
        for(int j = 0;j<s2.size();j++){
            b = b<<1;
            if(s2[j] == '1') b+=1;
        }
        while(a>1&&b>1){
            int x = b;
            b = a%b;
            a=x;
        }
      //  cout<<a<<' '<<b;
        if(a==0||b==0) printf("Pair #%d: All you need is love!\n",i);
        else printf("Pair #%d: Love is not all you need!\n",i);
    }
}
