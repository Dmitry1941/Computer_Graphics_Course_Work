#ifndef _NEW_GRAPHICS_H_
#define _NEW_GRAPHICS_H_

#include "Graphics.h"

class NewGarphics : public Graphics
{

private:

	std::vector<mesh> shapes;			

	float scale;						
	float _x, _y, _z;					
	float fThetaX, fThetaY, fThetaZ;

	mat4x4 matProj;						

	fPoint3D light;
	fPoint3D barycenter;

	
private:
	virtual void OnUserCreate() override;
	virtual void OnUserUpdate(float fElapsedTime) override;
};

#endif // !_NEW_GRAPHICS_H_
