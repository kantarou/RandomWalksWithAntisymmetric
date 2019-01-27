#ifndef MAIN_FUNCTIONS_HPP
#define MAIN_FUNCTIONS_HPP

#include<iostream>
#include<vector>
#include<unordered_map>

#include<random>
#include<ctime>

//#include<thread>
#include<omp.h>


#include"world.hpp"
#include"input.hpp"
#include"particle.hpp"
#include"edge.hpp"


WorldInfo world;
Grid grid;
std::unordered_map<Edge, long int, EdgeHash, EdgeEquals> edge_result;


//const static int P = 2;
//const static int P = std::thread::hardware_concurrency();
const static int P = omp_get_max_threads();
static long int percent = 0;

//const static int P = 1;
std::vector<std::mt19937> generator(P);
std::vector<std::uniform_real_distribution<double> > distribution(P);

std::vector<std::unordered_map<Edge, long int, EdgeHash, EdgeEquals> > particle_route(P);
std::vector<Particle> particle;



//Functions
inline void initilize(){
  initilizeWorld(&world);
  

  auto grid_temp = Grid(world.width, world.height);
  grid = grid_temp;
  grid.clear();

  for(int i = 0; i < P; ++i){
    auto generator_temp = std::mt19937((time(0)) + i);
    auto distribution_temp = std::uniform_real_distribution<double>(1.0, 5.0);
    generator[i] = generator_temp;
    distribution[i] = distribution_temp;
  }

  //set particles
  auto particle_temp = std::vector<Particle>(world.particle_num);
  particle = particle_temp;

  
  for(int i = 0; i < particle.size()/4; ++i){
    particle[i].setPosition(world.origin_x-1, world.origin_y-1);
  }

  for(int i = particle.size()/4; i < 2*particle.size()/4; ++i){
    particle[i].setPosition(world.origin_x-1, world.origin_y+1);
  }

 for(int i = 2*particle.size()/4; i < 3*particle.size()/4; ++i){
    particle[i].setPosition(world.origin_x+1, world.origin_y+1);
  }

   for(int i = 3*particle.size()/4; i < particle.size(); ++i){
    particle[i].setPosition(world.origin_x+1, world.origin_y-1);
  }


  // for(auto &foreach: particle){
  //   foreach.setPosition(world.origin_x, world.origin_y);
  // }

}




inline void margeData(){
  //initilize parcent
  percent = 0;

  //grid
  Point p;
  grid.clear();
  for(int i = 0; i < world.particle_num; ++i){
    p = particle[i].getPosition();
    grid(p.x, p.y)++;
  }

  //edge
  edge_result.clear();
  for(int i = 0; i < P; ++i){
    for(auto it: particle_route[i]){
      edge_result[it.first] += it.second;
    }
  }

}

#endif
