#ifndef Scene1_H
#define Scene1_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Body.h"

using namespace MATH;
class Scene1 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projectionMatrix;

	 Body * jetSki;
	 Body * jetSki2;

public:
	Scene1(SDL_Window* sdlWindow);
	~Scene1();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
};

#endif

