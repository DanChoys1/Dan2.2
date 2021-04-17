#pragma once
#include "array_class.h"

class Input {
public:

	virtual Array Read() = 0;

	virtual ~Input() = default;

};

class KeyboardInput final : public Input {
public:

	Array Read();

};

class FileInput final : public Input {
public:

	Array Read();

};

class RandomInput final : public Input {
public:

	Array Read();

};
