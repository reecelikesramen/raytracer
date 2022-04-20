#ifndef RENDERER_SCENE_H_
#define RENDERER_SCENE_H_

#include <vector>
#include <map>

#include <glm/glm.hpp>

#include <nlohmann/json.hpp>

#include "Vector3.hpp"
#include "Camera.hpp"
#include "Shape.hpp"
#include "Light.hpp"
#include "Shader.hpp"

using json = nlohmann::json;

class Scene
{
public:
  Scene(const size_t nx, const size_t ny);
  Scene(const Scene &scene);

  void parseJSONData(const std::string &filename);

  void add(Camera *camera);
  void add(Light *light);
  void add(Shape *shape);
  void addShader(const std::string &name, Shader *shader);

  const std::vector<Camera *> &cameras() const;
  const std::vector<Light *> &lights() const;
  const std::vector<Shape *> &shapes() const;

  Shader *getShader(const std::string &name) const;

  size_t pixelsX() const;
  size_t pixelsY() const;
  double aspectRatio() const;
  const Vec3f &background() const;

private:
  const size_t m_pixelsX, m_pixelsY;
  const double m_aspectRatio;
  Vec3f m_background;
  std::vector<Camera *> m_cameras;
  std::vector<Light *> m_lights;
  std::vector<Shape *> m_shapes;
  std::map<std::string, Shader *> m_shaders;

  glm::mat4 Scene::parseTransformData(json &transformData);
  Shape *Scene::extractAndCreateShapeFromJSONData(json &shapeData);
};

#endif
