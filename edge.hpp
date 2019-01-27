#ifndef EDGE_HPP
#define EDGE_HPP

#include<utility>
#include <functional>
#include<string>
#include<sstream>
#include"point.hpp"

class Edge{
private:
  Point start;
  Point term;

  inline void isSwap(){
    if(start.x > term.x || (start.x == term.x  && start.y > term.y)){
      std::swap(start, term);
    }
  }

public:
  Edge(){}

  Edge(Point& p1, Point& p2){
    start = p1;
    term = p2;

    isSwap();
  }

  ~Edge(){}


  inline void set(Point& p1, Point& p2){
    start = p1;
    term = p2;

    isSwap();
  }

  //get functions
  inline Point getStart(){
    return start;
  }

  inline Point getTerm(){
    return term;
  }

  inline Point getStart()const{
    return start;
  }

  inline Point getTerm()const{
    return term;
  }


  inline std::string makeHash()const{
    std::stringstream ss;
    ss << start.x << start.y << term.x << term.y;
    return ss.str();
  }

  //operators
  inline bool operator<(const Edge& e)const{
    Point p1 = e.getStart();
    Point p2 = e.getTerm();
    return ((start.x < p1.x || (start.x == p1.x && start.y < p1.y)) ||
	    (term.x < p2.x  || (term.x == p2.x && term.y < p2.y)));
  }


  friend std::ostream& operator<<(std::ostream& os, const Edge& e){
    os << e.getStart() << "->" << e.getTerm();
    return os;
  }



};


class EdgeHash{
public:
  inline std::size_t operator()(const Edge& e)const{
    return std::hash<std::string>()(e.makeHash());
  }
};

class EdgeEquals : public std::binary_function<Edge, Edge, bool>{
public:
  typedef Edge first_argument_type;
  typedef Edge second_argument_type;
  typedef bool result_type;

  inline bool operator()(const Edge& lhs, const Edge& rhs )const{
    return lhs.makeHash() == rhs.makeHash();
  }
};

#endif
