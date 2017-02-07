/*
* Copyright (C) 2011-2015 The Android Open Source Project
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef RENDER_API_H
#define RENDER_API_H

#include <string>

#include <boost/filesystem/path.hpp>

typedef void (*emugl_logger_func_t)(const char* fmt, ...);
typedef void (*emugl_crash_func_t)(const char* format, ...);

typedef struct {
  emugl_logger_func_t coarse;
  emugl_logger_func_t fine;
} emugl_logger_struct;

namespace anbox {
namespace graphics {
namespace emugl {
struct GLLibrary {
  enum class Type { EGL, GLESv1, GLESv2 };
  Type type;
  boost::filesystem::path path;
};

std::vector<GLLibrary> default_gl_libraries();

bool initialize(const std::vector<GLLibrary> &libs, emugl_logger_struct log_funcs, emugl_crash_func_t crash_func);
}  // namespace emugl
}  // namespace graphics
}  // namespace anbox

#endif
