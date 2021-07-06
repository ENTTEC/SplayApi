# SplayApi
## S-Play HTTP API description

This HTTP API allows for control over the ENTTEC S-Play (SKU: 70092), playback engine. To use this API to its full extent first record cues and make playlists using the S-Plays inbuilt web interface.

ENTTEC recommend that the S-Plays IP is set to be static before communicating using this API.

To ensure this API functions as intended, ensure you are running a software version of at least **v1.2.5**.

## HTTP POST Commands for S-Play's playback.
Enum CONTROL_COMMANDS below presents the list of available playback commands.
They can be sent using HTTP POST requests to the device IP on the`55555` port and path`/api`.

e.g. URL: ` http://192.168.1.13:55555/api`

Request can be tested using **curl**:

``
curl --header "Content-Type: application/json" -d "{\"command\":8}" http://192.168.1.13:55555/api --output -
``

## Development
After clone run the command inside repo's dir to automatically execute `flatc` compilation (v1.12.0) to cpp & js for all *.fbs files:
``
git config --local core.hooksPath .githooks/
``

## Description

### SplayEngine Commands
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

  UPDATE_PLAYLIST_COMMAND = 18, // Update/Create Playlist with json struct as received from GET_PLAYLIST_COMMAND
  DELETE_PLAYLIST_COMMAND = 19, // Delete Playlist by id
  
  UPDATE_SETTING_COMMAND = 20, // Update Setting by id
  GET_SETTING_COMMAND = 21, // Get Setting by id
  
  SET_PLAYLIST_TIME_POSITION_COMMAND = 22, // Set playback position of a playlist
  SET_WEBSOCKET_INPUT_COMMAND = 23, // Sets universe to monitor in Cue recording

  PLAY_CUE_COMMAND = 25, // Play cue with given id
  PAUSE_CUE_COMMAND = 26, // Pause cue with given id (not implemented)
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

> `Good to know`: Be careful with JSON values' types, some fields support only integers or floats.
> 
> In case of error the Response will return `"result": false` with "error" field describing the error.

For example if unsupported command is sent it Response:
```json
{
  "result": false,
  "error": "Unsupported command id: 100"
}
```

### Playlists Control Description and JSON Requests/Responses Examples

#### Supported Playlists Statuses returned in "status" field
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

#### PLAY_COMMAND: Play playlist by id
Request:
```json
{
 "command": 0,
 "playlist_id" : 1
}
```
Response:
```json
{ "result": true }
```

#### PAUSE_COMMAND: Pause the playing playlist by id
Request:
```json
{
 "command": 1,
 "playlist_id" : 1
}
```
Response:
```json
{ "result": true }
```


#### STOP_COMMAND: Stop the playlist if in PAUSE or PLAY status
This will perform STOP action, if Playlist's has Fade Out time not 0 the status become PLAYLIST_STATUS_STOPPING and with the repeaded STOP command Playlist will stop immediately, else it will stop.
Request:
```json
{
 "command": 2,
 "playlist_id" : 1
}
```
Response:
```json
{ "result": true }
```

#### GET_PLAYLIST_COMMAND: Get full information about playlist with Tracks, Triggers & Events
Request:
```json
{
 "command": 3,
 "playlist_id" : 1
}
```
Response:
```json
{
  "playlist": {
    "current_time": 0,
    "duration": 5000,
    "fade_in": 0,
    "fade_out": 2038,
    "group": 1,
    "hide_from_home": false,
    "intensity": 100,
    "loop": 1,
    "name": "One",
    "order": 1,
    "playlist_id": 1,
    "priority": 100,
    "start_trigger": {
      "active": true,"name": "","start": 0,"trigger_id": -1,"type": 0,"value": null
    },
    "status": 3,
    "stop_trigger": {
      "active": true,"name": "","start": 0,"trigger_id": -1,"type": 0,"value": null
    },
    "timeline": {
      "event": {
        "events": [
          {
            "active": true,      "event_id": 1,      "name": "Fist Udp",      "start": 500,      "type": 7,      "value": {
              "ip": "127.0.0.1",        "port": 33333,        "value": "yoyo"
            }
          }
        ]
      },"track1": {
        "cues": [
          {
            "ch_start": 0,      "ch_stop": 511,      "cue_id": 1,      "duration": 5000,      "fade": {
              "in": 0,        "out": 0
            },      "name": "Fst",      "start": 0,      "type": 0
          }
        ],  "intensity": 100
      },"track2": {
        "cues": [],  "intensity": 100
      },"track3": {
        "cues": [],  "intensity": 100
      },"track4": {
        "cues": [],  "intensity": 100
      },"trigger": {
        "triggers": [
          {
            "active": true,      "name": "YOOsc",      "start": 11500,      "trigger_id": 2,      "type": 1,      "value": {
              "address": "/yo",        "data_type": "string",        "ip": "127.0.0.255",        "net_type": "broadcast"
            }
          }
        ]
      }
    },
    "waiting_triggers": false
  }
}
```

#### UPDATE_PLAYLISTS_ORDER_COMMAND: Update playlists by ids with given orders
Request:
```json
{
  "command":4,
  "orders":[
    {"playlist_id":2,"order":1},
    {"playlist_id":1,"order":2}
  ]
}
```
Response:
```json
{ "result": true }
```

#### PLAY_ALL_PLAYLISTS_COMMAND: Play all playlists on the device
Request:
```json
{"command": 5}
```
Response:
```json
{ "result": true }
```

#### PAUSE_ALL_PLAYLISTS_COMMAND: Pause all playing playlists
Request:
```json
{"command": 6}
```
Response:
```json
{ "result": true }
```

#### STOP_ALL_PLAYLISTS_COMMAND: Stop all playlists is in PAUSE or PLAY status.
Request:
```json
{"command": 7}
```
Response:
```json
{ "result": true }
```

#### GET_ALL_PLAYLISTS_COMMAND: Get status of all currently playing playlists
This will return all the playlist IDs and its status and playing time.
Playlist with id 1 is stopped and is hidden from home page.
Playlist with id 2 is playing on 6th second with overall duration of 12 seconds/
Both have intencity 100%.

Request:
```json
{"command": 8}
```
Response:
```json
{
  "playlists": [
    {
      "current_time": 0,
      "duration": 5000,
      "hide_from_home": true,
      "intensity": 100,
      "name": "One",
      "order": 2,
      "playlist_id": 1,
      "status": 3,
      "waiting_triggers": false
    },
    {
      "current_time": 6000,
      "duration": 12000,
      "hide_from_home": false,
      "intensity": 100,
      "name": "Two ",
      "order": 1,
      "playlist_id": 2,
      "status": 1,
      "waiting_triggers": false
    }
  ]
}
```

#### SET_PLAYLIST_INTENSITY_COMMAND: Output intensity (Master Fader) of the given playlist, persists until power cycle
Set playlist intensity to 50%

Request:
```json
{
  "command": 9, 
  "playlist_id": 2, 
  "intensity": 50}
```
Response:
```json
{ "result": true }
```

#### UPDATE_PLAYLIST_COMMAND: Update/Create Playlist with json struct as received from GET_PLAYLIST_COMMAND
Update the properties of a playlist. To create new playlist `"playlist_id": 0` or no `"playlist_id"` key must be passsed  


Create new Playlist with 
- duration 312000ms
- has Fade In 3 sec and Fade Out 2 sec
- Static Cue on Track 1 at 5 min (300000ms) with duration 12 seconds
- Dynamic Cue on Track 2 at start with duration 5 minutes and 570 ms
- One Event on 30 sec named "BIM 1" id = 3, relay 1 to NO position
- Will wait for trigger on the second minute (120000ms)
- Start and Stop Triggers are unset 

Request:
```json
{
  "command": 18,  
  "playlist": 
  {
    "duration": 312000,
    "timeline": {
      "track1": {
        "intensity": 100,
        "cues": [
          {
            "start": 300000,
            "name": "Green Scene",
            "cue_id": 1,
            "duration": 12000,
            "type": 0,
            "fade": {
              "in": 2000,
              "out": 1500
            }
          }
        ]
      },
      "track2": {
        "intensity": 100,
        "cues": [
          {
            "start": 0,
            "name": "Bar Lighting Loop",
            "cue_id": 12,
            "duration": 300570,
            "type": 1,
            "fade": {
              "in": 0,
              "out": 1503
            }
          }
        ]
      },
      "track3": {
        "intensity": 100,
        "cues": []
      },
      "track4": {
        "intensity": 100,
        "cues": []
      },
      "event": {
        "events": [
          {
            "start": 30000,
            "name": "BIM 1",
            "event_id": 3,
            "type": 2,
            "value": {
              "output": 1,
              "value": 0
            }
          }
        ]
      },
      "trigger": {
        "triggers": [
          {
            "start": 120000,
            "name": "Button Trigger 1",
            "trigger_id": 6,
            "type": 3,
            "value": {
              "data": 1,
              "port": 0
            }
          }
        ]
      }
    },
    "order": 3,
    "intensity": 100,
    "loop": 0,
    "priority": 100,
    "group": 0,
    "start_trigger": {
      "trigger_id": -1
    },
    "stop_trigger": {
      "trigger_id": -1
    },
    "fade_in": 3000,
    "fade_out": 2000,
    "name": "Favorite"
  }
}
```
Response
It should return true.
```json
{ "result": true }
```

#### DELETE_PLAYLIST_COMMAND
Remove the playlist from active list (e.g. from PlayAll).
Request
```json
{
    "command": 19,
    "playlist_id": 3
}
```
Response:
```json
{ "result": true }
```

#### SET_PLAYLIST_TIME_POSITION on PlaylistID 25
Send request with needed timeline position for playlist playing currently, the position is set with current_time as float which represents seconds (ms after dot) and playlist_id
Request
```json
  {
      "command": 22,"playlist_id": 25,"position": 10.550
  }
```
Response
```json
{ "result": true }
```


-------------------------------------------------

### Cue Control Description and JSON Requests/Responses Examples

```c++
enum UNIVERSE_TYPE:uint8 {
  DMX_TYPE = 0,
  ARTNET_TYPE = 1,
  SACN_TYPE = 2,
  NONE_TYPE = 3,
}
```

```c++
enum CUE_TYPE:uint8 {
  CUE_TYPE_STATIC = 0,
  CUE_TYPE_DYNAMIC = 1,
  CUE_TYPE_EFFECT = 2,
}
```

#### GET_ALL_CUES_COMMAND: Get list of all available cues

Request
```json
{ "command": 29 }
```
Response
```json
{ 
  "result": true,
  "cues":
  [
    {
      "config": {
        "ch_start": 0,  "ch_stop": 511, "source": 1,  "universes": [
          0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
        ]
      },"cue_id": 2,"duration": 0,"frames": [],"name": "Down dark centre 988","path": "","type": 0
    },
    {
      "config": {
        "ch_start": 0,  "ch_stop": 511, "source": 2,  "universes": [
          1, 2, 3,-1, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
        ]
      },"cue_id": 20,"duration": 132281,"frames": [],"name": "Boot up","path": "/mnt/internal/cues","type": 1
    },
    {
      "config": {
        "ch_start": 0,  "ch_stop": 511, "source": 2,  "universes": [
          0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
        ]
      },"cue_id": 21,"duration": 132628,"frames": [],"name": "Boot Down","path": "/mnt/internal/cues","type": 1
    }
  ]
}
```

> "universes" - array of 32 inputs with universe selected: No input: `-1`; DMX: `1 - 2`; ArtNet: `0 - 32767`; sACN: `1 - 65535`.
> 
> "frames" - returns empty because of the size: 32 arrays * 512 bytes, to get "frames" for the particular Static cue use GET_CUE_COMMAND
> 
> "duration" - Dynamic cue recording length in milliseconds
>
> "ch_start" & "ch_stop" defines universe channels range to output during playback, beyond the range '0' will be send


#### GET_CUE_COMMAND: Get full info on cue by given id
Returns extended info about Cue with "frames": universes state in Static Cue and 1st frame of Dynamic Cue. Effect Cue API is in progress.

Below Dynamic Cue ("type" == CUE_TYPE_DYNAMIC) with only first 8 frames states of universes are shown, other 24 are zeroed arrays as the last here

Request
```json
{
  "command": 28,
  "cue_id": 32
}
```
Response
```json
{ 
  "result": true,
  "cue": 
  {
    "config": {
      "ch_start": 0,
      "ch_stop": 511,
      "source": 2,
      "universes": [
        1,2,3,-1,5,6,7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
      ]
    },
    "cue_id": 32,
    "duration": 5908,
    "frames": [
      [
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,204,0,15,0,207,0,16,0,209,0,16,0,211,0,16,0,214,0,16,0,216,0,16,0,219,0,16,0,221,0,17,0,223,0,17,0,226,0,17,0,228,0,17,0,231,0,17,0,233,0,17,0,235,0,18,0,238,0,18,0,240,0,18,0,243,0,18,0,245,0,18,0,247,0,19,0,250,0,19,0,252,0,19,0,255,0,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      ],[
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,4,0,0,0,7,0,1,0,9,0,1,0,12,0,1,0,14,0,1,0,17,0,1,0,19,0,1,0,21,0,2,0,24,0,2,0,26,0,2,0,29,0,2,0,31,0,2,0,33,0,3,0,36,0,3,0,38,0,3,0,41,0,3,0,43,0,3,0,45,0,3,0,48,0,4,0,50,0,4,0,53,0,4,0,55,0,4,0,57,0,4,0,60,0,4,0,62,0,5,0,65,0,5,0,67,0,5,0,69,0,5,0,72,0,5,0,74,0,6,0,77,0,6,0,79,0,6,0,81,0,6,0,84,0,6,0,86,0,6,0,89,0,7,0,91,0,7,0,93,0,7,0,96,0,7,0,98,0,7,0,101,0,8,0,103,0,8,0,106,0,8,0,108,0,8,0,110,0,8,0,113,0,8,0,115,0,9,0,118,0,9,0,120,0,9,0,122,0,9,0,125,0,9,0,127,0,10,0,130,0,10,0,132,0,10,0,134,0,10,0,137,0,10,0,139,0,10,0,142,0,11,0,144,0,11,0,146,0,11,0,149,0,11,0,151,0,11,0,154,0,12,0,156,0,12,0,158,0,12,0,161,0,12,0,163,0,12,0,0,0,0,0
      ],[
        166,0,12,0,168,0,13,0,170,0,13,0,173,0,13,0,175,0,13,0,178,0,13,0,180,0,14,0,182,0,14,0,185,0,14,0,187,0,14,0,190,0,14,0,192,0,14,0,195,0,15,0,197,0,15,0,199,0,15,0,202,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      ],[
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      ],[
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,205,0,15,0,208,0,16,0,210,0,16,0,213,0,16,0,215,0,16,0,217,0,16,0,220,0,17,0,222,0,17,0,225,0,17,0,227,0,17,0,229,0,17,0,232,0,17,0,234,0,18,0,237,0,18,0,239,0,18,0,241,0,18,0,244,0,18,0,246,0,18,0,249,0,19,0,251,0,19,0,253,0,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      ],[
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,3,0,0,0,6,0,0,0,8,0,1,0,10,0,1,0,13,0,1,0,15,0,1,0,18,0,1,0,20,0,2,0,23,0,2,0,25,0,2,0,27,0,2,0,30,0,2,0,32,0,2,0,35,0,3,0,37,0,3,0,39,0,3,0,42,0,3,0,44,0,3,0,47,0,3,0,49,0,4,0,51,0,4,0,54,0,4,0,56,0,4,0,59,0,4,0,61,0,5,0,63,0,5,0,66,0,5,0,68,0,5,0,71,0,5,0,73,0,5,0,75,0,6,0,78,0,6,0,80,0,6,0,83,0,6,0,85,0,6,0,87,0,7,0,90,0,7,0,92,0,7,0,95,0,7,0,97,0,7,0,99,0,7,0,102,0,8,0,104,0,8,0,107,0,8,0,109,0,8,0,112,0,8,0,114,0,9,0,116,0,9,0,119,0,9,0,121,0,9,0,124,0,9,0,126,0,9,0,128,0,10,0,131,0,10,0,133,0,10,0,136,0,10,0,138,0,10,0,140,0,11,0,143,0,11,0,145,0,11,0,148,0,11,0,150,0,11,0,152,0,11,0,155,0,12,0,157,0,12,0,160,0,12,0,162,0,12,0,164,0,12,0,167,0,13,0,169,0,13,0,172,0,13,0,174,0,13,0,176,0,13,0,179,0,13,0,181,0,14,0,184,0,14,0,186,0,14,0,189,0,14,0,191,0,14,0,193,0,15,0,196,0,15,0,198,0,15,0,201,0,15,0,203,0,15,0
      ],[
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,205,0,15,0,208,0,16,0,210,0,16,0,213,0,16,0,215,0,16,0,217,0,16,0,220,0,17,0,222,0,17,0,225,0,17,0,227,0,17,0,229,0,17,0,232,0,17,0,234,0,18,0,237,0,18,0,239,0,18,0,241,0,18,0,244,0,18,0,246,0,18,0,249,0,19,0,251,0,19,0,253,0,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      ],[
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      ]
    ],
    "name": "Pink Meteors Fast",
    "type": 1
  }
}
```

#### PLAY_CUE_COMMAND: Play cue with given id
Request
```json
{
  "command": 25,
  "cue_id": 21
}
```
Response
```json
{ "result": true }
```

#### PAUSE_CUE_COMMAND: Pause cue with given id (not implemented)
Request
```json
{
  "command": 26,
  "cue_id": 2
}
```
Response
```json
{ "result": true }
```

#### STOP_CUE_COMMAND: Stop playback of playing cue by given id
Request
```json
{
  "command": 27,
  "cue_id": 21
}
```
Response
```json
{ "result": true }
```

#### CAPTURE_DMX_FRAME_COMMAND: Start Static frame recording
Capture Static cue with id 2 from ArtNet
- "universe_type" = 2 (ARTNET_TYPE)
- "universes" - all universes from 0 to 31 will be listened

All recorded ArtNet data will be streamed via Websockets.

Request
```json
{
  "command":  13,
  "cue_id": 2,
  "universe_type": 1,
  "universes": [
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
  ]
}
```
Response
```json
{ "result": true }
```

#### RECORD_DMX_FRAME_COMMAND: Start Dynamic frame recording
Start recording of Dynamic cue with id 21, with params:
- "live_preview" enabled - send recorded data to output during recording 
- "loop" disabled - don't check for the first 5 frames repeat to create perfect loop
- "universe_type" = 2 (SACN_TYPE) record from sACN
- "universes" - array of sACN universes to record, `-1` : disabled
- "trigger" - recording will start when Digital Input 3 become on Make and stop on Break

All recorded sACN data will be streamed via Websockets.

Request
```json
{
  "command":  14,
  "cue_id": 21,
  "live_preview": true,
  "loop": false,
  "trigger": {
    "value": {
      "port": 2,"data": 1
    },
    "type": 3
  },
  "universe_type": 2,
  "universes": [
    1,2,3,-1,5,6,7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
  ]
}

```
Response
```json
{ "result": true }
```

#### STOP_RECORD_COMMAND: Stop any recording
This command will stop the DMX/ArtNet/sACN frame recording if any
Request
```json
{"command": 15}
```
Response
```json
{ "result": true }
```

#### SAVE_CUE_COMMAND: Save cue state
Saves Cue config and for Static saves "frames" state / for Dynamic persists temporary recorded file.
If "cue_id" = 0 , engine will create new Cue from given data 

Static cue id=2 is updated, with 20 active universes but only one universe with data (the first array at "frames" has value, the second and others are zero frames), so universes from 1 till 19 will be getting zero frames, nothing will be sent to outputs from 21 till 32.
Request
```json
{ 
  "command": 16,
  "cue": 
  {
    "config": {
      "ch_start": 0,
      "ch_stop": 511,
      "source": 1,
      "universes": [
        0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
      ],
      "trigger": {
        "type": 0
      }
    },
    "cue_id": 2,
    "duration": 0,
    "frames": [
      [
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,254,249,249,249,244,244,244,238,238,238,234,234,234,228,228,228,223,223,223,218,218,218,213,213,213,208,208,208,202,202,202,198,198,198,192,192,192,188,188,188,182,182,182,177,177,177,172,172,172,166,166,166,162,162,162,156,156,156,152,152,152,146,146,146,141,141,141,136,136,136,131,131,131,127,127,127,121,121,121,117,117,117,111,111,111,106,106,106,101,101,101,96,96,96,91,91,91,85,85,85,81,81,81,75,75,75,70,70,70,65,65,65,60,60,60,55,55,55,49,49,49,45,45,45,39,39,39,34,34,34,29,29,29,24,24,24,19,19,19,13,13,13,9,9,9,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      ],
      [
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      ],
      [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], []
    ],
    "name": "Static Lighting 2",
    "type": 0
  }
}
```
Response
```json
{ "result": true }
```


Create Dynamic cue with outputs to all 32 universes using the last recorded file, with active channels from 30 till 455 in all universes.
Request
```json
{
  "config": {
    "ch_start": 30,
    "ch_stop": 455,
    "source": 1,
    "universes": [
      0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31
    ],
    "trigger": {
      "type": 0
    }
  },
  "cue_id": 0,
  "duration": 693214,
  "frames": [
    [],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[]
  ],
  "name": "Lighting Loop 2",
  "type": 1
}
```
Response
```json
{ "result": true }
```

#### DELETE_CUE_COMMAND: Delete Cue by id
Request
```json
{ 
  "command": 17,
  "cue_id": 2
}
```
Response
```json
{ "result": true }
```
  
#### EXIT_CUE_EDIT_COMMAND: Frontend notifies on Cue editing finished, remove not persisted recorded files

Request
```json
{"command": 30}
```
Response
```json
{ "result": true }
```


-------------------------------------------------

#### SET_MASTER_INTENSITY
Set overall S-Play output intensity (Master Fader) with 50% brightness, doesn't persist after power cycle
Request
```json
{
  "command": 56,
  "intensity": 50
}
```
Response
```json
{ "result": true }
```

#### GET_MASTER_INTENSITY
Get overall S-Play output intensity (Master Fader) returns 50% brightness, doesn't persist after power cycle
Request
```json
{"command": 55}
```
Response
```json
{
  "result": true,
  "intensity": 50
}
```

#### UDP_MESSAGE: Accepts messages to interpret as UDP input
Send message to Playback to trigger existing UDP trigger with command "hello"
```json
{
  "command": 50,
  "message": "hello"
}
```
Response
```json
{ "result": true }
```

#### OSC_MESSAGE: Accepts messages to interpret as OSC input
Send message to Playback to trigger existing OSC trigger with address "/test"
Request
```json
{
  "command": 51,
  "address": "/test"
}
```
Response
```json
{ "result": true }
```

-------------------------------------------------

### Settings Control Description and JSON Requests/Responses Examples

> Be very careful while editing settings improper config can break S-Play logic and only factory reset will fix it.
> First get the setting parameter then keeping the syntax and fields names the same modify values

List of setting ids:
```c++
enum SETTING_CATEGORIES {
    IS_SPARE = 0,
    SYSTEM_NAME = 1,
    PLAYBACK_CONFIG = 2,
    PASSWORD = 3,
    HELP_HINTS = 4,
    SERIALNO = 5,
    ENABLE_PASSWORD = 6,
    SMTP = 7,
    EMAIL = 8,
    INPUT = 9,
    OUTPUT = 10,
    DMX = 11,
    ARTNET = 12,
    SACN = 13,
    LOCATION = 14,
    NTP = 15,
    BASE_PATH = 16,
    CUE_PATH = 17,
    HOME_INTERFACE = 18,
    UDP = 19,
    TCP = 20,
    RS232C = 21,
    OSC = 22,
    IEEE1588_CONFIG = 23,
    IEEE1588_ACTIVE = 24,
    LOCK_STATUS = 25,
    DB_VERSION = 26,
    SIZE_OF_SETTING_CATEGORIES
};
```

#### GET_SETTING_COMMAND: Get Setting by id
Get output settings
Request
```json
{
  "command": 21,
  "setting_id": 10
}
```
Response
```json
{
  "result": true,
  "setting": {
    "outputs":[
      "dmx1","dmx2","artnet1","artnet2","artnet3","artnet4","artnet5","artnet6","artnet7","artnet8","sacn1","sacn2","sacn3","sacn4","sacn5","sacn6","sacn7","sacn8","none","none","none","none","none","none","none","none","none","none","none","none","none","none"
    ]}
}
```
Here first two outputs are assigned to DMX 1 and 2 ports
Next 8 outputs goes to ArtNet 1 to 8
Next 8 outputs goes to sACN 1 to 8
Other 14 are not assigned to any output

#### UPDATE_SETTING_COMMAND: Update Setting by id
Update playback configuration, set:
"Send black frame on playlist stop" to false
"Restrict to one active playlist per Group" to true

Request
```json
{
  "command": 20,
  "setting": {
    "setting_id": 2,
    "value": {
      "send_blackout":false,"one_playlist_group_play":true
    }
  }
}
```
Response
```json
{ "result": true }
```

-------------------------------------------------

### Event Management Description and JSON Requests/Responses Examples

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

