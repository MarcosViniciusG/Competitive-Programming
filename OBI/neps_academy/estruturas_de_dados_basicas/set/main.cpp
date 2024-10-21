#include <bits/stdc++.h>

using namespace std;
int main()
{
    set<int> st;
    st.insert(9);
    st.insert(10);
    st.insert(4);
    st.insert(6);
    st.insert(9);

    auto ptr = st.begin();
    cout << *ptr << endl;

    ptr = st.end();
    ptr--;
    cout << *ptr << endl;

    cout << st.size() << endl;

    ptr--;
    st.erase(10);
    st.erase(1010);

    if(st.find(10) != st.end())
        cout << "Existe" << endl;
    else 
        cout << "Não existe" << endl;

    cout << *ptr << endl;

    cout << st.size() << endl;

    st.clear();

    cout << st.size() << endl;
    return 0;
}