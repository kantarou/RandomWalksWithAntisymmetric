#include<iostream>
#include<cstdio>

#include"input.hpp"
#include"output.hpp"
#include"util.hpp"
#include"main_functions.hpp"
using namespace std;



int main(){

  initilize();  
  writeInitData(&grid);


  int section = world.particle_num/P;


  for(int times = 0; times < world.times; ++times){

    # pragma omp parallel
    {
      std::tuple<Edge, int, Edge, int> result;
      double random = 0.0;
      int threadID = omp_get_thread_num();
      int i, j;

      #pragma omp for  private(j)
      for(i = 0; i < world.particle_num; ++i){
        for(j = 0; j < world.times_of_trajectory; ++j){
          //result = particle[i].randomWalk(distribution[0](generator[0]));

          //cout << "particle number::" << i  << " ID:" << threadID << endl; 
          random = distribution[threadID](generator[threadID]);
          result = particle[i].randomWalk(random);

          //write edge

          particle_route[threadID][std::get<0>(result)] += edge[std::get<1>(result)];
          particle_route[threadID][std::get<2>(result)] += edge[std::get<3>(result)];
        }
         //std::cout << "random " << threadID << ", " << random << std::endl;

        if(threadID == 0){
          ++percent;

          if(percent % 10000 == 0){
            std::cout << "particles moved::" << 100 * 1.0 * percent/world.particle_num * P << "%" << std::endl; 
          }
        }

      }
    }

    cout << "Marging Data...." << endl;
    margeData();
    cout << "Writing Data..." << endl;
    writeData(&grid);
    writeDataEdge(grid, edge_result);

    cout << (double)(times+1)/(double)world.times * 100<< "% finished" << endl;
  }
  
  return 0;
}
