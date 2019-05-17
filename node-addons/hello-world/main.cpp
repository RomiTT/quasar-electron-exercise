/* cppsrc/main.cpp */
#include <napi.h>
#include "./functions/hello.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
  return my_functions::Init(env, exports);
}

NODE_API_MODULE(testaddon, InitAll)