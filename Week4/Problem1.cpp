// Find the character having maximum occurence if all characters occurs once then report it

#include<bits/stdc++.h>

using namespace std;

void solve(void){

    int n;

    cin>>n;

    string s;

    cin>>s;

    int arr[26]={0};

    for(int i=0;i<n;++i){
        arr[s[i]-'a']++;
    }


    int mx=0;

    for(int i=0;i<26;++i){

        if(arr[i]>arr[mx]){
            mx=i;
        }
    }

    if(arr[mx]==1){
        cout<<"NO duplicates found\n";
    }
    else{

        cout<<(char)('a'+mx)<<' '<<arr[mx]<<'\n';
    }
}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int test_cases;

    cin>>test_cases;

    while(test_cases--){
        solve();
    }
}
