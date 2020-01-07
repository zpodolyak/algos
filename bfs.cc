#include <iostream>
#include <vector>
#include <queue>

bool bfs(std::vector<std::vector<int>>&& puzzle) {
    int whites = 0;
    auto s = puzzle.size();
    bool visited[s][s];
    for(int i=0; i<s; ++i)
        for(int j=0; j<s; ++j)
            if(puzzle[i][j]==0)
                ++whites, visited[i][j]=false;

    std::queue<std::pair<int, int>> q;
    for(int i=0; i<s; ++i)
        for(int j=0; j<s; ++j)
            if(puzzle[i][j]==0) {
                q.push(std::make_pair(i, j));
                visited[i][j] = true;
                while(!q.empty()) {
                    auto newItem = q.front();
                    q.pop();
                    int x = newItem.first, y = newItem.second;
                    --whites;
                    if(x+1 < s && !visited[x+1][y] && puzzle[x+1][y]==0) {
                        visited[x+1][y] = true;
                        q.push(std::make_pair(x+1, y));
                    }
                    if(y+1 < s && !visited[x][y+1] && puzzle[x][y+1]==0) {
                        visited[x][y+1] = true;
                        q.push(std::make_pair(x, y+1));
                    }
                    if(x-1 >= 0 && !visited[x-1][y] && puzzle[x-1][y]==0) {
                        visited[x-1][y] = true;
                        q.push(std::make_pair(x-1, y));
                    }
                    if(y-1 >= 0 && !visited[x][y-1] && puzzle[x][y-1]==0) {
                        visited[x][y-1] = true;
                        q.push(std::make_pair(x, y-1));
                    }
                }
                return (whites == 0);
            }
    return (whites == 0);
}

int main(){
    std::cout << bfs(std::vector<std::vector<int>>({std::vector<int>{0,1,0},std::vector<int>{0,0,0},std::vector<int>{0,1,0}})) << '\n';
    return 0;
}