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
    int n, p_x, p_y, th;
    // Number of new points to be inserted
    n = 100;
    // Threshold (upto this number of insertions are allowed without rebuilding the kd tree)
    th = 5;
    for(int i = 1 ; i <= n ; i++) {
        p_x = rand() % 1000;
        p_y = rand() % 1000;
        vec.push_back(make_pair(p_x, p_y));
        // if number of new insertions exceeds threshold rebuild the tree from scratch
        if(i % (th + 1) == 0) {
            delete_tree(rootaddr);
            rootaddr = NULL;
            rootaddr = static_build(rootaddr, vec, 0, 0, (int)vec.size() - 1);
        }
        else {
            rootaddr = dynamic_build(rootaddr, make_pair(p_x, p_y), 0);
        }
    }

    // Uncomment the below part to print the kd-tree (preorder traversal)
    /*
       cout << "tree traversal\n";
       print(rootaddr, 0, 'a');
     */
    return 0;
}
