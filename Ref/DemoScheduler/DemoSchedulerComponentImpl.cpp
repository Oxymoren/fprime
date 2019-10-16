// ======================================================================
// \title  DemoSchedulerComponentImpl.cpp
// \author oxymoren
// \brief  cpp file for DemoScheduler component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/DemoScheduler/DemoSchedulerComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"


namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  DemoSchedulerComponentImpl ::
#if FW_OBJECT_NAMES == 1
    DemoSchedulerComponentImpl(
        const char *const compName
    ) :
      DemoSchedulerComponentBase(compName)
#else
    DemoSchedulerComponentImpl(void)
#endif
  {

  }

  void DemoSchedulerComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    DemoSchedulerComponentBase::init(queueDepth, instance);
  }

  DemoSchedulerComponentImpl ::
    ~DemoSchedulerComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void DemoSchedulerComponentImpl ::
    SchedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    U32 currTime = this->getTime().getSeconds();
    for(unsigned int i = 0; i < sizeof(this->commandQueue)/sizeof(U32); i++) {
      if(this->commandQueue[i] != 0 && this->commandQueue[i] <= currTime) {
        this->commandQueue[i] = 0;
        this->ManagerOut_out(0, 0);
      }
    }
    this->tlmWrite_Demo_Scheduler_Queue_Size(this->GetQueuedCommandCount());
    this->tlmWrite_Demo_Scheduler_Curr_Time(currTime);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void DemoSchedulerComponentImpl ::
    Demo_Scheduler_Run_Now_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    this->ManagerOut_out(0, 0);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  U32 DemoSchedulerComponentImpl ::
    GetQueuedCommandCount()
  {
    U32 count = 0;
    for(unsigned int i = 0; i < sizeof(this->commandQueue)/sizeof(U32); i++) {
      if(this->commandQueue[i] != 0) {
        count++;
      }
    }
    return count;
  }

  void DemoSchedulerComponentImpl ::
    Demo_Scheduler_Run_Future_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        U32 Time
    )
  {
    for(unsigned int i = 0; i < sizeof(this->commandQueue)/sizeof(U32); i++) {
      if(this->commandQueue[i] == 0) {
        this->commandQueue[i] = Time;
        break;
      }
    }
    this->tlmWrite_Demo_Scheduler_Queue_Size(this->GetQueuedCommandCount());
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
