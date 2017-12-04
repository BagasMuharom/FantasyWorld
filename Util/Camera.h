#ifndef CAMERA_H
#define CAMERA_H

class Camera {

public:
    Camera(float* cameraX, float* cameraY, float* cameraZ, float* lookX, float* lookY, float* lookZ);
    void rotateAngleX(float angle);
    void rotateAngleY(float angle);
    void rotateCamera(float angle);
    void setAngleX(float angle);
    void setAngleY(float angle);
    void update();
    void toggleFPS();
    bool isFPSMode();
    void strafe(float speed = 0);
    void move(float speed = 0);
    void fly(float incr);
    void setTranslationSpeed(float speed);
    float getTranslationSpeed();

private:

    /**
     * Jika fpsmode bernilai false, maka akan beralih ke mode spactate seperti di CS
     */
    bool fpsmode = false;

    float* lookX;
    float* lookY;
    float* lookZ;

    float* cameraX;
    float* cameraY;
    float* cameraZ;

    float angleY = 4.7;
    float angleX = 0;

    /**
     * Variabel ini berfungsi untuk menggeser posisi kamera ke kanan
     * dan ke kiri
     */
    float strafeX;
    float strafeY;
    float strafeZ;

    float translationSpeed = 0.05;
    float rotationSpeed;

};

#endif