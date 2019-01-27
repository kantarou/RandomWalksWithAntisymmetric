#ifndef UTIL_HPP
#define UTIL_HPP

//vector and matrix
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

typedef boost::numeric::ublas::matrix<int> Grid;


#include"world.hpp"
#include"point.hpp"
#include"edge.hpp"

/*
  0     1   2      3     4
  stay, up, right, down, left
*/
const Point arrow[] = {Point(0, 0), Point(0, -1), Point(1, 0), Point(0, 1), Point(-1, 0)}; 
const int jumpIndex_left[]  = {0, 4, 1, 2, 3};
const int jumpIndex_right[] = {0, 2, 3, 4, 1};
const int edge[] = {0, -1, 1, 1, -1};

#endif
