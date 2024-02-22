#include <bits/stdc++.h>

using namespace std;
int main()
{
    string summation;
    string new_s = "";
    map<char, int> nums;
    nums['1'] = 0;
    nums['2'] = 0;
    nums['3'] = 0;
    getline(cin, summation);
    for(auto c: summation)
    {
        if(c=='1' || c=='2' || c=='3') nums[c]++;
    }

    auto ptr = nums.begin();
    while (ptr!= nums.end())
    {
        int n = ptr->second;
        for(int i=0; i<n; i++)
        {
            new_s += ptr->first;
            new_s += '+';
        }
        ptr++;
    }
    new_s.erase(new_s.size() - 1);

    cout << new_s << endl;

    return 0;
}