# SplayApi
## S-Play HTTP API description

This HTTP API allows for control over the ENTTEC S-Play (SKU: 70092), playback engine. To use this API to its full extent first record cues and make playlists using the S-Plays inbuilt web interface.

ENTTEC recommend that the S-Plays IP is set to be static before communicating using this API.

To ensure this API functions as intended, ensure you are running a software version of at least **v1.2.5**.

### HTTP POST Commands for S-Play's playback.
Enum CONTROL_COMMANDS below presents the list of available playback commands.
They can be sent using HTTP POST requests to the device IP on the`55555` port and path`/api`.

e.g. URL: ` http://192.168.1.13:55555/api`

Request can be tested using **curl**:

``
curl --header "Content-Type: application/json" -d "{\"command\":8}" http://192.168.1.13:55555/api --output -
``

### Development
After clone run the command inside repo's dir to automatically execute `flatc` compilation (v1.12.0) to cpp & js for all *.fbs files:
``
git config --local core.hooksPath .githooks/
``

### Definitions

#### SplayEngine Commands
All control commands supported by the device are listed in `fbs/Command.fbs`.
These ids can be used to fully control S-Play device
```c++
enum CONTROL_COMMANDS {
  PLAY_COMMAND = 0, // Play playlist by id
  PAUSE_COMMAND = 1, // Pause the playing playlist by id
  STOP_COMMAND = 2, // Stop the playlist if in PAUSE or PLAY status
  GET_PLAYLIST_COMMAND = 3, // Get full information about playlist with Tracks, Triggers & Events
  UPDATE_PLAYLISTS_ORDER_COMMAND = 4, // Update playlists by ids with given orders
  PLAY_ALL_PLAYLISTS_COMMAND = 5, // Play all playlists on the device
  PAUSE_ALL_PLAYLISTS_COMMAND = 6, // Pause all playing playlists
  STOP_ALL_PLAYLISTS_COMMAND = 7, // Stop all playlists is in PAUSE or PLAY status.
  GET_ALL_PLAYLISTS_COMMAND = 8, // Get status of all currently playing playlists
  SET_PLAYLIST_INTENSITY_COMMAND = 9, // Output intensity (Master Fader) of the given playlist, persists until power cycle
  
  SET_TRACK_INTENSITY_COMMAND = 11, // Output intensity of particular track in the given playlist (not implemented)
  GET_TRACK_INTENSITY_COMMAND = 12, // Return the current Intensity (not implemented)

  CAPTURE_DMX_FRAME_COMMAND = 13, // Static frame recording
  RECORD_DMX_FRAME_COMMAND = 14, // Dynamic frame recording
  STOP_RECORD_COMMAND = 15, // Stop any recording
  SAVE_CUE_COMMAND = 16, // Save cue state
  DELETE_CUE_COMMAND = 17, // Delete Cue by id

  UPDATE_PLAYLIST_COMMAND = 18, // Update/Create Playlist with json struct as gets from GET_PLAYLIST_COMMAND
  DELETE_PLAYLIST_COMMAND = 19, // Delete Playlist by id
  
  UPDATE_SETTING_COMMAND = 20, // Update Setting by id
  GET_SETTING_COMMAND = 21, // Get Setting by id
  
  SET_PLAYLIST_TIME_POSITION_COMMAND = 22, // Set playback position of a playlist
  SET_WEBSOCKET_INPUT_COMMAND = 23, // Sets universe to monitor in Cue recording

  PLAY_CUE_COMMAND = 25, // Play cue with given id
  PAUSE_CUE_COMMAND = 26, // Pause cue with given id
  STOP_CUE_COMMAND = 27, // Stop playback of playing cue by given id
  GET_CUE_COMMAND = 28, // Get full info on cue by given id
  GET_ALL_CUES_COMMAND = 29, // Get list of all cues
  EXIT_CUE_EDIT_COMMAND = 30, // Frontend notifies on Cue editing finished

  UPDATE_STORAGE_PATH = 34, // Update storage path using internal DB check for BASE_PATH setting

  GET_EVENT_COMMAND = 36, // Get Event by id
  GET_ALL_EVENTS_COMMAND = 37, // Get all existing Events
  UPDATE_EVENT_COMMAND = 38, // Update/Create Event
  DELETE_EVENT_COMMAND = 39, // Delete Event by id
  GET_TRIGGER_COMMAND = 40, // Get Trigger by id
  GET_ALL_TRIGGERS_COMMAND = 41, // Get all existing Triggers
  UPDATE_TRIGGER_COMMAND = 42, // Update/Create Trigger
  DELETE_TRIGGER_COMMAND = 43, // Delete Trigger by id
  SEND_EVENT_COMMAND = 44, // Send given event
  WAIT_TRIGGER_COMMAND = 45, // Add trigger to check
  CHECK_TRIGGER_COMMAND = 46, // Check if added trigger happen

  UDP_MESSAGE = 50, // Accepts messages to interpret as UDP input
  OSC_MESSAGE = 51, // Accepts messages to interpret as OSC input

  GET_MASTER_INTENSITY = 55, // Get / Set overall S-Play output intensity (Master Fader), persists until power cycle
  SET_MASTER_INTENSITY = 56,

  GET_SCHEDULES_COMMAND = 60, // Get all existing Schedules
  UPDATE_SCHEDULE_COMMAND = 61, // Update Schedule to file already exist.
  DELETE_SCHEDULE_COMMAND = 62, // Delete Schedule. it will be removed from database and storage.
  ENABLE_SCHEDULE_COMMAND = 63, // Change the Schedule state enable ACTIVE = 1 / PAUSED = 2

  GET_INTERFACE_COMMAND = 70, // Get Iterface page by id or URL
  GET_ALL_INTERFACES_COMMAND = 71, // Get all created Interfaces
  UPDATE_INTERFACE_COMMAND = 72, // Update/Create Interface page
  DELETE_INTERFACE_COMMAND = 73, // Delete Interface by id
}
```

#### Playlists Control 

PLAY_COMMAND: Play playlist by id

PAUSE_COMMAND:  Pause the playing playlist by id

STOP_COMMAND: Stop the playlist if in PAUSE or PLAY status

GET_PLAYLIST_COMMAND: Get full information about playlist with Tracks, Triggers & Events

UPDATE_PLAYLISTS_ORDER_COMMAND: Update playlists by ids with given orders

PLAY_ALL_PLAYLISTS_COMMAND: Play all playlists on the device

PAUSE_ALL_PLAYLISTS_COMMAND: Pause all playing playlists

STOP_ALL_PLAYLISTS_COMMAND: Stop all playlists is in PAUSE or PLAY status.

GET_ALL_PLAYLISTS_COMMAND: Get status of all currently playing playlists

SET_PLAYLIST_INTENSITY_COMMAND: Output intensity (Master Fader) of the given playlist, persists until power cycle


### Supported Playlists Statuses
```c++
enum PLAYLIST_STATUS_TYPES {
  PLAYLIST_STATUS_IDLE = 0,
  PLAYLIST_STATUS_PLAYING = 1,
  PLAYLIST_STATUS_PAUSED = 2,
  PLAYLIST_STATUS_STOPPED = 3,
  PLAYLIST_STATUS_STOPPING = 4,
  PLAYLIST_STATUS_ERROR = 5
};

```

#### Setting Command Sub-Command
Indicate what configuration is changed.
```c++
enum UPDATE_SETTINGS_TYPES {
    UPDATE_SETTINGS_NTP                    = 0,     // Ntp configuration is changed
    UPDATE_SETTINGS_ARTNET_DEVICE          = 1,     // ArtNet device configuration is changed
    UPDATE_SETTINGS_SACN_DEVICE            = 2,     // sACN device configuration is changed
    UPDATE_SETTINGS_DMX_DEVICE             = 3,     // DMX device configuration is changed
    UPDATE_SETTINGS_OUTPUT                 = 4,     // Output configuration is changed
    UPDATE_SETTINGS_SERIAL_DEVICE          = 5,     // Serial device configuration is changed
    UPDATE_SETTINGS_OSC_DEVICE             = 6      // OSC configuration is changed
    UPDATE_SETTINGS_NETWORK                = 7,     // Update network config
};

```

#### Event Type Names
Indicate what type of event is sent.
```c++
enum EVENT_TYPE {
    EVENT_TYPE_NONE = 0,
    EVENT_TYPE_RS232,
    EVENT_TYPE_IO,
    EVENT_TYPE_ARTNET,
    EVENT_TYPE_DMX,
    EVENT_TYPE_SACN,
    EVENT_TYPE_OSC,
    END_EVENT_TYPE
};
```

#### Trigger Types
Indicate what device do you wait to trigger from.
```c++
enum TRIGGER_TYPE {
    TRIGGER_TYPE_NONE = 0, // currently in playlist jsons it is -1
    TRIGGER_TYPE_OSC,
    TRIGGER_TYPE_RS232,
    TRIGGER_TYPE_IO,
    TRIGGER_TYPE_ARTNET,
    TRIGGER_TYPE_DMX,
    TRIGGER_TYPE_SACN,
    TRIGGER_TYPE_POWERUP,
    END_TRIGGER_TYPE
};
```

### JSON Requests and Responses Examples

> `Good to know`: Be careful with JSON values' types, some fields support only integers or floats.

#### ET Status of All Playlists
This will return all the playlist IDs and its status and playing time.
If playlist is waiting any trigger, it has trigger information.
##### Request
```json
    {
        "command": 8
    }
```
##### Response
The playlist 6 is stopped and playlist 4 is playing. We use the response object array to send playlist, as shown below.
```json
{
    "playlists":[
        {
            "current_time": 0,
            "duration": 3000,
            "intensity": 100.0,
            "name": "Art",
            "notification_message": "",
            "playlist_id": 6,
            "status": PLAYLIST_STATUS_STOPPED,
            "waiting_triggers": false,
            "start_trigger":
            {
                "active": true,
                "conditions": {
                    "channel_number": 0,"threshold": 200,"universe": 100
                },
                "name": "Art-100-1-200",
                "playlist_id": 1,
                "position": 0,
                "type": TRIGGER_TYPE_ARTNET
            },
            "stop_trigger":
            {
                "active": true,"conditions": null,"name": "","playlist_id": 0,"position": 0,"type": TRIGGER_TYPE_NONE
            },
            "triggers":
            [
                {
                    "active": true,
                    "conditions": "/test_int",
                    "name": "Osc-/test",
                    "playlist_id": 4,
                    "position": 2000,
                    "type": TRIGGER_TYPE_OSC
                },
                {
                    "active": true,
                    "conditions": {
                        "channel_number": 0,
                        "threshold": 200,
                        "universe": 100
                    },
                    "name": "Art-100-1-200",
                    "playlist_id": 1,
                    "position": 4000,
                    "type": TRIGGER_TYPE_ARTNET
                }
            ],

        },
        {
            "current_time": 1500,
            "duration": 5000,
            "intensity":100.0,
            "name":"Art",
            "notification_message":"",
            "playlist_id":4,
            "start_trigger":
            {
                "active":true,
                "conditions":
                {
                    "channel_number":0,
                    "threshold":200,
                    "universe":100
                },
                "name":"Art-100-1-200",
                "playlist_id":1,
                "position":0,
                "type": TRIGGER_TYPE_ARTNET
            },
            "status":PLAYLIST_STATUS_PLAYING,
            "stop_trigger":
            {
                "active":true,
                "conditions":null,
                "name":"",
                "playlist_id":0,
                "position":0,
                "type": TRIGGER_TYPE_NONE
            },
            "triggers":[],
            "waiting_triggers": false
        }
    ]
}
```

#### STOP RECORD
This command will stop to record DMX frame from device. This will return the latest record time.
##### Request
```json
    {
        "command": 15,
    }
```
##### Response
```json
    {
        "result": true,
    }
```

#### SET PlaylistID 25 to Play
This will perform PLAY action, and return current state, timing and current cue of the playlist in question.
If loop_count is 0, Playlist will keep PLAYING, till another Action is performed on this Playlist
If playlist is currently PAUSED - it will be RESUMED, with PLAY
Playlist must be in STOP state, to be started from the beginning.
Playlist will Loop for 4 times more, after initial Play has ended. So, in total it plays for 5 times.
Playlist will STOP, once it reaches the end of final loop.
##### Request
```json
    {
        "command": 0,
        "playlist_id": 25,
        "loop_count": 4
    }
```
##### Response
It should return playlist status.
```json
    {
        "result": true,
    }
```

#### SET PlaylistID 25 to PAUSE
This will perform PAUSE action, and return current state, timing and current cue of the playlist in question.
If playlist is PLAYING - it will be PAUSED.
If playlist is PAUSED - it will be RESUMED
##### Request
```json
    {
        "command": 1,
        "playlist_id": 25
    }
```
##### Response
```json
    {
        "result": true
    }
```

#### SET PlaylistID 25 to STOP
This will perform STOP action, and return current state, timing and current cue of the playlist in question.
Playlist will STOP immediately.
If Playlist is already Stopped, ignore STOP action.
##### Request
```json
    {
        "command": 2,
        "playlist_id": 25
    }
```
##### Response
```json
    {
        "result": true
    }
```

#### GET INTENSITY OF CUE TRACK on PlaylistID 25
##### Request
Get the intensity of special playlist.
```json
    {
        "command": 12,
        "playlist_id": 25,
        "cue_track_id": 3
    }
```
##### Response - Playlist ID 25 is PLAYING Cue ID 5, current time is 450.5 sec (playlist begins at 0)
This will return
```json
    {
        "result": true,
        "fader_level": 75
    }
```

#### SET INTENSITY OF CUE TRACK on PlaylistID 25 (not implemented)
This will update output intensity of particular track in the given playlist
Once the Fader Level is set, it must be maintained for this Playlist, even if the Playlist is stopped.
So a future PLAY, will use the last known Fader Level.
##### Request
It will return intensity value of track on playlist set by this command.
```json
    {
        "command": 11,
        "playlist_id": 25,
        "cue_track_id": 2,
        "intensity": 75
    }
```
##### Response - Playlist ID 25 is PLAYING Cue ID 5, current time is 450.5 sec (playlist begins at 0)
It will return playlist's status.
```json
    {
        "result": true,
    }
```

#### GET PLAYLIST INTENSITY on PlaylistID 25 (not implemented)
Get the intensity of special playlist.
##### Request
```json
    {
        "command": 10,
        "playlist_id": 25
    }
```
##### Response
It will return intensity of special playlist.
```json
    {
        "result": true,
        "fader_level": 75
    }
```

#### SET PLAYLIST INTENSITY on PlaylistID 25
This will update MASTER INTENSITY of the given playlist.
Once the Fader Level is set, it must be maintained for this Playlist, even if the Playlist is stopped, until power cycle.
So a future PLAY, will use the last known Fader Level.
##### Request
```json
    {
        "command": 9,
        "playlist_id": 25,
        "intensity": 75
    }
```

##### Response
```json
    {
        "result": true,
    }
```

#### UPDATE PLAYLIST
Update the properties of playlist with given filename and its time elements.
##### Request
```json
    {
        "command": 12,
        "playlist_filename": "playlist2.json",
    }
```
##### Response
It should return true.
```json
    {
        "result": true
    }
```

#### DELETE PLAYLIST
Remove the playlist from active list (e.g. from PlayAll).
##### Request
```json
    {
        "command": 19,
        "playlist_id": 3,
    }
```
##### Response
It should return true.
```json
    {
        "result": true
    }
```

#### UPDATE SETTINGS
Update configuration and system parameters from database. For example NTP.
##### Request
```json
    {
        "command": 20,
        "command_type": 0
    }
```
##### Response
It should return true.
```json
    {
        "result": true
    }
```
###  PLAY ALL PLAYLISTS
Play all playlist in playlist storage.
##### Request
```json
    {
        "command": 5
    }
```

##### Response
It should return true on success.
```json
    {
        "result": true,
    }
```

#### PAUSE ALL PLAYLISTS
Pause all running playlists.
##### Request
```json
    {
        "command": 6
    }
```
##### Response
It should return true on success.
```json
    {
        "result": true,
    }
```

#### STOP ALL PLAYLISTS
Stop all playing or paused playlist.
##### Request
```json
    {
        "command": 7
    }
```
##### Response
It should return true on success.
```json
    {
        "result": true,
    }
```

#### PLAY_CUE_COMMAND (not implemented)
Preview static or dynamic cue for the given cue id
##### Request
```json
    {
        "command": 16,
        "cue_id": 1
    }
```
##### Response
It should return cue previewing status.
```json
    {
        "result": true,
        "status": CUE_PLAY
    }
```

#### STOP_CUE_COMMAND (not implemented)
Stop previewing cue. and then the output should be stopped.
##### Request
```json
    {
        "command": 17,
    }
```
##### Response
It should return cue preview status.
```json
    {
        "result": true,
        "status": CUE_STOP
    }
```

#### SET_PLAYLIST_TIME_POSITION on PlaylistID 25
Send request with needed timeline position for playlist playing currently, the position is set with current_time as float which represents seconds (ms after dot) and playlist_id
##### Request
```json
    {
        "command": 22,
        "playlist_id": 25,
        "position": 10.55
    }
```
##### Response
```json
    {
        "result": true
    }
```

#### SET_MASTER_INTENSITY
Set overall S-Play output intensity (Master Fader) with 50% brightness, doesn't persist after power cycle
##### Request
```json
    {
        "command": 24,
        "intensity": 0.5,
    }
```
##### Response
```json
    {
        "result": true
    }
```
#### OSC_MESSAGE
Send OSC message to Playback to trigger existing OSC triggers
##### Request
```json
    {
        "command": 25,
        "address": "/test"
    }
```
##### Response
```json
    {
        "result": true
    }
```
