#include "HKGraphicManager.h"
#include "HKSurfaceImpl.h"

class HKGraphicManagerImpl : public HKGraphicManager {

private:
public:
    HKGraphicManagerImpl();
    void init(int feeder, int detecter, int drawer);
    int start();
    int stop();
    void setDetectFlags(int flags);
    int addSurface(HKSurface suface);
    int removeSurface(HKSurface suface);
    int removeSurface(int index);
    void draw();
};
