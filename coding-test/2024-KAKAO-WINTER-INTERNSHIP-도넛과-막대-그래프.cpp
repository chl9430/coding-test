#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct lineInfo
{
    vector<int> line{};
    bool isChecked = false;
};

struct nodeInfo
{
    int num = 0;
    int come = 0;
    int out = 0;
    vector<lineInfo> lineVec;
};

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;

    map<int, nodeInfo> nodeMap;

    nodeInfo rootNode{};

    int stickGraph = 0;
    int donutGraph = 0;
    int eightShapedGraph = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        auto& lineVec = edges[i];

        nodeMap[lineVec[0]].num = lineVec[0];
        nodeMap[lineVec[0]].out += 1;
        nodeMap[lineVec[1]].come += 1;

        lineInfo tLine{};
        tLine.line = lineVec;
        tLine.isChecked = false;

        nodeMap[lineVec[0]].lineVec.push_back(tLine);
    }

    // 정점 찾기
    for (auto& pair : nodeMap)
    {
        if (pair.second.come == 0 && pair.second.out >= 2)
        {
            rootNode = pair.second;
        }
    }

    // 정점을 기준으로 순회
    for (int i = 0; i < rootNode.lineVec.size(); i++)
    {
        auto& lineInfo = rootNode.lineVec[i];
        int firstNodeNum = nodeMap[lineInfo.line[1]].num;

        while (true)
        {
            auto& line = lineInfo.line;

            // 도달한 노드에 나가는 선이 없다면
            if (nodeMap[line[1]].out == 0)
            {
                // 막대 그래프이다.
                stickGraph++;
                break;
            }
            else
            {
                auto& tNode = nodeMap[line[1]];

                // 다음 탐색 선을 정한다.
                for (int j = 0; j < tNode.lineVec.size(); j++)
                {
                    if (tNode.lineVec[j].isChecked == false)
                    {
                        lineInfo = tNode.lineVec[j];
                    }
                }

                auto& tNextNodeInfo = nodeMap[lineInfo.line[1]];

                // 다음 라인의 도착 노드가 8자 그래프의 중간이라면
                if (tNextNodeInfo.come >= 2 && tNextNodeInfo.out == 2)
                {
                    eightShapedGraph++;
                    break;
                }
                
                if (firstNodeNum == tNextNodeInfo.num) // 다음 라인의 도착 노드가 처음 노드와 같다면
                {
                    donutGraph++;
                    break;
                }
            }
        }
    }

    answer.push_back(rootNode.num);
    answer.push_back(donutGraph);
    answer.push_back(stickGraph);
    answer.push_back(eightShapedGraph);

    return answer;
}

int main()
{
    vector<vector<int>> edges{};
    /*vector<int> line1{ 4, 11 };
    vector<int> line2{ 1, 12 };
    vector<int> line3{ 8, 3 };
    vector<int> line4{ 12, 7 };
    vector<int> line5{ 4, 2 };
    vector<int> line6{ 7, 11 };
    vector<int> line7{ 4, 8 };
    vector<int> line8{ 9, 6 };
    vector<int> line9{ 10, 11 };
    vector<int> line10{ 6, 10 };
    vector<int> line11{ 3, 5 };
    vector<int> line12{ 11, 1 };
    vector<int> line13{ 5, 3 };
    vector<int> line14{ 11, 9 };
    vector<int> line15{ 3, 8 };*/
    vector<int> line1{ 2, 3 };
    vector<int> line2{ 4, 3 };
    vector<int> line3{ 1, 1 };
    vector<int> line4{ 2, 1 };

    edges.push_back(line1);
    edges.push_back(line2);
    edges.push_back(line3);
    edges.push_back(line4);

    for (auto& num : solution(edges))
    {
        cout << num << endl;
    }
}