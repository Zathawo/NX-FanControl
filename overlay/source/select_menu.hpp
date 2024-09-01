#include <tesla.hpp>
#include "utils.hpp"

class SelectMenu : public tsl::Gui {
private:
    int i = 0;
    TemperaturePoint *fanCurveTable;

    tsl::elm::CategoryHeader *tempLabel;
    tsl::elm::CategoryHeader *fanLabel;
    tsl::elm::ListItem *saveBtn;

public:
    SelectMenu(int i, TemperaturePoint *tps);

    virtual tsl::elm::Element* createUI() override;
};