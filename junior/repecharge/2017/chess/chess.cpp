#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int m,n,chess[105][105];
int step[4][2]={ {0,-1},{0,1},{-1,0},{1,0} };
int cost[105][105];

void walk(int sx,int sy,int coin,int magic){
        if (coin < cost[sx][sy])
            cost[sx][sy] = coin;
        else
            return ;
            
        for(int i=0;i<4;i++){
            int tx = sx + step[i][0];
            int ty = sy + step[i][1];
            if(tx<=m && ty<=m && tx >=1 && ty >=1){
                if(chess[tx][ty]>0){
                    if(chess[sx][sy]==chess[tx][ty]){
                        walk(tx,ty,coin,0);
                    }else{
                        walk(tx,ty,coin+1,0);
                    }
                }else if(magic==0){
                    chess[tx][ty] = chess[sx][sy];
                    walk(tx,ty,coin+2,1);
                    chess[tx][ty] = 0;
                }
            }
        }

        return;
}

int main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    
    memset(cost,0x7f,sizeof(cost));
    
    int x, y, c;
    cin >> m >> n;
    
    for(int i=1;i<=n;i++){
        cin >> x >> y >> c;
        chess[x][y]=c+1;
    }

    walk(1,1,0,0);
    
    if(cost[m][m]==cost[0][0])
        cout << -1 << endl;
    else
        cout << cost[m][m] << endl;
    
    return 0;
}
