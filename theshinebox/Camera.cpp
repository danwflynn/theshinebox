#include "Camera.hpp"

Camera::Camera(sf::RenderWindow& window) :
	window(window)
{
}

void Camera::update(sf::Vector2f targetPosition)
{
    // Calculate the aspect ratio of the window
    float aspectRatio = static_cast<float>(window.getSize().x) / window.getSize().y;

    // Set the size of the view based on the aspect ratio
    view.setSize(1100 * aspectRatio, 1210); // Adjust these values as needed

    // Center the camera on the target position
    sf::Vector2f viewCenter = targetPosition;
    view.setCenter(viewCenter);

    // Apply the view to the window
    window.setView(view);
}
