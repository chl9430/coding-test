#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int width = 0;
    int height = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
    }

    for (int i = 0; i < sizes.size(); i++)
    {
        if (width < sizes[i][0])
        {
            width = sizes[i][0];
        }

        if (height < sizes[i][1])
        {
            height = sizes[i][1];
        }
    }

    answer = width * height;

    return answer;
}

int main()
{
    vector<vector<int>> sizes;

    /*sizes.push_back({ 60, 50 });
    sizes.push_back({ 30, 70 });
    sizes.push_back({ 60, 30 });
    sizes.push_back({ 80, 40 });*/

    /*sizes.push_back({ 10, 7 });
    sizes.push_back({ 12, 3 });
    sizes.push_back({ 8, 15 });
    sizes.push_back({ 14, 7 });
    sizes.push_back({ 5, 15 });*/

    sizes.push_back({ 14, 4 });
    sizes.push_back({ 19, 6 });
    sizes.push_back({ 6, 16 });
    sizes.push_back({ 18, 7 });
    sizes.push_back({ 7, 11 });

    cout << solution(sizes) << endl;
}