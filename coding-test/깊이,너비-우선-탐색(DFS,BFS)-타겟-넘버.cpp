#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct NodeInfo
{
    int nodeNum = 0;
    int value = 0;
};

// 그래프의 인접 리스트 표현
vector<vector<NodeInfo>> graph;
// 방문한 정점을 체크하는 배열
vector<bool> visited;

void dfs(int node, vector<int>& numbers, vector<int>& path, size_t layers, int& nextNodeNum, int sum, 
    const int& targetNum, int& answer) {
    path.push_back(node);

    if (layers < numbers.size())
    {
        NodeInfo tNode1{};
        tNode1.nodeNum = nextNodeNum;
        tNode1.value = -1;
        graph[node].push_back(tNode1);
        nextNodeNum++;

        NodeInfo tNode2{};
        tNode2.nodeNum = nextNodeNum;
        tNode2.value = 1;
        graph[node].push_back(tNode2);
        nextNodeNum++;
    }

    if (graph[node].size() == 0)
    {
        // 현재 노드를 방문 처리
        visited[node] = true;

        if (sum == targetNum)
        {
            answer++;
        }

        path.pop_back();
        return;
    }
    else
    {
        // 현재 노드와 연결된 모든 노드를 탐색
        for (int i = 0; i < graph[node].size(); i++)
        {
            NodeInfo tNextNode = graph[node][i];
            int nextSum = sum + (tNextNode.value * numbers[layers]);

            if (!visited[tNextNode.nodeNum]) {
                dfs(tNextNode.nodeNum, numbers, path, layers + 1, nextNodeNum, nextSum, targetNum, answer);
            }

            if (i == graph[node].size() - 1)
            {
                visited[node] = true;
                path.pop_back();
            }
        }
    }
}


int solution(vector<int> numbers, int target) {
    int dot = 1; // 정점의 개수
    int num = 1;
    int answer = 0;

    for (int i = 1; i <= numbers.size(); i++)
    {
        dot += num * 2;
        num *= 2;
    }

    graph.resize(dot);
    visited.resize(dot, false);

    vector<int> path;

    int nextNodeNum = 1;
    int sum = 0;

    // DFS 실행
    dfs(0, numbers, path, 0, nextNodeNum, sum, target, answer);

    cout << answer << endl;

    return answer;
}

int main()
{
    vector<int> numbers{4, 1, 2, 1};
    solution(numbers, 4);
}