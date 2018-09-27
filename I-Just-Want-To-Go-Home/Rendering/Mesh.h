#pragma once

#include <vector>
#include <glm/glm.hpp>

/* Testing out javadoc style documentation */

struct Vertex
{
	glm::vec3 Position;
	glm::vec2 Uv;
	glm::vec3 Normal; 

	Vertex() {};
	Vertex(float x, float y, float z, 
		float u, float v, 
		float nx, float ny, float nz) 
	{
		// TODO: use proper construtors
		Position = glm::vec3(x, y, z);	
		Uv = glm::vec2(u, v);
		Normal = glm::vec3(nx, ny, nz);
	};
};


/**
Geometry data for a model. Includes position, normals, and texture coordinates. 
Vertex data is sequenced: { x y z u v nx ny nz }
*/
class Mesh
{
public: 
	// Might want to revise this into array of Vertex
	float* vertices;
	unsigned int vertexCount;
	unsigned int* indices;
	unsigned int triangleCount; 
	unsigned int VAO; 

public:
	/**
	Initializes a mesh with all geometry data. 
	@param	vertices		All vertices in the format of { x y z u v nx ny nz ... } 
	@param	vertexCount		The number of vertices (not the size of vertices array!)
	@param	indices			An array specifying the triangles to draw in the format of { v1 v2 v3 ... } 
	@param	triangleCount	The number of triangles (not the size of indices array!)
	*/
	Mesh(float vertices[], 
		unsigned int vertexCount,
		unsigned int indices[],
		unsigned int triangleCount);
	
	Mesh(std::vector<Vertex> vertices, 
		std::vector<unsigned int> indices);
	
	~Mesh();
};

