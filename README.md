FOREST:
the Forest class is an object containing a vector
of type "tree_ptr_t". It holds pointers to trees
in a heap, so that it can find values in log(n) time.

#Compare_trees# is a struct function used for comparing
the values of the roots of trees stored in the forest's heap.

#size# is a method that simply returns the number of trees in the forest.
It uses the vector library's #size# function to do this.

#add_tree# is a method that allocates memory for a new tree,
then adds that tree to the forest heap using #push_heap# to retain
the heap structure.

#pop_tree# is a method that deallocates the memory of the tree
with the largest value in the heap, then returns a pointer to 
the tree. This also uses std heap functions to ensure the structure
is a heap.


BUILDING:

There is a makefile included in the repo. 
To build each test file, in terminal, type:
'''
make test_htree
'''
followed by
'''
./test_htree
'''
to test the file. The same can be done for test_hforest as well.
