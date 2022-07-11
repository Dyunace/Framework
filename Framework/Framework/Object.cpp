#include "Object.h"

Object::Object() : pBridge(nullptr) { }
Object::Object(Transform _Info) : TransInfo(_Info) { }
Object::~Object() { }
