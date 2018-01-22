#include<bits/stdc++.h>
#define SIZE 20
using namespace std;

int X[] = {0, 1, -1, 0};
int Y[] = {1, 0, 0, -1};
int row, col, c;
bool visited[SIZE][SIZE];
char arr[SIZE][SIZE];

int dfs(int x, int y);

int main(){
    int T, x, y, i, j;

    scanf("%d", &T);
    for(int z=1; z<=T; z++){
        scanf("%d %d", &col, &row);
        memset(visited, 0, sizeof(visited));

        getchar();
        for(i=0; i<row; i++){
            for(j=0; j<col; j++){
                arr[i][j] = getchar();

                if(arr[i][j] == '@'){
                    x = i;
                    y = j;
                    c = 1;
                    visited[x][y] = true;
                }
            }
            getchar();
        }
        dfs(x, y);
        printf("Case %d: %d\n", z, c);
    }

    return 0;
}

int dfs(int x, int y){
    for(int i=0; i<4; i++){
        if(((x+X[i]>=0 && x+X[i]<row) && (y+Y[i]>=0 && y+Y[i]<col)) && arr[x+X[i]][y+Y[i]]=='.' && visited[x+X[i]][y+Y[i]]==false){
            visited[x+X[i]][y+Y[i]] = true;
            c++;
            dfs(x+X[i], y+Y[i]);
        }
    }
}
