// automatically generated by the FlatBuffers compiler, do not modify

/**
 * @const
 * @namespace
 */
var SplayApi = SplayApi || {};

/**
 * @enum {number}
 */
SplayApi.CUE_TYPE = {
  STATIC: 0,
  DYNAMIC: 1,
  EFFECT: 2
};

/**
 * @enum {string}
 */
SplayApi.CUE_TYPEName = {
  '0': 'STATIC',
  '1': 'DYNAMIC',
  '2': 'EFFECT'
};

/**
 * @constructor
 */
SplayApi.RecordStop = function() {
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
 * @returns {SplayApi.RecordStop}
 */
SplayApi.RecordStop.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.RecordStop=} obj
 * @returns {SplayApi.RecordStop}
 */
SplayApi.RecordStop.getRootAsRecordStop = function(bb, obj) {
  return (obj || new SplayApi.RecordStop).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.RecordStop=} obj
 * @returns {SplayApi.RecordStop}
 */
SplayApi.RecordStop.getSizePrefixedRootAsRecordStop = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayApi.RecordStop).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @returns {number}
 */
SplayApi.RecordStop.prototype.time = function() {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? this.bb.readUint32(this.bb_pos + offset) : 0;
};

/**
 * @param {flatbuffers.Builder} builder
 */
SplayApi.RecordStop.startRecordStop = function(builder) {
  builder.startObject(1);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} time
 */
SplayApi.RecordStop.addTime = function(builder, time) {
  builder.addFieldInt32(0, time, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
SplayApi.RecordStop.endRecordStop = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} time
 * @returns {flatbuffers.Offset}
 */
SplayApi.RecordStop.createRecordStop = function(builder, time) {
  SplayApi.RecordStop.startRecordStop(builder);
  SplayApi.RecordStop.addTime(builder, time);
  return SplayApi.RecordStop.endRecordStop(builder);
}

/**
 * @constructor
 */
SplayApi.CueConfig = function() {
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
 * @returns {SplayApi.CueConfig}
 */
SplayApi.CueConfig.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.CueConfig=} obj
 * @returns {SplayApi.CueConfig}
 */
SplayApi.CueConfig.getRootAsCueConfig = function(bb, obj) {
  return (obj || new SplayApi.CueConfig).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.CueConfig=} obj
 * @returns {SplayApi.CueConfig}
 */
SplayApi.CueConfig.getSizePrefixedRootAsCueConfig = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayApi.CueConfig).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @returns {number}
 */
SplayApi.CueConfig.prototype.chStart = function() {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? this.bb.readUint16(this.bb_pos + offset) : 0;
};

/**
 * @returns {number}
 */
SplayApi.CueConfig.prototype.chStop = function() {
  var offset = this.bb.__offset(this.bb_pos, 6);
  return offset ? this.bb.readUint16(this.bb_pos + offset) : 511;
};

/**
 * @returns {SplayApi.UNIVERSE_TYPE}
 */
SplayApi.CueConfig.prototype.source = function() {
  var offset = this.bb.__offset(this.bb_pos, 8);
  return offset ? /** @type {SplayApi.UNIVERSE_TYPE} */ (this.bb.readUint8(this.bb_pos + offset)) : SplayApi.UNIVERSE_TYPE.DMX;
};

/**
 * @returns {boolean}
 */
SplayApi.CueConfig.prototype.recControl = function() {
  var offset = this.bb.__offset(this.bb_pos, 10);
  return offset ? !!this.bb.readInt8(this.bb_pos + offset) : false;
};

/**
 * @param {SplayApi.TriggerTable=} obj
 * @returns {SplayApi.TriggerTable|null}
 */
SplayApi.CueConfig.prototype.trigger = function(obj) {
  var offset = this.bb.__offset(this.bb_pos, 12);
  return offset ? (obj || new SplayApi.TriggerTable).__init(this.bb.__indirect(this.bb_pos + offset), this.bb) : null;
};

/**
 * @param {flatbuffers.Builder} builder
 */
SplayApi.CueConfig.startCueConfig = function(builder) {
  builder.startObject(5);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} chStart
 */
SplayApi.CueConfig.addChStart = function(builder, chStart) {
  builder.addFieldInt16(0, chStart, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} chStop
 */
SplayApi.CueConfig.addChStop = function(builder, chStop) {
  builder.addFieldInt16(1, chStop, 511);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {SplayApi.UNIVERSE_TYPE} source
 */
SplayApi.CueConfig.addSource = function(builder, source) {
  builder.addFieldInt8(2, source, SplayApi.UNIVERSE_TYPE.DMX);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {boolean} recControl
 */
SplayApi.CueConfig.addRecControl = function(builder, recControl) {
  builder.addFieldInt8(3, +recControl, +false);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} triggerOffset
 */
SplayApi.CueConfig.addTrigger = function(builder, triggerOffset) {
  builder.addFieldOffset(4, triggerOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
SplayApi.CueConfig.endCueConfig = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} chStart
 * @param {number} chStop
 * @param {NS10718616522061772901.SplayApi.UNIVERSE_TYPE} source
 * @param {boolean} recControl
 * @param {flatbuffers.Offset} triggerOffset
 * @returns {flatbuffers.Offset}
 */
SplayApi.CueConfig.createCueConfig = function(builder, chStart, chStop, source, recControl, triggerOffset) {
  SplayApi.CueConfig.startCueConfig(builder);
  SplayApi.CueConfig.addChStart(builder, chStart);
  SplayApi.CueConfig.addChStop(builder, chStop);
  SplayApi.CueConfig.addSource(builder, source);
  SplayApi.CueConfig.addRecControl(builder, recControl);
  SplayApi.CueConfig.addTrigger(builder, triggerOffset);
  return SplayApi.CueConfig.endCueConfig(builder);
}

/**
 * @constructor
 */
SplayApi.DmxFrame = function() {
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
 * @returns {SplayApi.DmxFrame}
 */
SplayApi.DmxFrame.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.DmxFrame=} obj
 * @returns {SplayApi.DmxFrame}
 */
SplayApi.DmxFrame.getRootAsDmxFrame = function(bb, obj) {
  return (obj || new SplayApi.DmxFrame).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.DmxFrame=} obj
 * @returns {SplayApi.DmxFrame}
 */
SplayApi.DmxFrame.getSizePrefixedRootAsDmxFrame = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayApi.DmxFrame).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @returns {number}
 */
SplayApi.DmxFrame.prototype.output = function() {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? this.bb.readUint16(this.bb_pos + offset) : 0;
};

/**
 * @returns {number}
 */
SplayApi.DmxFrame.prototype.time = function() {
  var offset = this.bb.__offset(this.bb_pos, 6);
  return offset ? this.bb.readUint32(this.bb_pos + offset) : 0;
};

/**
 * @param {number} index
 * @returns {number}
 */
SplayApi.DmxFrame.prototype.channels = function(index) {
  var offset = this.bb.__offset(this.bb_pos, 8);
  return offset ? this.bb.readUint8(this.bb.__vector(this.bb_pos + offset) + index) : 0;
};

/**
 * @returns {number}
 */
SplayApi.DmxFrame.prototype.channelsLength = function() {
  var offset = this.bb.__offset(this.bb_pos, 8);
  return offset ? this.bb.__vector_len(this.bb_pos + offset) : 0;
};

/**
 * @returns {Uint8Array}
 */
SplayApi.DmxFrame.prototype.channelsArray = function() {
  var offset = this.bb.__offset(this.bb_pos, 8);
  return offset ? new Uint8Array(this.bb.bytes().buffer, this.bb.bytes().byteOffset + this.bb.__vector(this.bb_pos + offset), this.bb.__vector_len(this.bb_pos + offset)) : null;
};

/**
 * @param {flatbuffers.Builder} builder
 */
SplayApi.DmxFrame.startDmxFrame = function(builder) {
  builder.startObject(3);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} output
 */
SplayApi.DmxFrame.addOutput = function(builder, output) {
  builder.addFieldInt16(0, output, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} time
 */
SplayApi.DmxFrame.addTime = function(builder, time) {
  builder.addFieldInt32(1, time, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} channelsOffset
 */
SplayApi.DmxFrame.addChannels = function(builder, channelsOffset) {
  builder.addFieldOffset(2, channelsOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {Array.<number>} data
 * @returns {flatbuffers.Offset}
 */
SplayApi.DmxFrame.createChannelsVector = function(builder, data) {
  builder.startVector(1, data.length, 1);
  for (var i = data.length - 1; i >= 0; i--) {
    builder.addInt8(data[i]);
  }
  return builder.endVector();
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} numElems
 */
SplayApi.DmxFrame.startChannelsVector = function(builder, numElems) {
  builder.startVector(1, numElems, 1);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
SplayApi.DmxFrame.endDmxFrame = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} output
 * @param {number} time
 * @param {flatbuffers.Offset} channelsOffset
 * @returns {flatbuffers.Offset}
 */
SplayApi.DmxFrame.createDmxFrame = function(builder, output, time, channelsOffset) {
  SplayApi.DmxFrame.startDmxFrame(builder);
  SplayApi.DmxFrame.addOutput(builder, output);
  SplayApi.DmxFrame.addTime(builder, time);
  SplayApi.DmxFrame.addChannels(builder, channelsOffset);
  return SplayApi.DmxFrame.endDmxFrame(builder);
}

/**
 * @constructor
 */
SplayApi.StaticFrameArray = function() {
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
 * @returns {SplayApi.StaticFrameArray}
 */
SplayApi.StaticFrameArray.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.StaticFrameArray=} obj
 * @returns {SplayApi.StaticFrameArray}
 */
SplayApi.StaticFrameArray.getRootAsStaticFrameArray = function(bb, obj) {
  return (obj || new SplayApi.StaticFrameArray).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.StaticFrameArray=} obj
 * @returns {SplayApi.StaticFrameArray}
 */
SplayApi.StaticFrameArray.getSizePrefixedRootAsStaticFrameArray = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayApi.StaticFrameArray).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {number} index
 * @returns {number}
 */
SplayApi.StaticFrameArray.prototype.channels = function(index) {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? this.bb.readUint8(this.bb.__vector(this.bb_pos + offset) + index) : 0;
};

/**
 * @returns {number}
 */
SplayApi.StaticFrameArray.prototype.channelsLength = function() {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? this.bb.__vector_len(this.bb_pos + offset) : 0;
};

/**
 * @returns {Uint8Array}
 */
SplayApi.StaticFrameArray.prototype.channelsArray = function() {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? new Uint8Array(this.bb.bytes().buffer, this.bb.bytes().byteOffset + this.bb.__vector(this.bb_pos + offset), this.bb.__vector_len(this.bb_pos + offset)) : null;
};

/**
 * @param {flatbuffers.Builder} builder
 */
SplayApi.StaticFrameArray.startStaticFrameArray = function(builder) {
  builder.startObject(1);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} channelsOffset
 */
SplayApi.StaticFrameArray.addChannels = function(builder, channelsOffset) {
  builder.addFieldOffset(0, channelsOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {Array.<number>} data
 * @returns {flatbuffers.Offset}
 */
SplayApi.StaticFrameArray.createChannelsVector = function(builder, data) {
  builder.startVector(1, data.length, 1);
  for (var i = data.length - 1; i >= 0; i--) {
    builder.addInt8(data[i]);
  }
  return builder.endVector();
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} numElems
 */
SplayApi.StaticFrameArray.startChannelsVector = function(builder, numElems) {
  builder.startVector(1, numElems, 1);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
SplayApi.StaticFrameArray.endStaticFrameArray = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} channelsOffset
 * @returns {flatbuffers.Offset}
 */
SplayApi.StaticFrameArray.createStaticFrameArray = function(builder, channelsOffset) {
  SplayApi.StaticFrameArray.startStaticFrameArray(builder);
  SplayApi.StaticFrameArray.addChannels(builder, channelsOffset);
  return SplayApi.StaticFrameArray.endStaticFrameArray(builder);
}

/**
 * @constructor
 */
SplayApi.CueTable = function() {
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
 * @returns {SplayApi.CueTable}
 */
SplayApi.CueTable.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.CueTable=} obj
 * @returns {SplayApi.CueTable}
 */
SplayApi.CueTable.getRootAsCueTable = function(bb, obj) {
  return (obj || new SplayApi.CueTable).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.CueTable=} obj
 * @returns {SplayApi.CueTable}
 */
SplayApi.CueTable.getSizePrefixedRootAsCueTable = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayApi.CueTable).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @returns {number}
 */
SplayApi.CueTable.prototype.id = function() {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? this.bb.readUint16(this.bb_pos + offset) : 0;
};

/**
 * @returns {SplayApi.CUE_TYPE}
 */
SplayApi.CueTable.prototype.type = function() {
  var offset = this.bb.__offset(this.bb_pos, 6);
  return offset ? /** @type {SplayApi.CUE_TYPE} */ (this.bb.readUint8(this.bb_pos + offset)) : SplayApi.CUE_TYPE.STATIC;
};

/**
 * @param {flatbuffers.Encoding=} optionalEncoding
 * @returns {string|Uint8Array|null}
 */
SplayApi.CueTable.prototype.name = function(optionalEncoding) {
  var offset = this.bb.__offset(this.bb_pos, 8);
  return offset ? this.bb.__string(this.bb_pos + offset, optionalEncoding) : null;
};

/**
 * @returns {number}
 */
SplayApi.CueTable.prototype.duration = function() {
  var offset = this.bb.__offset(this.bb_pos, 10);
  return offset ? this.bb.readUint32(this.bb_pos + offset) : 0;
};

/**
 * @param {number} index
 * @param {SplayApi.StaticFrameArray=} obj
 * @returns {SplayApi.StaticFrameArray}
 */
SplayApi.CueTable.prototype.frames = function(index, obj) {
  var offset = this.bb.__offset(this.bb_pos, 12);
  return offset ? (obj || new SplayApi.StaticFrameArray).__init(this.bb.__indirect(this.bb.__vector(this.bb_pos + offset) + index * 4), this.bb) : null;
};

/**
 * @returns {number}
 */
SplayApi.CueTable.prototype.framesLength = function() {
  var offset = this.bb.__offset(this.bb_pos, 12);
  return offset ? this.bb.__vector_len(this.bb_pos + offset) : 0;
};

/**
 * @param {SplayApi.CueConfig=} obj
 * @returns {SplayApi.CueConfig|null}
 */
SplayApi.CueTable.prototype.config = function(obj) {
  var offset = this.bb.__offset(this.bb_pos, 14);
  return offset ? (obj || new SplayApi.CueConfig).__init(this.bb.__indirect(this.bb_pos + offset), this.bb) : null;
};

/**
 * @param {flatbuffers.Builder} builder
 */
SplayApi.CueTable.startCueTable = function(builder) {
  builder.startObject(6);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} id
 */
SplayApi.CueTable.addId = function(builder, id) {
  builder.addFieldInt16(0, id, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {SplayApi.CUE_TYPE} type
 */
SplayApi.CueTable.addType = function(builder, type) {
  builder.addFieldInt8(1, type, SplayApi.CUE_TYPE.STATIC);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} nameOffset
 */
SplayApi.CueTable.addName = function(builder, nameOffset) {
  builder.addFieldOffset(2, nameOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} duration
 */
SplayApi.CueTable.addDuration = function(builder, duration) {
  builder.addFieldInt32(3, duration, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} framesOffset
 */
SplayApi.CueTable.addFrames = function(builder, framesOffset) {
  builder.addFieldOffset(4, framesOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {Array.<flatbuffers.Offset>} data
 * @returns {flatbuffers.Offset}
 */
SplayApi.CueTable.createFramesVector = function(builder, data) {
  builder.startVector(4, data.length, 4);
  for (var i = data.length - 1; i >= 0; i--) {
    builder.addOffset(data[i]);
  }
  return builder.endVector();
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} numElems
 */
SplayApi.CueTable.startFramesVector = function(builder, numElems) {
  builder.startVector(4, numElems, 4);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} configOffset
 */
SplayApi.CueTable.addConfig = function(builder, configOffset) {
  builder.addFieldOffset(5, configOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
SplayApi.CueTable.endCueTable = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} id
 * @param {SplayApi.CUE_TYPE} type
 * @param {flatbuffers.Offset} nameOffset
 * @param {number} duration
 * @param {flatbuffers.Offset} framesOffset
 * @param {flatbuffers.Offset} configOffset
 * @returns {flatbuffers.Offset}
 */
SplayApi.CueTable.createCueTable = function(builder, id, type, nameOffset, duration, framesOffset, configOffset) {
  SplayApi.CueTable.startCueTable(builder);
  SplayApi.CueTable.addId(builder, id);
  SplayApi.CueTable.addType(builder, type);
  SplayApi.CueTable.addName(builder, nameOffset);
  SplayApi.CueTable.addDuration(builder, duration);
  SplayApi.CueTable.addFrames(builder, framesOffset);
  SplayApi.CueTable.addConfig(builder, configOffset);
  return SplayApi.CueTable.endCueTable(builder);
}

/**
 * @constructor
 */
SplayApi.GetCueReq = function() {
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
 * @returns {SplayApi.GetCueReq}
 */
SplayApi.GetCueReq.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.GetCueReq=} obj
 * @returns {SplayApi.GetCueReq}
 */
SplayApi.GetCueReq.getRootAsGetCueReq = function(bb, obj) {
  return (obj || new SplayApi.GetCueReq).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.GetCueReq=} obj
 * @returns {SplayApi.GetCueReq}
 */
SplayApi.GetCueReq.getSizePrefixedRootAsGetCueReq = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayApi.GetCueReq).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @returns {SplayApi.COMMAND}
 */
SplayApi.GetCueReq.prototype.command = function() {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? /** @type {SplayApi.COMMAND} */ (this.bb.readUint8(this.bb_pos + offset)) : SplayApi.COMMAND.GET_CUE;
};

/**
 * @returns {number}
 */
SplayApi.GetCueReq.prototype.cueId = function() {
  var offset = this.bb.__offset(this.bb_pos, 6);
  return offset ? this.bb.readInt32(this.bb_pos + offset) : 0;
};

/**
 * @param {flatbuffers.Builder} builder
 */
SplayApi.GetCueReq.startGetCueReq = function(builder) {
  builder.startObject(2);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {SplayApi.COMMAND} command
 */
SplayApi.GetCueReq.addCommand = function(builder, command) {
  builder.addFieldInt8(0, command, SplayApi.COMMAND.GET_CUE);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} cueId
 */
SplayApi.GetCueReq.addCueId = function(builder, cueId) {
  builder.addFieldInt32(1, cueId, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
SplayApi.GetCueReq.endGetCueReq = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {NS14796042768305698587.SplayApi.COMMAND} command
 * @param {number} cueId
 * @returns {flatbuffers.Offset}
 */
SplayApi.GetCueReq.createGetCueReq = function(builder, command, cueId) {
  SplayApi.GetCueReq.startGetCueReq(builder);
  SplayApi.GetCueReq.addCommand(builder, command);
  SplayApi.GetCueReq.addCueId(builder, cueId);
  return SplayApi.GetCueReq.endGetCueReq(builder);
}

/**
 * @constructor
 */
SplayApi.GetCueRes = function() {
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
 * @returns {SplayApi.GetCueRes}
 */
SplayApi.GetCueRes.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.GetCueRes=} obj
 * @returns {SplayApi.GetCueRes}
 */
SplayApi.GetCueRes.getRootAsGetCueRes = function(bb, obj) {
  return (obj || new SplayApi.GetCueRes).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.GetCueRes=} obj
 * @returns {SplayApi.GetCueRes}
 */
SplayApi.GetCueRes.getSizePrefixedRootAsGetCueRes = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayApi.GetCueRes).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {SplayApi.CueTable=} obj
 * @returns {SplayApi.CueTable|null}
 */
SplayApi.GetCueRes.prototype.cue = function(obj) {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? (obj || new SplayApi.CueTable).__init(this.bb.__indirect(this.bb_pos + offset), this.bb) : null;
};

/**
 * @param {flatbuffers.Builder} builder
 */
SplayApi.GetCueRes.startGetCueRes = function(builder) {
  builder.startObject(1);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} cueOffset
 */
SplayApi.GetCueRes.addCue = function(builder, cueOffset) {
  builder.addFieldOffset(0, cueOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
SplayApi.GetCueRes.endGetCueRes = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} cueOffset
 * @returns {flatbuffers.Offset}
 */
SplayApi.GetCueRes.createGetCueRes = function(builder, cueOffset) {
  SplayApi.GetCueRes.startGetCueRes(builder);
  SplayApi.GetCueRes.addCue(builder, cueOffset);
  return SplayApi.GetCueRes.endGetCueRes(builder);
}

/**
 * @constructor
 */
SplayApi.GetAllCuesReq = function() {
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
 * @returns {SplayApi.GetAllCuesReq}
 */
SplayApi.GetAllCuesReq.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.GetAllCuesReq=} obj
 * @returns {SplayApi.GetAllCuesReq}
 */
SplayApi.GetAllCuesReq.getRootAsGetAllCuesReq = function(bb, obj) {
  return (obj || new SplayApi.GetAllCuesReq).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.GetAllCuesReq=} obj
 * @returns {SplayApi.GetAllCuesReq}
 */
SplayApi.GetAllCuesReq.getSizePrefixedRootAsGetAllCuesReq = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayApi.GetAllCuesReq).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @returns {SplayApi.COMMAND}
 */
SplayApi.GetAllCuesReq.prototype.command = function() {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? /** @type {SplayApi.COMMAND} */ (this.bb.readUint8(this.bb_pos + offset)) : SplayApi.COMMAND.GET_ALL_CUES;
};

/**
 * @param {flatbuffers.Builder} builder
 */
SplayApi.GetAllCuesReq.startGetAllCuesReq = function(builder) {
  builder.startObject(1);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {SplayApi.COMMAND} command
 */
SplayApi.GetAllCuesReq.addCommand = function(builder, command) {
  builder.addFieldInt8(0, command, SplayApi.COMMAND.GET_ALL_CUES);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
SplayApi.GetAllCuesReq.endGetAllCuesReq = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {NS14796042768305698587.SplayApi.COMMAND} command
 * @returns {flatbuffers.Offset}
 */
SplayApi.GetAllCuesReq.createGetAllCuesReq = function(builder, command) {
  SplayApi.GetAllCuesReq.startGetAllCuesReq(builder);
  SplayApi.GetAllCuesReq.addCommand(builder, command);
  return SplayApi.GetAllCuesReq.endGetAllCuesReq(builder);
}

/**
 * @constructor
 */
SplayApi.GetAllCuesRes = function() {
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
 * @returns {SplayApi.GetAllCuesRes}
 */
SplayApi.GetAllCuesRes.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.GetAllCuesRes=} obj
 * @returns {SplayApi.GetAllCuesRes}
 */
SplayApi.GetAllCuesRes.getRootAsGetAllCuesRes = function(bb, obj) {
  return (obj || new SplayApi.GetAllCuesRes).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {SplayApi.GetAllCuesRes=} obj
 * @returns {SplayApi.GetAllCuesRes}
 */
SplayApi.GetAllCuesRes.getSizePrefixedRootAsGetAllCuesRes = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayApi.GetAllCuesRes).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {number} index
 * @param {SplayApi.CueTable=} obj
 * @returns {SplayApi.CueTable}
 */
SplayApi.GetAllCuesRes.prototype.cues = function(index, obj) {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? (obj || new SplayApi.CueTable).__init(this.bb.__indirect(this.bb.__vector(this.bb_pos + offset) + index * 4), this.bb) : null;
};

/**
 * @returns {number}
 */
SplayApi.GetAllCuesRes.prototype.cuesLength = function() {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? this.bb.__vector_len(this.bb_pos + offset) : 0;
};

/**
 * @param {flatbuffers.Builder} builder
 */
SplayApi.GetAllCuesRes.startGetAllCuesRes = function(builder) {
  builder.startObject(1);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} cuesOffset
 */
SplayApi.GetAllCuesRes.addCues = function(builder, cuesOffset) {
  builder.addFieldOffset(0, cuesOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {Array.<flatbuffers.Offset>} data
 * @returns {flatbuffers.Offset}
 */
SplayApi.GetAllCuesRes.createCuesVector = function(builder, data) {
  builder.startVector(4, data.length, 4);
  for (var i = data.length - 1; i >= 0; i--) {
    builder.addOffset(data[i]);
  }
  return builder.endVector();
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} numElems
 */
SplayApi.GetAllCuesRes.startCuesVector = function(builder, numElems) {
  builder.startVector(4, numElems, 4);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
SplayApi.GetAllCuesRes.endGetAllCuesRes = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} cuesOffset
 * @returns {flatbuffers.Offset}
 */
SplayApi.GetAllCuesRes.createGetAllCuesRes = function(builder, cuesOffset) {
  SplayApi.GetAllCuesRes.startGetAllCuesRes(builder);
  SplayApi.GetAllCuesRes.addCues(builder, cuesOffset);
  return SplayApi.GetAllCuesRes.endGetAllCuesRes(builder);
}

// Exports for ECMAScript6 Modules
export {SplayApi};
