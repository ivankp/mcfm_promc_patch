// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ProMC.proto

#ifndef PROTOBUF_ProMC_2eproto__INCLUDED
#define PROTOBUF_ProMC_2eproto__INCLUDED

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

namespace promc {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_ProMC_2eproto();
void protobuf_AssignDesc_ProMC_2eproto();
void protobuf_ShutdownFile_ProMC_2eproto();

class ProMCEvent;
class ProMCEvent_Event;
class ProMCEvent_Particles;

// ===================================================================

class ProMCEvent_Event : public ::google::protobuf::Message {
 public:
  ProMCEvent_Event();
  virtual ~ProMCEvent_Event();

  ProMCEvent_Event(const ProMCEvent_Event& from);

  inline ProMCEvent_Event& operator=(const ProMCEvent_Event& from) {
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
  static const ProMCEvent_Event& default_instance();

  void Swap(ProMCEvent_Event* other);

  // implements Message ----------------------------------------------

  ProMCEvent_Event* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ProMCEvent_Event& from);
  void MergeFrom(const ProMCEvent_Event& from);
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

  // optional int32 Number = 1;
  inline bool has_number() const;
  inline void clear_number();
  static const int kNumberFieldNumber = 1;
  inline ::google::protobuf::int32 number() const;
  inline void set_number(::google::protobuf::int32 value);

  // optional int32 Process_ID = 2;
  inline bool has_process_id() const;
  inline void clear_process_id();
  static const int kProcessIDFieldNumber = 2;
  inline ::google::protobuf::int32 process_id() const;
  inline void set_process_id(::google::protobuf::int32 value);

  // repeated float fdata = 3;
  inline int fdata_size() const;
  inline void clear_fdata();
  static const int kFdataFieldNumber = 3;
  inline float fdata(int index) const;
  inline void set_fdata(int index, float value);
  inline void add_fdata(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      fdata() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_fdata();

  // repeated sint64 idata = 4;
  inline int idata_size() const;
  inline void clear_idata();
  static const int kIdataFieldNumber = 4;
  inline ::google::protobuf::int64 idata(int index) const;
  inline void set_idata(int index, ::google::protobuf::int64 value);
  inline void add_idata(::google::protobuf::int64 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      idata() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_idata();

  // @@protoc_insertion_point(class_scope:promc.ProMCEvent.Event)
 private:
  inline void set_has_number();
  inline void clear_has_number();
  inline void set_has_process_id();
  inline void clear_has_process_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 number_;
  ::google::protobuf::int32 process_id_;
  ::google::protobuf::RepeatedField< float > fdata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > idata_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_ProMC_2eproto();
  friend void protobuf_AssignDesc_ProMC_2eproto();
  friend void protobuf_ShutdownFile_ProMC_2eproto();

  void InitAsDefaultInstance();
  static ProMCEvent_Event* default_instance_;
};
// -------------------------------------------------------------------

class ProMCEvent_Particles : public ::google::protobuf::Message {
 public:
  ProMCEvent_Particles();
  virtual ~ProMCEvent_Particles();

  ProMCEvent_Particles(const ProMCEvent_Particles& from);

  inline ProMCEvent_Particles& operator=(const ProMCEvent_Particles& from) {
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
  static const ProMCEvent_Particles& default_instance();

  void Swap(ProMCEvent_Particles* other);

  // implements Message ----------------------------------------------

  ProMCEvent_Particles* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ProMCEvent_Particles& from);
  void MergeFrom(const ProMCEvent_Particles& from);
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

  // repeated uint32 id = 1 [packed = true];
  inline int id_size() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::uint32 id(int index) const;
  inline void set_id(int index, ::google::protobuf::uint32 value);
  inline void add_id(::google::protobuf::uint32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
      id() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
      mutable_id();

  // repeated sint32 pdg_id = 2 [packed = true];
  inline int pdg_id_size() const;
  inline void clear_pdg_id();
  static const int kPdgIdFieldNumber = 2;
  inline ::google::protobuf::int32 pdg_id(int index) const;
  inline void set_pdg_id(int index, ::google::protobuf::int32 value);
  inline void add_pdg_id(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      pdg_id() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_pdg_id();

  // repeated sint64 Energy = 3 [packed = true];
  inline int energy_size() const;
  inline void clear_energy();
  static const int kEnergyFieldNumber = 3;
  inline ::google::protobuf::int64 energy(int index) const;
  inline void set_energy(int index, ::google::protobuf::int64 value);
  inline void add_energy(::google::protobuf::int64 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      energy() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_energy();

  // repeated sint64 Px = 4 [packed = true];
  inline int px_size() const;
  inline void clear_px();
  static const int kPxFieldNumber = 4;
  inline ::google::protobuf::int64 px(int index) const;
  inline void set_px(int index, ::google::protobuf::int64 value);
  inline void add_px(::google::protobuf::int64 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      px() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_px();

  // repeated sint64 Py = 5 [packed = true];
  inline int py_size() const;
  inline void clear_py();
  static const int kPyFieldNumber = 5;
  inline ::google::protobuf::int64 py(int index) const;
  inline void set_py(int index, ::google::protobuf::int64 value);
  inline void add_py(::google::protobuf::int64 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      py() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_py();

  // repeated sint64 Pz = 6 [packed = true];
  inline int pz_size() const;
  inline void clear_pz();
  static const int kPzFieldNumber = 6;
  inline ::google::protobuf::int64 pz(int index) const;
  inline void set_pz(int index, ::google::protobuf::int64 value);
  inline void add_pz(::google::protobuf::int64 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      pz() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_pz();

  // @@protoc_insertion_point(class_scope:promc.ProMCEvent.Particles)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 > id_;
  mutable int _id_cached_byte_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > pdg_id_;
  mutable int _pdg_id_cached_byte_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > energy_;
  mutable int _energy_cached_byte_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > px_;
  mutable int _px_cached_byte_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > py_;
  mutable int _py_cached_byte_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > pz_;
  mutable int _pz_cached_byte_size_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(6 + 31) / 32];

  friend void  protobuf_AddDesc_ProMC_2eproto();
  friend void protobuf_AssignDesc_ProMC_2eproto();
  friend void protobuf_ShutdownFile_ProMC_2eproto();

  void InitAsDefaultInstance();
  static ProMCEvent_Particles* default_instance_;
};
// -------------------------------------------------------------------

class ProMCEvent : public ::google::protobuf::Message {
 public:
  ProMCEvent();
  virtual ~ProMCEvent();

  ProMCEvent(const ProMCEvent& from);

  inline ProMCEvent& operator=(const ProMCEvent& from) {
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
  static const ProMCEvent& default_instance();

  void Swap(ProMCEvent* other);

  // implements Message ----------------------------------------------

  ProMCEvent* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ProMCEvent& from);
  void MergeFrom(const ProMCEvent& from);
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

  typedef ProMCEvent_Event Event;
  typedef ProMCEvent_Particles Particles;

  // accessors -------------------------------------------------------

  // optional .promc.ProMCEvent.Event event = 1;
  inline bool has_event() const;
  inline void clear_event();
  static const int kEventFieldNumber = 1;
  inline const ::promc::ProMCEvent_Event& event() const;
  inline ::promc::ProMCEvent_Event* mutable_event();
  inline ::promc::ProMCEvent_Event* release_event();
  inline void set_allocated_event(::promc::ProMCEvent_Event* event);

  // optional .promc.ProMCEvent.Particles particles = 2;
  inline bool has_particles() const;
  inline void clear_particles();
  static const int kParticlesFieldNumber = 2;
  inline const ::promc::ProMCEvent_Particles& particles() const;
  inline ::promc::ProMCEvent_Particles* mutable_particles();
  inline ::promc::ProMCEvent_Particles* release_particles();
  inline void set_allocated_particles(::promc::ProMCEvent_Particles* particles);

  // @@protoc_insertion_point(class_scope:promc.ProMCEvent)
 private:
  inline void set_has_event();
  inline void clear_has_event();
  inline void set_has_particles();
  inline void clear_has_particles();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::promc::ProMCEvent_Event* event_;
  ::promc::ProMCEvent_Particles* particles_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_ProMC_2eproto();
  friend void protobuf_AssignDesc_ProMC_2eproto();
  friend void protobuf_ShutdownFile_ProMC_2eproto();

  void InitAsDefaultInstance();
  static ProMCEvent* default_instance_;
};
// ===================================================================


// ===================================================================

// ProMCEvent_Event

// optional int32 Number = 1;
inline bool ProMCEvent_Event::has_number() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ProMCEvent_Event::set_has_number() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ProMCEvent_Event::clear_has_number() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ProMCEvent_Event::clear_number() {
  number_ = 0;
  clear_has_number();
}
inline ::google::protobuf::int32 ProMCEvent_Event::number() const {
  return number_;
}
inline void ProMCEvent_Event::set_number(::google::protobuf::int32 value) {
  set_has_number();
  number_ = value;
}

// optional int32 Process_ID = 2;
inline bool ProMCEvent_Event::has_process_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ProMCEvent_Event::set_has_process_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ProMCEvent_Event::clear_has_process_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ProMCEvent_Event::clear_process_id() {
  process_id_ = 0;
  clear_has_process_id();
}
inline ::google::protobuf::int32 ProMCEvent_Event::process_id() const {
  return process_id_;
}
inline void ProMCEvent_Event::set_process_id(::google::protobuf::int32 value) {
  set_has_process_id();
  process_id_ = value;
}

// repeated float fdata = 3;
inline int ProMCEvent_Event::fdata_size() const {
  return fdata_.size();
}
inline void ProMCEvent_Event::clear_fdata() {
  fdata_.Clear();
}
inline float ProMCEvent_Event::fdata(int index) const {
  return fdata_.Get(index);
}
inline void ProMCEvent_Event::set_fdata(int index, float value) {
  fdata_.Set(index, value);
}
inline void ProMCEvent_Event::add_fdata(float value) {
  fdata_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
ProMCEvent_Event::fdata() const {
  return fdata_;
}
inline ::google::protobuf::RepeatedField< float >*
ProMCEvent_Event::mutable_fdata() {
  return &fdata_;
}

// repeated sint64 idata = 4;
inline int ProMCEvent_Event::idata_size() const {
  return idata_.size();
}
inline void ProMCEvent_Event::clear_idata() {
  idata_.Clear();
}
inline ::google::protobuf::int64 ProMCEvent_Event::idata(int index) const {
  return idata_.Get(index);
}
inline void ProMCEvent_Event::set_idata(int index, ::google::protobuf::int64 value) {
  idata_.Set(index, value);
}
inline void ProMCEvent_Event::add_idata(::google::protobuf::int64 value) {
  idata_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
ProMCEvent_Event::idata() const {
  return idata_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
ProMCEvent_Event::mutable_idata() {
  return &idata_;
}

// -------------------------------------------------------------------

// ProMCEvent_Particles

// repeated uint32 id = 1 [packed = true];
inline int ProMCEvent_Particles::id_size() const {
  return id_.size();
}
inline void ProMCEvent_Particles::clear_id() {
  id_.Clear();
}
inline ::google::protobuf::uint32 ProMCEvent_Particles::id(int index) const {
  return id_.Get(index);
}
inline void ProMCEvent_Particles::set_id(int index, ::google::protobuf::uint32 value) {
  id_.Set(index, value);
}
inline void ProMCEvent_Particles::add_id(::google::protobuf::uint32 value) {
  id_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
ProMCEvent_Particles::id() const {
  return id_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
ProMCEvent_Particles::mutable_id() {
  return &id_;
}

// repeated sint32 pdg_id = 2 [packed = true];
inline int ProMCEvent_Particles::pdg_id_size() const {
  return pdg_id_.size();
}
inline void ProMCEvent_Particles::clear_pdg_id() {
  pdg_id_.Clear();
}
inline ::google::protobuf::int32 ProMCEvent_Particles::pdg_id(int index) const {
  return pdg_id_.Get(index);
}
inline void ProMCEvent_Particles::set_pdg_id(int index, ::google::protobuf::int32 value) {
  pdg_id_.Set(index, value);
}
inline void ProMCEvent_Particles::add_pdg_id(::google::protobuf::int32 value) {
  pdg_id_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
ProMCEvent_Particles::pdg_id() const {
  return pdg_id_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
ProMCEvent_Particles::mutable_pdg_id() {
  return &pdg_id_;
}

// repeated sint64 Energy = 3 [packed = true];
inline int ProMCEvent_Particles::energy_size() const {
  return energy_.size();
}
inline void ProMCEvent_Particles::clear_energy() {
  energy_.Clear();
}
inline ::google::protobuf::int64 ProMCEvent_Particles::energy(int index) const {
  return energy_.Get(index);
}
inline void ProMCEvent_Particles::set_energy(int index, ::google::protobuf::int64 value) {
  energy_.Set(index, value);
}
inline void ProMCEvent_Particles::add_energy(::google::protobuf::int64 value) {
  energy_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
ProMCEvent_Particles::energy() const {
  return energy_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
ProMCEvent_Particles::mutable_energy() {
  return &energy_;
}

// repeated sint64 Px = 4 [packed = true];
inline int ProMCEvent_Particles::px_size() const {
  return px_.size();
}
inline void ProMCEvent_Particles::clear_px() {
  px_.Clear();
}
inline ::google::protobuf::int64 ProMCEvent_Particles::px(int index) const {
  return px_.Get(index);
}
inline void ProMCEvent_Particles::set_px(int index, ::google::protobuf::int64 value) {
  px_.Set(index, value);
}
inline void ProMCEvent_Particles::add_px(::google::protobuf::int64 value) {
  px_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
ProMCEvent_Particles::px() const {
  return px_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
ProMCEvent_Particles::mutable_px() {
  return &px_;
}

// repeated sint64 Py = 5 [packed = true];
inline int ProMCEvent_Particles::py_size() const {
  return py_.size();
}
inline void ProMCEvent_Particles::clear_py() {
  py_.Clear();
}
inline ::google::protobuf::int64 ProMCEvent_Particles::py(int index) const {
  return py_.Get(index);
}
inline void ProMCEvent_Particles::set_py(int index, ::google::protobuf::int64 value) {
  py_.Set(index, value);
}
inline void ProMCEvent_Particles::add_py(::google::protobuf::int64 value) {
  py_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
ProMCEvent_Particles::py() const {
  return py_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
ProMCEvent_Particles::mutable_py() {
  return &py_;
}

// repeated sint64 Pz = 6 [packed = true];
inline int ProMCEvent_Particles::pz_size() const {
  return pz_.size();
}
inline void ProMCEvent_Particles::clear_pz() {
  pz_.Clear();
}
inline ::google::protobuf::int64 ProMCEvent_Particles::pz(int index) const {
  return pz_.Get(index);
}
inline void ProMCEvent_Particles::set_pz(int index, ::google::protobuf::int64 value) {
  pz_.Set(index, value);
}
inline void ProMCEvent_Particles::add_pz(::google::protobuf::int64 value) {
  pz_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
ProMCEvent_Particles::pz() const {
  return pz_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
ProMCEvent_Particles::mutable_pz() {
  return &pz_;
}

// -------------------------------------------------------------------

// ProMCEvent

// optional .promc.ProMCEvent.Event event = 1;
inline bool ProMCEvent::has_event() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ProMCEvent::set_has_event() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ProMCEvent::clear_has_event() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ProMCEvent::clear_event() {
  if (event_ != NULL) event_->::promc::ProMCEvent_Event::Clear();
  clear_has_event();
}
inline const ::promc::ProMCEvent_Event& ProMCEvent::event() const {
  return event_ != NULL ? *event_ : *default_instance_->event_;
}
inline ::promc::ProMCEvent_Event* ProMCEvent::mutable_event() {
  set_has_event();
  if (event_ == NULL) event_ = new ::promc::ProMCEvent_Event;
  return event_;
}
inline ::promc::ProMCEvent_Event* ProMCEvent::release_event() {
  clear_has_event();
  ::promc::ProMCEvent_Event* temp = event_;
  event_ = NULL;
  return temp;
}
inline void ProMCEvent::set_allocated_event(::promc::ProMCEvent_Event* event) {
  delete event_;
  event_ = event;
  if (event) {
    set_has_event();
  } else {
    clear_has_event();
  }
}

// optional .promc.ProMCEvent.Particles particles = 2;
inline bool ProMCEvent::has_particles() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ProMCEvent::set_has_particles() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ProMCEvent::clear_has_particles() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ProMCEvent::clear_particles() {
  if (particles_ != NULL) particles_->::promc::ProMCEvent_Particles::Clear();
  clear_has_particles();
}
inline const ::promc::ProMCEvent_Particles& ProMCEvent::particles() const {
  return particles_ != NULL ? *particles_ : *default_instance_->particles_;
}
inline ::promc::ProMCEvent_Particles* ProMCEvent::mutable_particles() {
  set_has_particles();
  if (particles_ == NULL) particles_ = new ::promc::ProMCEvent_Particles;
  return particles_;
}
inline ::promc::ProMCEvent_Particles* ProMCEvent::release_particles() {
  clear_has_particles();
  ::promc::ProMCEvent_Particles* temp = particles_;
  particles_ = NULL;
  return temp;
}
inline void ProMCEvent::set_allocated_particles(::promc::ProMCEvent_Particles* particles) {
  delete particles_;
  particles_ = particles;
  if (particles) {
    set_has_particles();
  } else {
    clear_has_particles();
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace promc

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ProMC_2eproto__INCLUDED