#define TESLA_INIT_IMPL
#include <tesla.hpp>
#include "main_menu.hpp"

class NxFanControlOverlay : public tsl::Overlay {
public:
    virtual void initServices() override 
    {
        fsdevMountSdmc();
        pmshellInitialize();
    }
    virtual void exitServices() override 
    {
        fsdevUnmountAll();
        pmshellExit();
    }

    virtual std::unique_ptr<tsl::Gui> loadInitialGui() override {
        return initially<MainMenu>();
    }
};

int main(int argc, char **argv) {
    return tsl::loop<NxFanControlOverlay>(argc, argv);
}
