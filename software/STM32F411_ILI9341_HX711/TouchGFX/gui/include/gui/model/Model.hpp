#ifndef MODEL_HPP
#define MODEL_HPP
#ifndef SIMULATOR

#endif
#include "stdint.h"
class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void reset_weight();
    void Cx0_Update(uint32_t value);
    void Cx1_Update(uint32_t value);
    void Cy0_Update(uint32_t value);
    void Cy1_Update(uint32_t value);
    void save_Calibration();
    void restore_Calibration();

protected:
    ModelListener* modelListener;

};

#endif // MODEL_HPP
