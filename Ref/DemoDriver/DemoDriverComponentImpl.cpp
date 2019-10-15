// ======================================================================
// \title  DemoDriverComponentImpl.cpp
// \author oxymoren
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
    this->tlmWrite_Driver_DriverVal(val1);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void DemoDriverComponentImpl ::
    Driver_TestDriver_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        U32 set_val
    )
  {
    this->tlmWrite_Driver_DriverVal(set_val);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
