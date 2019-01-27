#ifndef INPUT_HPP
#define INPUT_HPP

#include<iostream>
#include<cstdio>
#include<cmath>

#include"world.hpp"


void printWorld(WorldInfo world){
  printf("height: %d \t width: %d\n", world.height, world.width);
  printf("number of particles at one node: %d\n", world.number_of_particle_at_one_node);
  printf("number of particles: %d \t epsilon_left: %f \t epsilon_right %f\n", world.particle_num, world.epsilon_left, world.epsilon_right);
  printf("original x: %d, original y: %d\n", world.origin_x, world.origin_y);
  printf("R: %f \t times %d \t  time of trajectory: %ld\n", world.R, world.times, world.times_of_trajectory);
}

void readData(WorldInfo* data){
  std::string temp;

  std::cin >> temp >> data->height;
  std::cin >> temp >> data->width;

  std::cin >> temp >> data->origin_x;
  std::cin >> temp >> data->origin_y;

  std::cin >> temp >> data->R;

  std::cin >> temp >> data->number_of_particle_at_one_node;
  std::cin >> temp >> data->particle_num;
  std::cin >> temp >> data->epsilon_left;
  std::cin >> temp >> data->epsilon_right;

  std::cin >> temp >> data->times;
  std::cin >> temp >> data->times_of_trajectory;
}


void initilizeWorld(WorldInfo* data){

  readData(data);
  
  //set up
  //data->width = 2 * data->height;
  //data->R = data->origin_y;
  if(data->R <= 0.0){
    data->R = std::min(std::min(data->width - data->origin_x, data->origin_x), 
		       std::min(data->height - data->origin_y, data->origin_y));
  }
  
  const int R = data->R;
  if(data->times_of_trajectory <= 0){
    data->times_of_trajectory = (R*R);
  }

  if(data->particle_num <= 0){
    data->particle_num = data->number_of_particle_at_one_node * R * R;
  }

  if(data->number_of_particle_at_one_node<=0){
    data->number_of_particle_at_one_node = 100;
  }


  //set original position
  data->origin_x = data->origin_x - 1;
  data->origin_y = data->origin_y - 1;

  //print initilized data
  printWorld(*data);

}

#endif
