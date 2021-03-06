#include <nan.h>
#include "serialization.h"
#include "lib.h"
#include "helpers.h"

using namespace Nan;

NAN_METHOD(ElementToJson) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal handle = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.ElementToJson(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ElementFromJson) {
    if (!TestArguments(info, { atNumber, atBuffer, atBuffer })) return;
    Cardinal handle = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PWChar json = (PWChar) BufferToPointer(info[2]);
    WordBool success = xelib.functions.ElementFromJson(handle, path, json);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(DefToJson) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal handle = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.DefToJson(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}