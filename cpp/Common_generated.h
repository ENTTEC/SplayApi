// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_COMMON_SPLAYAPI_H_
#define FLATBUFFERS_GENERATED_COMMON_SPLAYAPI_H_

#include "flatbuffers/flatbuffers.h"

namespace SplayApi {

enum UNIVERSE_TYPE {
  UNIVERSE_TYPE_DMX_TYPE = 0,
  UNIVERSE_TYPE_ARTNET_TYPE = 1,
  UNIVERSE_TYPE_SACN_TYPE = 2,
  UNIVERSE_TYPE_NONE_TYPE = 3,
  UNIVERSE_TYPE_MIN = UNIVERSE_TYPE_DMX_TYPE,
  UNIVERSE_TYPE_MAX = UNIVERSE_TYPE_NONE_TYPE
};

inline const UNIVERSE_TYPE (&EnumValuesUNIVERSE_TYPE())[4] {
  static const UNIVERSE_TYPE values[] = {
    UNIVERSE_TYPE_DMX_TYPE,
    UNIVERSE_TYPE_ARTNET_TYPE,
    UNIVERSE_TYPE_SACN_TYPE,
    UNIVERSE_TYPE_NONE_TYPE
  };
  return values;
}

inline const char * const *EnumNamesUNIVERSE_TYPE() {
  static const char * const names[5] = {
    "DMX_TYPE",
    "ARTNET_TYPE",
    "SACN_TYPE",
    "NONE_TYPE",
    nullptr
  };
  return names;
}

inline const char *EnumNameUNIVERSE_TYPE(UNIVERSE_TYPE e) {
  if (flatbuffers::IsOutRange(e, UNIVERSE_TYPE_DMX_TYPE, UNIVERSE_TYPE_NONE_TYPE)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesUNIVERSE_TYPE()[index];
}

/// Don't change order
enum PIXEL_ORDER {
  PIXEL_ORDER_RGB = 0,
  PIXEL_ORDER_RBG = 1,
  PIXEL_ORDER_GRB = 2,
  PIXEL_ORDER_GBR = 3,
  PIXEL_ORDER_BRG = 4,
  PIXEL_ORDER_BGR = 5,
  PIXEL_ORDER_RGBW = 6,
  PIXEL_ORDER_RBGW = 7,
  PIXEL_ORDER_GRBW = 8,
  PIXEL_ORDER_GBRW = 9,
  PIXEL_ORDER_BRGW = 10,
  PIXEL_ORDER_BGRW = 11,
  PIXEL_ORDER_WRGB = 12,
  PIXEL_ORDER_WRBG = 13,
  PIXEL_ORDER_WGRB = 14,
  PIXEL_ORDER_WGBR = 15,
  PIXEL_ORDER_WBRG = 16,
  PIXEL_ORDER_WBGR = 17,
  PIXEL_ORDER_RWGB = 18,
  PIXEL_ORDER_RWBG = 19,
  PIXEL_ORDER_GWRB = 20,
  PIXEL_ORDER_GWBR = 21,
  PIXEL_ORDER_BWRG = 22,
  PIXEL_ORDER_BWGR = 23,
  PIXEL_ORDER_RGWB = 24,
  PIXEL_ORDER_RBWG = 25,
  PIXEL_ORDER_GRWB = 26,
  PIXEL_ORDER_GBWR = 27,
  PIXEL_ORDER_BRWG = 28,
  PIXEL_ORDER_BGWR = 29,
  PIXEL_ORDER_MIN = PIXEL_ORDER_RGB,
  PIXEL_ORDER_MAX = PIXEL_ORDER_BGWR
};

inline const PIXEL_ORDER (&EnumValuesPIXEL_ORDER())[30] {
  static const PIXEL_ORDER values[] = {
    PIXEL_ORDER_RGB,
    PIXEL_ORDER_RBG,
    PIXEL_ORDER_GRB,
    PIXEL_ORDER_GBR,
    PIXEL_ORDER_BRG,
    PIXEL_ORDER_BGR,
    PIXEL_ORDER_RGBW,
    PIXEL_ORDER_RBGW,
    PIXEL_ORDER_GRBW,
    PIXEL_ORDER_GBRW,
    PIXEL_ORDER_BRGW,
    PIXEL_ORDER_BGRW,
    PIXEL_ORDER_WRGB,
    PIXEL_ORDER_WRBG,
    PIXEL_ORDER_WGRB,
    PIXEL_ORDER_WGBR,
    PIXEL_ORDER_WBRG,
    PIXEL_ORDER_WBGR,
    PIXEL_ORDER_RWGB,
    PIXEL_ORDER_RWBG,
    PIXEL_ORDER_GWRB,
    PIXEL_ORDER_GWBR,
    PIXEL_ORDER_BWRG,
    PIXEL_ORDER_BWGR,
    PIXEL_ORDER_RGWB,
    PIXEL_ORDER_RBWG,
    PIXEL_ORDER_GRWB,
    PIXEL_ORDER_GBWR,
    PIXEL_ORDER_BRWG,
    PIXEL_ORDER_BGWR
  };
  return values;
}

inline const char * const *EnumNamesPIXEL_ORDER() {
  static const char * const names[31] = {
    "RGB",
    "RBG",
    "GRB",
    "GBR",
    "BRG",
    "BGR",
    "RGBW",
    "RBGW",
    "GRBW",
    "GBRW",
    "BRGW",
    "BGRW",
    "WRGB",
    "WRBG",
    "WGRB",
    "WGBR",
    "WBRG",
    "WBGR",
    "RWGB",
    "RWBG",
    "GWRB",
    "GWBR",
    "BWRG",
    "BWGR",
    "RGWB",
    "RBWG",
    "GRWB",
    "GBWR",
    "BRWG",
    "BGWR",
    nullptr
  };
  return names;
}

inline const char *EnumNamePIXEL_ORDER(PIXEL_ORDER e) {
  if (flatbuffers::IsOutRange(e, PIXEL_ORDER_RGB, PIXEL_ORDER_BGWR)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesPIXEL_ORDER()[index];
}

enum SETTING_CATEGORIES {
  SETTING_CATEGORIES_IS_SPARE = 0,
  SETTING_CATEGORIES_SYSTEM_NAME = 1,
  SETTING_CATEGORIES_PLAYBACK_CONFIG = 2,
  SETTING_CATEGORIES_PASSWORD = 3,
  SETTING_CATEGORIES_HELP_HINTS = 4,
  SETTING_CATEGORIES_SERIALNO = 5,
  SETTING_CATEGORIES_ENABLE_PASSWORD = 6,
  SETTING_CATEGORIES_SMTP = 7,
  SETTING_CATEGORIES_EMAIL = 8,
  SETTING_CATEGORIES_INPUT = 9,
  SETTING_CATEGORIES_OUTPUT = 10,
  SETTING_CATEGORIES_DMX = 11,
  SETTING_CATEGORIES_ARTNET = 12,
  SETTING_CATEGORIES_SACN = 13,
  SETTING_CATEGORIES_LOCATION = 14,
  SETTING_CATEGORIES_NTP = 15,
  SETTING_CATEGORIES_BASE_PATH = 16,
  SETTING_CATEGORIES_CUE_PATH = 17,
  SETTING_CATEGORIES_HOME_INTERFACE = 18,
  SETTING_CATEGORIES_UDP = 19,
  SETTING_CATEGORIES_TCP = 20,
  SETTING_CATEGORIES_RS232C = 21,
  SETTING_CATEGORIES_OSC = 22,
  SETTING_CATEGORIES_IEEE1588_CONFIG = 23,
  SETTING_CATEGORIES_IEEE1588_ACTIVE = 24,
  SETTING_CATEGORIES_LOCK_STATUS = 25,
  SETTING_CATEGORIES_DB_VERSION = 26,
  SETTING_CATEGORIES_SIZE_OF_SETTING_CATEGORIES = 27,
  SETTING_CATEGORIES_MIN = SETTING_CATEGORIES_IS_SPARE,
  SETTING_CATEGORIES_MAX = SETTING_CATEGORIES_SIZE_OF_SETTING_CATEGORIES
};

inline const SETTING_CATEGORIES (&EnumValuesSETTING_CATEGORIES())[28] {
  static const SETTING_CATEGORIES values[] = {
    SETTING_CATEGORIES_IS_SPARE,
    SETTING_CATEGORIES_SYSTEM_NAME,
    SETTING_CATEGORIES_PLAYBACK_CONFIG,
    SETTING_CATEGORIES_PASSWORD,
    SETTING_CATEGORIES_HELP_HINTS,
    SETTING_CATEGORIES_SERIALNO,
    SETTING_CATEGORIES_ENABLE_PASSWORD,
    SETTING_CATEGORIES_SMTP,
    SETTING_CATEGORIES_EMAIL,
    SETTING_CATEGORIES_INPUT,
    SETTING_CATEGORIES_OUTPUT,
    SETTING_CATEGORIES_DMX,
    SETTING_CATEGORIES_ARTNET,
    SETTING_CATEGORIES_SACN,
    SETTING_CATEGORIES_LOCATION,
    SETTING_CATEGORIES_NTP,
    SETTING_CATEGORIES_BASE_PATH,
    SETTING_CATEGORIES_CUE_PATH,
    SETTING_CATEGORIES_HOME_INTERFACE,
    SETTING_CATEGORIES_UDP,
    SETTING_CATEGORIES_TCP,
    SETTING_CATEGORIES_RS232C,
    SETTING_CATEGORIES_OSC,
    SETTING_CATEGORIES_IEEE1588_CONFIG,
    SETTING_CATEGORIES_IEEE1588_ACTIVE,
    SETTING_CATEGORIES_LOCK_STATUS,
    SETTING_CATEGORIES_DB_VERSION,
    SETTING_CATEGORIES_SIZE_OF_SETTING_CATEGORIES
  };
  return values;
}

inline const char * const *EnumNamesSETTING_CATEGORIES() {
  static const char * const names[29] = {
    "IS_SPARE",
    "SYSTEM_NAME",
    "PLAYBACK_CONFIG",
    "PASSWORD",
    "HELP_HINTS",
    "SERIALNO",
    "ENABLE_PASSWORD",
    "SMTP",
    "EMAIL",
    "INPUT",
    "OUTPUT",
    "DMX",
    "ARTNET",
    "SACN",
    "LOCATION",
    "NTP",
    "BASE_PATH",
    "CUE_PATH",
    "HOME_INTERFACE",
    "UDP",
    "TCP",
    "RS232C",
    "OSC",
    "IEEE1588_CONFIG",
    "IEEE1588_ACTIVE",
    "LOCK_STATUS",
    "DB_VERSION",
    "SIZE_OF_SETTING_CATEGORIES",
    nullptr
  };
  return names;
}

inline const char *EnumNameSETTING_CATEGORIES(SETTING_CATEGORIES e) {
  if (flatbuffers::IsOutRange(e, SETTING_CATEGORIES_IS_SPARE, SETTING_CATEGORIES_SIZE_OF_SETTING_CATEGORIES)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesSETTING_CATEGORIES()[index];
}

}  // namespace SplayApi

#endif  // FLATBUFFERS_GENERATED_COMMON_SPLAYAPI_H_
