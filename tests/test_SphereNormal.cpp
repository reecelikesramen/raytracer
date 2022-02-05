#include <iostream>

#include "boost/filesystem.hpp"

#include "renderer.hpp"
#include "Camera.hpp"
#include "PerspectiveCamera.hpp"
#include "Vector3.hpp"
#include "CoordinateSys.hpp"
#include "Framebuffer.hpp"
#include "Sphere.hpp"

#include "handleGraphicsArgs.h"

using namespace renderer;

namespace fs = boost::filesystem;

int main(int argc, char *argv[])
{
  sivelab::GraphicsArgs args;
  args.process(argc, argv);

  // Used cmdline arguments
  const size_t nx(args.width), ny(args.height);
  const fs::path outdir(args.outputDirectory);

  if (!fs::exists(outdir))
  {
    std::cout << "Creating directory " << outdir.string() << std::endl;
    fs::create_directories(outdir);
  }

  Framebuffer fb(nx, ny);

  Sphere sph(Vec3d(0, 0, -2), 0.5);

  Camera *cam = new PerspectiveCamera("persp", CoordinateSys::GLOBAL, 1.0, nx, ny, 1.0, 1.0 * ny / nx);

  for (size_t i(0); i < nx; ++i)
  {
    for (size_t j(0); j < ny; ++j)
    {
      auto ray(cam->generateRay(i, j));

      double hit_T(0);
      auto hit(sph.closestHit(ray, 0, INFINITY, hit_T));

      Vec3f color(0.1, 0.1, 0.1);
      if (hit)
      {
        auto normal(sph.normal(ray.point(hit_T)));

        // normal shading
        color = normal;
        color += Vec3f(1.0, 1.0, 1.0);
        color /= 2;
      }

      fb.setPixelColor(i, j, color);
    }
  }

  fb.exportAsPNG((outdir / "test_SphereNormal.test.png").string());

  return 0;
}