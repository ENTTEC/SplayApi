// automatically generated by the FlatBuffers compiler, do not modify

/**
 * @const
 * @namespace
 */
var SplayApi = SplayApi || {};

/**
 * @enum {number}
 */
SplayApi.COMMAND = {
  PLAY: 0,
  PAUSE: 1,
  STOP: 2,
  GET_PLAYLIST: 3,
  UPDATE_PLAYLISTS_ORDER: 4,
  PLAY_ALL_PLAYLISTS: 5,
  PAUSE_ALL_PLAYLISTS: 6,
  STOP_ALL_PLAYLISTS: 7,
  GET_ALL_PLAYLISTS: 8,
  SET_PLAYLIST_INTENSITY: 9,
  GET_PLAYLIST_INTENSITY: 10,
  SET_TRACK_INTENSITY: 11,
  GET_TRACK_INTENSITY: 12,
  CAPTURE_DMX_FRAME: 13,
  RECORD_DMX_FRAME: 14,
  STOP_RECORD: 15,
  SAVE_CUE: 16,
  DELETE_CUE: 17,
  UPDATE_PLAYLIST: 18,
  DELETE_PLAYLIST: 19,
  UPDATE_SETTING: 20,
  GET_SETTING: 21,
  SET_PLAYLIST_TIME_POSITION: 22,
  SET_WEBSOCKET_INPUT: 23,
  PLAY_CUE: 25,
  PAUSE_CUE: 26,
  STOP_CUE: 27,
  GET_CUE: 28,
  GET_ALL_CUES: 29,
  EXIT_CUE_EDIT: 30,
  DUPLICATE_CUE: 31,
  UPDATE_STORAGE_PATH: 34,
  GET_EVENT: 36,
  GET_ALL_EVENTS: 37,
  UPDATE_EVENT: 38,
  DELETE_EVENT: 39,
  GET_TRIGGER: 40,
  GET_ALL_TRIGGERS: 41,
  UPDATE_TRIGGER: 42,
  DELETE_TRIGGER: 43,
  SEND_EVENT: 44,
  WAIT_TRIGGER: 45,
  CHECK_TRIGGER: 46,
  UDP_MESSAGE: 50,
  OSC_MESSAGE: 51,
  GET_MASTER_INTENSITY: 55,
  SET_MASTER_INTENSITY: 56,
  GET_SCHEDULES: 60,
  UPDATE_SCHEDULE: 61,
  DELETE_SCHEDULE: 62,
  ENABLE_SCHEDULE: 63,
  GET_INTERFACE: 70,
  GET_ALL_INTERFACES: 71,
  UPDATE_INTERFACE: 72,
  DELETE_INTERFACE: 73,
  GET_VERSION: 80,
  GET_NETWORK: 81,
  SET_NETWORK: 82,
  GET_TIME: 83,
  SET_TIME: 84,
  GET_STORAGES: 85,
  SET_STORAGE: 86,
  FACTORY_RESET: 87,
  GET_INFO: 88,
  GET_SSH_TUNNEL_STATUS: 90,
  GET_SSH_TUNNEL_CONFIG: 91,
  SET_SSH_TUNNEL_CONFIG: 92,
  GET_BACKUP: 93,
  MAKE_BACKUP: 94,
  LOGIN: 95,
  CHANGE_PASSWORD: 96,
  SHUTDOWN: 222,
  REFRESH_SETTING: 254
};

/**
 * @enum {string}
 */
SplayApi.COMMANDName = {
  '0': 'PLAY',
  '1': 'PAUSE',
  '2': 'STOP',
  '3': 'GET_PLAYLIST',
  '4': 'UPDATE_PLAYLISTS_ORDER',
  '5': 'PLAY_ALL_PLAYLISTS',
  '6': 'PAUSE_ALL_PLAYLISTS',
  '7': 'STOP_ALL_PLAYLISTS',
  '8': 'GET_ALL_PLAYLISTS',
  '9': 'SET_PLAYLIST_INTENSITY',
  '10': 'GET_PLAYLIST_INTENSITY',
  '11': 'SET_TRACK_INTENSITY',
  '12': 'GET_TRACK_INTENSITY',
  '13': 'CAPTURE_DMX_FRAME',
  '14': 'RECORD_DMX_FRAME',
  '15': 'STOP_RECORD',
  '16': 'SAVE_CUE',
  '17': 'DELETE_CUE',
  '18': 'UPDATE_PLAYLIST',
  '19': 'DELETE_PLAYLIST',
  '20': 'UPDATE_SETTING',
  '21': 'GET_SETTING',
  '22': 'SET_PLAYLIST_TIME_POSITION',
  '23': 'SET_WEBSOCKET_INPUT',
  '25': 'PLAY_CUE',
  '26': 'PAUSE_CUE',
  '27': 'STOP_CUE',
  '28': 'GET_CUE',
  '29': 'GET_ALL_CUES',
  '30': 'EXIT_CUE_EDIT',
  '31': 'DUPLICATE_CUE',
  '34': 'UPDATE_STORAGE_PATH',
  '36': 'GET_EVENT',
  '37': 'GET_ALL_EVENTS',
  '38': 'UPDATE_EVENT',
  '39': 'DELETE_EVENT',
  '40': 'GET_TRIGGER',
  '41': 'GET_ALL_TRIGGERS',
  '42': 'UPDATE_TRIGGER',
  '43': 'DELETE_TRIGGER',
  '44': 'SEND_EVENT',
  '45': 'WAIT_TRIGGER',
  '46': 'CHECK_TRIGGER',
  '50': 'UDP_MESSAGE',
  '51': 'OSC_MESSAGE',
  '55': 'GET_MASTER_INTENSITY',
  '56': 'SET_MASTER_INTENSITY',
  '60': 'GET_SCHEDULES',
  '61': 'UPDATE_SCHEDULE',
  '62': 'DELETE_SCHEDULE',
  '63': 'ENABLE_SCHEDULE',
  '70': 'GET_INTERFACE',
  '71': 'GET_ALL_INTERFACES',
  '72': 'UPDATE_INTERFACE',
  '73': 'DELETE_INTERFACE',
  '80': 'GET_VERSION',
  '81': 'GET_NETWORK',
  '82': 'SET_NETWORK',
  '83': 'GET_TIME',
  '84': 'SET_TIME',
  '85': 'GET_STORAGES',
  '86': 'SET_STORAGE',
  '87': 'FACTORY_RESET',
  '88': 'GET_INFO',
  '90': 'GET_SSH_TUNNEL_STATUS',
  '91': 'GET_SSH_TUNNEL_CONFIG',
  '92': 'SET_SSH_TUNNEL_CONFIG',
  '93': 'GET_BACKUP',
  '94': 'MAKE_BACKUP',
  '95': 'LOGIN',
  '96': 'CHANGE_PASSWORD',
  '222': 'SHUTDOWN',
  '254': 'REFRESH_SETTING'
};

// Exports for ECMAScript6 Modules
export {SplayApi};
