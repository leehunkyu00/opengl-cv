#include "HKGraphicManagerImpl.h"

int main(int argc, char *argv[]) {
    HKGraphicManager *manager = HKGraphicManagerImpl::getInstance();
    // start
    manager->init(HKGraphicManager::FEEDER_WEBCAM,
                    HKGraphicManager::DETECTER_OPENCV,
                    HKGraphicManager::DRAWER_OPENGL);
    manager->start();
    //manager->setDetectFlags(FACE|EYES/*flags*/);
    //HKSurface *surface_triangle = HKSurface::createSurfaceWithType(TRIANGLE);
    //manager->addSurface(surface_triangle);

    // end
    //manager->removeSurface(surface_triangle);
    //manager->stop();
    return 0;
}
