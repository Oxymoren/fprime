<title>DemoScheduler Component Dictionary</title>
# DemoScheduler Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|Demo_Scheduler_Run_Now|0 (0x0)|Command to schedule an immidate run of the demo manager.| | |
|Demo_Scheduler_Run_Future|1 (0x1)|Command to schedule an immidate run of the demo manager.| | |
| | | |Time|U32|Specifies at what time to execute the command |

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|Demo_Scheduler_Queue_Size|0 (0x0)|U32|Number of tasks in the scheduler queue.|
|Demo_Scheduler_Curr_Time|1 (0x1)|U32|Current Unix Time Reading|

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|Scheduler_CommandRecieved|0 (0x0)|Scheduler got task| | | | |
