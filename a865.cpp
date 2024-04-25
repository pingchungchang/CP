#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<char,int> m;
    m['A'] = 1;
    m['B'] = 2;
    m['G'] =3;
    m['D']=4;
    m['E']=5;
    m['#']=6;
    m['Z']=7;
    m['Y']=8;
    m['H']=9;
    m['I']=10;
    m['K']=20;
    m['L']=30;
    m['M']=40;
    m['N']=50;
    m['X']=60;
    m['O']=70;
    m['P']=80;
    m['Q']=90;
    m['R']=100;
    m['S']=200;
    m['T']=300;
    m['U']=400;
    m['F']=500;
    m['C']=600;
    m['$']=700;
    m['W']=800;
    m['3']=900; 
    string s;
    while(getline(cin,s)){
        if(s == ".")return 0;
        int ans =0;
        for(int i =0;i<s.size();i++){
            ans += m[s[i]];
        }
        printf("%d\n",ans);
    }
}