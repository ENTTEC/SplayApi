// automatically generated by the FlatBuffers compiler, do not modify

/**
 * @const
 * @namespace
 */
var SplayApi = SplayApi || {};

/**
 * @enum {number}
 */
SplayApi.Body = {
  NONE: 0,
  StatusRes: 1,
  PlayPlaylistReq: 2,
  PausePlaylistReq: 3,
  StopPlaylistReq: 4,
  GetPlaylistReq: 5,
  GetPlaylistRes: 6,
  GetAllPlaylistsReq: 7,
  GetAllPlaylistsRes: 8,
  GetCueReq: 9,
  GetCueRes: 10,
  GetAllCuesReq: 11,
  GetAllCuesRes: 12,
  GetFirmwareUpdateStatus: 13,
  SystemInfo: 14,
  RestorePackage: 15,
  BackupInfo: 16
};

/**
 * @enum {string}
 */
SplayApi.BodyName = {
  '0': 'NONE',
  '1': 'StatusRes',
  '2': 'PlayPlaylistReq',
  '3': 'PausePlaylistReq',
  '4': 'StopPlaylistReq',
  '5': 'GetPlaylistReq',
  '6': 'GetPlaylistRes',
  '7': 'GetAllPlaylistsReq',
  '8': 'GetAllPlaylistsRes',
  '9': 'GetCueReq',
  '10': 'GetCueRes',
  '11': 'GetAllCuesReq',
  '12': 'GetAllCuesRes',
  '13': 'GetFirmwareUpdateStatus',
  '14': 'SystemInfo',
  '15': 'RestorePackage',
  '16': 'BackupInfo'
};

/**
 * @constructor
 */
SplayApi.StatusRes = function() {
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
 * @returns {SplayApi.StatusRes}
 */
SplayApi.StatusRes.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.StatusRes=} obj
 * @returns {SplayApi.StatusRes}
 */
SplayApi.StatusRes.getRootAsStatusRes = function(bb, obj) {
  return (obj || new SplayApi.StatusRes).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.StatusRes=} obj
 * @returns {SplayApi.StatusRes}
 */
SplayApi.StatusRes.getSizePrefixedRootAsStatusRes = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayApi.StatusRes).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @returns {boolean}
 */
SplayApi.StatusRes.prototype.result = function() {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? !!this.bb.readInt8(this.bb_pos + offset) : false;
};

/**
 * @param {flatbuffers.Encoding=} optionalEncoding
 * @returns {string|Uint8Array|null}
 */
SplayApi.StatusRes.prototype.error = function(optionalEncoding) {
  var offset = this.bb.__offset(this.bb_pos, 6);
  return offset ? this.bb.__string(this.bb_pos + offset, optionalEncoding) : null;
};

/**
 * @param {flatbuffers.Builder} builder
 */
SplayApi.StatusRes.startStatusRes = function(builder) {
  builder.startObject(2);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {boolean} result
 */
SplayApi.StatusRes.addResult = function(builder, result) {
  builder.addFieldInt8(0, +result, +false);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} errorOffset
 */
SplayApi.StatusRes.addError = function(builder, errorOffset) {
  builder.addFieldOffset(1, errorOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
SplayApi.StatusRes.endStatusRes = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {boolean} result
 * @param {flatbuffers.Offset} errorOffset
 * @returns {flatbuffers.Offset}
 */
SplayApi.StatusRes.createStatusRes = function(builder, result, errorOffset) {
  SplayApi.StatusRes.startStatusRes(builder);
  SplayApi.StatusRes.addResult(builder, result);
  SplayApi.StatusRes.addError(builder, errorOffset);
  return SplayApi.StatusRes.endStatusRes(builder);
}

/**
 * @constructor
 */
SplayApi.Header = function() {
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
 * @returns {SplayApi.Header}
 */
SplayApi.Header.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.Header=} obj
 * @returns {SplayApi.Header}
 */
SplayApi.Header.getRootAsHeader = function(bb, obj) {
  return (obj || new SplayApi.Header).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.Header=} obj
 * @returns {SplayApi.Header}
 */
SplayApi.Header.getSizePrefixedRootAsHeader = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayApi.Header).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.Encoding=} optionalEncoding
 * @returns {string|Uint8Array|null}
 */
SplayApi.Header.prototype.token = function(optionalEncoding) {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? this.bb.__string(this.bb_pos + offset, optionalEncoding) : null;
};

/**
 * @param {flatbuffers.Builder} builder
 */
SplayApi.Header.startHeader = function(builder) {
  builder.startObject(1);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} tokenOffset
 */
SplayApi.Header.addToken = function(builder, tokenOffset) {
  builder.addFieldOffset(0, tokenOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
SplayApi.Header.endHeader = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} tokenOffset
 * @returns {flatbuffers.Offset}
 */
SplayApi.Header.createHeader = function(builder, tokenOffset) {
  SplayApi.Header.startHeader(builder);
  SplayApi.Header.addToken(builder, tokenOffset);
  return SplayApi.Header.endHeader(builder);
}

/**
 * @constructor
 */
SplayApi.Message = function() {
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
 * @returns {SplayApi.Message}
 */
SplayApi.Message.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.Message=} obj
 * @returns {SplayApi.Message}
 */
SplayApi.Message.getRootAsMessage = function(bb, obj) {
  return (obj || new SplayApi.Message).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.Message=} obj
 * @returns {SplayApi.Message}
 */
SplayApi.Message.getSizePrefixedRootAsMessage = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayApi.Message).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {SplayApi.Header=} obj
 * @returns {SplayApi.Header|null}
 */
SplayApi.Message.prototype.header = function(obj) {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? (obj || new SplayApi.Header).__init(this.bb.__indirect(this.bb_pos + offset), this.bb) : null;
};

/**
 * @returns {SplayApi.Body}
 */
SplayApi.Message.prototype.bodyType = function() {
  var offset = this.bb.__offset(this.bb_pos, 6);
  return offset ? /** @type {SplayApi.Body} */ (this.bb.readUint8(this.bb_pos + offset)) : SplayApi.Body.NONE;
};

/**
 * @param {flatbuffers.Table} obj
 * @returns {?flatbuffers.Table}
 */
SplayApi.Message.prototype.body = function(obj) {
  var offset = this.bb.__offset(this.bb_pos, 8);
  return offset ? this.bb.__union(obj, this.bb_pos + offset) : null;
};

/**
 * @param {flatbuffers.Builder} builder
 */
SplayApi.Message.startMessage = function(builder) {
  builder.startObject(3);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} headerOffset
 */
SplayApi.Message.addHeader = function(builder, headerOffset) {
  builder.addFieldOffset(0, headerOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {SplayApi.Body} bodyType
 */
SplayApi.Message.addBodyType = function(builder, bodyType) {
  builder.addFieldInt8(1, bodyType, SplayApi.Body.NONE);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} bodyOffset
 */
SplayApi.Message.addBody = function(builder, bodyOffset) {
  builder.addFieldOffset(2, bodyOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
SplayApi.Message.endMessage = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} offset
 */
SplayApi.Message.finishMessageBuffer = function(builder, offset) {
  builder.finish(offset);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} offset
 */
SplayApi.Message.finishSizePrefixedMessageBuffer = function(builder, offset) {
  builder.finish(offset, undefined, true);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} headerOffset
 * @param {SplayApi.Body} bodyType
 * @param {flatbuffers.Offset} bodyOffset
 * @returns {flatbuffers.Offset}
 */
SplayApi.Message.createMessage = function(builder, headerOffset, bodyType, bodyOffset) {
  SplayApi.Message.startMessage(builder);
  SplayApi.Message.addHeader(builder, headerOffset);
  SplayApi.Message.addBodyType(builder, bodyType);
  SplayApi.Message.addBody(builder, bodyOffset);
  return SplayApi.Message.endMessage(builder);
}

// Exports for ECMAScript6 Modules
export {SplayApi};
