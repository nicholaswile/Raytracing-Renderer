#pragma once

class Camera {
public:
    Camera();
    float* GetPosition() {
        return m_Position;
    }
    float* GetOrientation() {
        return m_Orientation;
    }
    float GetViewportWidth() {
        return m_viewportWidth;
    }
    float GetViewportHeight() {
        return m_viewportHeight;
    }
    float GetViewportDistance() {
        return m_viewportDistance;
    }
    int GetScreenWidth() {
        return m_screenWidth;
    }
    int GetScreenHeight() {
        return m_screenHeight;
    }
    void SetPosition(float x, float y, float z) {
        m_Position[0] = x;
        m_Position[1] = y;
        m_Position[2] = z;
    }
    void SetOrientation(float x, float y, float z) {
        m_Orientation[0] = x;
        m_Orientation[1] = y;
        m_Orientation[2] = z;
    }
    void SetViewportWidth(float width) {
        m_viewportWidth = width;
    }
    void SetViewportHeight(float height) {
        m_viewportHeight = height;
    }
    void SetViewportDistance(float d) {
        m_viewportDistance = d;
    }
    void SetScreenWidth(float width) {
        m_screenWidth = width;
    }
    void SetScreenHeight(float height) {
        m_screenHeight = height;
    }
    // Given canvas coordinates of the current pixel, determine corresponding position in viewport (space)
    float* CanvasToViewport(int canvasX, int canvasY) {
        return new float[3] {
            canvasX* m_viewportWidth / m_screenWidth,
            canvasY* m_viewportHeight / m_screenHeight,
            m_viewportDistance
        };
    }
private:
    float m_Position[3];
    float m_Orientation[3];
    float m_viewportWidth;
    float m_viewportHeight;
    float m_viewportDistance; // the distance between the camera and viewport/projection plane
    int m_screenWidth;
    int m_screenHeight;
};

