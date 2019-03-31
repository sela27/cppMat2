/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  ariel::Tree mytree;
  ariel::Tree bigtree;  

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())
  .print();


	tc.CHECK_OK(mytree.insert(-2)).
	CHECK_EQUAL(mytree.root(),-2).
      CHECK_THROWS(mytree.insert(-2)).
      CHECK_EQUAL(mytree.size(),1).
      CHECK_THROWS(mytree.parent(-2)).
      CHECK_OK(mytree.insert(-10)).
	CHECK_EQUAL(mytree.size(),2).
      CHECK_OK(mytree.insert(326326)).
	CHECK_EQUAL(mytree.size(),3).
      CHECK_OK(mytree.insert(-467347)).
	CHECK_EQUAL(mytree.size(),4).
      CHECK_OK(mytree.insert(0)).
	CHECK_EQUAL(mytree.size(),5).
      CHECK_OK(mytree.insert(1)).
	CHECK_EQUAL(mytree.size(),6).
      CHECK_THROWS(mytree.left(1)).
      CHECK_EQUAL(mytree.right(0) , 1).
      CHECK_EQUAL(mytree.contains(0) , true).
      CHECK_OK(mytree.remove(0)).
      CHECK_THROWS(mytree.remove(0)).
      CHECK_OK(mytree.remove(-2)).
      print();


	tc.CHECK_OK(bigtree.insert(20)).
	CHECK_EQUAL(bigtree.root(),20).
	CHECK_EQUAL(bigtree.size(),1).
	CHECK_OK(bigtree.insert(30)).
	CHECK_EQUAL(bigtree.size(),2).
	CHECK_OK(bigtree.insert(40)).
	CHECK_EQUAL(bigtree.size(),3).
	CHECK_OK(bigtree.insert(60)).
	CHECK_EQUAL(bigtree.size(),4).
	CHECK_OK(bigtree.insert(70)).
	CHECK_EQUAL(bigtree.size(),5).
	CHECK_OK(bigtree.insert(35)).
	CHECK_EQUAL(bigtree.size(),6).
	CHECK_OK(bigtree.insert(44)).
	CHECK_EQUAL(bigtree.size(),7).
	CHECK_THROWS(bigtree.insert(35)).
	CHECK_EQUAL(bigtree.size(),7).
	CHECK_THROWS(bigtree.insert(44)).
	CHECK_EQUAL(bigtree.size(),7).
	CHECK_OK(bigtree.remove(70)).
	CHECK_THROWS(bigtree.remove(70)).
	CHECK_EQUAL(bigtree.size(),6).
	CHECK_OK(bigtree.remove(20)).
	CHECK_EQUAL(bigtree.size(),5).
	CHECK_THROWS(bigtree.remove(20)).
	CHECK_OK(bigtree.remove(44)).
	CHECK_EQUAL(bigtree.size(),4).
	CHECK_THROWS(bigtree.remove(44)).
	print();

  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
