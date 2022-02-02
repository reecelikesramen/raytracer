#include "Camera.hpp"

const size_t Camera::DEFAULT_PIXELS_XY = 100;
const double Camera::DEFAULT_IMAGE_WH = 1.0;

Camera::Camera(const std::string &name, const CoordinateSys &basis)
  : m_name(name), m_basis(basis), m_pixels_x(DEFAULT_PIXELS_XY), m_pixels_y(DEFAULT_PIXELS_XY), m_image_w(DEFAULT_IMAGE_WH), m_image_h(DEFAULT_IMAGE_WH)
{
}

Camera::Camera(const std::string &name, const CoordinateSys &basis, const size_t pixels_x, const size_t pixels_y, const double image_w, const double image_h)
  : m_name(name), m_basis(basis), m_pixels_x(pixels_x), m_pixels_y(pixels_y), m_image_w(image_w), m_image_h(image_h)
{
}

std::string Camera::name() const
{
  return m_name;
}

CoordinateSys Camera::basis() const
{
  return m_basis;
}

size_t Camera::pixels_x() const
{
  return m_pixels_x;
}
size_t Camera::pixels_y() const
{
  return m_pixels_y;
}
double Camera::image_w() const
{
  return m_image_w;
}
double Camera::image_h() const
{
  return m_image_h;
}

void Camera::set_pixels_x(const size_t pixels_x)
{
  m_pixels_x = pixels_x;
}

void Camera::set_pixels_y(const size_t pixels_y)
{
  m_pixels_y = pixels_y;
}

void Camera::set_image_w(const double image_w)
{
  m_image_w = image_w;
}

void Camera::set_image_h(const double image_h)
{
  m_image_h = image_h;
}