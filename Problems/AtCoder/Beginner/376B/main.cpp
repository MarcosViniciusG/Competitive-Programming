#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    int ti;
    char hi;

    cin >> n >> q;

    int l=1;
    int r=2;
    int op_total=0;    

    for(int i=0; i<q; i++) {

        cin >> hi >> ti;

        int simulation=0;
        int og_simulation=0;
        int other=0;

        int op_simulation=0;
        if(hi=='L') {
            if(l==ti)
                continue;
            og_simulation=l;
            simulation = l;
            other = r;
        }
        else {
            if(r==ti)
                continue;
            og_simulation=r;
            simulation = r;
            other = l;
        }

        bool found=false;
        bool stop=false;
        while (!stop)
        {
            op_simulation++;
            simulation++;
            if(simulation > n) 
                simulation = 1;

            if(simulation==other) {
                stop=true;
            }
                
            if(simulation==ti) {
                stop=true;
                found = true;
            }
        }

        if(!found) {
            if(og_simulation > ti)
                op_simulation = og_simulation-ti;
            else
                op_simulation = (og_simulation-1) + (n-ti+1);
        }
        
        op_total+=op_simulation;

        if(hi=='L')
            l = ti;
        else
            r = ti;
        
    } 

    cout << op_total << endl;
    return 0;
}