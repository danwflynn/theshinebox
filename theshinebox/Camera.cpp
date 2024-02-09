#include "Camera.hpp"
#include <algorithm>

Camera::Camera(sf::RenderWindow& window) :
	window(window)
{
}

void Camera::update(float x, float y)
{
    float centerX = std::max(x, 770.f);
    float centerY = std::min(y, 450.f);

    // Calculate the aspect ratio of the window
    float aspectRatio = static_cast<float>(window.getSize().x) / window.getSize().y;

    // Set the size of the view based on the aspect ratio
    view.setSize(1100 * aspectRatio, 1100); // Adjust these values as needed

    // Center the camera on the target position
    sf::Vector2f viewCenter(centerX, centerY);
    view.setCenter(viewCenter);

    // Apply the view to the window
    window.setView(view);
}
