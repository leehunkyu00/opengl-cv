#include "HKSurfaceImpl.h"

HKSurface* HKSurface::createSurfaceWithUrl(char *url) {
    // template code
    HKSurface *surface = new HKSurfaceImpl();
    return surface;
}

HKSurface* HKSurface::createSurfaceWithFile(char *filePath) {
    // template code
    HKSurface *surface = new HKSurfaceImpl();
    return surface;
}

HKSurface* HKSurface::createSurfaceWithType(int type) {
    // template code
    HKSurface *surface = new HKSurfaceImpl();
    return surface;
}

void HKSurfaceImpl::dirty() {

}

