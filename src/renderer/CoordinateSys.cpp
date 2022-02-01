#include "CoordinateSys.hpp"

CoordinateSys::CoordinateSys(const Vec3d &position, const Vec3d &u, const Vec3d &v, const Vec3d &w)
  : m_position(position), m_u(u), m_v(v), m_w(w)
{
}

Vec3d CoordinateSys::toLocal(const Vec3d &global) const
{
  Vec3d temp(global - m_position);
  return Vec3d(temp.dot(m_u), temp.dot(m_v), temp.dot(m_w));
}

Vec3d CoordinateSys::toGlobal(const Vec3d &local) const
{
  return Vec3d(local.dot(m_u), local.dot(m_v), local.dot(m_w)) + m_position;
}