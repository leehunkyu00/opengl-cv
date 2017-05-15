class HKSurface;
class HKGraphicManager {
private:
    static HKGraphicManager *m_instance;
public:
    static const int FEEDER_ANDROID = 0;
    static const int FEEDER_IOS = 1;
    static const int FEEDER_WEBCAM = 2;
    static const int DETECTER_OPENCV = 0;
    static const int DRAWER_OPENGL = 0;

    static HKGraphicManager* getInstance();

    virtual void init(int feeder, int detecter, int drawer) = 0;
    virtual int start() = 0;
    virtual int stop() = 0;
    void setDetectFlags(int flags);
    int addSurface(HKSurface *suface);
    int removeSurface(HKSurface *suface);
    int removeSurface(int index);
};
