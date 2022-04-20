#include "Scene.hpp"

Scene::Scene(const size_t nx, const size_t ny) : m_pixelsX(nx), m_pixelsY(ny), m_aspectRatio(static_cast<double>(nx) / ny)
{
}

Scene::Scene(const Scene &scene)
    : m_pixelsX(scene.m_pixelsX), m_pixelsY(scene.m_pixelsY), m_aspectRatio(scene.m_aspectRatio), m_cameras(scene.m_cameras.size()), m_lights(scene.m_lights.size()), m_shapes(scene.m_shapes.size())
{
  // Does this need a copy ctor?
}

void Scene::add(Camera *camera)
{
  m_cameras.push_back(camera);
}

void Scene::add(Light *light)
{
  m_lights.push_back(light);
}

void Scene::add(Shape *shape)
{
  m_shapes.push_back(shape);
}

void Scene::addShader(const std::string &name, Shader *shader)
{
  m_shaders.insert({name, shader});
}

Shader *Scene::getShader(const std::string &name) const
{
  return m_shaders.at(name);
}

const std::vector<Camera *> &Scene::cameras() const
{
  return m_cameras;
}

const std::vector<Light *> &Scene::lights() const
{
  return m_lights;
}
const std::vector<Shape *> &Scene::shapes() const
{
  return m_shapes;
}

size_t Scene::pixelsX() const
{
  return m_pixelsX;
}

size_t Scene::pixelsY() const
{
  return m_pixelsY;
}

double Scene::aspectRatio() const
{
  return m_aspectRatio;
}

const Vec3f &Scene::background() const
{
  return m_background;
}
