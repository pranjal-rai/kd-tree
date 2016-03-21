//pranjalr34
#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

struct kdtree {
    kdtree *left,*right;
    int x,y;
};


/** Sorting comparison funtion */
int cmp(const PII &a, const PII &b) {
    return ((a.second < b.second) || ((a.second == b.second) && (a.first < b.first)));
}


/** Computes squared distance between two points */
int distance(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}


/** This function is for building the kdtree from scratch 
 *  sort all the nodes from s to e in the dimsension "depth"
 *  assign the median of elements from s to e as the current node
 *  for the left half make a recursive call to left subtree with depth increased by one
 *  for the right half make a recursive call to right subtree with depth increased by one
 */
kdtree* static_build(kdtree *rootaddr, VPII &vec, int depth, int s, int e) {
    if(e < s)
        return NULL;
    if(s == e) {
        rootaddr = (kdtree*)(malloc(sizeof(kdtree)));
        rootaddr->x = vec[s].first;
        rootaddr->y = vec[s].second;
        rootaddr->left = NULL;
        rootaddr->right = NULL;
    }
    else {
        if(depth % 2 == 0)
            sort(vec.begin() + s, vec.begin() + e + 1);
        else
            sort(vec.begin() + s, vec.begin() + e + 1, cmp);
        rootaddr = (kdtree*)(malloc(sizeof(kdtree)));
        rootaddr->x = vec[(s + e) / 2].first;
        rootaddr->y = vec[(s + e) / 2].second;
        rootaddr->left = static_build(rootaddr->left, vec, depth + 1, s, (s + e) / 2 - 1);
        rootaddr->right = static_build(rootaddr->right, vec, depth + 1, (s + e) / 2 + 1, e);
    }
    return rootaddr;
}


/** This function is for insertion in the kdtree one point at a time 
 *  It looks for the node closest to the point p and add the new point p is inserted at this node
 *  This leads to unbalancing of the tree which causes increase in complexity of queries
 */
kdtree* dynamic_build(kdtree *rootaddr, PII p, int depth) {
    int p_x, p_y;
    p_x = p.first;
    p_y = p.second;

    if(rootaddr == NULL) {
        rootaddr = (kdtree*)(malloc(sizeof(kdtree)));
        rootaddr->x = p_x;
        rootaddr->y = p_y;
        rootaddr->left = NULL;
        rootaddr->right = NULL;
    }
    else {
        if(depth % 2 == 0) {
            if(p_x < rootaddr->x)
                rootaddr->left = dynamic_build(rootaddr->left, p, depth + 1);
            else
                rootaddr->right = dynamic_build(rootaddr->right, p, depth + 1);
        }
        else {
            if(p_y < rootaddr->y)
                rootaddr->left = dynamic_build(rootaddr->left, p, depth + 1);
            else
                rootaddr->right = dynamic_build(rootaddr->right, p, depth + 1);
        }
    }
    return rootaddr;
}


/** This function is to look for a point in kd tree 
 *  if depth coordinate of point p is less than current node then recursively call left else call right
 */
kdtree* find_pt(kdtree *rootaddr, PII p, int depth) {
    int p_x, p_y;
    p_x = p.first;
    p_y = p.second;
    if(rootaddr == NULL)
        return NULL;
    if(rootaddr->x == p_x && rootaddr->y == p_y) {
        return rootaddr;
    }
    if(depth % 2 == 0) {
        if(p_x < rootaddr->x)
            return find_pt(rootaddr->left, make_pair(p_x, p_y), depth + 1);
        else
            return find_pt(rootaddr->right, make_pair(p_x, p_y), depth + 1);
    }
    else {
        if(p_y < rootaddr->y)
            return find_pt(rootaddr->left, make_pair(p_x, p_y), depth + 1);
        else
            return find_pt(rootaddr->right, make_pair(p_x, p_y), depth + 1);
    }
}


/** This function is to find the minimum element in "dim" dimension 
 *  If depth is same as dim then just recursively call left else call both left and right
 */
void find_min(kdtree *rootaddr, kdtree* &min_node, int dim, int depth, PII &p) {
    if(rootaddr==NULL)
        return;
    if(depth % 2 == dim) {
        find_min(rootaddr->left, min_node, dim, depth + 1, p);
        PII p_curr = make_pair(rootaddr->x, rootaddr->y);
        PII p_temp = p;
        if(dim==1) { 
            swap(p_curr.first, p_curr.second);
            swap(p_temp.first, p_temp.second);
        }
        if(p_curr < p_temp){
            p = make_pair(rootaddr->x, rootaddr->y);
            min_node=rootaddr;
        }
    }
    else { 
        find_min(rootaddr->left, min_node, dim, depth + 1, p);
        find_min(rootaddr->right, min_node, dim, depth + 1, p);
        PII p_curr = make_pair(rootaddr->x, rootaddr->y);
        PII p_temp = p;
        if(dim==1) { 
            swap(p_curr.first, p_curr.second);
            swap(p_temp.first, p_temp.second);
        }
        if(p_curr < p_temp){
            p = make_pair(rootaddr->x, rootaddr->y);
            min_node=rootaddr;
        }
    }
}


/** This function is to compute the nearest neighbourhood of a point */
void nearest_neighbour(kdtree *rootaddr, kdtree* &best_node, int &best_dist, PII p, int depth) {
    if(rootaddr == NULL)
        return;
    int p_x, p_y;
    p_x = rootaddr->x;
    p_y = rootaddr->y;
    if(distance(p.first, p.second, p_x, p_y) < best_dist) {
         best_dist = distance(p.first, p.second, p_x, p_y);
         best_node = rootaddr;
    }
    if(depth % 2 == 0) { 
        if(p.first < p_x) { 
            nearest_neighbour(rootaddr->left, best_node, best_dist, p, depth+1);
            if(abs(p_x - p.first) < best_dist)
                nearest_neighbour(rootaddr->right, best_node, best_dist, p, depth+1);
        }
        else { 
            nearest_neighbour(rootaddr->right, best_node, best_dist, p, depth+1);
            if(abs(p_y - p.second) < best_dist)
                nearest_neighbour(rootaddr->left, best_node, best_dist, p, depth+1);
        }
    }
    else {
        if(p.second < p_y) { 
            nearest_neighbour(rootaddr->left, best_node, best_dist, p, depth+1);
            if(abs(p_x - p.first) < best_dist)
                nearest_neighbour(rootaddr->right, best_node, best_dist, p, depth+1);
        }
        else { 
            nearest_neighbour(rootaddr->right, best_node, best_dist, p, depth+1);
            if(abs(p_y - p.second) < best_dist)
                nearest_neighbour(rootaddr->left, best_node, best_dist, p, depth+1);
        }
    }
}


/** This function prints the kdtree (preorder traversal) */
void print(kdtree *nodeaddr, int depth, char c) {
    if(nodeaddr == NULL)
        return;
    cout << nodeaddr->x << " " << nodeaddr->y << " " << depth << " " << c << "\n";
    print(nodeaddr->left, depth + 1, 'l');
    print(nodeaddr->right, depth + 1, 'r');
}


/** This function deletes the kdtree */
void delete_tree(kdtree *nodeaddr) {
    if(nodeaddr == NULL)
        return;
    delete_tree(nodeaddr->left);  
    delete_tree(nodeaddr->right);
    /** free the memory location associated with the node */
    free(nodeaddr);
}
