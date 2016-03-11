//pranjalr34

#include<bits/stdc++.h>

#include "../kdtree.h"

using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

void FastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(15);
}

int main() {
    srand(time(NULL));
    FastIO(); 
    
    // Keeps track of all elements in kd-tree 
    VPII vec;
    kdtree *rootaddr = NULL;
    int n, p_x, p_y;
    n = 100;
    for(int i = 0 ; i < n ; i++) {
        p_x = rand() % 1000;
        p_y = rand() % 1000;
        vec.push_back(make_pair(p_x, p_y));
    }
    rootaddr = static_build(rootaddr, vec, 0, 0, n - 1);

    // Uncomment the below part to print the kd-tree (preorder traversal)
    /*
       cout << "tree traversal\n";
       print(rootaddr, 0, 'a');
    */

    kdtree* location_pt = NULL;
    // Look for a random point in kd tree
    p_x = rand() % 1000;
    p_y = rand() % 1000;
    cout << p_x << " " << p_y << "\n";
    location_pt = find_pt(rootaddr, make_pair(p_x, p_y), 0);
    if(location_pt != NULL)
        cout << "Point Found" << "\n";
    else
        cout << "Point not Found" << "\n";

    // Look for a point which is surely in kd tree
    p_x = vec[0].first;
    p_y = vec[0].second;
    cout << p_x << " " << p_y << "\n";
    location_pt = find_pt(rootaddr, make_pair(p_x, p_y), 0);
    if(location_pt != NULL)
        cout << "Point Found" << "\n";
    else
        cout << "Point not Found" << "\n";
    return 0;
}
