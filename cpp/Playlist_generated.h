// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_PLAYLIST_SPLAYAPI_H_
#define FLATBUFFERS_GENERATED_PLAYLIST_SPLAYAPI_H_

#include "flatbuffers/flatbuffers.h"

#include "Command_generated.h"
#include "Common_generated.h"
#include "Control_generated.h"
#include "Cue_generated.h"

namespace SplayApi {

struct Playlist;
struct PlaylistBuilder;

struct PlayPlaylistReq;
struct PlayPlaylistReqBuilder;

struct PausePlaylistReq;
struct PausePlaylistReqBuilder;

struct StopPlaylistReq;
struct StopPlaylistReqBuilder;

struct GetPlaylistReq;
struct GetPlaylistReqBuilder;

struct GetPlaylistRes;
struct GetPlaylistResBuilder;

struct UpdatePlaylistReq;
struct UpdatePlaylistReqBuilder;

struct GetAllPlaylistsReq;
struct GetAllPlaylistsReqBuilder;

struct GetAllPlaylistsRes;
struct GetAllPlaylistsResBuilder;

enum PLAYLIST_STATUS_TYPE {
  PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_IDLE = 0,
  PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_PLAYING = 1,
  PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_PAUSED = 2,
  PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_STOPPED = 3,
  PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_RECORD = 4,
  PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_ERROR = 5,
  PLAYLIST_STATUS_TYPE_MIN = PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_IDLE,
  PLAYLIST_STATUS_TYPE_MAX = PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_ERROR
};

inline const PLAYLIST_STATUS_TYPE (&EnumValuesPLAYLIST_STATUS_TYPE())[6] {
  static const PLAYLIST_STATUS_TYPE values[] = {
    PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_IDLE,
    PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_PLAYING,
    PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_PAUSED,
    PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_STOPPED,
    PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_RECORD,
    PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_ERROR
  };
  return values;
}

inline const char * const *EnumNamesPLAYLIST_STATUS_TYPE() {
  static const char * const names[7] = {
    "PLAYLIST_STATUS_IDLE",
    "PLAYLIST_STATUS_PLAYING",
    "PLAYLIST_STATUS_PAUSED",
    "PLAYLIST_STATUS_STOPPED",
    "PLAYLIST_STATUS_RECORD",
    "PLAYLIST_STATUS_ERROR",
    nullptr
  };
  return names;
}

inline const char *EnumNamePLAYLIST_STATUS_TYPE(PLAYLIST_STATUS_TYPE e) {
  if (flatbuffers::IsOutRange(e, PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_IDLE, PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_ERROR)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesPLAYLIST_STATUS_TYPE()[index];
}

struct Playlist FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef PlaylistBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_PLAYLIST_ID = 4,
    VT_STATUS = 6,
    VT_CURRENT_TIME = 8,
    VT_DURATION = 10,
    VT_INTENSITY = 12,
    VT_NAME = 14,
    VT_WAITING_TRIGGERS = 16,
    VT_NOTIFICATION_MESSAGE = 18,
    VT_START_TRIGGER = 20,
    VT_STOP_TRIGGER = 22,
    VT_TRIGGERS = 24,
    VT_EVENTS = 26,
    VT_TRACK1 = 28,
    VT_TRACK2 = 30,
    VT_TRACK3 = 32,
    VT_TRACK4 = 34
  };
  int32_t playlist_id() const {
    return GetField<int32_t>(VT_PLAYLIST_ID, 0);
  }
  SplayApi::PLAYLIST_STATUS_TYPE status() const {
    return static_cast<SplayApi::PLAYLIST_STATUS_TYPE>(GetField<uint8_t>(VT_STATUS, 0));
  }
  uint32_t current_time() const {
    return GetField<uint32_t>(VT_CURRENT_TIME, 0);
  }
  uint32_t duration() const {
    return GetField<uint32_t>(VT_DURATION, 0);
  }
  float intensity() const {
    return GetField<float>(VT_INTENSITY, 0.0f);
  }
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  bool waiting_triggers() const {
    return GetField<uint8_t>(VT_WAITING_TRIGGERS, 0) != 0;
  }
  const flatbuffers::String *notification_message() const {
    return GetPointer<const flatbuffers::String *>(VT_NOTIFICATION_MESSAGE);
  }
  const SplayApi::Trigger *start_trigger() const {
    return GetPointer<const SplayApi::Trigger *>(VT_START_TRIGGER);
  }
  const SplayApi::Trigger *stop_trigger() const {
    return GetPointer<const SplayApi::Trigger *>(VT_STOP_TRIGGER);
  }
  const flatbuffers::Vector<flatbuffers::Offset<SplayApi::Trigger>> *triggers() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<SplayApi::Trigger>> *>(VT_TRIGGERS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<SplayApi::Event>> *events() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<SplayApi::Event>> *>(VT_EVENTS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>> *track1() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>> *>(VT_TRACK1);
  }
  const flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>> *track2() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>> *>(VT_TRACK2);
  }
  const flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>> *track3() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>> *>(VT_TRACK3);
  }
  const flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>> *track4() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>> *>(VT_TRACK4);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_PLAYLIST_ID) &&
           VerifyField<uint8_t>(verifier, VT_STATUS) &&
           VerifyField<uint32_t>(verifier, VT_CURRENT_TIME) &&
           VerifyField<uint32_t>(verifier, VT_DURATION) &&
           VerifyField<float>(verifier, VT_INTENSITY) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<uint8_t>(verifier, VT_WAITING_TRIGGERS) &&
           VerifyOffset(verifier, VT_NOTIFICATION_MESSAGE) &&
           verifier.VerifyString(notification_message()) &&
           VerifyOffset(verifier, VT_START_TRIGGER) &&
           verifier.VerifyTable(start_trigger()) &&
           VerifyOffset(verifier, VT_STOP_TRIGGER) &&
           verifier.VerifyTable(stop_trigger()) &&
           VerifyOffset(verifier, VT_TRIGGERS) &&
           verifier.VerifyVector(triggers()) &&
           verifier.VerifyVectorOfTables(triggers()) &&
           VerifyOffset(verifier, VT_EVENTS) &&
           verifier.VerifyVector(events()) &&
           verifier.VerifyVectorOfTables(events()) &&
           VerifyOffset(verifier, VT_TRACK1) &&
           verifier.VerifyVector(track1()) &&
           verifier.VerifyVectorOfTables(track1()) &&
           VerifyOffset(verifier, VT_TRACK2) &&
           verifier.VerifyVector(track2()) &&
           verifier.VerifyVectorOfTables(track2()) &&
           VerifyOffset(verifier, VT_TRACK3) &&
           verifier.VerifyVector(track3()) &&
           verifier.VerifyVectorOfTables(track3()) &&
           VerifyOffset(verifier, VT_TRACK4) &&
           verifier.VerifyVector(track4()) &&
           verifier.VerifyVectorOfTables(track4()) &&
           verifier.EndTable();
  }
};

struct PlaylistBuilder {
  typedef Playlist Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_playlist_id(int32_t playlist_id) {
    fbb_.AddElement<int32_t>(Playlist::VT_PLAYLIST_ID, playlist_id, 0);
  }
  void add_status(SplayApi::PLAYLIST_STATUS_TYPE status) {
    fbb_.AddElement<uint8_t>(Playlist::VT_STATUS, static_cast<uint8_t>(status), 0);
  }
  void add_current_time(uint32_t current_time) {
    fbb_.AddElement<uint32_t>(Playlist::VT_CURRENT_TIME, current_time, 0);
  }
  void add_duration(uint32_t duration) {
    fbb_.AddElement<uint32_t>(Playlist::VT_DURATION, duration, 0);
  }
  void add_intensity(float intensity) {
    fbb_.AddElement<float>(Playlist::VT_INTENSITY, intensity, 0.0f);
  }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Playlist::VT_NAME, name);
  }
  void add_waiting_triggers(bool waiting_triggers) {
    fbb_.AddElement<uint8_t>(Playlist::VT_WAITING_TRIGGERS, static_cast<uint8_t>(waiting_triggers), 0);
  }
  void add_notification_message(flatbuffers::Offset<flatbuffers::String> notification_message) {
    fbb_.AddOffset(Playlist::VT_NOTIFICATION_MESSAGE, notification_message);
  }
  void add_start_trigger(flatbuffers::Offset<SplayApi::Trigger> start_trigger) {
    fbb_.AddOffset(Playlist::VT_START_TRIGGER, start_trigger);
  }
  void add_stop_trigger(flatbuffers::Offset<SplayApi::Trigger> stop_trigger) {
    fbb_.AddOffset(Playlist::VT_STOP_TRIGGER, stop_trigger);
  }
  void add_triggers(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::Trigger>>> triggers) {
    fbb_.AddOffset(Playlist::VT_TRIGGERS, triggers);
  }
  void add_events(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::Event>>> events) {
    fbb_.AddOffset(Playlist::VT_EVENTS, events);
  }
  void add_track1(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>>> track1) {
    fbb_.AddOffset(Playlist::VT_TRACK1, track1);
  }
  void add_track2(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>>> track2) {
    fbb_.AddOffset(Playlist::VT_TRACK2, track2);
  }
  void add_track3(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>>> track3) {
    fbb_.AddOffset(Playlist::VT_TRACK3, track3);
  }
  void add_track4(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>>> track4) {
    fbb_.AddOffset(Playlist::VT_TRACK4, track4);
  }
  explicit PlaylistBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  PlaylistBuilder &operator=(const PlaylistBuilder &);
  flatbuffers::Offset<Playlist> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Playlist>(end);
    return o;
  }
};

inline flatbuffers::Offset<Playlist> CreatePlaylist(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t playlist_id = 0,
    SplayApi::PLAYLIST_STATUS_TYPE status = SplayApi::PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_IDLE,
    uint32_t current_time = 0,
    uint32_t duration = 0,
    float intensity = 0.0f,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    bool waiting_triggers = false,
    flatbuffers::Offset<flatbuffers::String> notification_message = 0,
    flatbuffers::Offset<SplayApi::Trigger> start_trigger = 0,
    flatbuffers::Offset<SplayApi::Trigger> stop_trigger = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::Trigger>>> triggers = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::Event>>> events = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>>> track1 = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>>> track2 = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>>> track3 = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::Cue>>> track4 = 0) {
  PlaylistBuilder builder_(_fbb);
  builder_.add_track4(track4);
  builder_.add_track3(track3);
  builder_.add_track2(track2);
  builder_.add_track1(track1);
  builder_.add_events(events);
  builder_.add_triggers(triggers);
  builder_.add_stop_trigger(stop_trigger);
  builder_.add_start_trigger(start_trigger);
  builder_.add_notification_message(notification_message);
  builder_.add_name(name);
  builder_.add_intensity(intensity);
  builder_.add_duration(duration);
  builder_.add_current_time(current_time);
  builder_.add_playlist_id(playlist_id);
  builder_.add_waiting_triggers(waiting_triggers);
  builder_.add_status(status);
  return builder_.Finish();
}

inline flatbuffers::Offset<Playlist> CreatePlaylistDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t playlist_id = 0,
    SplayApi::PLAYLIST_STATUS_TYPE status = SplayApi::PLAYLIST_STATUS_TYPE_PLAYLIST_STATUS_IDLE,
    uint32_t current_time = 0,
    uint32_t duration = 0,
    float intensity = 0.0f,
    const char *name = nullptr,
    bool waiting_triggers = false,
    const char *notification_message = nullptr,
    flatbuffers::Offset<SplayApi::Trigger> start_trigger = 0,
    flatbuffers::Offset<SplayApi::Trigger> stop_trigger = 0,
    const std::vector<flatbuffers::Offset<SplayApi::Trigger>> *triggers = nullptr,
    const std::vector<flatbuffers::Offset<SplayApi::Event>> *events = nullptr,
    const std::vector<flatbuffers::Offset<SplayApi::Cue>> *track1 = nullptr,
    const std::vector<flatbuffers::Offset<SplayApi::Cue>> *track2 = nullptr,
    const std::vector<flatbuffers::Offset<SplayApi::Cue>> *track3 = nullptr,
    const std::vector<flatbuffers::Offset<SplayApi::Cue>> *track4 = nullptr) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  auto notification_message__ = notification_message ? _fbb.CreateString(notification_message) : 0;
  auto triggers__ = triggers ? _fbb.CreateVector<flatbuffers::Offset<SplayApi::Trigger>>(*triggers) : 0;
  auto events__ = events ? _fbb.CreateVector<flatbuffers::Offset<SplayApi::Event>>(*events) : 0;
  auto track1__ = track1 ? _fbb.CreateVector<flatbuffers::Offset<SplayApi::Cue>>(*track1) : 0;
  auto track2__ = track2 ? _fbb.CreateVector<flatbuffers::Offset<SplayApi::Cue>>(*track2) : 0;
  auto track3__ = track3 ? _fbb.CreateVector<flatbuffers::Offset<SplayApi::Cue>>(*track3) : 0;
  auto track4__ = track4 ? _fbb.CreateVector<flatbuffers::Offset<SplayApi::Cue>>(*track4) : 0;
  return SplayApi::CreatePlaylist(
      _fbb,
      playlist_id,
      status,
      current_time,
      duration,
      intensity,
      name__,
      waiting_triggers,
      notification_message__,
      start_trigger,
      stop_trigger,
      triggers__,
      events__,
      track1__,
      track2__,
      track3__,
      track4__);
}

struct PlayPlaylistReq FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef PlayPlaylistReqBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_COMMAND = 4,
    VT_PLAYLIST_ID = 6
  };
  SplayApi::COMMAND command() const {
    return static_cast<SplayApi::COMMAND>(GetField<uint8_t>(VT_COMMAND, 0));
  }
  int32_t playlist_id() const {
    return GetField<int32_t>(VT_PLAYLIST_ID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_COMMAND) &&
           VerifyField<int32_t>(verifier, VT_PLAYLIST_ID) &&
           verifier.EndTable();
  }
};

struct PlayPlaylistReqBuilder {
  typedef PlayPlaylistReq Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_command(SplayApi::COMMAND command) {
    fbb_.AddElement<uint8_t>(PlayPlaylistReq::VT_COMMAND, static_cast<uint8_t>(command), 0);
  }
  void add_playlist_id(int32_t playlist_id) {
    fbb_.AddElement<int32_t>(PlayPlaylistReq::VT_PLAYLIST_ID, playlist_id, 0);
  }
  explicit PlayPlaylistReqBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  PlayPlaylistReqBuilder &operator=(const PlayPlaylistReqBuilder &);
  flatbuffers::Offset<PlayPlaylistReq> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<PlayPlaylistReq>(end);
    return o;
  }
};

inline flatbuffers::Offset<PlayPlaylistReq> CreatePlayPlaylistReq(
    flatbuffers::FlatBufferBuilder &_fbb,
    SplayApi::COMMAND command = SplayApi::COMMAND_PLAY_PLAYLIST_COMMAND,
    int32_t playlist_id = 0) {
  PlayPlaylistReqBuilder builder_(_fbb);
  builder_.add_playlist_id(playlist_id);
  builder_.add_command(command);
  return builder_.Finish();
}

struct PausePlaylistReq FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef PausePlaylistReqBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_COMMAND = 4,
    VT_PLAYLIST_ID = 6
  };
  SplayApi::COMMAND command() const {
    return static_cast<SplayApi::COMMAND>(GetField<uint8_t>(VT_COMMAND, 1));
  }
  int32_t playlist_id() const {
    return GetField<int32_t>(VT_PLAYLIST_ID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_COMMAND) &&
           VerifyField<int32_t>(verifier, VT_PLAYLIST_ID) &&
           verifier.EndTable();
  }
};

struct PausePlaylistReqBuilder {
  typedef PausePlaylistReq Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_command(SplayApi::COMMAND command) {
    fbb_.AddElement<uint8_t>(PausePlaylistReq::VT_COMMAND, static_cast<uint8_t>(command), 1);
  }
  void add_playlist_id(int32_t playlist_id) {
    fbb_.AddElement<int32_t>(PausePlaylistReq::VT_PLAYLIST_ID, playlist_id, 0);
  }
  explicit PausePlaylistReqBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  PausePlaylistReqBuilder &operator=(const PausePlaylistReqBuilder &);
  flatbuffers::Offset<PausePlaylistReq> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<PausePlaylistReq>(end);
    return o;
  }
};

inline flatbuffers::Offset<PausePlaylistReq> CreatePausePlaylistReq(
    flatbuffers::FlatBufferBuilder &_fbb,
    SplayApi::COMMAND command = SplayApi::COMMAND_PAUSE_PLAYLIST_COMMAND,
    int32_t playlist_id = 0) {
  PausePlaylistReqBuilder builder_(_fbb);
  builder_.add_playlist_id(playlist_id);
  builder_.add_command(command);
  return builder_.Finish();
}

struct StopPlaylistReq FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef StopPlaylistReqBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_COMMAND = 4,
    VT_PLAYLIST_ID = 6
  };
  SplayApi::COMMAND command() const {
    return static_cast<SplayApi::COMMAND>(GetField<uint8_t>(VT_COMMAND, 2));
  }
  int32_t playlist_id() const {
    return GetField<int32_t>(VT_PLAYLIST_ID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_COMMAND) &&
           VerifyField<int32_t>(verifier, VT_PLAYLIST_ID) &&
           verifier.EndTable();
  }
};

struct StopPlaylistReqBuilder {
  typedef StopPlaylistReq Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_command(SplayApi::COMMAND command) {
    fbb_.AddElement<uint8_t>(StopPlaylistReq::VT_COMMAND, static_cast<uint8_t>(command), 2);
  }
  void add_playlist_id(int32_t playlist_id) {
    fbb_.AddElement<int32_t>(StopPlaylistReq::VT_PLAYLIST_ID, playlist_id, 0);
  }
  explicit StopPlaylistReqBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  StopPlaylistReqBuilder &operator=(const StopPlaylistReqBuilder &);
  flatbuffers::Offset<StopPlaylistReq> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<StopPlaylistReq>(end);
    return o;
  }
};

inline flatbuffers::Offset<StopPlaylistReq> CreateStopPlaylistReq(
    flatbuffers::FlatBufferBuilder &_fbb,
    SplayApi::COMMAND command = SplayApi::COMMAND_STOP_PLAYLIST_COMMAND,
    int32_t playlist_id = 0) {
  StopPlaylistReqBuilder builder_(_fbb);
  builder_.add_playlist_id(playlist_id);
  builder_.add_command(command);
  return builder_.Finish();
}

struct GetPlaylistReq FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GetPlaylistReqBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_COMMAND = 4,
    VT_PLAYLIST_ID = 6
  };
  SplayApi::COMMAND command() const {
    return static_cast<SplayApi::COMMAND>(GetField<uint8_t>(VT_COMMAND, 3));
  }
  int32_t playlist_id() const {
    return GetField<int32_t>(VT_PLAYLIST_ID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_COMMAND) &&
           VerifyField<int32_t>(verifier, VT_PLAYLIST_ID) &&
           verifier.EndTable();
  }
};

struct GetPlaylistReqBuilder {
  typedef GetPlaylistReq Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_command(SplayApi::COMMAND command) {
    fbb_.AddElement<uint8_t>(GetPlaylistReq::VT_COMMAND, static_cast<uint8_t>(command), 3);
  }
  void add_playlist_id(int32_t playlist_id) {
    fbb_.AddElement<int32_t>(GetPlaylistReq::VT_PLAYLIST_ID, playlist_id, 0);
  }
  explicit GetPlaylistReqBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  GetPlaylistReqBuilder &operator=(const GetPlaylistReqBuilder &);
  flatbuffers::Offset<GetPlaylistReq> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GetPlaylistReq>(end);
    return o;
  }
};

inline flatbuffers::Offset<GetPlaylistReq> CreateGetPlaylistReq(
    flatbuffers::FlatBufferBuilder &_fbb,
    SplayApi::COMMAND command = SplayApi::COMMAND_GET_PLAYLIST_COMMAND,
    int32_t playlist_id = 0) {
  GetPlaylistReqBuilder builder_(_fbb);
  builder_.add_playlist_id(playlist_id);
  builder_.add_command(command);
  return builder_.Finish();
}

struct GetPlaylistRes FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GetPlaylistResBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_PLAYLIST = 4
  };
  const SplayApi::Playlist *playlist() const {
    return GetPointer<const SplayApi::Playlist *>(VT_PLAYLIST);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_PLAYLIST) &&
           verifier.VerifyTable(playlist()) &&
           verifier.EndTable();
  }
};

struct GetPlaylistResBuilder {
  typedef GetPlaylistRes Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_playlist(flatbuffers::Offset<SplayApi::Playlist> playlist) {
    fbb_.AddOffset(GetPlaylistRes::VT_PLAYLIST, playlist);
  }
  explicit GetPlaylistResBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  GetPlaylistResBuilder &operator=(const GetPlaylistResBuilder &);
  flatbuffers::Offset<GetPlaylistRes> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GetPlaylistRes>(end);
    return o;
  }
};

inline flatbuffers::Offset<GetPlaylistRes> CreateGetPlaylistRes(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<SplayApi::Playlist> playlist = 0) {
  GetPlaylistResBuilder builder_(_fbb);
  builder_.add_playlist(playlist);
  return builder_.Finish();
}

struct UpdatePlaylistReq FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef UpdatePlaylistReqBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_COMMAND = 4,
    VT_PLAYLIST = 6
  };
  SplayApi::COMMAND command() const {
    return static_cast<SplayApi::COMMAND>(GetField<uint8_t>(VT_COMMAND, 18));
  }
  const SplayApi::Playlist *playlist() const {
    return GetPointer<const SplayApi::Playlist *>(VT_PLAYLIST);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_COMMAND) &&
           VerifyOffset(verifier, VT_PLAYLIST) &&
           verifier.VerifyTable(playlist()) &&
           verifier.EndTable();
  }
};

struct UpdatePlaylistReqBuilder {
  typedef UpdatePlaylistReq Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_command(SplayApi::COMMAND command) {
    fbb_.AddElement<uint8_t>(UpdatePlaylistReq::VT_COMMAND, static_cast<uint8_t>(command), 18);
  }
  void add_playlist(flatbuffers::Offset<SplayApi::Playlist> playlist) {
    fbb_.AddOffset(UpdatePlaylistReq::VT_PLAYLIST, playlist);
  }
  explicit UpdatePlaylistReqBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  UpdatePlaylistReqBuilder &operator=(const UpdatePlaylistReqBuilder &);
  flatbuffers::Offset<UpdatePlaylistReq> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<UpdatePlaylistReq>(end);
    return o;
  }
};

inline flatbuffers::Offset<UpdatePlaylistReq> CreateUpdatePlaylistReq(
    flatbuffers::FlatBufferBuilder &_fbb,
    SplayApi::COMMAND command = SplayApi::COMMAND_UPDATE_PLAYLIST_COMMAND,
    flatbuffers::Offset<SplayApi::Playlist> playlist = 0) {
  UpdatePlaylistReqBuilder builder_(_fbb);
  builder_.add_playlist(playlist);
  builder_.add_command(command);
  return builder_.Finish();
}

struct GetAllPlaylistsReq FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GetAllPlaylistsReqBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_COMMAND = 4
  };
  SplayApi::COMMAND command() const {
    return static_cast<SplayApi::COMMAND>(GetField<uint8_t>(VT_COMMAND, 8));
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_COMMAND) &&
           verifier.EndTable();
  }
};

struct GetAllPlaylistsReqBuilder {
  typedef GetAllPlaylistsReq Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_command(SplayApi::COMMAND command) {
    fbb_.AddElement<uint8_t>(GetAllPlaylistsReq::VT_COMMAND, static_cast<uint8_t>(command), 8);
  }
  explicit GetAllPlaylistsReqBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  GetAllPlaylistsReqBuilder &operator=(const GetAllPlaylistsReqBuilder &);
  flatbuffers::Offset<GetAllPlaylistsReq> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GetAllPlaylistsReq>(end);
    return o;
  }
};

inline flatbuffers::Offset<GetAllPlaylistsReq> CreateGetAllPlaylistsReq(
    flatbuffers::FlatBufferBuilder &_fbb,
    SplayApi::COMMAND command = SplayApi::COMMAND_GET_ALL_PLAYLISTS_COMMAND) {
  GetAllPlaylistsReqBuilder builder_(_fbb);
  builder_.add_command(command);
  return builder_.Finish();
}

struct GetAllPlaylistsRes FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GetAllPlaylistsResBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_PLAYLISTS = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<SplayApi::Playlist>> *playlists() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<SplayApi::Playlist>> *>(VT_PLAYLISTS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_PLAYLISTS) &&
           verifier.VerifyVector(playlists()) &&
           verifier.VerifyVectorOfTables(playlists()) &&
           verifier.EndTable();
  }
};

struct GetAllPlaylistsResBuilder {
  typedef GetAllPlaylistsRes Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_playlists(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::Playlist>>> playlists) {
    fbb_.AddOffset(GetAllPlaylistsRes::VT_PLAYLISTS, playlists);
  }
  explicit GetAllPlaylistsResBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  GetAllPlaylistsResBuilder &operator=(const GetAllPlaylistsResBuilder &);
  flatbuffers::Offset<GetAllPlaylistsRes> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GetAllPlaylistsRes>(end);
    return o;
  }
};

inline flatbuffers::Offset<GetAllPlaylistsRes> CreateGetAllPlaylistsRes(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::Playlist>>> playlists = 0) {
  GetAllPlaylistsResBuilder builder_(_fbb);
  builder_.add_playlists(playlists);
  return builder_.Finish();
}

inline flatbuffers::Offset<GetAllPlaylistsRes> CreateGetAllPlaylistsResDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<SplayApi::Playlist>> *playlists = nullptr) {
  auto playlists__ = playlists ? _fbb.CreateVector<flatbuffers::Offset<SplayApi::Playlist>>(*playlists) : 0;
  return SplayApi::CreateGetAllPlaylistsRes(
      _fbb,
      playlists__);
}

}  // namespace SplayApi

#endif  // FLATBUFFERS_GENERATED_PLAYLIST_SPLAYAPI_H_
