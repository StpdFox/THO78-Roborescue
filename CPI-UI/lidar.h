#ifndef LIDAR_H
#define LIDAR_H


class lidar
{
public:
    lidar();
    ~lidar();

    void handleButtonLidar();
    int setRPM();
    void startLidar();
    void stopLidar();


};

#endif // LIDAR_H
