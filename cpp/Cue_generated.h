// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CUE_SPLAYAPI_H_
#define FLATBUFFERS_GENERATED_CUE_SPLAYAPI_H_

#include "flatbuffers/flatbuffers.h"

#include "Command_generated.h"
#include "Common_generated.h"
#include "Control_generated.h"

namespace SplayApi {

struct RecordStop;
struct RecordStopBuilder;

struct CueConfig;
struct CueConfigBuilder;

struct DmxFrame;
struct DmxFrameBuilder;

struct StaticFrameArray;
struct StaticFrameArrayBuilder;

struct CueTable;
struct CueTableBuilder;

struct GetCueReq;
struct GetCueReqBuilder;

struct GetCueRes;
struct GetCueResBuilder;

struct GetAllCuesReq;
struct GetAllCuesReqBuilder;

struct GetAllCuesRes;
struct GetAllCuesResBuilder;

enum CUE_TYPE {
  CUE_TYPE_STATIC = 0,
  CUE_TYPE_DYNAMIC = 1,
  CUE_TYPE_EFFECT = 2,
  CUE_TYPE_MIN = CUE_TYPE_STATIC,
  CUE_TYPE_MAX = CUE_TYPE_EFFECT
};

inline const CUE_TYPE (&EnumValuesCUE_TYPE())[3] {
  static const CUE_TYPE values[] = {
    CUE_TYPE_STATIC,
    CUE_TYPE_DYNAMIC,
    CUE_TYPE_EFFECT
  };
  return values;
}

inline const char * const *EnumNamesCUE_TYPE() {
  static const char * const names[4] = {
    "STATIC",
    "DYNAMIC",
    "EFFECT",
    nullptr
  };
  return names;
}

inline const char *EnumNameCUE_TYPE(CUE_TYPE e) {
  if (flatbuffers::IsOutRange(e, CUE_TYPE_STATIC, CUE_TYPE_EFFECT)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesCUE_TYPE()[index];
}

struct RecordStop FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef RecordStopBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TIME = 4
  };
  uint32_t time() const {
    return GetField<uint32_t>(VT_TIME, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_TIME) &&
           verifier.EndTable();
  }
};

struct RecordStopBuilder {
  typedef RecordStop Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_time(uint32_t time) {
    fbb_.AddElement<uint32_t>(RecordStop::VT_TIME, time, 0);
  }
  explicit RecordStopBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  RecordStopBuilder &operator=(const RecordStopBuilder &);
  flatbuffers::Offset<RecordStop> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<RecordStop>(end);
    return o;
  }
};

inline flatbuffers::Offset<RecordStop> CreateRecordStop(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t time = 0) {
  RecordStopBuilder builder_(_fbb);
  builder_.add_time(time);
  return builder_.Finish();
}

struct CueConfig FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef CueConfigBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CH_START = 4,
    VT_CH_STOP = 6,
    VT_SOURCE = 8,
    VT_REC_CONTROL = 10,
    VT_TRIGGER = 12
  };
  uint16_t ch_start() const {
    return GetField<uint16_t>(VT_CH_START, 0);
  }
  uint16_t ch_stop() const {
    return GetField<uint16_t>(VT_CH_STOP, 511);
  }
  SplayApi::UNIVERSE_TYPE source() const {
    return static_cast<SplayApi::UNIVERSE_TYPE>(GetField<uint8_t>(VT_SOURCE, 0));
  }
  bool rec_control() const {
    return GetField<uint8_t>(VT_REC_CONTROL, 0) != 0;
  }
  const SplayApi::TriggerTable *trigger() const {
    return GetPointer<const SplayApi::TriggerTable *>(VT_TRIGGER);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint16_t>(verifier, VT_CH_START) &&
           VerifyField<uint16_t>(verifier, VT_CH_STOP) &&
           VerifyField<uint8_t>(verifier, VT_SOURCE) &&
           VerifyField<uint8_t>(verifier, VT_REC_CONTROL) &&
           VerifyOffset(verifier, VT_TRIGGER) &&
           verifier.VerifyTable(trigger()) &&
           verifier.EndTable();
  }
};

struct CueConfigBuilder {
  typedef CueConfig Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_ch_start(uint16_t ch_start) {
    fbb_.AddElement<uint16_t>(CueConfig::VT_CH_START, ch_start, 0);
  }
  void add_ch_stop(uint16_t ch_stop) {
    fbb_.AddElement<uint16_t>(CueConfig::VT_CH_STOP, ch_stop, 511);
  }
  void add_source(SplayApi::UNIVERSE_TYPE source) {
    fbb_.AddElement<uint8_t>(CueConfig::VT_SOURCE, static_cast<uint8_t>(source), 0);
  }
  void add_rec_control(bool rec_control) {
    fbb_.AddElement<uint8_t>(CueConfig::VT_REC_CONTROL, static_cast<uint8_t>(rec_control), 0);
  }
  void add_trigger(flatbuffers::Offset<SplayApi::TriggerTable> trigger) {
    fbb_.AddOffset(CueConfig::VT_TRIGGER, trigger);
  }
  explicit CueConfigBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CueConfigBuilder &operator=(const CueConfigBuilder &);
  flatbuffers::Offset<CueConfig> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CueConfig>(end);
    return o;
  }
};

inline flatbuffers::Offset<CueConfig> CreateCueConfig(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint16_t ch_start = 0,
    uint16_t ch_stop = 511,
    SplayApi::UNIVERSE_TYPE source = SplayApi::UNIVERSE_TYPE_DMX,
    bool rec_control = false,
    flatbuffers::Offset<SplayApi::TriggerTable> trigger = 0) {
  CueConfigBuilder builder_(_fbb);
  builder_.add_trigger(trigger);
  builder_.add_ch_stop(ch_stop);
  builder_.add_ch_start(ch_start);
  builder_.add_rec_control(rec_control);
  builder_.add_source(source);
  return builder_.Finish();
}

struct DmxFrame FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef DmxFrameBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_OUTPUT = 4,
    VT_TIME = 6,
    VT_CHANNELS = 8
  };
  uint16_t output() const {
    return GetField<uint16_t>(VT_OUTPUT, 0);
  }
  uint32_t time() const {
    return GetField<uint32_t>(VT_TIME, 0);
  }
  const flatbuffers::Vector<uint8_t> *channels() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_CHANNELS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint16_t>(verifier, VT_OUTPUT) &&
           VerifyField<uint32_t>(verifier, VT_TIME) &&
           VerifyOffset(verifier, VT_CHANNELS) &&
           verifier.VerifyVector(channels()) &&
           verifier.EndTable();
  }
};

struct DmxFrameBuilder {
  typedef DmxFrame Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_output(uint16_t output) {
    fbb_.AddElement<uint16_t>(DmxFrame::VT_OUTPUT, output, 0);
  }
  void add_time(uint32_t time) {
    fbb_.AddElement<uint32_t>(DmxFrame::VT_TIME, time, 0);
  }
  void add_channels(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> channels) {
    fbb_.AddOffset(DmxFrame::VT_CHANNELS, channels);
  }
  explicit DmxFrameBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DmxFrameBuilder &operator=(const DmxFrameBuilder &);
  flatbuffers::Offset<DmxFrame> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DmxFrame>(end);
    return o;
  }
};

inline flatbuffers::Offset<DmxFrame> CreateDmxFrame(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint16_t output = 0,
    uint32_t time = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> channels = 0) {
  DmxFrameBuilder builder_(_fbb);
  builder_.add_channels(channels);
  builder_.add_time(time);
  builder_.add_output(output);
  return builder_.Finish();
}

inline flatbuffers::Offset<DmxFrame> CreateDmxFrameDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint16_t output = 0,
    uint32_t time = 0,
    const std::vector<uint8_t> *channels = nullptr) {
  auto channels__ = channels ? _fbb.CreateVector<uint8_t>(*channels) : 0;
  return SplayApi::CreateDmxFrame(
      _fbb,
      output,
      time,
      channels__);
}

struct StaticFrameArray FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef StaticFrameArrayBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CHANNELS = 4
  };
  const flatbuffers::Vector<uint8_t> *channels() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_CHANNELS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_CHANNELS) &&
           verifier.VerifyVector(channels()) &&
           verifier.EndTable();
  }
};

struct StaticFrameArrayBuilder {
  typedef StaticFrameArray Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_channels(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> channels) {
    fbb_.AddOffset(StaticFrameArray::VT_CHANNELS, channels);
  }
  explicit StaticFrameArrayBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  StaticFrameArrayBuilder &operator=(const StaticFrameArrayBuilder &);
  flatbuffers::Offset<StaticFrameArray> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<StaticFrameArray>(end);
    return o;
  }
};

inline flatbuffers::Offset<StaticFrameArray> CreateStaticFrameArray(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> channels = 0) {
  StaticFrameArrayBuilder builder_(_fbb);
  builder_.add_channels(channels);
  return builder_.Finish();
}

inline flatbuffers::Offset<StaticFrameArray> CreateStaticFrameArrayDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<uint8_t> *channels = nullptr) {
  auto channels__ = channels ? _fbb.CreateVector<uint8_t>(*channels) : 0;
  return SplayApi::CreateStaticFrameArray(
      _fbb,
      channels__);
}

struct CueTable FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef CueTableBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4,
    VT_TYPE = 6,
    VT_NAME = 8,
    VT_DURATION = 10,
    VT_FRAMES = 12,
    VT_CONFIG = 14
  };
  uint16_t id() const {
    return GetField<uint16_t>(VT_ID, 0);
  }
  SplayApi::CUE_TYPE type() const {
    return static_cast<SplayApi::CUE_TYPE>(GetField<uint8_t>(VT_TYPE, 0));
  }
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  uint32_t duration() const {
    return GetField<uint32_t>(VT_DURATION, 0);
  }
  const flatbuffers::Vector<flatbuffers::Offset<SplayApi::StaticFrameArray>> *frames() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<SplayApi::StaticFrameArray>> *>(VT_FRAMES);
  }
  const SplayApi::CueConfig *config() const {
    return GetPointer<const SplayApi::CueConfig *>(VT_CONFIG);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint16_t>(verifier, VT_ID) &&
           VerifyField<uint8_t>(verifier, VT_TYPE) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<uint32_t>(verifier, VT_DURATION) &&
           VerifyOffset(verifier, VT_FRAMES) &&
           verifier.VerifyVector(frames()) &&
           verifier.VerifyVectorOfTables(frames()) &&
           VerifyOffset(verifier, VT_CONFIG) &&
           verifier.VerifyTable(config()) &&
           verifier.EndTable();
  }
};

struct CueTableBuilder {
  typedef CueTable Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(uint16_t id) {
    fbb_.AddElement<uint16_t>(CueTable::VT_ID, id, 0);
  }
  void add_type(SplayApi::CUE_TYPE type) {
    fbb_.AddElement<uint8_t>(CueTable::VT_TYPE, static_cast<uint8_t>(type), 0);
  }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(CueTable::VT_NAME, name);
  }
  void add_duration(uint32_t duration) {
    fbb_.AddElement<uint32_t>(CueTable::VT_DURATION, duration, 0);
  }
  void add_frames(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::StaticFrameArray>>> frames) {
    fbb_.AddOffset(CueTable::VT_FRAMES, frames);
  }
  void add_config(flatbuffers::Offset<SplayApi::CueConfig> config) {
    fbb_.AddOffset(CueTable::VT_CONFIG, config);
  }
  explicit CueTableBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CueTableBuilder &operator=(const CueTableBuilder &);
  flatbuffers::Offset<CueTable> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CueTable>(end);
    return o;
  }
};

inline flatbuffers::Offset<CueTable> CreateCueTable(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint16_t id = 0,
    SplayApi::CUE_TYPE type = SplayApi::CUE_TYPE_STATIC,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    uint32_t duration = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::StaticFrameArray>>> frames = 0,
    flatbuffers::Offset<SplayApi::CueConfig> config = 0) {
  CueTableBuilder builder_(_fbb);
  builder_.add_config(config);
  builder_.add_frames(frames);
  builder_.add_duration(duration);
  builder_.add_name(name);
  builder_.add_id(id);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<CueTable> CreateCueTableDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint16_t id = 0,
    SplayApi::CUE_TYPE type = SplayApi::CUE_TYPE_STATIC,
    const char *name = nullptr,
    uint32_t duration = 0,
    const std::vector<flatbuffers::Offset<SplayApi::StaticFrameArray>> *frames = nullptr,
    flatbuffers::Offset<SplayApi::CueConfig> config = 0) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  auto frames__ = frames ? _fbb.CreateVector<flatbuffers::Offset<SplayApi::StaticFrameArray>>(*frames) : 0;
  return SplayApi::CreateCueTable(
      _fbb,
      id,
      type,
      name__,
      duration,
      frames__,
      config);
}

struct GetCueReq FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GetCueReqBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_COMMAND = 4,
    VT_CUE_ID = 6
  };
  SplayApi::COMMAND command() const {
    return static_cast<SplayApi::COMMAND>(GetField<uint8_t>(VT_COMMAND, 28));
  }
  int32_t cue_id() const {
    return GetField<int32_t>(VT_CUE_ID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_COMMAND) &&
           VerifyField<int32_t>(verifier, VT_CUE_ID) &&
           verifier.EndTable();
  }
};

struct GetCueReqBuilder {
  typedef GetCueReq Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_command(SplayApi::COMMAND command) {
    fbb_.AddElement<uint8_t>(GetCueReq::VT_COMMAND, static_cast<uint8_t>(command), 28);
  }
  void add_cue_id(int32_t cue_id) {
    fbb_.AddElement<int32_t>(GetCueReq::VT_CUE_ID, cue_id, 0);
  }
  explicit GetCueReqBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  GetCueReqBuilder &operator=(const GetCueReqBuilder &);
  flatbuffers::Offset<GetCueReq> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GetCueReq>(end);
    return o;
  }
};

inline flatbuffers::Offset<GetCueReq> CreateGetCueReq(
    flatbuffers::FlatBufferBuilder &_fbb,
    SplayApi::COMMAND command = SplayApi::COMMAND_GET_CUE,
    int32_t cue_id = 0) {
  GetCueReqBuilder builder_(_fbb);
  builder_.add_cue_id(cue_id);
  builder_.add_command(command);
  return builder_.Finish();
}

struct GetCueRes FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GetCueResBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CUE = 4
  };
  const SplayApi::CueTable *cue() const {
    return GetPointer<const SplayApi::CueTable *>(VT_CUE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_CUE) &&
           verifier.VerifyTable(cue()) &&
           verifier.EndTable();
  }
};

struct GetCueResBuilder {
  typedef GetCueRes Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_cue(flatbuffers::Offset<SplayApi::CueTable> cue) {
    fbb_.AddOffset(GetCueRes::VT_CUE, cue);
  }
  explicit GetCueResBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  GetCueResBuilder &operator=(const GetCueResBuilder &);
  flatbuffers::Offset<GetCueRes> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GetCueRes>(end);
    return o;
  }
};

inline flatbuffers::Offset<GetCueRes> CreateGetCueRes(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<SplayApi::CueTable> cue = 0) {
  GetCueResBuilder builder_(_fbb);
  builder_.add_cue(cue);
  return builder_.Finish();
}

struct GetAllCuesReq FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GetAllCuesReqBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_COMMAND = 4
  };
  SplayApi::COMMAND command() const {
    return static_cast<SplayApi::COMMAND>(GetField<uint8_t>(VT_COMMAND, 29));
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_COMMAND) &&
           verifier.EndTable();
  }
};

struct GetAllCuesReqBuilder {
  typedef GetAllCuesReq Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_command(SplayApi::COMMAND command) {
    fbb_.AddElement<uint8_t>(GetAllCuesReq::VT_COMMAND, static_cast<uint8_t>(command), 29);
  }
  explicit GetAllCuesReqBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  GetAllCuesReqBuilder &operator=(const GetAllCuesReqBuilder &);
  flatbuffers::Offset<GetAllCuesReq> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GetAllCuesReq>(end);
    return o;
  }
};

inline flatbuffers::Offset<GetAllCuesReq> CreateGetAllCuesReq(
    flatbuffers::FlatBufferBuilder &_fbb,
    SplayApi::COMMAND command = SplayApi::COMMAND_GET_ALL_CUES) {
  GetAllCuesReqBuilder builder_(_fbb);
  builder_.add_command(command);
  return builder_.Finish();
}

struct GetAllCuesRes FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GetAllCuesResBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CUES = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<SplayApi::CueTable>> *cues() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<SplayApi::CueTable>> *>(VT_CUES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_CUES) &&
           verifier.VerifyVector(cues()) &&
           verifier.VerifyVectorOfTables(cues()) &&
           verifier.EndTable();
  }
};

struct GetAllCuesResBuilder {
  typedef GetAllCuesRes Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_cues(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::CueTable>>> cues) {
    fbb_.AddOffset(GetAllCuesRes::VT_CUES, cues);
  }
  explicit GetAllCuesResBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  GetAllCuesResBuilder &operator=(const GetAllCuesResBuilder &);
  flatbuffers::Offset<GetAllCuesRes> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GetAllCuesRes>(end);
    return o;
  }
};

inline flatbuffers::Offset<GetAllCuesRes> CreateGetAllCuesRes(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SplayApi::CueTable>>> cues = 0) {
  GetAllCuesResBuilder builder_(_fbb);
  builder_.add_cues(cues);
  return builder_.Finish();
}

inline flatbuffers::Offset<GetAllCuesRes> CreateGetAllCuesResDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<SplayApi::CueTable>> *cues = nullptr) {
  auto cues__ = cues ? _fbb.CreateVector<flatbuffers::Offset<SplayApi::CueTable>>(*cues) : 0;
  return SplayApi::CreateGetAllCuesRes(
      _fbb,
      cues__);
}

}  // namespace SplayApi

#endif  // FLATBUFFERS_GENERATED_CUE_SPLAYAPI_H_
