# ----------------------------------------------------------------------
# mod.mk 
# ----------------------------------------------------------------------

TEST_SRC=TesterBase.cpp \
				 GTestBase.cpp \
				 Tester.cpp \
				 Main.cpp 

TEST_MODS=Svc/BufferAccumulator \
					Fw/Buffer Fw/Cmd Fw/Comp Fw/Port Fw/Time \
					Fw/Tlm Fw/Types Fw/Log Fw/Obj Os Fw/Com \
					Svc/Ping Svc/Sched
					gtest

