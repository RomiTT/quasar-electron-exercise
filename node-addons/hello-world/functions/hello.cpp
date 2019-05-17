#include "hello.h"

std::string my_functions::hello()
{
  return "Hello World";
}

Napi::String my_functions::HelloWrapped(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Napi::String returnValue = Napi::String::New(env, my_functions::hello());

  return returnValue;
}

Napi::Object my_functions::Init(Napi::Env env, Napi::Object exports)
{
  exports.Set("hello", Napi::Function::New(env, my_functions::HelloWrapped));

  return exports;
}