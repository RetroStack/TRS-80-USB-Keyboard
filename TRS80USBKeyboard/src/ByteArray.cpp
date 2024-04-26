#include "./ByteArray.h"

ByteArray::ByteArray(int len) {
  _length = len;
  _data = new byte[_length];

  clear();
}
ByteArray::~ByteArray() {
  delete[] _data;
}

void ByteArray::print() {
  for (int i = _length - 1; i >= 0; i--) {
    byte temp = _data[i];
    for (int j = 0; j < 8; j++) {
      Serial.print((temp & 128) == 0 ? '0' : '1');
      temp <<= 1;
    }
    Serial.print(' ');
  }
}
void ByteArray::println() {
  print();
  Serial.println();
}

bool ByteArray::isZero() {
  for (int i = 0; i < _length; i++) {
    if (_data[i] != 0) {
      return false;
    }
  }
  return true;
}
bool ByteArray::isEqual(const ByteArray& b) {
  if (_length != b._length) return false;
  if (_data == nullptr || b._data == nullptr) return false;

  for (int i = 0; i < _length; i++) {
    if (_data[i] != b._data[i]) {
      return false;
    }
  }
  return true;
}

byte& ByteArray::operator[](int index) {
  return _data[index];
}
ByteArray& ByteArray::operator=(const ByteArray& other) {
  if (this != &other) {
    _length = other._length;
    delete[] _data;
    _data = new byte[_length];
    for (int i = 0; i < _length; i++) {
      _data[i] = other._data[i];
    }
  }
  return *this;
}

byte ByteArray::get(int index) const {
  return _data[index];
}

void ByteArray::clear() {
  for (int i = 0; i < _length; i++) {
    _data[i] = 0;
  }
}