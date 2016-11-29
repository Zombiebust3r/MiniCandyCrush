#pragma once
#include "Grid.hh"
#include "SceneManager.hh"
#include "GameScene.hh"

class Button
{
public:
	Button();
	~Button();
	void IsClicked(void);

private:
	Sprite b_sprite;
	struct coords { int x; int y; };
	coords buttonCoords;
	bool buttonClicked;
};

