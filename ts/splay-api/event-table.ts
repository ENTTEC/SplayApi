// automatically generated by the FlatBuffers compiler, do not modify

import * as flatbuffers from 'flatbuffers';

import { EVENT_TYPE } from '../splay-api/event-type.js';


export class EventTable {
  bb: flatbuffers.ByteBuffer|null = null;
  bb_pos = 0;
  __init(i:number, bb:flatbuffers.ByteBuffer):EventTable {
  this.bb_pos = i;
  this.bb = bb;
  return this;
}

static getRootAsEventTable(bb:flatbuffers.ByteBuffer, obj?:EventTable):EventTable {
  return (obj || new EventTable()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

static getSizePrefixedRootAsEventTable(bb:flatbuffers.ByteBuffer, obj?:EventTable):EventTable {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new EventTable()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

id():number {
  const offset = this.bb!.__offset(this.bb_pos, 4);
  return offset ? this.bb!.readInt32(this.bb_pos + offset) : 0;
}

name():string|null
name(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
name(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 6);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

type():EVENT_TYPE {
  const offset = this.bb!.__offset(this.bb_pos, 8);
  return offset ? this.bb!.readUint8(this.bb_pos + offset) : EVENT_TYPE.NONE;
}

active():boolean {
  const offset = this.bb!.__offset(this.bb_pos, 10);
  return offset ? !!this.bb!.readInt8(this.bb_pos + offset) : false;
}

value():string|null
value(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
value(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 12);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

start():number {
  const offset = this.bb!.__offset(this.bb_pos, 14);
  return offset ? this.bb!.readUint32(this.bb_pos + offset) : 0;
}

static startEventTable(builder:flatbuffers.Builder) {
  builder.startObject(6);
}

static addId(builder:flatbuffers.Builder, id:number) {
  builder.addFieldInt32(0, id, 0);
}

static addName(builder:flatbuffers.Builder, nameOffset:flatbuffers.Offset) {
  builder.addFieldOffset(1, nameOffset, 0);
}

static addType(builder:flatbuffers.Builder, type:EVENT_TYPE) {
  builder.addFieldInt8(2, type, EVENT_TYPE.NONE);
}

static addActive(builder:flatbuffers.Builder, active:boolean) {
  builder.addFieldInt8(3, +active, +false);
}

static addValue(builder:flatbuffers.Builder, valueOffset:flatbuffers.Offset) {
  builder.addFieldOffset(4, valueOffset, 0);
}

static addStart(builder:flatbuffers.Builder, start:number) {
  builder.addFieldInt32(5, start, 0);
}

static endEventTable(builder:flatbuffers.Builder):flatbuffers.Offset {
  const offset = builder.endObject();
  return offset;
}

static createEventTable(builder:flatbuffers.Builder, id:number, nameOffset:flatbuffers.Offset, type:EVENT_TYPE, active:boolean, valueOffset:flatbuffers.Offset, start:number):flatbuffers.Offset {
  EventTable.startEventTable(builder);
  EventTable.addId(builder, id);
  EventTable.addName(builder, nameOffset);
  EventTable.addType(builder, type);
  EventTable.addActive(builder, active);
  EventTable.addValue(builder, valueOffset);
  EventTable.addStart(builder, start);
  return EventTable.endEventTable(builder);
}
}