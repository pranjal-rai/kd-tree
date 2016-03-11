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

int main()
{
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
    kdtree *location_closest;
    int min_dist;
    p_x = 1;
    p_y = 1;
    location_closest = NULL;
    min_dist = INT_MAX;
    nearest_neighbour(rootaddr, location_closest, min_dist, make_pair(p_x, p_y), 0);
    cout << "Closest Element to given point is : " << location_closest->x << " " << location_closest->y << "\n";
    cout << "Squared Distance: " << min_dist << "\n";
    return 0;
}
