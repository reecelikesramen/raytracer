#include <iostream>

#include "boost/filesystem.hpp"

#include "renderer.hpp"
#include "Camera.hpp"
#include "PerspectiveCamera.hpp"
#include "OrthographicCamera.hpp"
#include "Vector3.hpp"
#include "CoordSys.hpp"
#include "Framebuffer.hpp"
#include "Triangle.hpp"
#include "HitStruct.hpp"
#include "DiffuseShader.hpp"

#include "handleGraphicsArgs.h"

using namespace renderer;

namespace fs = boost::filesystem;

int main(int argc, char *argv[])
{
    sivelab::GraphicsArgs args;
    args.process(argc, argv);

    // Used cmdline arguments
    const size_t nx(args.width), ny(args.height);
    const fs::path outdir(fs::path(args.outputFileName).parent_path());

    Framebuffer fbPersp(nx, ny);
    Framebuffer fbOrtho(nx, ny);

    Triangle tri;
    tri.setShader(new DiffuseShader(Vec3f(), Vec3f(1, 0, 1)));

    Camera *persp = new PerspectiveCamera();
    Camera *ortho = new OrthographicCamera();

    persp->setImagePixels(nx, ny);
    ortho->setImagePixels(nx, ny);

    for (size_t i(0); i < nx; ++i)
    {
        for (size_t j(0); j < ny; ++j)
        {
            auto orthoRay(ortho->generateRay(i, j));
            auto perspRay(persp->generateRay(i, j));

            auto hitOrtho = HitStruct();
            auto hitPersp = HitStruct();

            Vec3f colorPersp(0.1, 0.1, 0.1);
            Vec3f colorOrtho(0.1, 0.1, 0.1);
            if (tri.closestHit(perspRay, hitPersp))
            {
                colorPersp = hitPersp.shaderPtr->apply(hitPersp);
            }

            if (tri.closestHit(orthoRay, hitOrtho))
            {
                colorOrtho = hitOrtho.shaderPtr->apply(hitOrtho);
            }

            fbPersp.setPixelColor(i, j, colorPersp);
            fbOrtho.setPixelColor(i, j, colorOrtho);
        }
    }

    fbPersp.exportAsPNG((outdir / "test_DefaultTrianglePerspective.test.png").string());
    fbOrtho.exportAsPNG((outdir / "test_DefaultTriangleOrthographic.test.png").string());

    return 0;
}