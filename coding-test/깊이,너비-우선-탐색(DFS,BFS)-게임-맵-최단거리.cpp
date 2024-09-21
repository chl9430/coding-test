#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = numeric_limits<int>::max();

bool CheckIndex(vector<vector<int>>& maps, vector<bool>& visitedVec, queue<pair<int, int>>& pointQueue, int nextX, int nextY, int pathCount, int& answer)
{
    int next_node = nextX * maps[0].size() + nextY;

    if (nextX < 0 || nextX > maps.size() - 1 || nextY < 0 || nextY > maps[0].size() - 1
        || visitedVec[next_node] || maps[nextX][nextY] == 0)
    {
        return false;
    }

    if (nextX == maps.size() - 1 && nextY == maps[0].size() - 1)
    {
        answer = pathCount + 1;
        return true;
    }

    pointQueue.push({ next_node, pathCount + 1 });
    return false;
}

int solution(vector<vector<int>> maps) {
    int answer = -1;
    int idxCnt = maps.size() * maps[0].size();
    queue<pair<int, int>> pointQueue;
    vector<bool> visitedVec(idxCnt, false);

    pointQueue.push({ 0, 1 });

    while (!pointQueue.empty()) {
        int current_node = pointQueue.front().first;
        int current_dist = pointQueue.front().second;
        pointQueue.pop();

        int currentX = current_node / maps[0].size();
        int currentY = current_node % maps[0].size();

        if (visitedVec[currentX * maps[0].size() + currentY]) {
            continue;
        }

        visitedVec[currentX * maps[0].size() + currentY] = true;

        // 왼쪽
        if (CheckIndex(maps, visitedVec, pointQueue, currentX, currentY - 1, current_dist, answer))
        {
            return answer;
        }

        // 오른쪽
        if (CheckIndex(maps, visitedVec, pointQueue, currentX, currentY + 1, current_dist, answer))
        {
            return answer;
        }

        // 위쪽
        if (CheckIndex(maps, visitedVec, pointQueue, currentX - 1, currentY, current_dist, answer))
        {
            return answer;
        }

        // 아래쪽
        if (CheckIndex(maps, visitedVec, pointQueue, currentX + 1, currentY, current_dist, answer))
        {
            return answer;
        }
    }

    return answer;
}

int main() {
    vector<std::vector<int>> maps = {
        {1,0,1,1,1},
        {1,0,1,0,1},
        {1,0,1,1,1},
        {1,1,1,0,1},
        {0,0,0,0,1},
    };

    cout << solution(maps) << endl;
    
    return 0;
}