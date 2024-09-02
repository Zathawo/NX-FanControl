#include <tesla.hpp>
#include "utils.hpp"

class SelectMenu : public tsl::Gui {
private:
    int _i = 0;
    TemperaturePoint* _fanCurveTable;
    bool* _tableIsChanged;

    tsl::elm::CategoryHeader* _tempLabel;
    tsl::elm::CategoryHeader* _fanLabel;
    tsl::elm::ListItem* _saveBtn;

public:
    SelectMenu(int i, TemperaturePoint *tps, bool* tableIsChanged);

    virtual tsl::elm::Element* createUI() override;
};