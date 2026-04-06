#include <bits/stdc++.h>



int preX[4] = {-1,1,0,0};
int preY[4] = {0,0,-1,1};

int n;
int city;

int map[2001][2001];
int country[100001];

std::queue<std::pair<int,int>> points;

int find_country(int k) {
    if(country[k] == k) return k;
    return country[k] = find_country(country[k]);
}


int time_go() {
    int year = 1;
    while(!points.empty()) {

        int queue_size = points.size();
        while(queue_size--) {
                
            int x = points.front().first;
            int y = points.front().second;
            points.pop();

            for(int i = 0;i<4;i++) {
                int curX = x+preX[i];
                int curY = y+preY[i];

                if(curX <= 0 or curY <= 0 or curX > n or curY > n) continue;
                if(map[curX][curY] != 0) continue;

                map[curX][curY] = map[x][y];
                points.push({curX,curY});
                
                for(int j = 0;j<4;j++) {
                    int furX = curX+preX[j];
                    int furY = curY+preY[j];

                    if(furX <= 0 or furY <= 0 or furX > n or furY > n) continue;
                    if(map[furX][furY] == 0) continue;
                    if(find_country(map[furX][furY]) == find_country(map[x][y])) continue;

                    country[find_country(map[x][y])] = find_country(map[furX][furY]); 
                    city -= 1;
                    if(city == 1) {
                        return year;
                    }
                }
            }

        }
        year += 1;

    }
}



int main() {
    int k;
    scanf("%d %d",&n,&k);
    city = k;

    for(int i = 1;i<=k;i++) {
        int a,b;
        scanf("%d %d",&a,&b);

        map[a][b] = i;
        country[i] = i;

        points.push({a,b});

        for(int j = 0;j<4;j++) {
            int curX = preX[j]+a;
            int curY = preY[j]+b;
            if(curX <= 0 or curY <= 0 or curX > n or curY > n) continue;
            if(map[curX][curY] != 0) {
                if(find_country(map[a][b]) == find_country(map[curX][curY])) continue;
                country[find_country(map[a][b])] = find_country(map[curX][curY]);
                city -= 1;
            }
        }
    }

    if(city == 1) {
        printf("0\n");
        return 0;
    }
    printf("%d",time_go());


    return 0;
}