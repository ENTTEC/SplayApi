// automatically generated by the FlatBuffers compiler, do not modify

/**
 * @const
 * @namespace
 */
var SplayApi = SplayApi || {};

/**
 * @enum {number}
 */
SplayApi.UNIVERSE_TYPE = {
  DMX: 0,
  ARTNET: 1,
  SACN: 2,
  NONE: 3
};

/**
 * @enum {string}
 */
SplayApi.UNIVERSE_TYPEName = {
  '0': 'DMX',
  '1': 'ARTNET',
  '2': 'SACN',
  '3': 'NONE'
};

/**
 * @enum {number}
 */
SplayApi.WEBSOCKET_OUTPUT = {
  NOTHING: -2,
  ALL: -1
};

/**
 * @enum {string}
 */
SplayApi.WEBSOCKET_OUTPUTName = {
  '-2': 'NOTHING',
  '-1': 'ALL'
};

/**
 * Don't change order
 *
 * @enum {number}
 */
SplayApi.PIXEL_ORDER = {
  RGB: 0,
  RBG: 1,
  GRB: 2,
  GBR: 3,
  BRG: 4,
  BGR: 5,
  RGBW: 6,
  RBGW: 7,
  GRBW: 8,
  GBRW: 9,
  BRGW: 10,
  BGRW: 11,
  WRGB: 12,
  WRBG: 13,
  WGRB: 14,
  WGBR: 15,
  WBRG: 16,
  WBGR: 17,
  RWGB: 18,
  RWBG: 19,
  GWRB: 20,
  GWBR: 21,
  BWRG: 22,
  BWGR: 23,
  RGWB: 24,
  RBWG: 25,
  GRWB: 26,
  GBWR: 27,
  BRWG: 28,
  BGWR: 29,
  W: 30,
  RRGGBB: 31,
  RRGGBBWW: 32
};

/**
 * Don't change order
 *
 * @enum {string}
 */
SplayApi.PIXEL_ORDERName = {
  '0': 'RGB',
  '1': 'RBG',
  '2': 'GRB',
  '3': 'GBR',
  '4': 'BRG',
  '5': 'BGR',
  '6': 'RGBW',
  '7': 'RBGW',
  '8': 'GRBW',
  '9': 'GBRW',
  '10': 'BRGW',
  '11': 'BGRW',
  '12': 'WRGB',
  '13': 'WRBG',
  '14': 'WGRB',
  '15': 'WGBR',
  '16': 'WBRG',
  '17': 'WBGR',
  '18': 'RWGB',
  '19': 'RWBG',
  '20': 'GWRB',
  '21': 'GWBR',
  '22': 'BWRG',
  '23': 'BWGR',
  '24': 'RGWB',
  '25': 'RBWG',
  '26': 'GRWB',
  '27': 'GBWR',
  '28': 'BRWG',
  '29': 'BGWR',
  '30': 'W',
  '31': 'RRGGBB',
  '32': 'RRGGBBWW'
};

/**
 * @enum {number}
 */
SplayApi.SETTING = {
  IS_SPARE: 0,
  SYSTEM_NAME: 1,
  PLAYBACK_CONFIG: 2,
  PASSWORD: 3,
  HELP_HINTS: 4,
  SERIALNO: 5,
  ENABLE_PASSWORD: 6,
  SMTP: 7,
  EMAIL: 8,
  INPUT: 9,
  OUTPUT: 10,
  DMX: 11,
  ARTNET: 12,
  SACN: 13,
  LOCATION: 14,
  NTP: 15,
  BASE_PATH: 16,
  CUE_PATH: 17,
  HOME_INTERFACE: 18,
  UDP: 19,
  TCP: 20,
  RS232C: 21,
  OSC: 22,
  IEEE1588_CONFIG: 23,
  IEEE1588_ACTIVE: 24,
  LOCK_STATUS: 25,
  DB_VERSION: 26
};

/**
 * @enum {string}
 */
SplayApi.SETTINGName = {
  '0': 'IS_SPARE',
  '1': 'SYSTEM_NAME',
  '2': 'PLAYBACK_CONFIG',
  '3': 'PASSWORD',
  '4': 'HELP_HINTS',
  '5': 'SERIALNO',
  '6': 'ENABLE_PASSWORD',
  '7': 'SMTP',
  '8': 'EMAIL',
  '9': 'INPUT',
  '10': 'OUTPUT',
  '11': 'DMX',
  '12': 'ARTNET',
  '13': 'SACN',
  '14': 'LOCATION',
  '15': 'NTP',
  '16': 'BASE_PATH',
  '17': 'CUE_PATH',
  '18': 'HOME_INTERFACE',
  '19': 'UDP',
  '20': 'TCP',
  '21': 'RS232C',
  '22': 'OSC',
  '23': 'IEEE1588_CONFIG',
  '24': 'IEEE1588_ACTIVE',
  '25': 'LOCK_STATUS',
  '26': 'DB_VERSION'
};

/**
 * @constructor
 */
SplayApi.GetFirmwareUpdateStatus = function() {
  /**
   * @type {flatbuffers.ByteBuffer}
   */
  this.bb = null;

  /**
   * @type {number}
   */
  this.bb_pos = 0;
};

/**
 * @param {number} i
 * @param {flatbuffers.ByteBuffer} bb
 * @returns {SplayApi.GetFirmwareUpdateStatus}
 */
SplayApi.GetFirmwareUpdateStatus.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.GetFirmwareUpdateStatus=} obj
 * @returns {SplayApi.GetFirmwareUpdateStatus}
 */
SplayApi.GetFirmwareUpdateStatus.getRootAsGetFirmwareUpdateStatus = function(bb, obj) {
  return (obj || new SplayApi.GetFirmwareUpdateStatus).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.GetFirmwareUpdateStatus=} obj
 * @returns {SplayApi.GetFirmwareUpdateStatus}
 */
SplayApi.GetFirmwareUpdateStatus.getSizePrefixedRootAsGetFirmwareUpdateStatus = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayApi.GetFirmwareUpdateStatus).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @returns {number}
 */
SplayApi.GetFirmwareUpdateStatus.prototype.progress = function() {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
};

/**
 * @param {flatbuffers.Encoding=} optionalEncoding
 * @returns {string|Uint8Array|null}
 */
SplayApi.GetFirmwareUpdateStatus.prototype.error = function(optionalEncoding) {
  var offset = this.bb.__offset(this.bb_pos, 6);
  return offset ? this.bb.__string(this.bb_pos + offset, optionalEncoding) : null;
};

/**
 * @param {flatbuffers.Builder} builder
 */
SplayApi.GetFirmwareUpdateStatus.startGetFirmwareUpdateStatus = function(builder) {
  builder.startObject(2);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} progress
 */
SplayApi.GetFirmwareUpdateStatus.addProgress = function(builder, progress) {
  builder.addFieldInt8(0, progress, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} errorOffset
 */
SplayApi.GetFirmwareUpdateStatus.addError = function(builder, errorOffset) {
  builder.addFieldOffset(1, errorOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
SplayApi.GetFirmwareUpdateStatus.endGetFirmwareUpdateStatus = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} progress
 * @param {flatbuffers.Offset} errorOffset
 * @returns {flatbuffers.Offset}
 */
SplayApi.GetFirmwareUpdateStatus.createGetFirmwareUpdateStatus = function(builder, progress, errorOffset) {
  SplayApi.GetFirmwareUpdateStatus.startGetFirmwareUpdateStatus(builder);
  SplayApi.GetFirmwareUpdateStatus.addProgress(builder, progress);
  SplayApi.GetFirmwareUpdateStatus.addError(builder, errorOffset);
  return SplayApi.GetFirmwareUpdateStatus.endGetFirmwareUpdateStatus(builder);
}

/**
 * @constructor
 */
SplayApi.SystemInfo = function() {
  /**
   * @type {flatbuffers.ByteBuffer}
   */
  this.bb = null;

  /**
   * @type {number}
   */
  this.bb_pos = 0;
};

/**
 * @param {number} i
 * @param {flatbuffers.ByteBuffer} bb
 * @returns {SplayApi.SystemInfo}
 */
SplayApi.SystemInfo.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.SystemInfo=} obj
 * @returns {SplayApi.SystemInfo}
 */
SplayApi.SystemInfo.getRootAsSystemInfo = function(bb, obj) {
  return (obj || new SplayApi.SystemInfo).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.SystemInfo=} obj
 * @returns {SplayApi.SystemInfo}
 */
SplayApi.SystemInfo.getSizePrefixedRootAsSystemInfo = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayApi.SystemInfo).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @returns {number}
 */
SplayApi.SystemInfo.prototype.cpuUsage = function() {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? this.bb.readFloat32(this.bb_pos + offset) : 0.0;
};

/**
 * @returns {number}
 */
SplayApi.SystemInfo.prototype.temperature = function() {
  var offset = this.bb.__offset(this.bb_pos, 6);
  return offset ? this.bb.readFloat32(this.bb_pos + offset) : 0.0;
};

/**
 * @param {flatbuffers.Encoding=} optionalEncoding
 * @returns {string|Uint8Array|null}
 */
SplayApi.SystemInfo.prototype.time = function(optionalEncoding) {
  var offset = this.bb.__offset(this.bb_pos, 8);
  return offset ? this.bb.__string(this.bb_pos + offset, optionalEncoding) : null;
};

/**
 * @param {flatbuffers.Builder} builder
 */
SplayApi.SystemInfo.startSystemInfo = function(builder) {
  builder.startObject(3);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} cpuUsage
 */
SplayApi.SystemInfo.addCpuUsage = function(builder, cpuUsage) {
  builder.addFieldFloat32(0, cpuUsage, 0.0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} temperature
 */
SplayApi.SystemInfo.addTemperature = function(builder, temperature) {
  builder.addFieldFloat32(1, temperature, 0.0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} timeOffset
 */
SplayApi.SystemInfo.addTime = function(builder, timeOffset) {
  builder.addFieldOffset(2, timeOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
SplayApi.SystemInfo.endSystemInfo = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} cpuUsage
 * @param {number} temperature
 * @param {flatbuffers.Offset} timeOffset
 * @returns {flatbuffers.Offset}
 */
SplayApi.SystemInfo.createSystemInfo = function(builder, cpuUsage, temperature, timeOffset) {
  SplayApi.SystemInfo.startSystemInfo(builder);
  SplayApi.SystemInfo.addCpuUsage(builder, cpuUsage);
  SplayApi.SystemInfo.addTemperature(builder, temperature);
  SplayApi.SystemInfo.addTime(builder, timeOffset);
  return SplayApi.SystemInfo.endSystemInfo(builder);
}

// Exports for ECMAScript6 Modules
export {SplayApi};
