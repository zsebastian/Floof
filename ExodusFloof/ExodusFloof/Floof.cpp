#include "Floof.h"
#include "StaticObject.h"
#include "Collidable.h"
#include "SimpleImageJob.h"

Floof::Floof(double x, double y, b2World& world):
	GameObject(x, y, world)
	,mBody(nullptr)
{
	SetSizeX(64);
	SetSizeY(64);

	SetID("Floof");

	b2BodyDef bodyDef;
	bodyDef.position.Set(x, y);
	mBody = world.CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(32.0f, 32.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	mBody->CreateFixture(&fixtureDef);

}
	
Floof::~Floof()
{
	GetWorld().DestroyBody(mBody);
}

void Floof::Render()
{
	GetCanvas()->AddNewJob(new SimpleImageJob("Floof", GetX() - 32, GetY() - 32), 1);
}
