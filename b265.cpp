#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        if(n == 0)return 0;
        unordered_map<string,int> strtoint;
        unordered_map<int,vector<string>> inttostr;
        vector<int> v(5,0);
        int biggest = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<5;j++){
                int k;
                cin>>k;
                v[j] = k;
            }
            sort(v.begin(),v.end());
            string s;
            for(int j = 0;j<5;j++){
                s+= to_string(v[j]);
            }
            if(strtoint.count(s) == 0){
                strtoint[s] = 1;
            }
            else{
                strtoint[s]++;
            }
            biggest = max(strtoint[s],biggest);
            inttostr[strtoint[s]].push_back(s);
        }
        printf("%d\n",inttostr[biggest].size()*biggest);
    }
}