#include <iostream>
using namespace std;

const int n=7;
int g[n+2][n+2];
string p;
int total;

void search(int y, int x, int c){
    if (g[y][x]){
        return;
    }
    if (y==n && x==1){
        if (c==n*n){
            total++;
        }
        return;
    }
    bool down=g[y+1][x];
    bool up=g[y-1][x];
    bool left=g[y][x-1];
    bool right=g[y][x+1];
    if (down && up && !left && !right){
        return;
    }
    if (!down && !up && left && right){
        return;
    }

    char d=p[c-1];
    g[y][x]=1;
    if (d=='?' || d=='D'){
        search(y+1,x,c + 1);
    }
    if (d=='?' || d=='U'){
        search(y-1,x,c+1);
    }
    if (d=='?' || d=='L'){
        search(y,x-1,c+1);
    }
    if (d=='?' || d=='R'){
        search(y,x+1,c+1);
    }
    g[y][x]=0;
}

int main(){
    for (int i=0; i<=n+1; i++){
        g[0][i] = g[n + 1][i] = 1;
        g[i][0] = g[i][n + 1] = 1;
    }

    cin >> p;
    search(1,1,1);
    cout << total << endl;
}