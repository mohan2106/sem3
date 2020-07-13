#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long li;
#define forz(n) for (long i = 0; i < n; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
#define inf 99999
struct edges{
    int e,u,v;
};

bool comp(edges a,edges b){
    return a.e < b.e;
}
int root(int v,vector<int> &parent)
{
    if(v == parent[v]){
        return v;
    }
    return parent[v] = root(parent[v],parent);
    
}

// void union1(int x, int y,vector<int> &id)
// {
//     int p = root(x,id);
//     int q = root(y,id);
//     id[p] = id[q];
// }

void union_set(int x,int y,vector<int> &parent,vector<int> &rank){
    int x = root(x,parent);
    int y = root(y,parent);
    if(x != y){
        if(rank[x]<rank[y]){
            swap(x,y);
        }
        parent[y] = x;
        if(rank[x] == rank[y]){
            rank[x]++;
        }
    }
}
int kruskals(vector<edges> graph,vector<int> vis,vector<int> &id,vector<int> &rank){
    // vector<edges> res;
    int res=0;
    for(edges x:graph){
        int e = x.e;
        int u = x.u;
        int v = x.v;
        // if(vis[u] && vis[v]) continue;
        if(root(u,id)!=root(v,id)){
            vis[u] = 1;
            vis[v] = 1; 
            union_set(u,v,id,rank);
            // res.push_back(x);
            res+=e;
        }
        
    }
    // bool connected=true;
    // for(int i=1;i<vis.size();i++){
    //     if(vis[i]==0){
    //         connected = false;
    //         break;
    //     }
    // // }
    // if(true){
    //     return res;
    // }
    // vector<edges> nl;
    // return nl;
    return res;
}

int main(){
    int n,m;
    cin>>n>>m;
    // map<int,pair<int,int>> graph;
    vector<int> vis(n+1,0);
    vector<edges> graph;
    int e,u,v;
    while(m--){
        cin>>u>>v;
        graph.push_back({1,u,v});
    }
    sort(graph.begin(),graph.end(),comp);
    vector<int> id(n+1),rank(n+1,0);
    forz(n) id[i] = i;

    int res = kruskals(graph,vis,id,rank);
    cout<<res<<'\n';
    // if(res.size()>0){
    //     cout<<"edges: vertex(u,v)\n";
    //     for(edges x:res){
    //         cout<<x.e<<"     ( "<<x.u<<" , "<<x.v<<" )"<<'\n';
    //     }
    // }else{
    //     cout<<"Disconnected graph\n";
    // }
    return 0;
}