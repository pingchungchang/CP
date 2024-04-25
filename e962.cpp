#include <unordered_map>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    unordered_map<char,double> m;
    m['T'] = 1;
    m['U'] = 30.9;
    m['J'] = 0.28;
    m['E'] = 34.5;
    char c;
    double budget;
    int num;
    cin>>budget>>num>>c;
    budget/=m[c];
    budget -= num;
    if(budget<0)cout<<"No Money";
    else if(budget<0.05)cout<<c<<' '<<"0.00";
    else cout<<c<<' '<<fixed<<setprecision(2)<<budget;
}
