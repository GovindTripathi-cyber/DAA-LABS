// Problem Statement: Given a sorted array of positive integers, design an algorithm and implement it using a program
// to find three indices i, j, k such that arr[i] + arr[j] = arr[k].

//Approach : 2pointer

// Time Complexity : O(N*N)

// Space Complexity : O(1)



#include<bits/stdc++.h>

using namespace std;


void solve(){

    int n;

    cin>>n;


    vector<int>v(n);


    for(int i=0;i<n;++i){
        cin>>v[i];
    }



    for(int i=n-1;i>=2;--i){

        int left=0,right=i-1;


        while(left<right){

            if(v[left]+v[right]==v[i]){

                cout<<left+1<<' '<<right+1<<' '<<i+1<<'\n';

                return;
            }

            else if(v[left]+v[right]>v[i]){
                --right;
            }
            else{
                ++left;
            }
        }
    }

    cout<<"Sequence Not Found\n";


}

int main(){



    freopen("input2.txt","r",stdin);
    freopen("output2.txt","w",stdout);


    int test_cases;

    cin>>test_cases;

    while(test_cases--){

        solve();
    }
}
