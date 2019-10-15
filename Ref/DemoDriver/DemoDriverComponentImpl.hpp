// ======================================================================
// \title  DemoDriverComponentImpl.hpp
// \author oxymoren
// \brief  hpp file for DemoDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef DemoDriver_HPP
#define DemoDriver_HPP

#include "Ref/DemoDriver/DemoDriverComponentAc.hpp"

namespace Ref {

  class DemoDriverComponentImpl :
    public DemoDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object DemoDriver
      //!
      DemoDriverComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif

        
      );

      //! Initialize object DemoDriver
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object DemoDriver
      //!
      ~DemoDriverComponentImpl(void);

      private:

        bool m_componentEnabled;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for ManagerIn
      //!
      void ManagerIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 val1 
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for Driver_TestDriver command handler
      //! Command to test driver commands
      void Driver_TestDriver_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U32 set_val 
      );


    };

} // end namespace Ref

#endif
