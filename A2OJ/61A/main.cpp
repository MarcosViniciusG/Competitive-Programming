#include <bits/stdc++.h>

using namespace std;
int main()
{
    string n1, n2, answer;
    cin >> n1;
    cin.ignore(1, '\n');
    cin >> n2;
    answer.append(n1.size(), '0');
    for(int i=0; i<n1.size(); i++)
    {
        if(n1[i]==n2[i]) answer[i]= '0';
        else answer[i] = '1';
    }

    cout << answer << endl;
    return 0;
}