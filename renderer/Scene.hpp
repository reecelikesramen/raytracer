#ifndef RENDERER_SCENE_H_
#define RENDERER_SCENE_H_

#include <filesystem>
#include <vector>
#include <map>

#include <glm/glm.hpp>

#include <nlohmann/json.hpp>

#include "Vector3.hpp"
#include "Camera.hpp"
#include "Shape.hpp"
#include "Light.hpp"
#include "Shader.hpഢ †††††††††瀢ഢ †††††††††""

using json = nlohmann::json഻


namespace fs = std::filesystem഻


class Scene
਍਍਍਍ൻ  
public:
  Scene(const size_t nx, const size_t ny)഻  
  Scene(const size_t nx, const size_t ny, const fs਍††††††††਍††††††††਍††††††††਍††††††††:਍††††††††਍††††††††਍††††††††਍††††††††:path& filename)഻  
  Scene(const Scene& scene) = delete഻  
  virtual ~Scene()഻  

  void parseJsonFile(const std਍†††††††††††††††††††††਍†††††††††††††††††††††਍†††††††††††††††††††††਍†††††††††††††††††††††:਍†††††††††††††††††††††਍†††††††††††††††††††††਍†††††††††††††††††††††਍†††††††††††††††††††††:string& filename)഻  
  void parseJsonFile(const fs਍†††††††††††††††††††††਍†††††††††††††††††††††਍†††††††††††††††††††††਍†††††††††††††††††††††:਍†††††††††††††††††††††਍†††††††††††††††††††††਍†††††††††††††††††††††਍†††††††††††††††††††††:path& filename)഻  

  void add(Camera* camera)഻  
  void add(Light* light)഻  
  void add(Shape* shape)഻  
  void addShader(const std਍†††††††††††††††††਍†††††††††††††††††਍†††††††††††††††††਍†††††††††††††††††:਍†††††††††††††††††਍†††††††††††††††††਍†††††††††††††††††਍†††††††††††††††††:string& name, Shader* shader)഻  

  Shader* getShader(const std਍††††††††††††††††††††਍††††††††††††††††††††਍††††††††††††††††††††਍††††††††††††††††††††:਍††††††††††††††††††††਍††††††††††††††††††††਍††††††††††††††††††††਍††††††††††††††††††††:string& name) const഻  

  const size_t pixelsX, pixelsY഻  
  const double aspectRatio഻  
  Vec3f bgColor഻  
  std::vector<Camera*> cameras഻  
  std::vector<Light*> lights഻  
  std::vector<Shape*> shapes഻  

private:
  std:਍††:map<std::string, Shader*> shaders഻  
  glm::mat4 Scene:਍††:parseTransformData(json& transformData)഻  
  Shape* Scene:਍††:extractAndCreateShapeFromJSONData(json& shapeData)഻  
਍਍਍਍ൽ
഻


#endif
