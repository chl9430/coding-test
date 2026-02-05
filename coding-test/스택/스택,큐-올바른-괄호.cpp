#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stack;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            stack.push(s[i]);
        else
        {
            if (stack.empty() == false)
            {
                if (stack.top() == '(')
                {
                    stack.pop();
                    continue;
                }
                else
                    stack.push(s[i]);
            }
            else
                return false;
        }
    }

    if (stack.empty())
        return true;
    else
        return false;
}

int main()
{
    cout << solution("(()(()") << endl;
}