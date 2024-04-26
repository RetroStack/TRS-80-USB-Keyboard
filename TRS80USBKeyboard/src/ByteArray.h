#ifndef BYTE_ARRAY_H
#define BYTE_ARRAY_H

#include <Arduino.h>

class ByteArray {
private:
  byte* _data;
  int _length;

public:
  ByteArray(int len);
  ~ByteArray();

  void print();
  void println();

  bool isZero();
  bool isEqual(const ByteArray& b);

  byte& operator[](int index);
  ByteArray& operator=(const ByteArray& other);

  byte get(int index) const;

  void clear();
};

#endif /* BYTE_ARRAY_H */
