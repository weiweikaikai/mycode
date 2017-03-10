// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg.proto

#ifndef PROTOBUF_msg_2eproto__INCLUDED
#define PROTOBUF_msg_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace demo {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_msg_2eproto();
void protobuf_AssignDesc_msg_2eproto();
void protobuf_ShutdownFile_msg_2eproto();

class msg;

// ===================================================================

class msg : public ::google::protobuf::Message {
 public:
  msg();
  virtual ~msg();

  msg(const msg& from);

  inline msg& operator=(const msg& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const msg& default_instance();

  void Swap(msg* other);

  // implements Message ----------------------------------------------

  msg* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const msg& from);
  void MergeFrom(const msg& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 MsgType = 1;
  inline bool has_msgtype() const;
  inline void clear_msgtype();
  static const int kMsgTypeFieldNumber = 1;
  inline ::google::protobuf::int32 msgtype() const;
  inline void set_msgtype(::google::protobuf::int32 value);

  // required string MsgInfo = 2;
  inline bool has_msginfo() const;
  inline void clear_msginfo();
  static const int kMsgInfoFieldNumber = 2;
  inline const ::std::string& msginfo() const;
  inline void set_msginfo(const ::std::string& value);
  inline void set_msginfo(const char* value);
  inline void set_msginfo(const char* value, size_t size);
  inline ::std::string* mutable_msginfo();
  inline ::std::string* release_msginfo();
  inline void set_allocated_msginfo(::std::string* msginfo);

  // required string MsgFrom = 3;
  inline bool has_msgfrom() const;
  inline void clear_msgfrom();
  static const int kMsgFromFieldNumber = 3;
  inline const ::std::string& msgfrom() const;
  inline void set_msgfrom(const ::std::string& value);
  inline void set_msgfrom(const char* value);
  inline void set_msgfrom(const char* value, size_t size);
  inline ::std::string* mutable_msgfrom();
  inline ::std::string* release_msgfrom();
  inline void set_allocated_msgfrom(::std::string* msgfrom);

  // optional string opt = 4;
  inline bool has_opt() const;
  inline void clear_opt();
  static const int kOptFieldNumber = 4;
  inline const ::std::string& opt() const;
  inline void set_opt(const ::std::string& value);
  inline void set_opt(const char* value);
  inline void set_opt(const char* value, size_t size);
  inline ::std::string* mutable_opt();
  inline ::std::string* release_opt();
  inline void set_allocated_opt(::std::string* opt);

  // @@protoc_insertion_point(class_scope:demo.msg)
 private:
  inline void set_has_msgtype();
  inline void clear_has_msgtype();
  inline void set_has_msginfo();
  inline void clear_has_msginfo();
  inline void set_has_msgfrom();
  inline void clear_has_msgfrom();
  inline void set_has_opt();
  inline void clear_has_opt();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* msginfo_;
  ::std::string* msgfrom_;
  ::std::string* opt_;
  ::google::protobuf::int32 msgtype_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_msg_2eproto();
  friend void protobuf_AssignDesc_msg_2eproto();
  friend void protobuf_ShutdownFile_msg_2eproto();

  void InitAsDefaultInstance();
  static msg* default_instance_;
};
// ===================================================================


// ===================================================================

// msg

// required int32 MsgType = 1;
inline bool msg::has_msgtype() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void msg::set_has_msgtype() {
  _has_bits_[0] |= 0x00000001u;
}
inline void msg::clear_has_msgtype() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void msg::clear_msgtype() {
  msgtype_ = 0;
  clear_has_msgtype();
}
inline ::google::protobuf::int32 msg::msgtype() const {
  return msgtype_;
}
inline void msg::set_msgtype(::google::protobuf::int32 value) {
  set_has_msgtype();
  msgtype_ = value;
}

// required string MsgInfo = 2;
inline bool msg::has_msginfo() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void msg::set_has_msginfo() {
  _has_bits_[0] |= 0x00000002u;
}
inline void msg::clear_has_msginfo() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void msg::clear_msginfo() {
  if (msginfo_ != &::google::protobuf::internal::kEmptyString) {
    msginfo_->clear();
  }
  clear_has_msginfo();
}
inline const ::std::string& msg::msginfo() const {
  return *msginfo_;
}
inline void msg::set_msginfo(const ::std::string& value) {
  set_has_msginfo();
  if (msginfo_ == &::google::protobuf::internal::kEmptyString) {
    msginfo_ = new ::std::string;
  }
  msginfo_->assign(value);
}
inline void msg::set_msginfo(const char* value) {
  set_has_msginfo();
  if (msginfo_ == &::google::protobuf::internal::kEmptyString) {
    msginfo_ = new ::std::string;
  }
  msginfo_->assign(value);
}
inline void msg::set_msginfo(const char* value, size_t size) {
  set_has_msginfo();
  if (msginfo_ == &::google::protobuf::internal::kEmptyString) {
    msginfo_ = new ::std::string;
  }
  msginfo_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* msg::mutable_msginfo() {
  set_has_msginfo();
  if (msginfo_ == &::google::protobuf::internal::kEmptyString) {
    msginfo_ = new ::std::string;
  }
  return msginfo_;
}
inline ::std::string* msg::release_msginfo() {
  clear_has_msginfo();
  if (msginfo_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = msginfo_;
    msginfo_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void msg::set_allocated_msginfo(::std::string* msginfo) {
  if (msginfo_ != &::google::protobuf::internal::kEmptyString) {
    delete msginfo_;
  }
  if (msginfo) {
    set_has_msginfo();
    msginfo_ = msginfo;
  } else {
    clear_has_msginfo();
    msginfo_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string MsgFrom = 3;
inline bool msg::has_msgfrom() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void msg::set_has_msgfrom() {
  _has_bits_[0] |= 0x00000004u;
}
inline void msg::clear_has_msgfrom() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void msg::clear_msgfrom() {
  if (msgfrom_ != &::google::protobuf::internal::kEmptyString) {
    msgfrom_->clear();
  }
  clear_has_msgfrom();
}
inline const ::std::string& msg::msgfrom() const {
  return *msgfrom_;
}
inline void msg::set_msgfrom(const ::std::string& value) {
  set_has_msgfrom();
  if (msgfrom_ == &::google::protobuf::internal::kEmptyString) {
    msgfrom_ = new ::std::string;
  }
  msgfrom_->assign(value);
}
inline void msg::set_msgfrom(const char* value) {
  set_has_msgfrom();
  if (msgfrom_ == &::google::protobuf::internal::kEmptyString) {
    msgfrom_ = new ::std::string;
  }
  msgfrom_->assign(value);
}
inline void msg::set_msgfrom(const char* value, size_t size) {
  set_has_msgfrom();
  if (msgfrom_ == &::google::protobuf::internal::kEmptyString) {
    msgfrom_ = new ::std::string;
  }
  msgfrom_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* msg::mutable_msgfrom() {
  set_has_msgfrom();
  if (msgfrom_ == &::google::protobuf::internal::kEmptyString) {
    msgfrom_ = new ::std::string;
  }
  return msgfrom_;
}
inline ::std::string* msg::release_msgfrom() {
  clear_has_msgfrom();
  if (msgfrom_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = msgfrom_;
    msgfrom_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void msg::set_allocated_msgfrom(::std::string* msgfrom) {
  if (msgfrom_ != &::google::protobuf::internal::kEmptyString) {
    delete msgfrom_;
  }
  if (msgfrom) {
    set_has_msgfrom();
    msgfrom_ = msgfrom;
  } else {
    clear_has_msgfrom();
    msgfrom_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string opt = 4;
inline bool msg::has_opt() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void msg::set_has_opt() {
  _has_bits_[0] |= 0x00000008u;
}
inline void msg::clear_has_opt() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void msg::clear_opt() {
  if (opt_ != &::google::protobuf::internal::kEmptyString) {
    opt_->clear();
  }
  clear_has_opt();
}
inline const ::std::string& msg::opt() const {
  return *opt_;
}
inline void msg::set_opt(const ::std::string& value) {
  set_has_opt();
  if (opt_ == &::google::protobuf::internal::kEmptyString) {
    opt_ = new ::std::string;
  }
  opt_->assign(value);
}
inline void msg::set_opt(const char* value) {
  set_has_opt();
  if (opt_ == &::google::protobuf::internal::kEmptyString) {
    opt_ = new ::std::string;
  }
  opt_->assign(value);
}
inline void msg::set_opt(const char* value, size_t size) {
  set_has_opt();
  if (opt_ == &::google::protobuf::internal::kEmptyString) {
    opt_ = new ::std::string;
  }
  opt_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* msg::mutable_opt() {
  set_has_opt();
  if (opt_ == &::google::protobuf::internal::kEmptyString) {
    opt_ = new ::std::string;
  }
  return opt_;
}
inline ::std::string* msg::release_opt() {
  clear_has_opt();
  if (opt_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = opt_;
    opt_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void msg::set_allocated_opt(::std::string* opt) {
  if (opt_ != &::google::protobuf::internal::kEmptyString) {
    delete opt_;
  }
  if (opt) {
    set_has_opt();
    opt_ = opt;
  } else {
    clear_has_opt();
    opt_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace demo

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_msg_2eproto__INCLUDED
