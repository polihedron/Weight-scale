#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <string.h>

MainScreenView::MainScreenView()
{

}

void MainScreenView::setupScreen()
{
    MainScreenViewBase::setupScreen();
}

void MainScreenView::tearDownScreen()
{
    MainScreenViewBase::tearDownScreen();
}

void MainScreenView::Update_Weight_Text(int32_t value)
{
	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", value);
	textArea1.invalidate();

}

void MainScreenView::resetClicked(){

	presenter->reset_weight();
}
