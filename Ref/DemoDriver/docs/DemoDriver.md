<title>DemoDriver Component Dictionary</title>
# DemoDriver Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|Driver_TestDriver|0 (0x0)|Command to test driver commands| | |
| | | |set_val|U32|Forceed Value|

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|Driver_DriverVal|0 (0x0)|U32|Driver Run Value|

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|Driver_CommandRecieved|0 (0x0)|Got driver output| | | | |
| | | |driver_output|U32||Driver Output|
