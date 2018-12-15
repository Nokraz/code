#include "Scene1.h"
#include <SDL.h>
Scene1::Scene1(SDL_Window* sdlWindow_){
	window = sdlWindow_;
	jetSki = nullptr;
	jetSki2 = nullptr;
}

Scene1::~Scene1(){
}

bool Scene1::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	projectionMatrix = MMath::viewportNDC(w,h) * MMath::orthographic(0.0f, 14.0f, 0.0f, 7.0f, 0.0f, 1.0f) ;
	
	jetSki = new Body(200.0f);
	jetSki2 = new Body(400.0f);
	
	jetSki->image = SDL_LoadBMP("jetski.bmp");
	jetSki2->image = SDL_LoadBMP("jetski.bmp");
	
	if (jetSki->image == nullptr || jetSki2->image == nullptr)
	{
		return false;
	}
	return true;
}

void Scene1::OnDestroy() 
{
	delete jetSki;
	delete jetSki2;
}

void Scene1::Update(const float time) {
	jetSki->ApplyForce(100.0f);
	jetSki2->ApplyForce(50.0f);
	
	jetSki->Update(time);
	jetSki2->Update(time);

}

void Scene1::Render() {

	Vec3 screenCoords = projectionMatrix * jetSki->position;
	SDL_Rect rect;
	rect.h = jetSki->image->h;
	rect.w = jetSki->image->w;
	rect.x = screenCoords.x; /// implicit type conversions BAD - probably causes a compiler warning
	rect.y = screenCoords.y; /// implicit type conversions BAD - probably causes a compiler warning
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	SDL_BlitSurface(jetSki->image, nullptr, screenSurface, &rect);

	// adding jetski image to the screen (JetSki 2)
	Vec3 screenCoords2 = projectionMatrix * jetSki2->position;
	rect.h = jetSki2->image->h;
	rect.w = jetSki2->image->w;
	rect.x = screenCoords2.x; /// implicit type conversions BAD - probably causes a compiler warning
	rect.y = screenCoords2.y; /// implicit type conversions BAD - probably causes a compiler warning
	SDL_BlitSurface(jetSki2->image, nullptr, screenSurface, &rect);
	SDL_UpdateWindowSurface(window);

}