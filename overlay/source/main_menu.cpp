#include "main_menu.hpp"
#include "select_menu.hpp"

MainMenu::MainMenu()
{
    ReadConfigFile(&(this->fanCurveTable));

    this->p0Label = new tsl::elm::ListItem("P0: " + std::to_string(this->fanCurveTable->temperature_c) + "C | " + std::to_string((int)(this->fanCurveTable->fanLevel_f * 100)) + "%");
    this->p1Label = new tsl::elm::ListItem("P1: " + std::to_string((this->fanCurveTable + 1)->temperature_c) + "C | " + std::to_string((int)((this->fanCurveTable + 1)->fanLevel_f * 100)) + "%");
    this->p2Label = new tsl::elm::ListItem("P2: " + std::to_string((this->fanCurveTable + 2)->temperature_c) + "C | " + std::to_string((int)((this->fanCurveTable + 2)->fanLevel_f * 100)) + "%");
    this->p3Label = new tsl::elm::ListItem("P3: " + std::to_string((this->fanCurveTable + 3)->temperature_c) + "C | " + std::to_string((int)((this->fanCurveTable + 3)->fanLevel_f * 100)) + "%");
    this->p4Label = new tsl::elm::ListItem("P4: " + std::to_string((this->fanCurveTable + 4)->temperature_c) + "C | " + std::to_string((int)((this->fanCurveTable + 4)->fanLevel_f * 100)) + "%");

    if (IsRunning() != 0)
    {
        this->enabledBtn = new tsl::elm::ToggleListItem("Enabled", true);
    }
    else
    {
        this->enabledBtn = new tsl::elm::ToggleListItem("Enabled", false);
    }
}

tsl::elm::Element* MainMenu::createUI()
{
    auto frame = new tsl::elm::OverlayFrame("NX-FanControl", "v1.0.0");

    auto list = new tsl::elm::List();

    this->enabledBtn->setStateChangedListener([this](bool state)
    {
	    if (state)
        {
            CreateB2F();
            const NcmProgramLocation programLocation{
                .program_id = SysFanControlID,
                .storageID = NcmStorageId_None,
            };
            u64 pid = 0;
            pmshellLaunchProgram(0, &programLocation, &pid);
            return true;
		}
        else
        {
            RemoveB2F();
            pmshellTerminateProgram(SysFanControlID);
            return true;
        }
	    return false;
    });
    list->addItem(this->enabledBtn);

    list->addItem(new tsl::elm::CategoryHeader("Fan Curve", true));
    this->p0Label->setClickListener([this](uint64_t keys)
    {
	    if (keys & HidNpadButton_A) 
        {
			tsl::changeTo<SelectMenu>(0, this->fanCurveTable);
			return true;
		}
		return false; 
    });
    list->addItem(this->p0Label);

    this->p1Label->setClickListener([this](uint64_t keys)
    {
	    if (keys & HidNpadButton_A) 
        {
			tsl::changeTo<SelectMenu>(1, this->fanCurveTable);
			return true;
		}
		return false;
    });
    list->addItem(this->p1Label);

    this->p2Label->setClickListener([this](uint64_t keys)
    {
	    if (keys & HidNpadButton_A) 
        {
			tsl::changeTo<SelectMenu>(2, this->fanCurveTable);
			return true;
		}
		return false; 
    });
    list->addItem(this->p2Label);

    this->p3Label->setClickListener([this](uint64_t keys)
    {
	    if (keys & HidNpadButton_A) 
        {
		    tsl::changeTo<SelectMenu>(3, this->fanCurveTable);
			return true;
		}
		return false; 
    });
    list->addItem(this->p3Label);

    this->p4Label->setClickListener([this](uint64_t keys)
    {
	    if (keys & HidNpadButton_A) 
        {
				tsl::changeTo<SelectMenu>(4, this->fanCurveTable);
				return true;
	    }
	    return false; 
    });
    list->addItem(this->p4Label);

    frame->setContent(list);

    return frame;
}

void MainMenu::update()
{
    ReadConfigFile(&(this->fanCurveTable));
    this->p0Label->setText("P0: " + std::to_string(this->fanCurveTable->temperature_c) + "C | " + std::to_string((int)(this->fanCurveTable->fanLevel_f * 100)) + "%");
    this->p1Label->setText("P1: " + std::to_string((this->fanCurveTable + 1)->temperature_c) + "C | " + std::to_string((int)((this->fanCurveTable + 1)->fanLevel_f * 100)) + "%");
    this->p2Label->setText("P2: " + std::to_string((this->fanCurveTable + 2)->temperature_c) + "C | " + std::to_string((int)((this->fanCurveTable + 2)->fanLevel_f * 100)) + "%");
    this->p3Label->setText("P3: " + std::to_string((this->fanCurveTable + 3)->temperature_c) + "C | " + std::to_string((int)((this->fanCurveTable + 3)->fanLevel_f * 100)) + "%");
    this->p4Label->setText("P4: " + std::to_string((this->fanCurveTable + 4)->temperature_c) + "C | " + std::to_string((int)((this->fanCurveTable + 4)->fanLevel_f * 100)) + "%");
}
