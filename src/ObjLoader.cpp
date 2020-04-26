//
// Created by dani on 26/04/2020.
//

#include "ObjLoader.h"

void ObjLoader::calcTriangles(Eigen::Vector3f const &translation, Material const &mat) {
  for (auto &f : faces_) {
    xyz p0 = vertexes_[f(0)] + translation;
    xyz p1 = vertexes_[f(1)] + translation;
    xyz p2 = vertexes_[f(2)] + translation;
    triangles_.emplace_back(p0, p1, p2, mat);
  }
}


void ObjLoader::readFile(const char *file_name, Eigen::Vector3f const &translation, Material const &mat) {
  ObjFile obj_file(file_name);
  std::string line;
  while (!obj_file.EndOfFile()) {
    line = obj_file.GetLine();
    std::istringstream iss(line.c_str());
    char discard;
    if (!line.compare(0, 2, "v ")) {
      iss >> discard;
      Vec3f vertex;
      for (int i = 0; i < 3; ++i) { iss >> vertex[i]; }
      vertexes_.push_back(std::move(vertex));
    } else if (!line.compare(0, 2, "vt")) {
      continue;
    } else if (!line.compare(0, 2, "f ")) {
      Eigen::Vector3i f;
      int idx, cnt = 0;
      iss >> discard;
      while (iss >> idx) {
        --idx;
        f[cnt++] = idx;
        while (iss.get() != ' ') {}
      }
      if (3 == cnt) { faces_.push_back(std::move(f)); }
    }
  }
  calcTriangles(translation, mat);
}