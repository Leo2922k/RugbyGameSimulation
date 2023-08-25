#pragma once

#include <vector>
#include "PxPhysicsAPI.h"
#include "Exception.h"
#include "Extras\UserData.h"
#include <string>

namespace PhysicsEngine
{
	using namespace physx;
	using namespace std;
	
	///Initialise PhysX framework
	void PxInit();

	///Release PhysX resources
	void PxRelease();

	///Get the PxPhysics object
	PxPhysics* GetPhysics();

	///Get the cooking object
	PxCooking* GetCooking();

	///Get the specified material
	PxMaterial* GetMaterial(PxU32 index=0);

	///Create a new material
	PxMaterial* CreateMaterial(PxReal sf=.0f, PxReal df=.0f, PxReal cr=.0f);

	static const PxVec3 default_color(.8f,.8f,.8f);

	///Abstract Actor class
	///Inherit from this class to create your own actors
	class Actor
	{
	protected:
		PxActor* actor;
		std::vector<PxVec3> colors;
		std::string name;

	public:
		///Constructor
		Actor()
			: actor(0)
		{
		}

		PxActor* Get();

		void Color(PxVec3 new_color, PxU32 shape_index=-1);

		const PxVec3* Color(PxU32 shape_indx=0);

		void Actor::Name(const string& name);

		string Actor::Name();

		void Material(PxMaterial* new_material, PxU32 shape_index=-1);

		PxShape* GetShape(PxU32 index=0);

		std::vector<PxShape*> Actor::GetShapes(PxU32 index=-1);

		virtual void CreateShape(const PxGeometry& geometry, PxReal density) {}
	};

	class DynamicActor : public Actor
	{
	public:
		DynamicActor(const PxTransform& pose);

		~DynamicActor();

		void CreateShape(const PxGeometry& geometry, PxReal density);

		void SetKinematic(bool value, PxU32 index=-1);
	};

	// CompoundObject

	class CompoundObject : public DynamicActor {
	public:
		CompoundObject(const PxTransform& pose = PxTransform(PxIdentity)) : DynamicActor(pose) {
			// Create five sphere shapes and add them to the actor
			PxTransform localPose1(PxVec3(-.6f, 0.0f, 0.0f)); // position of the first sphere relative to the actor
			PxSphereGeometry sphere1(0.4f);
			CreateShape(sphere1, 1.0f);
			GetShape(0)->setLocalPose(localPose1);

			PxTransform localPose2(PxVec3(.6f, 0.0f, 0.0f)); // position of the second sphere relative to the actor
			PxSphereGeometry sphere2(0.4f);
			CreateShape(sphere2, 1.0f);
			GetShape(1)->setLocalPose(localPose2);

			PxTransform localPose3(PxVec3(0.0f, 0.0f, 0.0f)); // position of the third sphere relative to the actor
			PxSphereGeometry sphere3(.7f);
			CreateShape(sphere3, 1.0f);
			GetShape(2)->setLocalPose(localPose3);

			PxTransform localPose4(PxVec3(-0.4f, 0.0f, 0.0f)); // position of the fourth sphere relative to the actor
			PxSphereGeometry sphere4(.5f);
			CreateShape(sphere4, 1.0f);
			GetShape(3)->setLocalPose(localPose4);

			PxTransform localPose5(PxVec3(0.4f, 0.0f, 0.0f)); // position of the fifth sphere relative to the actor
			PxSphereGeometry sphere5(.5f);
			CreateShape(sphere5, 1.0f);
			GetShape(4)->setLocalPose(localPose5);

		}
	};

	class StaticActor : public Actor
	{
	public:
		StaticActor(const PxTransform& pose);

		~StaticActor();

		void CreateShape(const PxGeometry& geometry, PxReal density=0.f);
	};

	///Generic scene class
	class Scene
	{
	protected:
		//a PhysX scene object
		PxScene* px_scene;
		//pause simulation
		bool pause;
		//selected dynamic actor on the scene
		PxRigidDynamic* selected_actor;
		//original and modified colour of the selected actor
		std::vector<PxVec3> sactor_color_orig;

		void HighlightOn(PxRigidDynamic* actor);

		void HighlightOff(PxRigidDynamic* actor);

	public:
		///Init the scene
		void Init();

		///User defined initialisation
		virtual void CustomInit() {}

		///Perform a single simulation step
		void Update(PxReal dt);

		///User defined update step
		virtual void CustomUpdate() {}

		///Add actors
		void Add(Actor* actor);

		///Get the PxScene object
		PxScene* Get();

		///Reset the scene
		void Reset();

		///Set pause
		void Pause(bool value);

		///Get pause
		bool Pause();

		///Get the selected dynamic actor on the scene
		PxRigidDynamic* GetSelectedActor();

		///Switch to the next dynamic actor
		void SelectNextActor();

		///a list with all actors
		std::vector<PxActor*> GetAllActors();
	};
}
