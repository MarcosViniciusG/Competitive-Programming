#include <bits/stdc++.h>

using namespace std;
int main()
{
    stack<int> s;
    s.push(1);
    s.push(4);
    s.push(3);
    
    cout << s.size() << endl;

    s.pop();

    cout << s.size() << endl << s.top() << endl;
}