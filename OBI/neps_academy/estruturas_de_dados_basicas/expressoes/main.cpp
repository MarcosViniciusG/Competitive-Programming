#include <bits/stdc++.h>

using namespace std;
int main()
{
    int T;
    cin >> T;
    cin.ignore(1, '\n');
    string cadeia;
    stack<char> s;
    for (int i = 0; i < T; i++)
    {

        getline(cin, cadeia);
        for (auto c : cadeia)
        {
            if (c == '(')
                s.push(c);
            else if (c == '[')
                s.push(c);
            else if (c == '{')
                s.push(c);

            if (c == ')')
            {
                if (s.size() != 0 && s.top() == '(')
                    s.pop();
                else
                    s.push(c);
            }
            else if (c == ']')
            {
                if (s.size() != 0 && s.top() == '[')
                    s.pop();
                else
                    s.push(c);
            }
            else if (c == '}')
            {
                if (s.size() != 0 && s.top() == '{')
                    s.pop();
                else
                    s.push(c);
            }
        }

        if (s.size() != 0)
            cout << "N\n";
        else
            cout << "S\n";

        // Limpa a stack
        while (s.size() != 0)
        {
            s.pop();
        }
    }

    return 0;
}