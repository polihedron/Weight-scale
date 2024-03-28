#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <touchgfx/hal/Types.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }


    virtual void Update_Weight_Text(int32_t value) {}
    virtual void Update_RawWeight_Text(uint32_t value) {}
    virtual void Update_CalibrationX0_Text(uint32_t value) {}
    virtual void Update_CalibrationY0_Text(uint32_t value) {}
    virtual void Update_CalibrationX1_Text(uint32_t value) {}
    virtual void Update_CalibrationY1_Text(uint32_t value) {}

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
