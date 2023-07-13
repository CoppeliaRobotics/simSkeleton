#include <simSkeleton.h>
#include <simStack/stackArray.h>
#include <simStack/stackMap.h>
#include <simLib/simLib.h>
#include <iostream>

#define PLUGIN_VERSION 6 // 2 since version 3.2.1, 3 since V3.3.1, 4 since V3.4.0, 5 since V3.4.1, 6 since V4.6

static LIBRARY simLib; // the CoppelisSim library that we will dynamically load and bind

// --------------------------------------------------------------------------------------
// simSkeleton.getData: an example of custom Lua command
// --------------------------------------------------------------------------------------
void LUA_GETDATA_CALLBACK(SScriptCallBack* p)
{ // the callback function of the new Lua command ("simSkeleton.getData")
    int stack=p->stackID;

    CStackArray inArguments;
    inArguments.buildFromStack(stack);

    if ( (inArguments.getSize()>=2)&&inArguments.isString(0)&&inArguments.isMap(1) )
    { // we expect at least 2 arguments: a string and a map
        CStackMap* map=inArguments.getMap(1);
        std::string tmp("we received a string (");
        tmp+=inArguments.getString(0).c_str();
        tmp+=") and following message in the map: ";
        tmp+=map->getString("message").c_str();
        simAddLog("PluginSkeleton",sim_verbosity_msgs,tmp.c_str());
    }
    else
        simSetLastError(nullptr,"Not enough arguments or wrong arguments.");

    // Now return a string and a map:
    CStackArray outArguments;
    outArguments.pushString("Hello World");
    CStackMap* map=new CStackMap();
    map->setBool("operational",true);
    CStackArray* pos=new CStackArray();
    double _pos[3]={0.0,1.0,2.0};
    pos->setDoubleArray(_pos,3);
    map->setArray("position",pos);
    outArguments.pushMap(map);
    outArguments.buildOntoStack(stack);
}
// --------------------------------------------------------------------------------------


// This is the plugin start routine (called just once, just after the plugin was loaded):
SIM_DLLEXPORT int simInit(SSimInit* info)
{
    // Dynamically load and bind CoppelisSim functions:
    simLib=loadSimLibrary(info->coppeliaSimLibPath);
    if (simLib==NULL)
    {
        simAddLog(info->pluginName,sim_verbosity_errors,"could not find or correctly load the CoppeliaSim library. Cannot start the plugin.");
        return(0); // Means error, CoppelisSim will unload this plugin
    }
    if (getSimProcAddresses(simLib)==0)
    {
        simAddLog(info->pluginName,sim_verbosity_errors,"could not find all required functions in the CoppeliaSim library. Cannot start the plugin.");
        unloadSimLibrary(simLib);
        return(0); // Means error, CoppelisSim will unload this plugin
    }

    // Check the version of CoppelisSim:
    int simVer,simRev;
    simGetInt32Param(sim_intparam_program_version,&simVer);
    simGetInt32Param(sim_intparam_program_revision,&simRev);
    if( (simVer<40000) || ((simVer==40000)&&(simRev<1)) )
    {
        simAddLog(pluginName,sim_verbosity_errors,"sorry, your CoppelisSim copy is somewhat old, CoppelisSim 4.0.0 rev1 or higher is required. Cannot start the plugin.");
        unloadSimLibrary(simLib);
        return(0); // Means error, CoppelisSim will unload this plugin
    }

    // Register the new function:
    simRegisterScriptCallbackFunction("getData",nullptr,LUA_GETDATA_CALLBACK);

    return(PLUGIN_VERSION); // initialization went fine, we return the version number of this plugin (can be queried with simGetModuleName)
}

// This is the plugin end routine (called just once, when CoppelisSim is ending, i.e. releasing this plugin):
SIM_DLLEXPORT void simCleanup()
{
    // Here you could handle various clean-up tasks

    unloadSimLibrary(simLib); // release the library
}

// This is the plugin messaging routine (i.e. CoppelisSim calls this function very often, with various messages):
SIM_DLLEXPORT void simMsg(SSimMsg* info)
{ // This is called quite often. Just watch out for messages/events you want to handle
    // Here we can intercept many messages from CoppelisSim. Only the most important messages are listed here.
    // For a complete list of messages that you can intercept/react with, search for "sim_message_eventcallback"-type constants
    // in the CoppelisSim user manual.

    if (info->msgId==sim_message_eventcallback_instancepass)
    {   // This message is sent each time the scene was rendered (well, shortly after) (very often)

    }

    if (info->msgId==sim_message_eventcallback_simulationabouttostart)
    { // Simulation is about to start

    }

    if (info->msgId==sim_message_eventcallback_simulationended)
    { // Simulation just ended

    }

    if (info->msgId==sim_message_eventcallback_instanceswitch)
    { // We switched to a different scene. Such a switch can only happen while simulation is not running

    }

    // You can add many more messages to handle here
}

SIM_DLLEXPORT void simInit_ui()
{
}

SIM_DLLEXPORT void simCleanup_ui()
{
}

SIM_DLLEXPORT void simMsg_ui(SSimMsg_ui*)
{
}

