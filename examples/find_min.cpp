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
    
    kdtree* location_min;
    
    // Look for minimum element in first dimension
    location_min = NULL;
    PII p;
    p.first = INT_MAX;
    p.second = INT_MAX;
    find_min(rootaddr, location_min, 0, 0, p);
    cout << "Element with smallest x value is: ";
    cout << location_min->x << " " << location_min->y << "\n";
    
    // Look for minimum element in second dimension
    location_min = NULL;
    p.first = INT_MAX;
    p.second = INT_MAX;
    find_min(rootaddr, location_min, 1, 0, p);
    cout << "Element with smallest y value is: ";
    cout << location_min->x << " " << location_min->y << "\n";
    return 0;
}
