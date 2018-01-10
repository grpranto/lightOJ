#include<bits/stdc++.h>
#define SIZE 30005
#define ll long long
using namespace std;

ll i, j, x, N, maximum, k;
string arr[SIZE];
vector<pair<ll, ll> >adjList[SIZE];
queue<ll>bfsQueue;

void BFS(ll S);
ll dis[SIZE] = {-1};

int main(){
    ll E, n1, n2, test, c, W, src;
    scanf("%lld", &test);

    for(c=1; c<=test; c++){
        maximum = 0;
        scanf("%lld", &N);

        for(i=0; i<N-1; i++){
            scanf("%lld %lld %lld", &n1, &n2, &W);
            adjList[n1].push_back(make_pair(n2, W));
            adjList[n2].push_back(make_pair(n1, W));
        }

        src = 0;
        BFS(src);
        for(i=0; i<N-1; i++){
            if(dis[src] < dis[i]){
                src = i;
                arr[i] = "WHITE";
            }
        }
        BFS(src);

        printf("Case %lld: %lld\n", c, maximum);

        while(!bfsQueue.empty())
            bfsQueue.pop();

        for(i=0; i<N; i++)
            adjList[i].clear();

    }
    return 0;
}

void BFS(ll S){

    for(j=0; j<N; j++) arr[j] = "WHITE";

    arr[S] = "GREY";
    dis[S] = 0;

    bfsQueue.push(S);
    while(!bfsQueue.empty()){
        x = bfsQueue.front();
        bfsQueue.pop();
        for(j=0; j<adjList[x].size(); j++){
            if(arr[adjList[x][j].first] == "WHITE"){
                bfsQueue.push(adjList[x][j].first);
                arr[adjList[x][j].first] == "GREY";
                dis[adjList[x][j].first] = dis[x]+adjList[x][j].second;

                if(dis[x]+adjList[x][j].second > maximum) maximum = dis[x]+adjList[x][j].second;
            }
            arr[x] = "BLACK";
        }
    }
}
