#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>
#include <string>
#include <fstream>
#include "background.hpp"
#include "objects.hpp"

using namespace std;

class Scene
{
 private:
  Background bg;
 public:
  Scene(int height, int width, Color bg_color) : bg(height, width, bg_color){};
  Scene(int height, int width, Color c00, Color c01, Color c10, Color c11) : 
    bg(height, width, c00, c01, c10, c11){};
  Scene(int height, int width, Color c1, Color c2) : 
    bg(height, width, c1, c2, c1, c2){};
  /**
   * @brief     Write a ppm image in a especified file name.
   * @param Name for the output file.
   */
  void render(string filename="output-image.ppm") {
    std::fstream fs (filename, fstream::out);
    if (!fs) 
      std::cout << "Error loading file\n";
    fs << "P3\n" << bg.get_width() << " " << bg.get_height() << "\n" << "255\n" ;
    for ( int i = 0; i < bg.get_height(); ++i ) {
      for ( int j = 0; j < bg.get_width(); ++j ) {
        fs << (int) this->bg[i][j][RED] << " "
          << (int) this->bg[i][j][GREEN] << " "
          << (int) this->bg[i][j][BLUE] << "\n";
      }
    }
    fs.close();
  }
};

#endif // _SCENE_H_
