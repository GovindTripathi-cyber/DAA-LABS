// Path finding between 2 vertices usibg BFS and DFS

#include<bits/stdc++.h>

using namespace std;


bool dfs(int src,int destination,vector<bool>&visited,vector<vector<int>>&adjacency_matrix){

    int n = adjacency_matrix.size();

    visited[src]=true;

    if(src==destination){
        return true;
    }

    bool isexist=false;

    for(int i=0;i<n;++i){

        if(adjacency_matrix[src][i] && !visited[i]){

            isexist|=dfs(i,destination,visited,adjacency_matrix);
        }
    }

    return isexist;
}


bool bfs(int src,int destination,vector<bool>&visited,vector<vector<int>>&adjacency_matrix){

    int n = adjacency_matrix.size();

    queue<int>q;

    q.push(src);

    visited[src]=true;

    while(!q.empty()){

        int v = q.front();

        q.pop();


        for(int i=0;i<n;++i){

            if(adjacency_matrix[v][i] && !visited[i]){

                visited[i]=true;

                q.push(i);
            }
        }
    }


    return visited[destination];


}


void solve(){

    int n;

    cin>>n;

    vector<vector<int>>adjacency_matrix(n,vector<int>(n));


    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>adjacency_matrix[i][j];
        }
    }

    int source,destination;

    cin>>source>>destination;


    vector<bool>visited(n,false);

    --source;

    --destination;

    if(dfs(source,destination,visited,adjacency_matrix)){
        cout<<"Path existed by dfs\n";
    }
    else{
        cout<<"Path not existed by dfs\n";
    }


    for(int i=0;i<n;++i){

        visited[i]=false;
    }



    if(bfs(source,destination,visited,adjacency_matrix)){
        cout<<"Path existed by bfs\n";
    }
    else{
        cout<<"Path not existed by bfs\n";
    }


}

int  main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int test_cases;

    cin>>test_cases;

    while(test_cases--){
        solve();
    }
}
