#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, unordered_map<string, int>> friendsMap;
    string friendName;

    for (auto& name : friends)
    {
        friendsMap[name]["point"] = 0;
    }

    for (auto& history : gifts)
    {
        std::istringstream iss(history);
        vector<string> historyVec;

        // ���ڿ��� ���� �������� ������.
        while (iss >> friendName) {
            historyVec.push_back(friendName);
        }

        // ���� ����
        friendsMap[historyVec[0]]["point"] += 1;
        friendsMap[historyVec[1]]["point"] -= 1;

        // ���� ���� �����丮
        friendsMap[historyVec[0]][historyVec[1]] += 1;
    }

    for (auto& pair : friendsMap)
    {
        int total = 0;
        auto& firstName = pair.first;

        for (auto& pair : friendsMap)
        {
            auto& secondName = pair.first;

            if (firstName == secondName)
                continue;

            // ���� ���� �ְ���� ���� ���ٸ�
            if (friendsMap[firstName].find(secondName) == friendsMap[firstName].end()
                && friendsMap[secondName].find(firstName) == friendsMap[secondName].end())
            {
                if (friendsMap[firstName]["point"] > friendsMap[secondName]["point"])
                {
                    total += 1;
                }
            }
            else // ���� �ְ���� ���� �ִٸ�
            {
                if (friendsMap[firstName][secondName] > friendsMap[secondName][firstName])
                {
                    total += 1;
                }
                else if (friendsMap[firstName][secondName] == friendsMap[secondName][firstName])
                {
                    if (friendsMap[firstName]["point"] > friendsMap[secondName]["point"])
                    {
                        total += 1;
                    }
                }
            }
        }

        friendsMap[firstName]["total"] = total;
    }

    for (auto& pair : friendsMap)
    {
        if (answer < pair.second["total"])
        {
            answer = pair.second["total"];
        }
    }

    return answer;
}

int main()
{
    vector<string> friends{ "muzi", "ryan", "frodo", "neo" };
    vector<string> gifts{ "muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi" };

    cout << solution(friends, gifts) << endl;
}