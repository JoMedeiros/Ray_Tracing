#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <vector>
#include "vec3.h"

using namespace std;
typedef unsigned char pixel_type;

class Buffer
{
private:
	pixel_type* p; // Matrix of pixels
  int _height;
  int _width;
public:
  // Setters & getters
  int height() const { return _height; }
  int width() const { return _width; }
  pixel_type* data() { return p; }
  // Constructors
  // @TODO Constructor with image as param
  // Use a library to open, resize images
  /**
   * @brief Constructs a buffer with height x width pixels (by default a pixel has 3 bytes)
   */
	Buffer(int height=0, int width=0);
  /**
   * @brief Copy constructor
   */
  Buffer(Buffer & other);
  /**
   * @brief Class Destructor
   */
  ~Buffer() { delete[] p; }
  /**
   * @brief Saves a color to buffer on the address corresponding to coordinate (x, y)
   */
  void paint(int x, int y, Color color);
  /**
   * @brief Returns the color on the coordinate (x, y)
   */
  Color get_color(int x, int y);
	inline pixel_type operator[](int i) const { return p[i*_height]; }
	inline pixel_type& operator[](int i) { return p[i*_height]; }
};

#endif // _BUFFER_H_
