#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>

MainScreenPresenter::MainScreenPresenter(MainScreenView& v)
    : view(v)
{

}

void MainScreenPresenter::activate()
{

}

void MainScreenPresenter::deactivate()
{

}

void MainScreenPresenter::Update_Weight_Text(int32_t value)
{
	view.Update_Weight_Text(value);
}
void MainScreenPresenter::reset_weight()
{
	model->reset_weight();
}
