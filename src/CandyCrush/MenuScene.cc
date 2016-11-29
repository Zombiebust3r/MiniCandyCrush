#include "GUI.hh"
#include "System.hh"
#include "Logger.hh"
#include "MenuScene.hh"
using namespace Logger;

#define CELL_WIDTH 80
#define CELL_HEIGHT 80

MenuScene::MenuScene(void) {
	m_background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::BG_Menu };
	buttonClicked = false;
}

MenuScene::~MenuScene(void) {
}

void MenuScene::OnEntry(void) {
}

void MenuScene::OnExit(void) {
}

bool MenuScene::ButtonIsClicked(void) {
	return buttonClicked;
}

void MenuScene::Update(void) {
	static MouseCoords mouseCoords(0, 0);
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) {
		Println("===============");
		Println("mxp: ", mouseCoords);
		mouseCoords = IM.GetMouseCoords();
		if (mouseCoords.x >= (W.GetWidth()/2)-60 && mouseCoords.x <= (W.GetWidth() / 2) + 60 && mouseCoords.y >= (W.GetHeight() / 2) - 30 && mouseCoords.y >= (W.GetHeight() / 2) + 30) {
			buttonClicked = true;
		}
	}
	else if (IM.IsMouseUp<MOUSE_BUTTON_LEFT>()) {
		Println("mxn: ", IM.GetMouseCoords());
	}
							// Test InputManager key methods
	if (IM.IsKeyHold<'a'>()) Println("a hold");
	if (IM.IsKeyDown<'0'>()) Println("0 down");
	if (IM.IsKeyUp<KEY_BUTTON_DOWN>()) Println("down arrow up");

}

void MenuScene::Draw(void) {
	m_background.Draw(); // Render background
	
	/*m_grid.Draw(); // Render grid
	GUI::DrawTextShaded<FontID::FACTORY>("ENTI CRUSH",
	{ W.GetWidth() >> 1, int(W.GetHeight()*.1f), 1, 1 },
	{ 190, 0, 160 }, { 50, 200, 230 }); // Render score that will be different when updated
	GUI::DrawTextBlended<FontID::CANDY>("Score: " + std::to_string(m_score),
	{ W.GetWidth() >> 1, int(W.GetHeight()*.9f), 1, 1 },
	{ 115, 0, 180 }); // Render score that will be different when updated
	*/
}
