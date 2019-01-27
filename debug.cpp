#include<iostream>
#include<cstdio>

#include<map>
#include <unordered_map>

#include"world.hpp"
#include"input.hpp"
#include"util.hpp"
#include"edge.hpp"
#include"particle.hpp"
//#include"test.hpp"


using namespace std;

WorldInfo world;


int main(){

  initilizeWorld(&world);

  std::vector<Particle> particles;

  for(int i=0; i<=3; ++i){
    Particle p(0,500);
    particles.push_back(p);
  }

  double rand = 0.9;
  cout << "random: " << rand << endl;

  particles[0].randomWalk(1 + rand);
  particles[1].randomWalk(2 + rand);
  particles[2].randomWalk(3 + rand);
  particles[3].randomWalk(4 + rand);

  cout << particles.size() << endl;
  for(int i = 0; i < particles.size(); ++i){
    cout << i << " "<< particles[i].getPosition() << endl;
  }

  //initilizeWorld(&world);
  /*
  Point p(4, 1);
  Point p2(4, 3);
  Point p3(4, 5);
  Point p4(8, 6);

  Edge e1(p, p2);
  Edge e2(p, p3);

  std::unordered_map<Edge, int, EdgeHash, EdgeEquals> hash;

  hash[e2] = 2;
  hash[e1]++;


  for(auto it: hash){
    cout << it.first << it.second << endl;
  }
  */

  return 0;
}
