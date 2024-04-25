#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    for(int i = 0;i<n;i++){
        cin>>s;
        sort(s.begin(),s.end());
        cout<<s<<endl;
        while(next_permutation(s.begin(),s.end())){
            cout<<s<<endl;
        }
        cout<<endl;
    }
}