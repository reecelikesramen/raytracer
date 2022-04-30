#ifndef RENDERER_SHADER_DIFFUSE_SHADER_H_
#define RENDERER_SHADER_DIFFUSE_SHADER_H_

#include "Vector3.hpp"
#include "HitStruct.hpp"
#include "Constants.hpp"

class DiffuseShader : public Shader
{
public:
  DiffuseShader(const Vec3f& color = renderer::constants::DEFAULT_DIFFUSE);
  virtual ~DiffuseShader() {}

  virtual Vec3f apply(const HitStruct& h) const;

private:
  Vec3f m_color;
};

#endif