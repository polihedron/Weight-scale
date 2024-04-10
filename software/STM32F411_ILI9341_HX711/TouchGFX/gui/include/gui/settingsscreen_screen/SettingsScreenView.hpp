#ifndef SETTINGSSCREENVIEW_HPP
#define SETTINGSSCREENVIEW_HPP

#include <gui_generated/settingsscreen_screen/SettingsScreenViewBase.hpp>
#include <gui/settingsscreen_screen/SettingsScreenPresenter.hpp>
#include <gui/common/CustomNumericKeyboard.hpp>


class SettingsScreenView : public SettingsScreenViewBase
{

public:
    SettingsScreenView();
    virtual ~SettingsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void Update_Weight_Text(int32_t value);
    virtual void Update_RawWeight_Text(uint32_t value);
    virtual void Update_CalibrationX0_Text(uint32_t value);
    virtual void Update_CalibrationY0_Text(uint32_t value);
    virtual void Update_CalibrationX1_Text(uint32_t value);
    virtual void Update_CalibrationY1_Text(uint32_t value);
    virtual void calCx0Clicked();
    virtual void calCx1Clicked();
    virtual void calCy0Clicked();
    virtual void calCy1Clicked();
    virtual void saveClicked();
    virtual void restoreClicked();

    void okPressedHandler();
    void exitPressedHandler();




protected:

    CustomNumericKeyboard customKeyboard;

    Callback<SettingsScreenView> okPressed;

    Callback<SettingsScreenView> exitPressed;

    int text_C;


private:


};

#endif // SETTINGSSCREENVIEW_HPP
