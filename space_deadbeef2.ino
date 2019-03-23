#include "SystemManager.h"

static UTJ::SystemManager system_manager;

void setup()
{
	system_manager.init();
}

void loop()
{
	system_manager.update();
	system_manager.render();
}
