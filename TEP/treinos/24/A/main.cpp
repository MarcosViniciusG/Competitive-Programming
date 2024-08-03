#include <bits/stdc++.h>

using namespace std;

string convert_to_bin(int n)
{
    string bin="";
    for(int i=7; i>= 0; i--)
    {
        int value = (pow(2, i) - 1);
        if(n <= value)
        {
            n -= value;
            bin += "1";
        }
        else
            bin += "0";

    }

    return bin;
}

int convert_to_10(string bin)
{
    int n
}

int main()
{
    int A, B;
    cin >> A >> B;



    return 0;
}