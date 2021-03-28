#pragma once
#include "htree.hh"
#include <vector>
//compare trees is an object function that compares the values of two trees,
//it is used for the heap functions.
struct compare_trees {
	bool operator()(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2) const {
		return t1->get_value() < t2->get_value();
	}
};
class HForest {
using forest_vect = std::vector<HTree::tree_ptr_t>;//using a vector as the data structure for holding the trees of the forest.
forest_vect forest;//forest will be the member name of the object's vector
public:
size_t size();//defining the three necessary functions for hforest.cc
void add_tree(HTree::tree_ptr_t new_tree);
HTree::tree_ptr_t pop_tree();
};
