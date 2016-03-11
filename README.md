# kd-tree
My implementation of kd-tree

**_About:_**

This repository contains a header file [**kdtree.h**](kdtree.h) which can be directly included in the code to use kd-tree data structure with various function supports. This file contains all the implementations of kd-tree functions. Further I have inlcluded some [**examples**](examples) of how to use these functions.


**_Code Examples:_**

Build kdtree for static array using static_build():  [kdtree_static.cpp](examples/kdtree_static.cpp)

Build kdtree for dynamic elements using dynamic_build():  [kdtree_dynamic.cpp](examples/kdtree_dynamic.cpp)

Look for a point in kd-tree using find_pt() : [find_pt.cpp](examples/find_pt.cpp)

Look for the minimum point in some dimension in the kd-tree using find_min() : [find_min.cpp](examples/find_min.cpp)

Look for the NEAREST NEIGHBOUR in the kd-tree for some given point using nearest_neighbour() :  [nearest_neighbour.cpp](examples/nearest_neighbour.cpp)




**_Some details:_** 

The given implementation uses concept of **"REBUILD THRESHOLD"** Approach for dynamic points. (i.e after some number of insertions into the kd tree the tree is rebuild from the scratch)
