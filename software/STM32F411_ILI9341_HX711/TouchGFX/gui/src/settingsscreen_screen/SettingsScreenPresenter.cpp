#include <gui/settingsscreen_screen/SettingsScreenView.hpp>
#include <gui/settingsscreen_screen/SettingsScreenPresenter.hpp>

SettingsScreenPresenter::SettingsScreenPresenter(SettingsScreenView& v)
    : view(v)
{

}

void SettingsScreenPresenter::activate()
{

}

void SettingsScreenPresenter::deactivate()
{

}
void SettingsScreenPresenter::Update_Weight_Text(int32_t value)
{
	view.Update_Weight_Text(value);
}

void SettingsScreenPresenter::Update_RawWeight_Text(uint32_t value)
{
	view.Update_RawWeight_Text(value);
}

void SettingsScreenPresenter::Update_CalibrationX0_Text(uint32_t value)
{
	view.Update_CalibrationX0_Text(value);
}

void SettingsScreenPresenter::Update_CalibrationY0_Text(uint32_t value)
{
	view.Update_CalibrationY0_Text(value);
}
void SettingsScreenPresenter::Update_CalibrationX1_Text(uint32_t value)
{
	view.Update_CalibrationX1_Text(value);
}
void SettingsScreenPresenter::Update_CalibrationY1_Text(uint32_t value)
{
	view.Update_CalibrationY1_Text(value);
}
void SettingsScreenPresenter::Cx0_Update(double value)
{
	model->Cx0_Update(value);
}
void SettingsScreenPresenter::Cx1_Update(double value)
{
	model->Cx1_Update(value);
}
void SettingsScreenPresenter::Cy0_Update(double value)
{
	model->Cy0_Update(value);
}
void SettingsScreenPresenter::Cy1_Update(double value)
{
	model->Cy1_Update(value);
}
void SettingsScreenPresenter::save_Calibration()
{
	model->save_Calibration();
}
void SettingsScreenPresenter::restore_Calibration()
{
	model->restore_Calibration();
}

