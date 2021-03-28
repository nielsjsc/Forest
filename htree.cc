/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "htree.hh"
#include <iostream>
HTree::~HTree(){

}

HTree::HTree(key_t key, value_t value, tree_ptr_t left, tree_ptr_t right){
	key_ = key;
    value_ = value;
    left_ = left;
    right_ = right;
}

// Return an optional list of directions from root to a node of a given key.
// If key not contained in this tree, returns nullptr
HTree::possible_path_t
HTree::path_to(key_t key) const
{
	if (get_key() == key) {
		return possible_path_t(new path_t());
	}

	if (get_child(Direction::LEFT)) {
		auto left_res = get_child(Direction::LEFT)->path_to(key);
		
		if (left_res) {
			left_res->push_front(Direction::LEFT);
			return left_res;
		}

	}

	if (get_child(Direction::RIGHT)) {
		auto right_res = get_child(Direction::RIGHT)->path_to(key);
		
		if (right_res) {
			right_res->push_front(Direction::RIGHT);
			return right_res;
		}

	}
	
	return nullptr;

 /* if (get_key() == key) {
    return possible_path_t(new path_t());
  }
  if (get_child(Direction::LEFT)){
	auto left_res = get_child(Direction::LEFT)->path_to(key);
  	if (left_res) {
    	return left_res;
  	}

  }
  
  if (get_child(Direction::RIGHT)){
  	auto right_res = get_child(Direction::RIGHT)->path_to(key);
  	if (right_res == nullptr) {
    	return nullptr;
  	} else {
    	return right_res;
  	}	
  }
  return nullptr;*/
}



HTree::key_t 
HTree::get_key() const{
	return key_;
}  
HTree::value_t
HTree::get_value() const{
	return value_;
}    

HTree::tree_ptr_t
HTree::get_child(Direction dir) const{
	if (dir == Direction::LEFT){
		if (left_){
			return left_;
		} else {
			return nullptr;
		}
	} else {
		if (right_){
			return right_;
		} else{
			return nullptr;
		}
	}
}