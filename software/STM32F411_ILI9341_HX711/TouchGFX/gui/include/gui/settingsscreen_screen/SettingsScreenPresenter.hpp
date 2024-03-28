#ifndef SETTINGSSCREENPRESENTER_HPP
#define SETTINGSSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SettingsScreenView;

class SettingsScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SettingsScreenPresenter(SettingsScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~SettingsScreenPresenter() {};

    virtual void Update_Weight_Text(int32_t value);
    virtual void Update_RawWeight_Text(uint32_t value);
    virtual void Update_CalibrationX0_Text(uint32_t value);
    virtual void Update_CalibrationY0_Text(uint32_t value);
    virtual void Update_CalibrationX1_Text(uint32_t value);
    virtual void Update_CalibrationY1_Text(uint32_t value);

    virtual void Cy1_Update(double value);
    virtual void Cy0_Update(double value);
    virtual void Cx1_Update(double value);
    virtual void Cx0_Update(double value);

    virtual void save_Calibration();
    virtual void restore_Calibration();

private:
    SettingsScreenPresenter();

    SettingsScreenView& view;
};

#endif // SETTINGSSCREENPRESENTER_HPP
