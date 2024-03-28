#ifndef MODEL_HPP
#define MODEL_HPP

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
    void Cx0_Update(double value);
    void Cx1_Update(double value);
    void Cy0_Update(double value);
    void Cy1_Update(double value);
    void save_Calibration();
    void restore_Calibration();

protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
