#include "NewGarphics.h"

void NewGarphics::OnUserCreate()
{
	shapes.resize(2);

	shapes[0].tris =
	{
		
		// Перед
		{ 0.0f, 0.0f, 0.0f,    0.0f, 2.0f, 0.0f,    1.0f, 2.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f,    1.0f, 2.0f, 0.0f,    1.0f, 0.0f, 0.0f },

		// Право
		{ 1.0f, 0.0f, 0.0f,    1.0f, 2.0f, 0.0f,    1.0f, 2.0f, 1.0f },
		{ 1.0f, 0.0f, 0.0f,    1.0f, 2.0f, 1.0f,    1.0f, 0.0f, 1.0f },
	
		// Зад
		{ 1.0f, 0.0f, 1.0f,    1.0f, 2.0f, 1.0f,    0.0f, 2.0f, 1.0f },
		{ 1.0f, 0.0f, 1.0f,    0.0f, 2.0f, 1.0f,    0.0f, 0.0f, 1.0f },

		// Лево
		{ 0.0f, 0.0f, 1.0f,    0.0f, 2.0f, 1.0f,    0.0f, 2.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f,    0.0f, 2.0f, 0.0f,    0.0f, 0.0f, 0.0f },

		// Лево
		{ 0.0f, 0.0f, 1.0f,    0.0f, 2.0f, 1.0f,    0.0f, 2.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f,    0.0f, 2.0f, 0.0f,    0.0f, 0.0f, 0.0f },

		// Вверх
		{ 0.0f, 2.0f, 0.0f,    0.0f, 2.0f, 1.0f,    1.0f, 2.0f, 1.0f },
		{ 0.0f, 2.0f, 0.0f,    1.0f, 2.0f, 1.0f,    1.0f, 2.0f, 0.0f },

		// Низ
		{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f },
		{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f }
	};

	shapes[1].tris =
	{
		
		
		//Перед
		{ 0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 0.0f, 0.0f },

		// Право
		{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 1.0f },

		// Зад
		{ 1.0f, 0.0f, 1.0f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f },

		// Лево
		{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 0.0f,    0.0f, 0.0f, 0.0f },

		// Лево
		{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 0.0f,    0.0f, 0.0f, 0.0f },

		// Вверх
		{ 0.0f, 1.0f, 0.0f,    0.0f, 1.0f, 1.0f,    1.0f, 1.0f, 1.0f },
		{ 0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f, 0.0f },

		// Низ
		{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f },
		{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f }

		
	};

	
	matProj = Matrix_MakeProjection(90.0f, static_cast<float>(GetConsoleHeight()) / static_cast<float>(GetConsoleWidth()), 0.1f, 1000.0f);

	light.x = 1.0f;
	light.y = -100.0f;
	light.z = 1.0f;
	
	scale = 1.0f;							
	_x = 0.5f; _y = 0.5f; _z = 4.0f;
	fThetaX = fThetaY = fThetaZ = 0.0f;
}

void NewGarphics::OnUserUpdate(float fElapsedTime)
{
	
	Fill(0, 0, GetConsoleWidth(), GetConsoleHeight());

	
	Fill(0, iConsoleHeight / 2, iConsoleWidth, iConsoleHeight, PIXEL_SOLID, FG_WHITE);

	//// Move around axies
	if (GetKey(L'X').bHeld)
		fThetaX += 8.0f * fElapsedTime;
	if (GetKey(L'Y').bHeld)
		fThetaY += 8.0f * fElapsedTime;
	
	if (GetKey(L'Z').bHeld)
		fThetaZ += 8.0f * fElapsedTime;
	

	// Scaling
	if (GetKey(L'1').bHeld)		
		scale = (scale <= 1.2f) ? scale + 0.01f : scale;
	if (GetKey(L'2').bHeld)		
		scale = (scale >= 0.5f) ? scale - 0.01f : scale;



	if (IsFocused())
	{
		if (GetKey(VK_LBUTTON).bHeld)
		{
			if (GetMouseX() >= 0.9f * iConsoleWidth)		// Move to right
				_x += 0.005f;
			if (GetMouseX() <= 0.2f * iConsoleWidth)		// Move to left
				_x -= 0.005f;
			if (GetMouseY() <= 0.2f * iConsoleHeight)		// Move to up
				_y -= 0.005f;
			if (GetMouseY() >= 0.9f * iConsoleHeight)		// Move to down
				_y += 0.005f;
			if ((GetMouseX() >= 0.40f * iConsoleWidth) && (GetMouseX() <= 0.60f * iConsoleWidth)
				&& (GetMouseY() >= 0.35f * iConsoleHeight) && (GetMouseY() <= 0.49f * iConsoleHeight))		// Move to forward
				_z = (_z < 7.0f) ? _z + 0.1f : _z;
			if ((GetMouseX() >= 0.40f * iConsoleWidth) && (GetMouseX() <= 0.60f * iConsoleWidth)
				&& (GetMouseY() >= 0.51f * iConsoleHeight) && (GetMouseY() <= 0.65f * iConsoleHeight))		// Move to back
				_z = (_z > 4.5f) ? _z - 0.1f : _z;
		}
	}


	mat4x4 matRotX, matRotY, matRotZ;
	matRotX = Matrix_MakeRotationX(fThetaX * 0.5f);
	matRotY = Matrix_MakeRotationY(fThetaY * 0.5f);
	matRotZ = Matrix_MakeRotationZ(fThetaZ * 0.5f);

	mat4x4 ScalingMatrix;
	ScalingMatrix = Matrix_MakeScale(scale, scale, scale);

	mat4x4 TranslationMatrix;
	TranslationMatrix = Matrix_MakeTranslation(0.0f, 0.0f, _z);

	mat4x4 WorldMatrix;
	WorldMatrix = Matrix_MakeIdentity();
	WorldMatrix = matRotY * matRotX * matRotZ * ScalingMatrix * TranslationMatrix;

	std::vector<triangle> vecTrianglesToRaster;

	float  t = 0.0f;					
	int16_t tri_color = FG_DARK_GREEN;
	int16_t count_tris = 0;
	for (auto& sh: shapes) 
	{
		
		for (auto tri : sh.tris)
		{
			triangle triProjected, triTransformed;

			triTransformed.points[0] = MultiplyMatrixVector(WorldMatrix, tri.points[0]);
			triTransformed.points[1] = MultiplyMatrixVector(WorldMatrix, tri.points[1]);
			triTransformed.points[2] = MultiplyMatrixVector(WorldMatrix, tri.points[2]);		

		
			triProjected.points[0] = MultiplyMatrixVector(matProj, triTransformed.points[0]);
			triProjected.points[1] = MultiplyMatrixVector(matProj, triTransformed.points[1]);
			triProjected.points[2] = MultiplyMatrixVector(matProj, triTransformed.points[2]);

		

			triProjected.points[0] = triProjected.points[0] / triProjected.points[0].w;
			triProjected.points[1] = triProjected.points[1] / triProjected.points[1].w;
			triProjected.points[2] = triProjected.points[2] / triProjected.points[2].w;

			
			triProjected.points[0].x *= -1.0f;
			triProjected.points[1].x *= -1.0f;
			triProjected.points[2].x *= -1.0f;
			triProjected.points[0].y *= -1.0f;
			triProjected.points[1].y *= -1.0f;
			triProjected.points[2].y *= -1.0f;

			
			for (int16_t i = 0; i < 3; i++)
			{
				triProjected.points[i].x += _x + t;
				triProjected.points[i].y += _y;

				triProjected.points[i].x *= 0.5f * static_cast<float>(GetConsoleWidth());
				triProjected.points[i].y *= 0.5f * static_cast<float>(GetConsoleHeight());

				
				barycenter += triProjected.points[i];
			}
			count_tris++;

		
			tri_color++;
			if (tri_color == FG_GREY) tri_color++;
			triProjected.col = tri_color;

			vecTrianglesToRaster.push_back(triProjected);
		}

	
		barycenter /= count_tris * 3;

	
		std::sort(vecTrianglesToRaster.begin(), vecTrianglesToRaster.end(), [](triangle& t1, triangle& t2)
			{
				float z1 = (t1.points[0].z + t1.points[1].z + t1.points[2].z) / 3.0f;
				float z2 = (t2.points[0].z + t2.points[1].z + t2.points[2].z) / 3.0f;
				return z1 > z2; // was >
			});

	
		for (auto& tri : vecTrianglesToRaster)
		{
			for (int16_t i = 0; i < 3; i++)
			{
				tri.points[i].x = roundf(tri.points[i].x);
				tri.points[i].y = roundf(tri.points[i].y);
			}
		}

		
		DrawShadow(vecTrianglesToRaster, light);
		std::vector<triangle> vecVisibleSurfaces;
		fPoint3D view_point = { static_cast<float>(iConsoleWidth) / 2.0f, static_cast<float>(iConsoleHeight) / 2.0f, -100.0f };

		vecVisibleSurfaces = RobertsAlgorithm(vecTrianglesToRaster, view_point, barycenter, PIXEL_THREEQUARTERS, BG_GREEN);
		RobertsAlgorithm(vecVisibleSurfaces, light, barycenter, PIXEL_THREEQUARTERS, BG_GREEN);
		
		t += 1.0f;
		count_tris = 0;
		barycenter = 0.0f;
		vecTrianglesToRaster.clear();
	}
}