#include "Scene.hpp"

Scene::Scene(const Scene &scene)
    : m_cameras(scene.m_cameras.size()), m_lights(scene.m_lights.size()), m_shapes(scene.m_shapes.size())
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

void Scene::add(const std::string &name, Shader *shader)
{
  m_shaders[name] = shader;
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
const std::map<std::string, Shader *> &Scene::shaders() const
{
  return m_shaders;
}
