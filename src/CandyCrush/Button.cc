#include "Button.hh"



Button::Button(void) {
	buttonClicked = false;
	b_sprite = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::BT_Play };
}


Button::~Button()
{
}


void Button::IsClicked(void) {
	static MouseCoords mouseCoords(0, 0);
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) {
		mouseCoords = IM.GetMouseCoords();
		if (mouseCoords.x >= (W.GetWidth() / 2) - 60 && mouseCoords.x <= (W.GetWidth() / 2) + 60 && mouseCoords.y >= (W.GetHeight() / 2) - 30 && mouseCoords.y >= (W.GetHeight() / 2) + 30) {
			buttonClicked = true;
			SM.SetCurScene<GameScene>();
		}
	}
}