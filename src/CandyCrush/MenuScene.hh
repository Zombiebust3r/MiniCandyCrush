#pragma once
#include "Grid.hh"
#include "Scene.hh"
#include "Button.hh"

// GameScene class with the main gameplay mode
class MenuScene : public Scene {
public:
	explicit MenuScene();
	~MenuScene() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	bool ButtonIsClicked(void);
	void Draw(void) override;
private:
	Sprite m_background;
	bool buttonClicked;

};