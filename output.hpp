#ifndef OUT_PUT_HPP
#define OUT_PUT_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>

#include"util.hpp"

//#incldue"particle.hpp"


inline void writeInitData(const Grid *grid){
    std::ofstream ofs;
    const std::string fileLocation = "./result/";
    const std::string fileName = fileLocation + "init_data" + ".csv";

    ofs.open(fileName);

    //ofs << numberOfParticle << std::endl;
    ofs << grid->size1() << "," << grid->size2() << "," << world.particle_num << "," << world.times << std::endl;

}


inline void writeData(Grid *grid){
    std::ofstream ofs;
    
    static int i = 0;
    const std::string fileLocation = "./result/particle/";

    std::stringstream ss;
    ss << i++;
    std::string fileName = fileLocation + "particle_dist_" + ss.str() + ".csv";
    

    ofs.open(fileName.c_str());

    for(int i=0; i < grid->size1(); i++){
      for(int j=0; j < grid->size2(); j++){
        if((*grid)(i,j) != 0 )
          ofs << i  << "," << j << "," << 1.0 * (*grid)(i,j) <<std::endl;
        }
    }
}


inline void writeDataEdge(Grid& grid, std::unordered_map<Edge, long int, EdgeHash, EdgeEquals>& edge_result){
  std::ofstream ofs;
    
  static int i = 0;
  const std::string fileLocation = "./result/edge/";

  std::stringstream ss;
  ss << i++;
  std::string fileName = fileLocation + "edge_dist_" + ss.str() + ".csv";



  ofs.open(fileName.c_str());
  //ofs << grid.size1() << "," << grid.size2() <<  std::endl;
  
  Edge e;
  Point p1, p2;

  for(auto it: edge_result){
    e = it.first;
    p1 = e.getStart();
    p2 = e.getTerm();
    ofs << p1.x << "," << p1.y << "," << p2.x << "," << p2.y << "," << it.second <<  std::endl;
  }
  
}


#endif
