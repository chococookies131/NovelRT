// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root for more information.
#include "../NrtInteropErrorHandlingInternal.h"
#include "NovelRT.Interop/Utilities/NrtMisc.h"
#include "NovelRT.Interop/NrtInteropUtils.h"
#include <NovelRT.h>
#include <stdarg.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

const char* Nrt_getExecutablePath() {
  std::string cppPath = NovelRT::Utilities::Misc::getExecutablePath().string();
  char* path = new char[cppPath.length() + 1];
  if (strlen(path) < cppPath.length() + 1) {
    Nrt_setErrMsgCustomInternal("Could not properly allocate memory for path!");
    return NULL;
  }

#if defined(WIN32)
  strcpy_s(path, cppPath.length()+1, cppPath.c_str());
#else
  path = strdup(cppPath.c_str());
#endif
  return path;
}

const char* Nrt_getExecutableDirPath() {
  std::string cppPath = NovelRT::Utilities::Misc::getExecutableDirPath().string();
  char* path = new char[cppPath.length() + 1];
  if(strlen(path) < (cppPath.length() + 1)) {
    Nrt_setErrMsgCustomInternal("Could not properly allocate memory for path!");
    return NULL;
  }

#if defined(WIN32)
  strcpy_s(path, cppPath.length()+1, cppPath.c_str());
#else
  path = strdup(cppPath.c_str());
#endif
  return path;
}

const char* Nrt_appendFilePath(int numberOfArgs, ...) {
  if (numberOfArgs <= 1) {
    Nrt_setErrMsgCustomInternal("Cannot append file path when nothing is being appended!");
    return NULL;
  }

  const char* dirMarker = static_cast<const char*>("/");
#if defined(WIN32)
  dirMarker = "\\";
#endif

  std::string finalString = "";
  va_list args;
  va_start(args, numberOfArgs);

  for(int i = 0; i < numberOfArgs; i++) {
    finalString.append(va_arg(args, const char*));
    if (i < numberOfArgs-1) {
      finalString.append(dirMarker);
    }
  }
  va_end(args);

  char* finalPath = new char[finalString.length() + 1];
  if(strlen(finalPath) < (finalString.length() + 1)) {
    Nrt_setErrMsgCustomInternal("Could not properly allocate memory for path!");
    return NULL;
  }

//strcpy_s is not included by all compilers that don't have __STDC_LIB_EXT1__ available, including clang.
#if defined(WIN32)
  strcpy_s(finalPath, finalString.length() + 1, finalString.c_str());
#else
  finalPath = strdup(finalString.c_str());
#endif
  return finalPath;
}

const char* Nrt_appendText(int numberOfArgs, ...) {
  if (numberOfArgs <= 1) {
    Nrt_setErrMsgCustomInternal("Cannot append text when nothing is being appended!");
    return NULL;
  }

  std::string finalString = "";
  va_list args;
  va_start(args, numberOfArgs);

  for(int i = 0; i < numberOfArgs; i++) {
    finalString.append(va_arg(args, const char*));
  }
  va_end(args);

  char* finalText = new char[finalString.length() + 1];
  if(strlen(finalText) < (finalString.length() + 1)) {
    Nrt_setErrMsgCustomInternal("Could not properly allocate memory for test!");
    return NULL;
  }

  #if defined(WIN32)
  strcpy_s(finalText, finalString.length() + 1, finalString.c_str());
#else
  finalText = strdup(finalString.c_str());
#endif
  return finalText;
}

#ifdef __cplusplus
}
#endif
