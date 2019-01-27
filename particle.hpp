#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include<iostream>

#include <cmath>
#include<tuple>
#include<cmath>

#include"world.hpp"
#include"util.hpp"
#include"edge.hpp"

class Particle{

private:
  Point position;
  
  inline double function(const Point& p){
    return -1 * p.x + 100 * std::sqrt(2) + 300;
    //return -1 * p.x + world.height;
    //return -((world.height/2.0) / (world.width/4.0)) * p.x + (world.height/2.0);
  }


  inline bool isSpace(const Point& p){
    if((p.x >= 0 && p.y >= 0) &&
       (p.x < world.width && p.y < world.height)/*&&
        function(p) < p.y*/){
      return true;    
    }

    return false;
  }

  
  //if a particle cannot move, this function return false.
  inline bool move(int index){

    //move
    Point newPosition = position + arrow[index];
    bool result = isSpace(newPosition);
    if(result == false){
      newPosition = position;
      index = 0;
    }
    position = newPosition;

    return result;
  }
  
  

public:
  inline Particle(){
    position.x = world.width/2;
    position.y = world.height/2;
  }

  inline Particle(int x, int y){
    position.x = x;
    position.y = y;
  }

  ~Particle(){};


  inline Point getPosition(){
    return position;
  }

  inline void setPosition(int x, int y){
    position.x = x;
    position.y = y;
  }
  
  //this return value is not a position.
  //it is indexes which is written how to move grid.
  inline std::tuple<Edge, int, Edge, int> randomWalk(const double randomValue){
    const int index = (int)randomValue;

    Point resultIndex;
    Point start, end;
    start = this->getPosition();

    //move and get index
    resultIndex.x = move(index)? index : 0;
    end = this->getPosition();

    Edge move1(start, end);

    //jump and get jump index
    start = end;

    if(resultIndex.x != 0 &&  
       randomValue - index <=  world.epsilon_left){
       resultIndex.y = move(jumpIndex_left[index])? jumpIndex_left[index] : 0;
    }
      /*
    else if(resultIndex.x != 0 &&  
            randomValue - index >= 1.0 - world.epsilon_right){
      resultIndex.y = move(jumpIndex_right[index])? jumpIndex_right[index] : 0;
    }*/
    end = this->getPosition();

    Edge move2(start, end);

    return std::tuple<Edge, int, Edge, int>(move1, resultIndex.x, move2, resultIndex.y);
  }

  
};


#endif
