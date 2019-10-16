// ======================================================================
// \title  DemoManagerComponentImpl.cpp
// \author aleha
// \brief  cpp file for DemoManager component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/DemoManager/DemoManagerComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  DemoManagerComponentImpl ::
#if FW_OBJECT_NAMES == 1
    DemoManagerComponentImpl(
        const char *const compName
    ) :
      DemoManagerComponentBase(compName)
#else
    DemoManagerComponentImpl(void)
#endif
  {
    this->m_componentEnabled = true;
    this->tlmWrite_Manager_IsActive(1);
  }

  void DemoManagerComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    DemoManagerComponentBase::init(queueDepth, instance);
  }

  DemoManagerComponentImpl ::
    ~DemoManagerComponentImpl(void)
  {
    
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void DemoManagerComponentImpl ::
    DriverIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 val1
    )
  {
    this->tlmWrite_Manager_ReceivedVal(val1);
  }

  void DemoManagerComponentImpl ::
    SchedulerIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 val
    )
  {
    if (this->m_componentEnabled == true)
    {
      this->ManagerOut_out(0, 1);
    }
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void DemoManagerComponentImpl ::
    Manager_Test_Manager_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    if (this->m_componentEnabled == true)
    {
      this->ManagerOut_out(0, 1);
    }
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void DemoManagerComponentImpl ::
    Manager_Disable_Manager_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    this->m_componentEnabled = false;
    this->tlmWrite_Manager_IsActive(0);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void DemoManagerComponentImpl ::
    Manager_Enable_Manager_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    this->m_componentEnabled = true;
    this->tlmWrite_Manager_IsActive(1);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
