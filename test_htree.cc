/*
 * test_tree: A simple unit test for the Tree data structure.
 */

#include "htree.hh"
#include <cassert>

using namespace std;

// Create an elaborate example test tree:
HTree::tree_ptr_t create_test_tree()
{
  return make_shared<HTree>(126, 1,
  			make_shared<HTree>(19,7,
  				make_shared<HTree>(3,2),
  				make_shared<HTree>(12,15)),
  			make_shared<HTree>(9,22,
  				nullptr, //filler so i can add to the right path
  				make_shared<HTree>(3,122,
  					make_shared<HTree>(100,19))));
  /* the tree that should be made from the above mess
     126
	 / \
	/   \
   19    9
   /\     \
  /  \     \
 3    12    3
           /
          /
         100
   */
}

void test_htree(const HTree::tree_ptr_t root)
{
  assert(*(root->path_to(126)) == HTree::path_t({ })); //test on root
  assert(*(root->path_to(19)) == HTree::path_t({HTree::Direction::LEFT})); //this one and next for testing its traverse ability
  assert(*(root->path_to(100)) == HTree::path_t({HTree::Direction::RIGHT, HTree::Direction::RIGHT, HTree::Direction::LEFT}));
  assert((root->path_to(2000)) == nullptr); //will it return nullptr when key not in string? yes
  assert(*(root->path_to(3)) == HTree::path_t({HTree::Direction::LEFT, HTree::Direction::LEFT})); //test for leftmost duplicate

}

int main()
{
  auto root = create_test_tree();
  test_htree(root);

  return 0;
}

