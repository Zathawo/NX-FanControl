#include <tesla.hpp>
#include <fancontrol.h>
#include "utils.hpp"

class MainMenu : public tsl::Gui 
{
private:
    TemperaturePoint* _fanCurveTable;
    bool _tableIsChanged;

    tsl::elm::ToggleListItem* _enabledBtn;

    tsl::elm::ListItem* _p0Label;
    tsl::elm::ListItem* _p1Label;
    tsl::elm::ListItem* _p2Label;
    tsl::elm::ListItem* _p3Label;
    tsl::elm::ListItem* _p4Label;

public:
    MainMenu();

    virtual tsl::elm::Element* createUI() override;

    virtual void update() override;
};