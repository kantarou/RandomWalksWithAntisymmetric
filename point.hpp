#ifndef POINT_HPP
#define POINT_HPP

#include<iostream>

class Point{
  
public:
  int x, y;

  Point(){
    x = 0;
    y = 0;
  }
  
  Point(int x, int y){
    this->x = x;
    this->y = y;
  }

  inline Point operator+(const Point& p){
    Point result(this->x + p.x, this->y + p.y);
    return result;
  }

  inline bool operator==(const Point& p){
    return ((this->x == p.x) && (this->y == p.y));
  }


  friend std::ostream& operator<<(std::ostream& os, const Point& p){
    os << "(" << p.x << ", " << p.y << ")";
    return os;
  }

};

#endif
