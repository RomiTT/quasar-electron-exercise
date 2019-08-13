#include "hello.h"
#include <windows.h>


std::string my_functions::hello()
{
  RECT rc;
  GetWindowRect(NULL, &rc);

  char buff[100];
  snprintf(buff, sizeof(buff), "Rectangle(%d, %d, %d, %d)", rc.left, rc.top, rc.right, rc.bottom);

  return buff;
  //return "Hello World";
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