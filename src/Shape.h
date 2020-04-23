//
// Created by dani on 20/04/2020.
//

#ifndef TRACERR_SHAPE_H
#define TRACERR_SHAPE_H
#include <array>
#include <iostream>
#include <tuple>

typedef std::array<float, 3> xyz;
typedef std::array<unsigned int, 3> rgb;


class Shape {
  public:
  Shape(xyz pos = {0, 0, 0}, rgb color = {100, 100, 100});

  virtual bool RayIntersect(xyz origin, xyz direction, float t0) const = 0;

  xyz GetPos() const { return pos_; }
  rgb GetColor() const { return color_; }
  friend std::ostream &operator<<(std::ostream &o, Shape const &s);

  virtual ~Shape() = default;
  Shape() = default;
  Shape(Shape const &) = default;
  Shape(Shape &&) = default;
  Shape &operator=(Shape const &) = default;
  Shape &operator=(Shape &&) = default;

  protected:
  xyz pos_;
  float mat_reflectivity_;
  rgb color_;
};


#endif//TRACERR_SHAPE_H
