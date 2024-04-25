#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int spaces = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i]==' ')spaces++;
        else if(s[i] != '\t'){
            if(spaces&1)printf(" ");
            printf("%c",s[i]);
            spaces = 0;
        }
        else if(s[i] == '\t')printf("\t");
    }
    return 0;
}
//failed