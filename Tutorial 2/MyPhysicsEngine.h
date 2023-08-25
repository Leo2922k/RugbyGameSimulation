#pragma once

#include "BasicActors.h"
#include <iostream>
#include <iomanip>
#include "VisualDebugger.h"
#include <vector>
#include "Extras\Camera.h"
#include "Extras\Renderer.h"
#include "Extras\HUD.h"
#include "foundation/PxTransform.h"
#include "foundation/PxMat33.h"

namespace PhysicsEngine
{
	using namespace std;

	//a list of colours: Circus Palette
	static const PxVec3 color_palette[] = {PxVec3(0.f,153.f/255.f,0.f),PxVec3(255.f,255.f,255.f),
		PxVec3(255.f/255.f,45.f/255.f,0.f/255.f),PxVec3(255.f/255.f,140.f/255.f,54.f/255.f),PxVec3(4.f/255.f,117.f/255.f,111.f/255.f)};

	

	//RugbyField vertices

	static PxVec3 RugbyField_verts[] = { PxVec3(-5,0,0), PxVec3(111,0,0), PxVec3(-5,0,68), PxVec3(111,.02,68)};

	class RugbyField : public ConvexMesh 
	{
	public:
		RugbyField(PxTransform pose = PxTransform(PxIdentity), PxReal density = 1.f) :
			ConvexMesh(vector<PxVec3>(begin(RugbyField_verts), end(RugbyField_verts)), pose, density)
		{
		}
	};

	// field lines 
	// lineC

	static PxVec3 lineC_verts[] = { PxVec3(52.8,0,0), PxVec3(53.2,0,0), PxVec3(52.8,0,68), PxVec3(53.2,.02,68)};

	class LineC : public ConvexMesh
	{
	public:
		LineC(PxTransform pose = PxTransform(PxIdentity), PxReal density = 1.f) :
			ConvexMesh(vector<PxVec3>(begin(lineC_verts), end(lineC_verts)), pose, density)
		{
		}
	};

	// lineA

	static PxVec3 lineA_verts[] = { PxVec3(2.8,0,0), PxVec3(3.2,0,0), PxVec3(2.8,0,68), PxVec3(3.2,.02,68) };

	class LineA : public ConvexMesh
	{
	public:
		LineA(PxTransform pose = PxTransform(PxIdentity), PxReal density = 1.f) :
			ConvexMesh(vector<PxVec3>(begin(lineA_verts), end(lineA_verts)), pose, density)
		{
		}
	};

	// lineB

	static PxVec3 lineB_verts[] = { PxVec3(102.8,0,0), PxVec3(103.2,0,0), PxVec3(102.8,0,68), PxVec3(103.2,.02,68) };

	class LineB : public ConvexMesh
	{
	public:
		LineB(PxTransform pose = PxTransform(PxIdentity), PxReal density = 1.f) :
			ConvexMesh(vector<PxVec3>(begin(lineB_verts), end(lineB_verts)), pose, density)
		{
		}
	};

	// lineD

	static PxVec3 lineD_verts[] = { PxVec3(27.8,0,0), PxVec3(28.2,0,0), PxVec3(27.8,0,68), PxVec3(28.2,.02,68) };

	class LineD : public ConvexMesh
	{
	public:
		LineD(PxTransform pose = PxTransform(PxIdentity), PxReal density = 1.f) :
			ConvexMesh(vector<PxVec3>(begin(lineD_verts), end(lineD_verts)), pose, density)
		{
		}
	};

	// lineE

	static PxVec3 lineE_verts[] = { PxVec3(78.8,0,0), PxVec3(79.2,0,0), PxVec3(78.8,0,68), PxVec3(79.2,.02,68) };

	class LineE : public ConvexMesh
	{
	public:
		LineE(PxTransform pose = PxTransform(PxIdentity), PxReal density = 1.f) :
			ConvexMesh(vector<PxVec3>(begin(lineE_verts), end(lineE_verts)), pose, density)
		{
		}
	};
	



	//goal vertices
	static PxVec3 goal_verts1[] = {PxVec3(0,0,0), PxVec3(.3,0,0), PxVec3(0,16,0), PxVec3(.3,16,0),
		                          PxVec3(0,0,.3), PxVec3(.3,0,.3), PxVec3(0,16,.3), PxVec3(.3,16,.3) };

	static PxVec3 goal_verts2[] = { PxVec3(0,0,0), PxVec3(.3,0,0), PxVec3(0,.3,0), PxVec3(.3,.3,0),
								    PxVec3(0,0,6), PxVec3(.3,0,6), PxVec3(0,.3,6), PxVec3(.3,.3,6) };

	// goal implemented by ConvexMesh
	class goal1 : public ConvexMesh
	{
	public:
		goal1(PxTransform pose = PxTransform(PxIdentity), PxReal density = 1.f) :
			ConvexMesh(vector<PxVec3>(begin(goal_verts1), end(goal_verts1)), pose, density)
		{
		}
	};

	class goal2 : public ConvexMesh
	{
	public:
		goal2(PxTransform pose = PxTransform(PxIdentity), PxReal density = 1.f) :
			ConvexMesh(vector<PxVec3>(begin(goal_verts2), end(goal_verts2)), pose, density)
		{
		}
	};



	///Custom scene class
	class MyScene : public Scene
	{

		Plane* plane;
		Rugby* rugby;
		SSphere* sun;
		Sphere* MOVERHOVER;
		RugbyField* RF;
		goal1* G1;
		goal1* G2;
		goal1* G3;
		goal1* G4;
		goal2* G5;
		goal2* G6;
		LineA* lineA;
		LineB* lineB;
		LineC* lineC;
		LineD* lineD;
		LineE* lineE;

	public:

		///A custom scene class
		void SetVisualisation()
		{
			px_scene->setVisualizationParameter(PxVisualizationParameter::eSCALE, 1.0f);
			px_scene->setVisualizationParameter(PxVisualizationParameter::eCOLLISION_SHAPES, 1.0f);
		}

		// balls waterfalls
		void ducks() {
			int x = 5;
			while (x--) {
				Rugby* balls;

				balls = new Rugby(PxTransform(PxVec3(25.0f, 25.f, 15.0f)));
				balls->Color(color_palette[2]);
				Add(balls);
			}
		};

		//Custom scene initialisation
		virtual void CustomInit() 
		{
			PxMaterial* Aluminum = CreateMaterial(0.61, 0.47, 0.75);


			SetVisualisation();			

			GetMaterial()->setDynamicFriction(.2f);

			plane = new Plane();
			plane->Color(PxVec3(0.f,0.f,0.f));
			Add(plane);

			RF = new RugbyField(PxTransform(PxVec3(0.0f, 0.f, .0f)));
			RF->Color(color_palette[0]);
			PxMaterial* RFMaterial = GetPhysics()->createMaterial(0.2f, 0.25f, 0.1f);
			RF->Material(RFMaterial);
			Add(RF);

			G1 = new goal1(PxTransform(PxVec3(3.0f, 0.f, 31.0f)));
			G1->Color(color_palette[1]);
			Add(G1);

			G2 = new goal1(PxTransform(PxVec3(3.0f, 0.f, 37.0f)));
			G2->Color(color_palette[1]);
			Add(G2);


			G3 = new goal1(PxTransform(PxVec3(103.0f, 0.f, 31.0f)));
			G3->Color(color_palette[1]);
			Add(G3);

			G4 = new goal1(PxTransform(PxVec3(103.0f, 0.f, 37.0f)));
			G4->Color(color_palette[1]);
			Add(G4);


			G5 = new goal2(PxTransform(PxVec3(3.0f, 4.f, 31.0f)));
			G5->Color(color_palette[1]);
			Add(G5);

			G6 = new goal2(PxTransform(PxVec3(103.0f, 4.f, 31.0f)));
			G6->Color(color_palette[1]);
			Add(G6);

			lineA = new LineA();
			lineA->Color(PxVec3(1.f, 1.f, 1.f));
			PxMaterial* lineMaterial = GetPhysics()->createMaterial(0.61f, 0.47f, 0.45f);
			lineA->Material(lineMaterial);
			Add(lineA);

			lineB = new LineB();
			lineB->Color(PxVec3(1.f, 1.f, 1.f));
			lineB->Material(lineMaterial);
			Add(lineB);

			lineC = new LineC();
			lineC->Color(PxVec3(1.f, 1.f, 1.f));
			lineC->Material(lineMaterial);
			Add(lineC);

			lineD = new LineD();
			lineD->Color(PxVec3(1.f, 1.f, 1.f));
			lineD->Material(lineMaterial);
			Add(lineD);

			lineE = new LineE();
			lineE->Color(PxVec3(1.f, 1.f, 1.f));
			lineE->Material(lineMaterial);
			Add(lineE);

			

			sun = new SSphere(PxTransform(PxVec3(25.0f, 25.f, 15.0f)));
			sun->Color(PxVec3(1.f,1.f, 0.f));
			Add(sun);


			MOVERHOVER = new Sphere(PxTransform(PxVec3(48.0f, 0.0f, 30.0f)));
			MOVERHOVER->Color(PxVec3(1.f, 1.f, 0.f));
			Add(MOVERHOVER);

			rugby = new Rugby(PxTransform(PxVec3(50.0f, 0.0f, 30.0f)));
			rugby->Color(color_palette[2]);
			PxMaterial* ballMaterial = GetPhysics()->createMaterial(0.2f, 0.5f, 1.3f);
			rugby->Material(ballMaterial);
			Add(rugby);

			


		}

		//Custom udpate function
		virtual void CustomUpdate() 
		{
		}
	};
}
