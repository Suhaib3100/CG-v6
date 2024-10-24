#include <iostream>
#include <GLFW/glfw3.h>
#include "EmotionDetector.h"
#include "Renderer.h"
#include "AudioPlayer.h"

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Emotion Detector", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize Emotion Detector, Renderer, and Audio Player
    EmotionDetector detector;
    Renderer renderer;
    AudioPlayer audioPlayer;

    while (!glfwWindowShouldClose(window)) {
        // Detect emotion
        std::string emotion = detector.detectEmotion();

        // Render based on detected emotion
        renderer.render(emotion);

        // Play appropriate song
        audioPlayer.playSong(emotion);

        // Swap front and back buffers
        glfwSwapBuffers(window);
        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
