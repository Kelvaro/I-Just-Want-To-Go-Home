#pragma once

#include <glm\glm.hpp>
#include "EntitySystems\Component.h"
#include "EntitySystems\Entity.h"

class Camera : public Component
{
public: 
	float nearPlane = 0.1f;	 // near plane 
	float farPlane  = 50.0f; // far plane 
	float aspect    = 1.0f;	 // aspect ratio (width/height)
	float fov       = 60.0f; // field of view (degrees) or units vertically visible (ortho)
	bool  isOrtho   = false; // orthographic enabled

public:
	Camera(Entity* e) : Component(e) {};
	~Camera() {};
	virtual void Update(float dt) override {};
	virtual void Draw() override {};
	glm::mat4 GetProjectionMatrix(); 
	glm::mat4 GetViewMatrix(); 
};

