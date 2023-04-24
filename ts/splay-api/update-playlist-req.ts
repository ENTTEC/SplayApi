// automatically generated by the FlatBuffers compiler, do not modify

import * as flatbuffers from 'flatbuffers';

import { COMMAND } from '../splay-api/command.js';
import { Playlist } from '../splay-api/playlist.js';


export class UpdatePlaylistReq {
  bb: flatbuffers.ByteBuffer|null = null;
  bb_pos = 0;
  __init(i:number, bb:flatbuffers.ByteBuffer):UpdatePlaylistReq {
  this.bb_pos = i;
  this.bb = bb;
  return this;
}

static getRootAsUpdatePlaylistReq(bb:flatbuffers.ByteBuffer, obj?:UpdatePlaylistReq):UpdatePlaylistReq {
  return (obj || new UpdatePlaylistReq()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

static getSizePrefixedRootAsUpdatePlaylistReq(bb:flatbuffers.ByteBuffer, obj?:UpdatePlaylistReq):UpdatePlaylistReq {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new UpdatePlaylistReq()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

command():COMMAND {
  const offset = this.bb!.__offset(this.bb_pos, 4);
  return offset ? this.bb!.readUint8(this.bb_pos + offset) : COMMAND.UPDATE_PLAYLIST;
}

playlist(obj?:Playlist):Playlist|null {
  const offset = this.bb!.__offset(this.bb_pos, 6);
  return offset ? (obj || new Playlist()).__init(this.bb!.__indirect(this.bb_pos + offset), this.bb!) : null;
}

static startUpdatePlaylistReq(builder:flatbuffers.Builder) {
  builder.startObject(2);
}

static addCommand(builder:flatbuffers.Builder, command:COMMAND) {
  builder.addFieldInt8(0, command, COMMAND.UPDATE_PLAYLIST);
}

static addPlaylist(builder:flatbuffers.Builder, playlistOffset:flatbuffers.Offset) {
  builder.addFieldOffset(1, playlistOffset, 0);
}

static endUpdatePlaylistReq(builder:flatbuffers.Builder):flatbuffers.Offset {
  const offset = builder.endObject();
  return offset;
}

}