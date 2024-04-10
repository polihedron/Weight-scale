#include <gui/settingsscreen_screen/SettingsScreenView.hpp>
#include <string.h>
#ifndef SIMULATOR

#endif

SettingsScreenView::SettingsScreenView():
okPressed(this,&SettingsScreenView::okPressedHandler),
exitPressed(this,&SettingsScreenView::exitPressedHandler),
text_C (0)
{

}

void SettingsScreenView::setupScreen()
{

    SettingsScreenViewBase::setupScreen();
	customKeyboard.setPosition(55,0,265,240);
	customKeyboard.setVisible(false);
	customKeyboard.setOKCallback(&okPressed);
	customKeyboard.setEXITCallback(&exitPressed);
	add(customKeyboard);
	customKeyboard.invalidate();
}

void SettingsScreenView::tearDownScreen()
{
    SettingsScreenViewBase::tearDownScreen();
}

void SettingsScreenView::Update_Weight_Text(int32_t value)
{
	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", value);

	textArea1.invalidate();

}

void SettingsScreenView::Update_RawWeight_Text(uint32_t  value)
{
	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%d", value);

	textArea2.invalidate();

}

void SettingsScreenView::Update_CalibrationX0_Text(uint32_t  value)
{
	Unicode::snprintf(textAreaCx0Buffer, TEXTAREACX0_SIZE, "%d", value);

	textAreaCx0.invalidate();

}

void SettingsScreenView::Update_CalibrationY0_Text(uint32_t  value)
{
	Unicode::snprintf(textAreaCy0Buffer, TEXTAREACY0_SIZE, "%d", value);

	textAreaCy0.invalidate();

}

void SettingsScreenView::Update_CalibrationX1_Text(uint32_t  value)
{
	Unicode::snprintf(textAreaCx1Buffer, TEXTAREACX1_SIZE, "%d", value);

	textAreaCx1.invalidate();

}

void SettingsScreenView::Update_CalibrationY1_Text(uint32_t  value)
{
	Unicode::snprintf(textAreaCy1Buffer, TEXTAREACY1_SIZE, "%d", value);

	textAreaCy1.invalidate();

}


void SettingsScreenView::okPressedHandler(){
    customKeyboard.setVisible(false);
    customKeyboard.invalidate();
    lineV0.setVisible(true);
	lineV0.invalidate();
	lineV1.setVisible(true);
	lineV1.invalidate();
	lineV2.setVisible(true);
	lineV2.invalidate();
	lineH0.setVisible(true);
	lineH0.invalidate();
	lineH1.setVisible(true);
	lineH1.invalidate();
	lineH2.setVisible(true);
	lineH2.invalidate();
	lineH3.setVisible(true);
	lineH3.invalidate();

	textArea1.setVisible(true);
	textArea1.invalidate();
	textArea2.setVisible(true);
	textArea2.invalidate();
	textAreaCx0.setVisible(true);
	textAreaCx0.invalidate();
	textAreaCx1.setVisible(true);
	textAreaCx1.invalidate();
	textAreaCy0.setVisible(true);
	textAreaCy0.invalidate();
	textAreaCy1.setVisible(true);
	textAreaCy1.invalidate();

	flexButtonReset.setVisible(true);
	flexButtonReset.invalidate();
	flexButtonSave.setVisible(true);
	flexButtonSave.invalidate();
	button1.setVisible(true);
	button1.invalidate();

    if (text_C == 1)	{
    	 Unicode::strncpy(textAreaCx0Buffer, customKeyboard.getBuffer(), TEXTAREACX0_SIZE);
    	 uint32_t KeypadNumber = Unicode::atoi(textAreaCx0Buffer);
    	 presenter->Cx0_Update(KeypadNumber);
    	 textAreaCx0.invalidate();
    }
    if (text_C == 2)	{
    	 Unicode::strncpy(textAreaCx1Buffer, customKeyboard.getBuffer(), TEXTAREACX1_SIZE);
    	 uint32_t KeypadNumber = Unicode::atoi(textAreaCx1Buffer);
    	 presenter->Cx1_Update(KeypadNumber);
    	 textAreaCx1.invalidate();
    }
    if (text_C == 3)	{
    	 Unicode::strncpy(textAreaCy0Buffer, customKeyboard.getBuffer(), TEXTAREACY0_SIZE);
    	 uint32_t KeypadNumber = Unicode::atoi(textAreaCy0Buffer);
    	 presenter->Cy0_Update(KeypadNumber);
    	 textAreaCy0.invalidate();
    }
    if (text_C == 4)	{
    	 Unicode::strncpy(textAreaCy1Buffer, customKeyboard.getBuffer(), TEXTAREACY1_SIZE);
    	 uint32_t KeypadNumber = Unicode::atoi(textAreaCy1Buffer);
    	 presenter->Cy1_Update(KeypadNumber);
    	 textAreaCy1.invalidate();
    }


    customKeyboard.clearBuffer();
}

void SettingsScreenView::exitPressedHandler(){
    customKeyboard.setVisible(false);
    customKeyboard.invalidate();
    lineV0.setVisible(true);
	lineV0.invalidate();
	lineV1.setVisible(true);
	lineV1.invalidate();
	lineV2.setVisible(true);
	lineV2.invalidate();
	lineH0.setVisible(true);
	lineH0.invalidate();
	lineH1.setVisible(true);
	lineH1.invalidate();
	lineH2.setVisible(true);
	lineH2.invalidate();
	lineH3.setVisible(true);
	lineH3.invalidate();

	textArea1.setVisible(true);
	textArea1.invalidate();
	textArea2.setVisible(true);
	textArea2.invalidate();
	textAreaCx0.setVisible(true);
	textAreaCx0.invalidate();
	textAreaCx1.setVisible(true);
	textAreaCx1.invalidate();
	textAreaCy0.setVisible(true);
	textAreaCy0.invalidate();
	textAreaCy1.setVisible(true);
	textAreaCy1.invalidate();

	flexButtonReset.setVisible(true);
	flexButtonReset.invalidate();
	flexButtonSave.setVisible(true);
	flexButtonSave.invalidate();
	button1.setVisible(true);
	button1.invalidate();
    text_C = 0;
}

void SettingsScreenView::calCx0Clicked()
{
    lineV0.setVisible(false);
    lineV0.invalidate();
    lineV1.setVisible(false);
    lineV1.invalidate();
    lineV2.setVisible(false);
    lineV2.invalidate();
    lineH0.setVisible(false);
    lineH0.invalidate();
    lineH1.setVisible(false);
    lineH1.invalidate();
    lineH2.setVisible(false);
    lineH2.invalidate();
    lineH3.setVisible(false);
    lineH3.invalidate();

    textArea1.setVisible(false);
    textArea1.invalidate();
    textArea2.setVisible(false);
    textArea2.invalidate();
    textAreaCx0.setVisible(false);
    textAreaCx0.invalidate();
    textAreaCx1.setVisible(false);
    textAreaCx1.invalidate();
    textAreaCy0.setVisible(false);
    textAreaCy0.invalidate();
    textAreaCy1.setVisible(false);
    textAreaCy1.invalidate();

    flexButtonReset.setVisible(false);
    flexButtonReset.invalidate();
    flexButtonSave.setVisible(false);
    flexButtonSave.invalidate();
    button1.setVisible(false);
    button1.invalidate();

    customKeyboard.setVisible(true);
    customKeyboard.invalidate();
    text_C = 1;


}


void SettingsScreenView::calCy0Clicked()
{
	lineV0.setVisible(false);
	lineV0.invalidate();
	lineV1.setVisible(false);
	lineV1.invalidate();
	lineV2.setVisible(false);
	lineV2.invalidate();
	lineH0.setVisible(false);
	lineH0.invalidate();
	lineH1.setVisible(false);
	lineH1.invalidate();
	lineH2.setVisible(false);
	lineH2.invalidate();
	lineH3.setVisible(false);
	lineH3.invalidate();

	textArea1.setVisible(false);
	textArea1.invalidate();
	textArea2.setVisible(false);
	textArea2.invalidate();
	textAreaCx0.setVisible(false);
	textAreaCx0.invalidate();
	textAreaCx1.setVisible(false);
	textAreaCx1.invalidate();
	textAreaCy0.setVisible(false);
	textAreaCy0.invalidate();
	textAreaCy1.setVisible(false);
	textAreaCy1.invalidate();

	flexButtonReset.setVisible(false);
	flexButtonReset.invalidate();
	flexButtonSave.setVisible(false);
	flexButtonSave.invalidate();
	button1.setVisible(false);
	button1.invalidate();

    customKeyboard.setVisible(true);
    customKeyboard.invalidate();
    text_C = 3;


}

void SettingsScreenView::calCx1Clicked()
{
	lineV0.setVisible(false);
	lineV0.invalidate();
	lineV1.setVisible(false);
	lineV1.invalidate();
	lineV2.setVisible(false);
	lineV2.invalidate();
	lineH0.setVisible(false);
	lineH0.invalidate();
	lineH1.setVisible(false);
	lineH1.invalidate();
	lineH2.setVisible(false);
	lineH2.invalidate();
	lineH3.setVisible(false);
	lineH3.invalidate();

	textArea1.setVisible(false);
	textArea1.invalidate();
	textArea2.setVisible(false);
	textArea2.invalidate();
	textAreaCx0.setVisible(false);
	textAreaCx0.invalidate();
	textAreaCx1.setVisible(false);
	textAreaCx1.invalidate();
	textAreaCy0.setVisible(false);
	textAreaCy0.invalidate();
	textAreaCy1.setVisible(false);
	textAreaCy1.invalidate();

	flexButtonReset.setVisible(false);
	flexButtonReset.invalidate();
	flexButtonSave.setVisible(false);
	flexButtonSave.invalidate();
	button1.setVisible(false);
	button1.invalidate();

    customKeyboard.setVisible(true);
    customKeyboard.invalidate();
    text_C = 2;


}
void SettingsScreenView::calCy1Clicked()
{
	lineV0.setVisible(false);
	lineV0.invalidate();
	lineV1.setVisible(false);
	lineV1.invalidate();
	lineV2.setVisible(false);
	lineV2.invalidate();
	lineH0.setVisible(false);
	lineH0.invalidate();
	lineH1.setVisible(false);
	lineH1.invalidate();
	lineH2.setVisible(false);
	lineH2.invalidate();
	lineH3.setVisible(false);
	lineH3.invalidate();

	textArea1.setVisible(false);
	textArea1.invalidate();
	textArea2.setVisible(false);
	textArea2.invalidate();
	textAreaCx0.setVisible(false);
	textAreaCx0.invalidate();
	textAreaCx1.setVisible(false);
	textAreaCx1.invalidate();
	textAreaCy0.setVisible(false);
	textAreaCy0.invalidate();
	textAreaCy1.setVisible(false);
	textAreaCy1.invalidate();

	flexButtonReset.setVisible(false);
	flexButtonReset.invalidate();
	flexButtonSave.setVisible(false);
	flexButtonSave.invalidate();
	button1.setVisible(false);
	button1.invalidate();

    customKeyboard.setVisible(true);
    customKeyboard.invalidate();
    text_C = 4;

}

void SettingsScreenView::saveClicked()
{
	presenter->save_Calibration();
}

void SettingsScreenView::restoreClicked()
{
	presenter->restore_Calibration();
}
