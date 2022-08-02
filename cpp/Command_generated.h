// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_COMMAND_SPLAYAPI_H_
#define FLATBUFFERS_GENERATED_COMMAND_SPLAYAPI_H_

#include "flatbuffers/flatbuffers.h"

namespace SplayApi {

enum COMMAND {
  COMMAND_PLAY = 0,
  COMMAND_PAUSE = 1,
  COMMAND_STOP = 2,
  COMMAND_GET_PLAYLIST = 3,
  COMMAND_UPDATE_PLAYLISTS_ORDER = 4,
  COMMAND_PLAY_ALL_PLAYLISTS = 5,
  COMMAND_PAUSE_ALL_PLAYLISTS = 6,
  COMMAND_STOP_ALL_PLAYLISTS = 7,
  COMMAND_GET_ALL_PLAYLISTS = 8,
  COMMAND_SET_PLAYLIST_INTENSITY = 9,
  COMMAND_GET_PLAYLIST_INTENSITY = 10,
  COMMAND_SET_TRACK_INTENSITY = 11,
  COMMAND_GET_TRACK_INTENSITY = 12,
  COMMAND_CAPTURE_DMX_FRAME = 13,
  COMMAND_RECORD_DMX_FRAME = 14,
  COMMAND_STOP_RECORD = 15,
  COMMAND_SAVE_CUE = 16,
  COMMAND_DELETE_CUE = 17,
  COMMAND_UPDATE_PLAYLIST = 18,
  COMMAND_DELETE_PLAYLIST = 19,
  COMMAND_UPDATE_SETTING = 20,
  COMMAND_GET_SETTING = 21,
  COMMAND_SET_PLAYLIST_TIME_POSITION = 22,
  COMMAND_SET_WEBSOCKET_INPUT = 23,
  COMMAND_PLAY_CUE = 25,
  COMMAND_PAUSE_CUE = 26,
  COMMAND_STOP_CUE = 27,
  COMMAND_GET_CUE = 28,
  COMMAND_GET_ALL_CUES = 29,
  COMMAND_EXIT_CUE_EDIT = 30,
  COMMAND_DUPLICATE_CUE = 31,
  COMMAND_UPDATE_STORAGE_PATH = 34,
  COMMAND_GET_EVENT = 36,
  COMMAND_GET_ALL_EVENTS = 37,
  COMMAND_UPDATE_EVENT = 38,
  COMMAND_DELETE_EVENT = 39,
  COMMAND_GET_TRIGGER = 40,
  COMMAND_GET_ALL_TRIGGERS = 41,
  COMMAND_UPDATE_TRIGGER = 42,
  COMMAND_DELETE_TRIGGER = 43,
  COMMAND_SEND_EVENT = 44,
  COMMAND_WAIT_TRIGGER = 45,
  COMMAND_CHECK_TRIGGER = 46,
  COMMAND_UDP_MESSAGE = 50,
  COMMAND_OSC_MESSAGE = 51,
  COMMAND_GET_MASTER_INTENSITY = 55,
  COMMAND_SET_MASTER_INTENSITY = 56,
  COMMAND_GET_SCHEDULES = 60,
  COMMAND_UPDATE_SCHEDULE = 61,
  COMMAND_DELETE_SCHEDULE = 62,
  COMMAND_ENABLE_SCHEDULE = 63,
  COMMAND_GET_INTERFACE = 70,
  COMMAND_GET_ALL_INTERFACES = 71,
  COMMAND_UPDATE_INTERFACE = 72,
  COMMAND_DELETE_INTERFACE = 73,
  COMMAND_GET_VERSION = 80,
  COMMAND_GET_NETWORK = 81,
  COMMAND_SET_NETWORK = 82,
  COMMAND_GET_TIME = 83,
  COMMAND_SET_TIME = 84,
  COMMAND_GET_STORAGES = 85,
  COMMAND_SET_STORAGE = 86,
  COMMAND_FACTORY_RESET = 87,
  COMMAND_GET_INFO = 88,
  COMMAND_GET_SSH_TUNNEL_STATUS = 90,
  COMMAND_GET_SSH_TUNNEL_CONFIG = 91,
  COMMAND_SET_SSH_TUNNEL_CONFIG = 92,
  COMMAND_LOGIN = 95,
  COMMAND_CHANGE_PASSWORD = 96,
  COMMAND_SET_LICENSE = 97,
  COMMAND_GET_BACKUP = 100,
  COMMAND_MAKE_BACKUP = 101,
  COMMAND_COPY_STORAGE = 102,
  COMMAND_APPLY_RESTORE = 103,
  COMMAND_DISCOVER_DEVICES = 110,
  COMMAND_SHUTDOWN = 222,
  COMMAND_REFRESH_SETTING = 254,
  COMMAND_MIN = COMMAND_PLAY,
  COMMAND_MAX = COMMAND_REFRESH_SETTING
};

inline const COMMAND (&EnumValuesCOMMAND())[77] {
  static const COMMAND values[] = {
    COMMAND_PLAY,
    COMMAND_PAUSE,
    COMMAND_STOP,
    COMMAND_GET_PLAYLIST,
    COMMAND_UPDATE_PLAYLISTS_ORDER,
    COMMAND_PLAY_ALL_PLAYLISTS,
    COMMAND_PAUSE_ALL_PLAYLISTS,
    COMMAND_STOP_ALL_PLAYLISTS,
    COMMAND_GET_ALL_PLAYLISTS,
    COMMAND_SET_PLAYLIST_INTENSITY,
    COMMAND_GET_PLAYLIST_INTENSITY,
    COMMAND_SET_TRACK_INTENSITY,
    COMMAND_GET_TRACK_INTENSITY,
    COMMAND_CAPTURE_DMX_FRAME,
    COMMAND_RECORD_DMX_FRAME,
    COMMAND_STOP_RECORD,
    COMMAND_SAVE_CUE,
    COMMAND_DELETE_CUE,
    COMMAND_UPDATE_PLAYLIST,
    COMMAND_DELETE_PLAYLIST,
    COMMAND_UPDATE_SETTING,
    COMMAND_GET_SETTING,
    COMMAND_SET_PLAYLIST_TIME_POSITION,
    COMMAND_SET_WEBSOCKET_INPUT,
    COMMAND_PLAY_CUE,
    COMMAND_PAUSE_CUE,
    COMMAND_STOP_CUE,
    COMMAND_GET_CUE,
    COMMAND_GET_ALL_CUES,
    COMMAND_EXIT_CUE_EDIT,
    COMMAND_DUPLICATE_CUE,
    COMMAND_UPDATE_STORAGE_PATH,
    COMMAND_GET_EVENT,
    COMMAND_GET_ALL_EVENTS,
    COMMAND_UPDATE_EVENT,
    COMMAND_DELETE_EVENT,
    COMMAND_GET_TRIGGER,
    COMMAND_GET_ALL_TRIGGERS,
    COMMAND_UPDATE_TRIGGER,
    COMMAND_DELETE_TRIGGER,
    COMMAND_SEND_EVENT,
    COMMAND_WAIT_TRIGGER,
    COMMAND_CHECK_TRIGGER,
    COMMAND_UDP_MESSAGE,
    COMMAND_OSC_MESSAGE,
    COMMAND_GET_MASTER_INTENSITY,
    COMMAND_SET_MASTER_INTENSITY,
    COMMAND_GET_SCHEDULES,
    COMMAND_UPDATE_SCHEDULE,
    COMMAND_DELETE_SCHEDULE,
    COMMAND_ENABLE_SCHEDULE,
    COMMAND_GET_INTERFACE,
    COMMAND_GET_ALL_INTERFACES,
    COMMAND_UPDATE_INTERFACE,
    COMMAND_DELETE_INTERFACE,
    COMMAND_GET_VERSION,
    COMMAND_GET_NETWORK,
    COMMAND_SET_NETWORK,
    COMMAND_GET_TIME,
    COMMAND_SET_TIME,
    COMMAND_GET_STORAGES,
    COMMAND_SET_STORAGE,
    COMMAND_FACTORY_RESET,
    COMMAND_GET_INFO,
    COMMAND_GET_SSH_TUNNEL_STATUS,
    COMMAND_GET_SSH_TUNNEL_CONFIG,
    COMMAND_SET_SSH_TUNNEL_CONFIG,
    COMMAND_LOGIN,
    COMMAND_CHANGE_PASSWORD,
    COMMAND_SET_LICENSE,
    COMMAND_GET_BACKUP,
    COMMAND_MAKE_BACKUP,
    COMMAND_COPY_STORAGE,
    COMMAND_APPLY_RESTORE,
    COMMAND_DISCOVER_DEVICES,
    COMMAND_SHUTDOWN,
    COMMAND_REFRESH_SETTING
  };
  return values;
}

inline const char * const *EnumNamesCOMMAND() {
  static const char * const names[256] = {
    "PLAY",
    "PAUSE",
    "STOP",
    "GET_PLAYLIST",
    "UPDATE_PLAYLISTS_ORDER",
    "PLAY_ALL_PLAYLISTS",
    "PAUSE_ALL_PLAYLISTS",
    "STOP_ALL_PLAYLISTS",
    "GET_ALL_PLAYLISTS",
    "SET_PLAYLIST_INTENSITY",
    "GET_PLAYLIST_INTENSITY",
    "SET_TRACK_INTENSITY",
    "GET_TRACK_INTENSITY",
    "CAPTURE_DMX_FRAME",
    "RECORD_DMX_FRAME",
    "STOP_RECORD",
    "SAVE_CUE",
    "DELETE_CUE",
    "UPDATE_PLAYLIST",
    "DELETE_PLAYLIST",
    "UPDATE_SETTING",
    "GET_SETTING",
    "SET_PLAYLIST_TIME_POSITION",
    "SET_WEBSOCKET_INPUT",
    "",
    "PLAY_CUE",
    "PAUSE_CUE",
    "STOP_CUE",
    "GET_CUE",
    "GET_ALL_CUES",
    "EXIT_CUE_EDIT",
    "DUPLICATE_CUE",
    "",
    "",
    "UPDATE_STORAGE_PATH",
    "",
    "GET_EVENT",
    "GET_ALL_EVENTS",
    "UPDATE_EVENT",
    "DELETE_EVENT",
    "GET_TRIGGER",
    "GET_ALL_TRIGGERS",
    "UPDATE_TRIGGER",
    "DELETE_TRIGGER",
    "SEND_EVENT",
    "WAIT_TRIGGER",
    "CHECK_TRIGGER",
    "",
    "",
    "",
    "UDP_MESSAGE",
    "OSC_MESSAGE",
    "",
    "",
    "",
    "GET_MASTER_INTENSITY",
    "SET_MASTER_INTENSITY",
    "",
    "",
    "",
    "GET_SCHEDULES",
    "UPDATE_SCHEDULE",
    "DELETE_SCHEDULE",
    "ENABLE_SCHEDULE",
    "",
    "",
    "",
    "",
    "",
    "",
    "GET_INTERFACE",
    "GET_ALL_INTERFACES",
    "UPDATE_INTERFACE",
    "DELETE_INTERFACE",
    "",
    "",
    "",
    "",
    "",
    "",
    "GET_VERSION",
    "GET_NETWORK",
    "SET_NETWORK",
    "GET_TIME",
    "SET_TIME",
    "GET_STORAGES",
    "SET_STORAGE",
    "FACTORY_RESET",
    "GET_INFO",
    "",
    "GET_SSH_TUNNEL_STATUS",
    "GET_SSH_TUNNEL_CONFIG",
    "SET_SSH_TUNNEL_CONFIG",
    "",
    "",
    "LOGIN",
    "CHANGE_PASSWORD",
    "SET_LICENSE",
    "",
    "",
    "GET_BACKUP",
    "MAKE_BACKUP",
    "COPY_STORAGE",
    "APPLY_RESTORE",
    "",
    "",
    "",
    "",
    "",
    "",
    "DISCOVER_DEVICES",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "SHUTDOWN",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "REFRESH_SETTING",
    nullptr
  };
  return names;
}

inline const char *EnumNameCOMMAND(COMMAND e) {
  if (flatbuffers::IsOutRange(e, COMMAND_PLAY, COMMAND_REFRESH_SETTING)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesCOMMAND()[index];
}

}  // namespace SplayApi

#endif  // FLATBUFFERS_GENERATED_COMMAND_SPLAYAPI_H_
