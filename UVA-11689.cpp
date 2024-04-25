#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int ans = 0;
        int bottles = a+b;
        while(bottles>=c){
            ans += bottles/c;
            bottles = bottles/c+bottles%c;
        }
        cout<<ans<<endl;
    }
}
