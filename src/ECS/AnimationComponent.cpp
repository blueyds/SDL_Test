#include <Utilities.hpp>
#include "AnimationComponent.hpp"

void ECS::AnimationComponent::init(){
	sprite = &entity->getCompnent<ECS::Sprite>();
	transform = &entity->getComponent<ECS::Transformable>;
	
}

void ECS::AnimationComponent::update(){
	if (playing){
		int x = static_cast<int>(Utilities::getTicks() / speed % nFrames);
		int y = index * transforms->height;
		sprite->setSrcRectPos(x,y);
	}
}

void play(int mIndex){
	playing = true;
	index = mIndex;
}

void stop(){
	playing = false;
}