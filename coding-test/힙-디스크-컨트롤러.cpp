#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        if (a[1] != b[1]) {
            return a[1] > b[1];
        }
        return a[0] > b[0];
    }
};

int solution(vector<vector<int>> jobs)
{
    sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
        });

    int curTime = jobs[0][0];
    int totalTime = 0;
    int jobCnt = jobs.size();
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

    while (1)
    {
        for (auto it = jobs.begin(); it != jobs.end(); )
        {
            if (curTime >= (*it)[0])
            {
                pq.push(*it);
                it = jobs.erase(it);
            }
            else
                it++;
        }

        if (pq.empty() && jobs.size() > 0)
        {
            pq.push(jobs[0]);
            curTime = jobs[0][0];
            jobs.erase(jobs.begin());
        }

        vector<int> job = pq.top();

        curTime += job[1];
        totalTime += (curTime - job[0]);

        pq.pop();

        if (pq.empty() && jobs.size() == 0)
            break;
    }

    return totalTime / jobCnt;
}

int main()
{
    vector<vector<int>> jobs = {
        {0, 3},
        {1, 9},
        {30, 5},
    };

    cout << solution(jobs) << endl;

    return 0;
}