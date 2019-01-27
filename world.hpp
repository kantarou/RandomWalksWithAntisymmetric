#ifndef WORLD_HPP
#define WORLD_HPP

/*
=====File Format======
Grid_Size_height    height
Grid_Size_width      width
the_origin x        origin_x
the_origin y        origin_y
R                   R
NoPatOneNode        number_of_particle_at_one_node
Particle            particle_num
Epsilon_left        epsilon_left
Epsilon_right       epsilon_right
Times               times
Times_of_Trajectory times_of_trajectory
 */


struct _WorldInfo{
  //Grid Infomation
  int height, width;

  //Particle Infomation
  int origin_x, origin_y;
  int particle_num;
  double epsilon_left, epsilon_right;

  //Simulation Infomation
  double R;
  int number_of_particle_at_one_node;
  int times;
  long int times_of_trajectory;
};
typedef struct _WorldInfo WorldInfo;

extern WorldInfo world;

#endif
