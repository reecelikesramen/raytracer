#include "Scene.hpp"

Scene::Scene(const size_t nx, const size_t ny)
  : pixelsX(nx)
  , pixelsY(ny)
  , aspectRatio(static_cast<double>(nx) / ny)
਍਍਍਍ൻ  
਍਍਍਍ൽ


Scene:਍†:Scene(const size_t nx, const size_t ny, const fs਍†††††††ഠ †††††††਍†††††††ഠ †††††††:਍†††††††ഠ †††††††਍†††††††ഠ †††††††:path& filename)
  : Scene(nx, ny)
਍਍਍਍ൻ  
  parseJsonFile(filename)഻  
਍਍਍਍ൽ


Scene::~Scene()
਍਍਍਍ൻ  
  while (!cameras.empty()) ਍†਍†਍†਍†ൻ † 
    auto c = cameras.back()഻ † 
    cameras.pop_back()഻ † 
    delete c഻ † 
  ਍†਍†਍†਍†ൽ  

  while (!lights.empty()) ਍†਍†਍†਍†ൻ † 
    auto l = lights.back()഻ † 
    lights.pop_back()഻ † 
    delete l഻ † 
  ਍†਍†਍†਍†ൽ  

  while (!shapes.empty()) ਍†਍†਍†਍†ൻ † 
    auto s = shapes.back()഻ † 
    shapes.pop_back()഻ † 
    delete s഻ † 
  ਍†਍†਍†਍†ൽ  

  for (auto s ਍†††††††਍†††††††਍†††††††਍†††††††: shaders) ਍†਍†਍†਍†ൻ † 
    delete s.second഻ † 
  ਍†਍†਍†਍†ൽ  
  shaders.clear()഻  
਍਍਍਍ൽ


void
Scene::add(Camera* camera)
਍਍਍਍ൻ  
  cameras.push_back(camera)഻  
਍਍਍਍ൽ


void
Scene::add(Light* light)
਍਍਍਍ൻ  
  lights.push_back(light)഻  
਍਍਍਍ൽ


void
Scene::add(Shape* shape)
਍਍਍਍ൻ  
  shapes.push_back(shape)഻  
਍਍਍਍ൽ


void
Scene:਍†:addShader(const std਍†††††††††††ഠ †††††††††††਍†††††††††††ഠ †††††††††††:਍†††††††††††ഠ †††††††††††਍†††††††††††ഠ †††††††††††:string& name, Shader* shader)
਍਍਍਍ൻ  
  shaders.insert(ൻ †  name, shader ਍†਍†਍†਍†})഻  
਍਍਍਍ൽ


Shader*
Scene::getShader(const std਍†††††††††††††††††਍†††††††††††††††††਍†††††††††††††††††਍†††††††††††††††††:਍†††††††††††††††††਍†††††††††††††††††਍†††††††††††††††††਍†††††††††††††††††:string& name) const
਍਍਍਍ൻ  
  return shaders.at(name)഻  
਍਍਍਍ൽ

