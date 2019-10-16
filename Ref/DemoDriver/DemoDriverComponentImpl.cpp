// ======================================================================
// \title  DemoDriverComponentImpl.cpp
// \author aleha
// \brief  cpp file for DemoDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/DemoDriver/DemoDriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include <stdlib.h>

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  DemoDriverComponentImpl ::
#if FW_OBJECT_NAMES == 1
    DemoDriverComponentImpl(
        const char *const compName
    ) :
      DemoDriverComponentBase(compName)
#else
    DemoDriverComponentImpl(void)
#endif
  {
    this->m_componentEnabled = true;
    this->m_prev_value = 0;
    this->tlmWrite_Driver_DriverVal(0);
  }

  void DemoDriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    DemoDriverComponentBase::init(instance);
  }

  DemoDriverComponentImpl ::
    ~DemoDriverComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void DemoDriverComponentImpl ::
    ManagerIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 val1
    )
  {
    U32 newDriverValue;
    do {
      newDriverValue = (rand() % 100) + 1;
    }
    while(newDriverValue == this->m_prev_value);

    this->tlmWrite_Driver_DriverVal(newDriverValue);
    this->log_DIAGNOSTIC_Driver_CommandRecieved(newDriverValue);
    this->m_prev_value = newDriverValue;
    this->DriverOut_out(0, newDriverValue);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void DemoDriverComponentImpl ::
    Driver_TestDriver_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    U32 newDriverValue;
    do {
      newDriverValue = (rand() % 100) + 1;
    }
    while(newDriverValue == this->m_prev_value);

    this->tlmWrite_Driver_DriverVal(newDriverValue);
    this->log_DIAGNOSTIC_Driver_CommandRecieved(newDriverValue);
    this->m_prev_value = newDriverValue;
    this->DriverOut_out(0, newDriverValue);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
