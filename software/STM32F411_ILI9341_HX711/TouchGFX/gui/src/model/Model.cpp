#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#ifndef SIMULATOR
//#include "stm32f4xx_hal.h"
#include "main.h"
extern __IO uint32_t raw_avg;
extern __IO uint32_t raw_avg_offset;
extern __IO int32_t weight_avg;
extern __IO double CalibrationX0;
extern __IO double CalibrationY0;
extern __IO double CalibrationX1;
extern __IO double CalibrationY1;
#endif

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
#ifndef SIMULATOR
	modelListener->Update_Weight_Text(weight_avg);
	modelListener->Update_RawWeight_Text(raw_avg);
	modelListener->Update_CalibrationX0_Text((uint32_t) CalibrationX0);
	modelListener->Update_CalibrationY0_Text((uint32_t) CalibrationY0);
	modelListener->Update_CalibrationX1_Text((uint32_t) CalibrationX1);
	modelListener->Update_CalibrationY1_Text((uint32_t) CalibrationY1);
#endif
}
void Model::reset_weight(){
#ifndef SIMULATOR
	raw_avg_offset = raw_avg;
#endif
}

void Model::Cx0_Update(double value){
#ifndef SIMULATOR
	CalibrationX0 = value;
#endif
}
void Model::Cx1_Update(double value){
#ifndef SIMULATOR
	CalibrationX1 = value;
#endif
}
void Model::Cy0_Update(double value){
#ifndef SIMULATOR
	CalibrationY0 = value;
#endif
}
void Model::Cy1_Update(double value){
#ifndef SIMULATOR
	CalibrationY1 = value;
#endif
}

void Model::save_Calibration(){
#ifndef SIMULATOR
	saveMemories();
#endif
}

void Model::restore_Calibration(){
#ifndef SIMULATOR
	CalibrationX0 = CALIBRATION_X0;
	CalibrationX1 = CALIBRATION_X1;
	CalibrationY0 = CALIBRATION_Y0;
	CalibrationY1 = CALIBRATION_Y1;
#endif
}

