#include "HKGraphicManagerImpl.h"

HKGraphicManager *HKGraphicManager::m_instance;
HKGraphicManager* HKGraphicManager::getInstance() {
    if (!HKGraphicManager::m_instance) {
        HKGraphicManager::m_instance = new HKGraphicManagerImpl();
    }
    return HKGraphicManager::m_instance;
}

HKGraphicManagerImpl::HKGraphicManagerImpl() {
}

void HKGraphicManagerImpl::init(int feeder, int detecter, int drawer) {
}

int HKGraphicManagerImpl::start() {
    return 0;
}

int HKGraphicManagerImpl::stop() {
    return 0;
}

void HKGraphicManagerImpl::setDetectFlags(int flags) {
}

int HKGraphicManagerImpl::addSurface(HKSurface suface) {
    return 0;
}

int HKGraphicManagerImpl::removeSurface(HKSurface suface) {
    return 0;
}

int HKGraphicManagerImpl::removeSurface(int index) {
    return 0;
}

void HKGraphicManagerImpl::draw() {
}

