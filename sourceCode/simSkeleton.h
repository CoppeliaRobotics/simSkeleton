#pragma once

#include <simLib/simTypes.h>
#include <simLib/simExp.h>

SIM_DLLEXPORT int simInit(SSimInit*);
SIM_DLLEXPORT void simCleanup();
SIM_DLLEXPORT void simMsg(SSimMsg*);

SIM_DLLEXPORT void simInit_ui();
SIM_DLLEXPORT void simMsg_ui(SSimMsg_ui*);
SIM_DLLEXPORT void simCleanup_ui();
