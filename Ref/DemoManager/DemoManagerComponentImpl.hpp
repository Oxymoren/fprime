// ======================================================================
// \title  DemoManagerComponentImpl.hpp
// \author aleha
// \brief  hpp file for DemoManager component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef DemoManager_HPP
#define DemoManager_HPP

#include "Ref/DemoManager/DemoManagerComponentAc.hpp"

namespace Ref {

  class DemoManagerComponentImpl :
    public DemoManagerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object DemoManager
      //!
      DemoManagerComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object DemoManager
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object DemoManager
      //!
      ~DemoManagerComponentImpl(void);

      private:
        bool m_componentEnabled;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for DriverIn
      //!
      void DriverIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 val1 
      );

      //! Handler implementation for SchedulerIn
      //!
      void SchedulerIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 val 
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for Manager_Test_Manager command handler
      //! 
      void Manager_Test_Manager_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

      //! Implementation for Manager_Disable_Manager command handler
      //! 
      void Manager_Disable_Manager_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

      //! Implementation for Manager_Enable_Manager command handler
      //! 
      void Manager_Enable_Manager_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );


    };

} // end namespace Ref

#endif
