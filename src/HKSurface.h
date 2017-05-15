class HKSurface {
private:
    // Not yet define Bitmap, Data type
    //Bitmap m_bitmap
    //Data m_data
public:
    static const int TRIANGLE = 0;  // for test

    static HKSurface* createSurfaceWithUrl(char *url);
    static HKSurface* createSurfaceWithFile(char *filePath);
    static HKSurface* createSurfaceWithType(int type);   // for test
    virtual void dirty() = 0;
};
