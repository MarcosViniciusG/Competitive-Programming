#include <bits/stdc++.h>

using namespace std;
int students[5][5];

int main()
{
    int i, j, g;

    for(i=0; i<5; i++) {
        for(j=0; j<5; j++) {
            cin >> g;
            students[i][j] = g;
        }
    }

    vector<int> line = {1, 2, 3, 4, 5};
    int biggest = 0;
    int current;
    int first;
    int second;
    int third;
    int fourth;
    int fifth;
    do
    {
      first = line[0] - 1;
      second = line[1] - 1;
      third = line[2] - 1;
      fourth = line[3] - 1;
      fifth = line[4] - 1;

      current = (students[first][second] + students[second][first] + students[third][fourth] + students[fourth][third]) + (students[second][third] + students[third][second] + students[fourth][fifth] + students[fifth][fourth]) + (students[third][fourth] + students[fourth][third]) + (students[fourth][fifth] + students[fifth][fourth]); 
      biggest = max(current, biggest);
    } while (next_permutation(line.begin(), line.end()));
    
    cout << biggest << endl;
    return 0;
}