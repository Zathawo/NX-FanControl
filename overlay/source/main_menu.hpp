#include <tesla.hpp>
#include <fancontrol.h>
#include "utils.hpp"

class MainMenu : public tsl::Gui 
{
private:
    TemperaturePoint *fanCurveTable;

    tsl::elm::ToggleListItem *enabledBtn;

    tsl::elm::ListItem *p0Label;
    tsl::elm::ListItem *p1Label;
    tsl::elm::ListItem *p2Label;
    tsl::elm::ListItem *p3Label;
    tsl::elm::ListItem *p4Label;

public:
    MainMenu();

    virtual tsl::elm::Element* createUI() override;

    virtual void update() override;
};