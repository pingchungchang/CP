#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d\n",&n);
    string wh;
    getline(cin,wh);
    for(int i = 0;i<n;i++){
        int arr[5] = {0};
        int poison = 0;
        int effects = 0;
        int now;
        scanf("%d %d %d %d %d %d\n",&arr[1],&arr[2],&arr[3],&arr[4],&poison,&now);
        string s;
        int done = 0;
        arr[3] = -arr[3];
        arr[4] = -arr[4];
        getline(cin,wh);
        getline(cin,s);
        for(int j = 0;j<s.size();j+=2){
            int k = s[j]-'0';
            now -= effects;
            now += arr[k];
            if(now<=0) {
                done = 1;
                break;
            }
            if(k == 4) effects += poison;
        }
        if(done == 1)cout<<"bye~Rabbit\n";
        else cout<<now<<"g\n";
    }
}
