#include <iostream>
#include "htree.hh"
#include "hforest.hh"
#include<algorithm>
//simply returning the size of the forest
size_t HForest::size() {
	return forest.size();//the built in function #size()# takes the size of a vector or similar heap-like data structure
}



//adds a tree to the forest of HForest object
void HForest::add_tree(HTree::tree_ptr_t new_tree) {

	forest.push_back(new_tree);//the #push_back()# vector function allocates memory and adds a new 
	//tree to the vector, it puts it at the end by default.
	if (forest.size() == 1) return;//since #push_heap()# cannot take a length 1 vector as an argument, we must check to make sure the length is greater than 1.
	std::push_heap(forest.begin(), forest.end(), compare_trees());//pushes the new tree from the end of the vector into the correct place, making it a heap.
}


//pops the tree with the greatest value and returns it
HTree::tree_ptr_t HForest::pop_tree() {
	if (forest.size() < 1) return nullptr;//returns a nullptr if the forest is empty
	std::pop_heap(forest.begin(), forest.end(), compare_trees());//std function #pop_heap# takes the largest valued tree and places it at the end of the vector
	HTree::tree_ptr_t popped_ptr = forest.back();//set the popped_ptr variable equal to the ptr at the end of the vector, the recently popped tree
	forest.pop_back();//the vector function #pop_back()# deallocates the memory of the last element of the vector, freeing the memory.
	return popped_ptr;//return the ptr
}