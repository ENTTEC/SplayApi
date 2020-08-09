# SplayApi
##S-Play HTTP API description
**S-Play firmware version 1.2.5**

### HTTP POST Commands for S-Play's playback.
Enum CONTROL_COMMANDS below presents the list of available playback commands.
They can be sent using HTTP POST requests to the device IP on the`55555` port and path`/api/`.

e.g. URL: ` http://192.168.1.13:55555/api`

Request can be tested using **curl**:

``
curl --header "Content-Type: application/json" -d "{\"command\":8}" http://localhost:55555/api --output -
``
> `Good to know`: RECORD only works on Dynamic Cues.

### Definitions

#### SplayEngine Commands
All playback control commands supported by the device
```c++
enum CONTROL_COMMANDS {
    PLAY_COMMAND = 0, // Play playlist already made by user
    PAUSE_COMMAND = 1, // Pause the playing playlist
    STOP_COMMAND = 2, // Stop the playlist is in PAUSE or PLAY status.
    STATUS_COMMAND = 3, // Get the status of playlist or cue in playlist
    CHECK_FILE_COMMAND = 4, // Check the recording exists, or data is not empty
    PLAY_ALL_PLAYLISTS_COMMAND = 5, // Play all playlist already made by user
    PAUSE_ALL_PLAYLISTS_COMMAND = 6, // Pause all playing playlists
    STOP_ALL_PLAYLISTS_COMMAND = 7, // Stop all playlists is in PAUSE or PLAY status.
    GET_RUNNING_PLAYLIST_COMMAND = 8, // Get status of all currently playing playlists
    SET_PLAYLIST_INTENSITY_COMMAND = 9, // Output intensity (Master Fader) of the given playlist, doesn't persist after stop
    GET_PLAYLIST_INTENSITY_COMMAND = 10, // Return the intensity of given playlist (not implemented)
    SET_TRACK_INTENSITY_COMMAND = 11, // Master Fader is the Output Intensity, doesn't persist after stop
    GET_TRACK_INTENSITY_COMMAND = 12, // Return the current Intensity (not implemented)
    CAPTURE_DMX_FRAME_COMMAND = 13, // Static frame recording (not implemented)
    RECORD_DMX_FRAME_COMMAND = 14, // Dynamic frame recording (not implemented)
    STOP_RECORD_COMMAND = 15, // Stop current recording
    PLAY_CUE_COMMAND = 16, // Play given cue
    STOP_CUE_COMMAND = 17, // Stop given cue
    UPDATE_PLAYLIST_COMMAND = 18,
    DELETE_PLAYLIST_COMMAND = 19,
    UPDATE_SETTINGS_COMMAND = 20,

    SET_PLAYLIST_TIME_POSITION_COMMAND = 22,

    SET_MASTER_INTENSITY = 24, // Set overall S-Play output intensity (Master Fader), doesn't persist after power cycle
    OSC_MESSAGE = 25, // Send OSC message to Playback to trigger existing OSC triggers
}
```
#### GetStatus Command Sub-Commands
Here are definition of Sub-Commands that used by STATUS_COMMAND, CAPTURE_DMX_FRAME_COMMAND and RECORD_DMX_FRAME_COMMAND comm}and.
```c++
enum COMMAND_TYPES {
    PLAYLIST_COMMAND                       = 0,     // Target is playlist.
    CUE_COMMAND                            = 1,     // Target is cue.
    ARTNET_COMMAND                         = 2,     // Capture or record from ArtNet device.
    SACN_COMMAND                           = 3,     // Capture or record from sACN device.
    DMX_COMMAND                            = 4      // Capture or record from DMX device.
};
```

#### Playlist Status
```c++
enum PLAYLIST_STATUS_TYPES {
    PLAYLIST_STATUS_IDLE                   = 0,     // Idle Status, No Action.
    PLAYLIST_STATUS_PLAYING                = 1,     // The playlist in Playing.
    PLAYLIST_STATUS_PAUSED                 = 2,     // The playlist in Paused.
    PLAYLIST_STATUS_STOPPED                = 3,     // The playlist in Stopped.
    PLAYLIST_STATUS_RECORD                 = 4,     // Futhure
    PLAYLIST_STATUS_ERROR                  = 5      // Error in playlist's last action.
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
};
```

### Trigger Kind Names
Indicate what device do you wait to trigger from.
```c++
#define TRIGGER_TYPENAME_OSC               "osc"    // value: "string command"
#define TRIGGER_TYPENAME_RS232             "rs232"  // value: "string command"
#define TRIGGER_TYPENAME_DMX               "dmx"    // value: { "channel_number": 0~511, "threshold": 0~255 }
```

### Event Kind Names
Indicate event target device to implement event action
```c++
#define EVENT_TYPE_RELAY                   "relay"  // value: { "relay_number": 0~.., "value": 0~1 }
#define EVENT_TYPE_RS232                   "rs232"  // value: "string"
```

### Trigger Kinds
Indicate what device do you wait to trigger from.
```c++
enum TRIGGER_TYPE {
    TRIGGER_TYPE_NONE = 0,
    TRIGGER_TYPE_OSC,
    TRIGGER_TYPE_RS232,
    TRIGGER_TYPE_IO,
    TRIGGER_TYPE_ARTNET,
    TRIGGER_TYPE_DMX,
    TRIGGER_TYPE_SACN,
    TRIGGER_TYPE_POWERUP
};
```
