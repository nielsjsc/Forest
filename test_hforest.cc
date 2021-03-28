#include <iostream>
#include "hforest.hh"
#include <cassert>
//makes a forest with an input *tree_count* that decides the number of trees in the forest
HForest make_forest(int tree_count) {
	HForest forest = HForest();
	
	for (int i=0;i < tree_count;i++) {
		HTree::tree_ptr_t curr_tree = std::make_shared<HTree>(1, i*10);//set the *curr_tree* variable to a ptr to an HTree with key 1 and value i*10 to ensure different values.
		forest.add_tree(curr_tree);//add the tree to forest
	}
	return forest;//return the forest
}
int main() {
	HForest test_forest_1 = make_forest(0);//make a forest with no trees
	assert(test_forest_1.size() == 0);//assert the size is 0
	assert(test_forest_1.pop_tree() == nullptr);//check to see if the pop tree of an empty forest returns a nullptr
	HForest test_forest_2 = make_forest(5);//make a forest with 5 trees
	assert(test_forest_2.size() == 5);//assert the size is 5
	HTree::tree_ptr_t popped_tree_ptr = test_forest_2.pop_tree();//pop the largest valued tree and set it equal to a pointer variable
	HTree popped_tree = *popped_tree_ptr;//dereference the pointer to another variable of type *HTree object*
	assert(popped_tree.get_value() == 40);//assert the *get_value()* of the popped tree ptr is 40.
	return 0;
}

