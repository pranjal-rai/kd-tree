# kd-tree
My implementation of kd-tree

About:

This repository contains a header file "kdtree.h" which can be directly included in the code to use kd-tree data structure with various function supports.


Code Examples:

Build kdtree for static array using static_build():  kdtree_static.cpp
Build kdtree for dynamic elements using dynamic_build():  kdtree_dynamic.cpp
Look for a point in kd-tree using find_pt() : find_pt.cpp
Look for the minimum point in some dimension in the kd-tree using find_min() : find_min.cpp
Look for the Nearest Neighbour in the kd-tree for some given point using nearest_neighbour() :  nearest_neighbour.cpp


Some details: 

The given implementation uses concept of "Rebuild Threshold" Approach for dynamic points. (i.e after some number of insertions into the kd tree the tree is rebuild from the scratch)
