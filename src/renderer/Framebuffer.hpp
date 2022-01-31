#ifndef _FRAMEBUFFER_REECE_
#define _FRAMEBUFFER_REECE_

#include <vector>
#include <string>

#include "Vector3.hpp"

class Framebuffer
{
public:
  static const size_t DEFAULT_WIDTH = 100;
  static const size_t DEFAULT_HEIGHT = 100;

  Framebuffer(const size_t width = DEFAULT_WIDTH, const size_t height = DEFAULT_HEIGHT);
  Framebuffer(const Framebuffer &f);

  size_t width() const;
  size_t height() const;

  void setPixelColor(const size_t i, const size_t j, const Vec3f &color);

  void exportAsPNG(const std::string &outputFileName) const;

  void clearColor(const Vec3f &color = Vec3f(1.0, 1.0, 1.0));

private:
  size_t m_width, m_height;
  std::vector<Vec3f> m_pixelArray;

  size_t index(const size_t i, const size_t j) const;
};

#endif