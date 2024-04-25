#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int formers = 0;
        int times = 0;
        string s;
        cin>>s;
        for(int j = 0;j<s.size();j++){
            if(s[j] == '(') formers++;
            if(s[j] == ')'){
                if(formers <=0){
                    times = 0;
                    break;
                }
                else{
                    times ++;
                    formers --;
                }
            }
        }
        if(formers != 0){
            times = 0;
        }
        cout<<times<<endl;
    }
}
