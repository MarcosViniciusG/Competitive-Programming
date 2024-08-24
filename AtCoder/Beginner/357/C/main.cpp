#include <bits/stdc++.h>

using namespace std;

int threepow(int k) {
    int p3=1;

    for(int i=0; i<k; i++) {
        p3*=3;
    }

    return p3;
}

void build(vector<string> &s, int k, int starti, int endi, int startj, int endj) {
    if(k==0) {
        s[starti][startj] = '#';
        return;
    }
    else {
        int sm = threepow(k-1);

        for(int i=starti; i<endi; i+=sm) {
            for(int j=startj; j<endj; j+=sm) {
                if(i==(sm+starti)  && j==(sm+startj)) {
                    for(int k=i; k<(i+sm); k++) {
                        for(int w=j; w<(j+sm); w++) {
                            s[k][w]='.';
                        }
                    }
                }
                else {
                    build(s, k-1, i, i+sm, j, j+sm);
                }
            }
        }
    }

}

int main() {
    int n;
    cin >> n;

    vector<string> s;
    int k = threepow(n);

    for(int i=0; i<k; i++) {
        string si="";

        for(int j=0; j<k; j++) {
            si+='#';
        }

        s.push_back(si);
    }


    build(s, n, 0, k, 0, k);

    for(int i=0; i<k; i++) {
        cout << s[i] << endl;
    }

    return 0;
}