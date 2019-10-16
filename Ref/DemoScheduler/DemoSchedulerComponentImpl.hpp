// ======================================================================
// \title  DemoSchedulerComponentImpl.hpp
// \author oxymoren
// \brief  hpp file for DemoScheduler component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef DemoScheduler_HPP
#define DemoScheduler_HPP

#include "Ref/DemoScheduler/DemoSchedulerComponentAc.hpp"

namespace Ref {

  class DemoSchedulerComponentImpl :
    public DemoSchedulerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object DemoScheduler
      //!
      DemoSchedulerComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object DemoScheduler
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object DemoScheduler
      //!
      ~DemoSchedulerComponentImpl(void);

      private:
        U32 commandQueue[10] = {};

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for SchedIn
      //!
      void SchedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );
    
    PRIVATE:
      U32 GetQueuedCommandCount();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for Demo_Scheduler_Run_Now command handler
      //! Command to schedule an immidiate run of the demo manager.
      void Demo_Scheduler_Run_Now_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

      //! Implementation for Demo_Scheduler_Run_Future command handler
      //! Command to schedule an immidate run of the demo manager.
      void Demo_Scheduler_Run_Future_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U32 Time /*!< Specifies at what time to execute the command */
      );


    };

} // end namespace Ref

#endif
