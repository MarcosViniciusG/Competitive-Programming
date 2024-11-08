#include <bits/stdc++.h>

using namespace std;
int main()
{
    int result=0;
    string str1, str2;

    cin >> str1;
    cin.ignore(1, '\n');
    cin >> str2;

    for(int i=0; i<str1.size() && result==0; i++)
    {
        if(tolower(str1[i]) > tolower(str2[i])) result = 1;
        if(tolower(str1[i]) < tolower(str2[i])) result = -1;
    
    }

    cout << result << endl;

    return 0;
}