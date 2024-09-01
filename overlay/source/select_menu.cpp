#include "select_menu.hpp"

SelectMenu::SelectMenu(int i, TemperaturePoint *fanCurveTable) 
{
    this->i = i;
    this->fanCurveTable = fanCurveTable;

    this->saveBtn = new tsl::elm::ListItem("Save");
    this->tempLabel = new tsl::elm::CategoryHeader(std::to_string((this->fanCurveTable + i)->temperature_c) + "C", true);
    this->fanLabel = new tsl::elm::CategoryHeader(std::to_string((int)((this->fanCurveTable + i)->fanLevel_f * 100)) + "%", true);
}

tsl::elm::Element* SelectMenu::createUI(){

    auto frame = new tsl::elm::OverlayFrame("NX-FanControl", "v1.0.0");

    auto list = new tsl::elm::List();

    list->addItem(this->tempLabel);
    auto stepTemp = new tsl::elm::StepTrackBar("C", 21);
    stepTemp->setValueChangedListener([this](u8 value)
    {
        this->tempLabel->setText(std::to_string(value * 5) + "C");
        (this->fanCurveTable + i)->temperature_c = value * 5;
        this->saveBtn->setText("Save");
    });
    stepTemp->setProgress(((this->fanCurveTable + i)->temperature_c) / 5);
    list->addItem(stepTemp);

    list->addItem(this->fanLabel);
    auto stepFanL = new tsl::elm::StepTrackBar("%", 21);
    stepFanL->setValueChangedListener([this](u8 value)
    {
        this->fanLabel->setText(std::to_string(value * 5) + "%");
        (this->fanCurveTable + i)->fanLevel_f = (float)(value * 5)/100;
        this->saveBtn->setText("Save");
    });
    stepFanL->setProgress(((int)((this->fanCurveTable + i)->fanLevel_f * 100)) / 5);
    list->addItem(stepFanL);

    this->saveBtn->setClickListener([this](uint64_t keys) 
    {
	    if (keys & HidNpadButton_A) 
        {
		    WriteConfigFile(this->fanCurveTable);

            pmshellTerminateProgram(SysFanControlID);
                
            const NcmProgramLocation programLocation
            {
                .program_id = SysFanControlID,
                .storageID = NcmStorageId_None,
            };
            u64 pid = 0;
            pmshellLaunchProgram(0, &programLocation, &pid);
                
            this->saveBtn->setText("Saved!");
		    return true;
		}
		
        return false;
		
    });

    list->addItem(this->saveBtn);

    frame->setContent(list);

    return frame;
}