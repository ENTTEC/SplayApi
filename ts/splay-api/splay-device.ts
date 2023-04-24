// automatically generated by the FlatBuffers compiler, do not modify

import * as flatbuffers from 'flatbuffers';

export class SplayDevice {
  bb: flatbuffers.ByteBuffer|null = null;
  bb_pos = 0;
  __init(i:number, bb:flatbuffers.ByteBuffer):SplayDevice {
  this.bb_pos = i;
  this.bb = bb;
  return this;
}

static getRootAsSplayDevice(bb:flatbuffers.ByteBuffer, obj?:SplayDevice):SplayDevice {
  return (obj || new SplayDevice()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

static getSizePrefixedRootAsSplayDevice(bb:flatbuffers.ByteBuffer, obj?:SplayDevice):SplayDevice {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new SplayDevice()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

ip():string|null
ip(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
ip(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 4);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

mac():string|null
mac(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
mac(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 6);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

hostname():string|null
hostname(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
hostname(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 8);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

serviceName():string|null
serviceName(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
serviceName(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 10);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

static startSplayDevice(builder:flatbuffers.Builder) {
  builder.startObject(4);
}

static addIp(builder:flatbuffers.Builder, ipOffset:flatbuffers.Offset) {
  builder.addFieldOffset(0, ipOffset, 0);
}

static addMac(builder:flatbuffers.Builder, macOffset:flatbuffers.Offset) {
  builder.addFieldOffset(1, macOffset, 0);
}

static addHostname(builder:flatbuffers.Builder, hostnameOffset:flatbuffers.Offset) {
  builder.addFieldOffset(2, hostnameOffset, 0);
}

static addServiceName(builder:flatbuffers.Builder, serviceNameOffset:flatbuffers.Offset) {
  builder.addFieldOffset(3, serviceNameOffset, 0);
}

static endSplayDevice(builder:flatbuffers.Builder):flatbuffers.Offset {
  const offset = builder.endObject();
  return offset;
}

static createSplayDevice(builder:flatbuffers.Builder, ipOffset:flatbuffers.Offset, macOffset:flatbuffers.Offset, hostnameOffset:flatbuffers.Offset, serviceNameOffset:flatbuffers.Offset):flatbuffers.Offset {
  SplayDevice.startSplayDevice(builder);
  SplayDevice.addIp(builder, ipOffset);
  SplayDevice.addMac(builder, macOffset);
  SplayDevice.addHostname(builder, hostnameOffset);
  SplayDevice.addServiceName(builder, serviceNameOffset);
  return SplayDevice.endSplayDevice(builder);
}
}
