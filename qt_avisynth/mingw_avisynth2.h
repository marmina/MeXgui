// Avisynth v2.5.  Copyright 2002 Ben Rudiak-Gould et al.
// http://www.avisynth.org

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA, or visit
// http://www.gnu.org/copyleft/gpl.html .
//
// Linking Avisynth statically or dynamically with other modules is making a
// combined work based on Avisynth.  Thus, the terms and conditions of the GNU
// General Public License cover the whole combination.
//
// As a special exception, the copyright holders of Avisynth give you
// permission to link Avisynth with independent modules that communicate with
// Avisynth solely through the interfaces defined in avisynth.h, regardless of the license
// terms of these independent modules, and to copy and distribute the
// resulting combined work under terms of your choice, provided that
// every copy of the combined work is accompanied by a complete copy of
// the source code of Avisynth (the version of Avisynth used to produce the
// combined work), being distributed under the terms of the GNU General
// Public License plus this exception.  An independent module is a module
// which is not derived from or based on Avisynth, such as 3rd-party filters,
// import and export plugins, or graphical user interfaces.





#ifndef AVISYNTH_H
#define AVISYNTH_H

enum { AVISYNTH_INTERFACE_VERSION = 2 };


/* Define all types necessary for interfacing with avisynth.dll
   Moved from internal.h */

// Win32 API macros, notably the types unsigned char, DWORD, int64_t, etc.
//#include <windef.h>
#include <stdio.h>
// COM interface macros
//#include <objbase.h>
#include <QAtomicInt>


// Raster types used by VirtualDub & Avisynth
#define in64 (int64_t)(unsigned short)
typedef int64_t	Pixel;    // this will break on 64-bit machines!
typedef int64_t	Pixel32;
typedef unsigned char   Pixel8;
typedef int64_t			PixCoord;
typedef	int64_t			PixDim;
typedef	int64_t			PixOffset;


// Set up debugging macros
#define _RPT0(a,b) ((void)0)
#define _RPT1(a,b,c) ((void)0)
#define _RPT2(a,b,c,d) ((void)0)
#define _RPT3(a,b,c,d,e) ((void)0)
#define _RPT4(a,b,c,d,e,f) ((void)0)
#define _ASSERTE(x) assert(x)
#define _ASSERT(x) assert(x)
#include <assert.h>


// I had problems with Premiere wanting 1-unsigned char alignment for its structures,
// so I now set the Avisynth struct alignment explicitly here.
#pragma pack(push,8)

#define FRAME_ALIGN 16
// Default frame alignment is 16 unsigned chars, to help P4, when using SSE2

// The VideoInfo struct holds global information about a clip (i.e.
// information that does not depend on the frame number).  The GetVideoInfo
// method in IClip returns this struct.

// Audio Sample information
typedef float SFLOAT;

enum {SAMPLE_INT8  = 1<<0,
        SAMPLE_INT16 = 1<<1, 
        SAMPLE_INT24 = 1<<2,    // Int24 is a very stupid thing to code, but it's supported by some hardware.
        SAMPLE_INT32 = 1<<3,
        SAMPLE_FLOAT = 1<<4};

enum {
   PLANAR_Y=1<<0,
   PLANAR_U=1<<1,
   PLANAR_V=1<<2,
   PLANAR_ALIGNED=1<<3,
   PLANAR_Y_ALIGNED=PLANAR_Y|PLANAR_ALIGNED,
   PLANAR_U_ALIGNED=PLANAR_U|PLANAR_ALIGNED,
   PLANAR_V_ALIGNED=PLANAR_V|PLANAR_ALIGNED
  };

struct VideoInfo {
  int width, height;    // width=0 means no video
  unsigned fps_numerator, fps_denominator;
  int num_frames;
  // This is more extensible than previous versions. More properties can be added seeminglesly.

  // Colorspace properties.
  enum {
    CS_BGR = 1<<28,  
    CS_YUV = 1<<29,
    CS_INTERLEAVED = 1<<30,
    CS_PLANAR = 1<<31
  };

  // Specific colorformats
  enum { CS_UNKNOWN = 0,
         CS_BGR24 = 1<<0 | CS_BGR | CS_INTERLEAVED,
         CS_BGR32 = 1<<1 | CS_BGR | CS_INTERLEAVED,
         CS_YUY2 = 1<<2 | CS_YUV | CS_INTERLEAVED,
         CS_YV12 = 1<<3 | CS_YUV | CS_PLANAR,  // y-v-u, planar
         CS_I420 = 1<<4 | CS_YUV | CS_PLANAR,  // y-u-v, planar
         CS_IYUV = 1<<4 | CS_YUV | CS_PLANAR  // same as above
         };
  int pixel_type;                // changed to int as of 2.5
  

  int audio_samples_per_second;   // 0 means no audio
  int sample_type;                // as of 2.5
  int64_t num_audio_samples;      // changed as of 2.5
  int nchannels;                  // as of 2.5

  // Imagetype properties

  int image_type;

  enum {
    IT_BFF = 1<<0,
    IT_TFF = 1<<1,
    IT_FIELDBASED = 1<<2
  };

  // useful functions of the above
  bool HasVideo() const { return (width!=0); }
  bool HasAudio() const { return (audio_samples_per_second!=0); }
  bool IsRGB() const { return !!(pixel_type&CS_BGR); }
  bool IsRGB24() const { return (pixel_type&CS_BGR24)==CS_BGR24; } // Clear out additional properties
  bool IsRGB32() const { return (pixel_type & CS_BGR32) == CS_BGR32 ; }
  bool IsYUV() const { return !!(pixel_type&CS_YUV ); }
  bool IsYUY2() const { return (pixel_type & CS_YUY2) == CS_YUY2; }  
  bool IsYV12() const { return ((pixel_type & CS_YV12) == CS_YV12)||((pixel_type & CS_I420) == CS_I420); }
  bool IsColorSpace(int c_space) const { return ((pixel_type & c_space) == c_space); }
  bool Is(int property) const { return ((pixel_type & property)==property ); }
  bool IsPlanar() const { return !!(pixel_type & CS_PLANAR); }
  bool IsFieldBased() const { return !!(image_type & IT_FIELDBASED); }
  bool IsParityKnown() const { return ((image_type & IT_FIELDBASED)&&(image_type & (IT_BFF||IT_TFF))); }
  bool IsBFF() const { return !!(image_type & IT_BFF); }
  bool IsTFF() const { return !!(image_type & IT_TFF); }
  
  bool IsVPlaneFirst() const {return ((pixel_type & CS_YV12) == CS_YV12); }  // Don't use this 
  int unsigned charsFromPixels(int pixels) const { return pixels * (BitsPerPixel()>>3); }   // Will not work on planar images, but will return only luma planes
  int RowSize() const { return unsigned charsFromPixels(width); }  // Also only returns first plane on planar images
  int BMPSize() const { if (IsPlanar()) {int p = height * ((RowSize()+3) & ~3); p+=p>>1; return p;  } return height * ((RowSize()+3) & ~3); }
  int64_t AudioSamplesFromFrames(int64_t frames) const { return ((int64_t)(frames) * audio_samples_per_second * fps_denominator / fps_numerator); }
  int FramesFromAudioSamples(int64_t samples) const { return (int)(samples * (int64_t)fps_numerator / (int64_t)fps_denominator / (int64_t)audio_samples_per_second); }
  int64_t AudioSamplesFromunsigned chars(int64_t unsigned chars) const { return unsigned chars / unsigned charsPerAudioSample(); }
  int64_t unsigned charsFromAudioSamples(int64_t samples) const { return samples * unsigned charsPerAudioSample(); }
  int AudioChannels() const { return nchannels; }
  int SampleType() const{ return sample_type;}
  int SamplesPerSecond() const { return audio_samples_per_second; }
  int unsigned charsPerAudioSample() const { return nchannels*unsigned charsPerChannelSample();}
  void SetFieldBased(bool isfieldbased)  { if (isfieldbased) image_type|=IT_FIELDBASED; else  image_type&=~IT_FIELDBASED; }
  void Set(int property)  { image_type|=property; }
  void Clear(int property)  { image_type&=~property; }

  int BitsPerPixel() const { 
    switch (pixel_type) {
      case CS_BGR24:
        return 24;
      case CS_BGR32:
        return 32;
      case CS_YUY2:
        return 16;
      case CS_YV12:
      case CS_I420:
        return 12;
      default:
        return 0;
    }
  }
  int unsigned charsPerChannelSample() const {
    switch (sample_type) {
    case SAMPLE_INT8:
      return sizeof(signed char);
    case SAMPLE_INT16:
      return sizeof(signed short);
    case SAMPLE_INT24:
      return 3;
    case SAMPLE_INT32:
      return sizeof(signed int);
    case SAMPLE_FLOAT:
      return sizeof(SFLOAT);
    default:
      _ASSERTE("Sample type not recognized!");
      return 0;
    }
  }

  // useful mutator
  void SetFPS(unsigned numerator, unsigned denominator) {
    unsigned x=numerator, y=denominator;
    while (y) {   // find gcd
      unsigned t = x%y; x = y; y = t;
    }
    fps_numerator = numerator/x;
    fps_denominator = denominator/x;
  }
  // Test for same colorspace
  bool IsSameColorspace(const VideoInfo& vi) {
    if (vi.pixel_type == pixel_type) return TRUE;
    if (IsYV12() && vi.IsYV12()) return TRUE;
    return FALSE;
  }

};

enum {
  FILTER_TYPE=1,
  FILTER_INPUT_COLORSPACE=2,
  FILTER_OUTPUT_TYPE=9,
  FILTER_NAME=4,
  FILTER_AUTHOR=5,
  FILTER_VERSION=6,
  FILTER_ARGS=7,
  FILTER_ARGS_INFO=8,
  FILTER_ARGS_DESCRIPTION=10,
  FILTER_DESCRIPTION=11
};
enum {  //SUBTYPES
  FILTER_TYPE_AUDIO=1,
  FILTER_TYPE_VIDEO=2,
  FILTER_OUTPUT_TYPE_SAME=3,
  FILTER_OUTPUT_TYPE_DIFFERENT=4
};



// VideoFrameBuffer holds information about a memory block which is used
// for video data.  For efficiency, instances of this class are not deleted
// when the refcount reaches zero; instead they're stored in a linked list
// to be reused.  The instances are deleted when the corresponding AVS
// file is closed.

class VideoFrameBuffer {
  unsigned char* const data;
  const int data_size;
  // sequence_number is incremented every time the buffer is changed, so
  // that stale views can tell they're no int64_ter valid.
  int64_t sequence_number;

  friend class VideoFrame;
  friend class Cache;
  friend class ScriptEnvironment;
  int64_t refcount;

public:
  VideoFrameBuffer(int size);
  VideoFrameBuffer();
  ~VideoFrameBuffer();

  const unsigned char* GetReadPtr() const { return data; }
  unsigned char* GetWritePtr() { ++sequence_number; return data; }
  int GetDataSize() { return data_size; }
  int GetSequenceNumber() { return sequence_number; }
  int GetRefcount() { return refcount; }
};


class IClip;
class PClip;
class PVideoFrame;
class IScriptEnvironment;
class AVSValue;


// VideoFrame holds a "window" into a VideoFrameBuffer.  Operator new
// is overloaded to recycle class instances.

class VideoFrame {
  int refcount;
  VideoFrameBuffer* const vfb;
  const int offset, pitch, row_size, height, offsetU, offsetV, pitchUV;  // U&V offsets are from top of picture.

  friend class PVideoFrame;
  QAtomicInt::ref((int64_t *)&refcount);
  void AddRef() { reference::fetchAndAddOrdered(1) + 1; }
  void Release() { if (refcount==1) refrence(&vfb->refcount)+1; reference::fetchAndAddOrdered((int64_t *)&refcount) + 1; }

  friend class ScriptEnvironment;
  friend class Cache;

  VideoFrame(VideoFrameBuffer* _vfb, int _offset, int _pitch, int _row_size, int _height);
  VideoFrame(VideoFrameBuffer* _vfb, int _offset, int _pitch, int _row_size, int _height, int _offsetU, int _offsetV, int _pitchUV);

  void* operator new(unsigned size);
// TESTME: OFFSET U/V may be switched to what could be expected from AVI standard!
public:
  int GetPitch() const { return pitch; }
  int GetPitch(int plane) const { switch (plane) {case PLANAR_U: case PLANAR_V: return pitchUV;} return pitch; }
  int GetRowSize() const { return row_size; }
  int GetRowSize(int plane) const { 
    switch (plane) {
    case PLANAR_U: case PLANAR_V: if (pitchUV) return row_size>>1; else return 0;
    case PLANAR_U_ALIGNED: case PLANAR_V_ALIGNED: 
      if (pitchUV) { 
        int r = ((row_size+FRAME_ALIGN-1)&(~(FRAME_ALIGN-1)) )>>1; // Aligned rowsize
        if (r<=pitchUV) 
          return r; 
        return row_size>>1; 
      } else return 0;
    case PLANAR_Y_ALIGNED:
      int r = (row_size+FRAME_ALIGN-1)&(~(FRAME_ALIGN-1)); // Aligned rowsize
      if (r<=pitch) 
        return r; 
      return row_size;
    }
    return row_size; }
  int GetHeight() const { return height; }
  int GetHeight(int plane) const {  switch (plane) {case PLANAR_U: case PLANAR_V: if (pitchUV) return height>>1; return 0;} return height; }

  // generally you shouldn't use these three
  VideoFrameBuffer* GetFrameBuffer() const { return vfb; }
  int GetOffset() const { return offset; }
  int GetOffset(int plane) const { switch (plane) {case PLANAR_U: return offsetU;case PLANAR_V: return offsetV;default: return offset;}; }

  // in plugins use env->SubFrame()
  VideoFrame* Subframe(int rel_offset, int new_pitch, int new_row_size, int new_height) const;
  VideoFrame* Subframe(int rel_offset, int new_pitch, int new_row_size, int new_height, int rel_offsetU, int rel_offsetV, int pitchUV) const;


  const unsigned char* GetReadPtr() const { return vfb->GetReadPtr() + offset; }
  const unsigned char* GetReadPtr(int plane) const { return vfb->GetReadPtr() + GetOffset(plane); }

  bool IsWritable() const { return (refcount == 1 && vfb->refcount == 1); }

  unsigned char* GetWritePtr() const {
    if (vfb->GetRefcount()>1) {
      _ASSERT(FALSE);
      //throw AvisynthError("Internal Error - refcount was more than one!");
    }
    return IsWritable() ? (vfb->GetWritePtr() + offset) : 0;
  }

  unsigned char* GetWritePtr(int plane) const {
    if (plane==PLANAR_Y) {
      if (vfb->GetRefcount()>1) {
        _ASSERT(FALSE);
//        throw AvisynthError("Internal Error - refcount was more than one!");
      }
      return IsWritable() ? vfb->GetWritePtr() + GetOffset(plane) : 0;
    }
    return vfb->data + GetOffset(plane);
  }

  ~VideoFrame() { InterlockedDecrement(&vfb->refcount); }
};

enum {
  CACHE_NOTHING=0,
  CACHE_RANGE=1,
  CACHE_ALL=2
 };

// Base class for all filters.
class IClip {
  friend class PClip;
  friend class AVSValue;
  int refcnt;
  QAtomicInt::QAtomicInt(refcnt);
  void AddRef() { QAtomicInt::ref((int64_t *)&refcnt); }
  void Release() { QAtomicInt::deref((int64_t *)&refcnt); if (!refcnt) delete this; }
public:
  IClip() : refcnt(0) {}

  virtual int __stdcall GetVersion() { return AVISYNTH_INTERFACE_VERSION; }
  
  virtual PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env) = 0;
  virtual bool __stdcall GetParity(int n) = 0;  // return field parity if field_based, else parity of first field in frame
  virtual void __stdcall GetAudio(void* buf, int64_t start, int64_t count, IScriptEnvironment* env) = 0;  // start and count are in samples
  virtual void __stdcall SetCacheHints(int cachehints,int frame_range) = 0 ;  // We do not pass cache requests upwards, only to the next filter.
  virtual const VideoInfo& __stdcall GetVideoInfo() = 0;
  virtual __stdcall ~IClip() {}
};


// smart pointer to IClip
class PClip {

  IClip* p;

  IClip* GetPointerWithAddRef() const { if (p) p->AddRef(); return p; }
  friend class AVSValue;
  friend class VideoFrame;

  void Init(IClip* x) {
    if (x) x->AddRef();
    p=x;
  }
  void Set(IClip* x) {
    if (x) x->AddRef();
    if (p) p->Release();
    p=x;
  }

public:
  PClip() { p = 0; }
  PClip(const PClip& x) { Init(x.p); }
  PClip(IClip* x) { Init(x); }
  void operator=(IClip* x) { Set(x); }
  void operator=(const PClip& x) { Set(x.p); }

  IClip* operator->() const { return p; }

  // useful in conditional expressions
  operator void*() const { return p; }
  bool operator!() const { return !p; }

  ~PClip() { if (p) p->Release(); }
};


// smart pointer to VideoFrame
class PVideoFrame {

  VideoFrame* p;

  void Init(VideoFrame* x) {
    if (x) x->AddRef();
    p=x;
  }
  void Set(VideoFrame* x) {
    if (x) x->AddRef();
    if (p) p->Release();
    p=x;
  }

public:
  PVideoFrame() { p = 0; }
  PVideoFrame(const PVideoFrame& x) { Init(x.p); }
  PVideoFrame(VideoFrame* x) { Init(x); }
  void operator=(VideoFrame* x) { Set(x); }
  void operator=(const PVideoFrame& x) { Set(x.p); }

  VideoFrame* operator->() const { return p; }

  // for conditional expressions
  operator void*() const { return p; }
  bool operator!() const { return !p; }

  ~PVideoFrame() { if (p) p->Release();}
};


class AVSValue {
public:

  AVSValue() { type = 'v'; }
  AVSValue(IClip* c) { type = 'c'; clip = c; if (c) c->AddRef(); }
  AVSValue(const PClip& c) { type = 'c'; clip = c.GetPointerWithAddRef(); }
  AVSValue(bool b) { type = 'b'; boolean = b; }
  AVSValue(int i) { type = 'i'; integer = i; }
//  AVSValue(int64_t l) { type = 'l'; int64_tlong = l; }
  AVSValue(float f) { type = 'f'; floating_pt = f; }
  AVSValue(double f) { type = 'f'; floating_pt = float(f); }
  AVSValue(const char* s) { type = 's'; string = s; }
  AVSValue(const AVSValue* a, int size) { type = 'a'; array = a; array_size = size; }
  AVSValue(const AVSValue& v) { Assign(&v, true); }

  ~AVSValue() { if (IsClip() && clip) clip->Release(); }
  AVSValue& operator=(const AVSValue& v) { Assign(&v, false); return *this; }

  // Note that we transparently allow 'int' to be treated as 'float'.
  // There are no int<->bool conversions, though.

  bool Defined() const { return type != 'v'; }
  bool IsClip() const { return type == 'c'; }
  bool IsBool() const { return type == 'b'; }
  bool IsInt() const { return type == 'i'; }
//  bool Isint64_t() const { return (type == 'l'|| type == 'i'); }
  bool IsFloat() const { return type == 'f' || type == 'i'; }
  bool IsString() const { return type == 's'; }
  bool IsArray() const { return type == 'a'; }

  PClip AsClip() const { _ASSERTE(IsClip()); return IsClip()?clip:0; }
  bool AsBool() const { _ASSERTE(IsBool()); return boolean; }
  int AsInt() const { _ASSERTE(IsInt()); return integer; }   
//  int Asint64_t() const { _ASSERTE(Isint64_t()); return int64_tlong; }
  const char* AsString() const { _ASSERTE(IsString()); return IsString()?string:0; }
  double AsFloat() const { _ASSERTE(IsFloat()); return IsInt()?integer:floating_pt; }

  bool AsBool(bool def) const { _ASSERTE(IsBool()||!Defined()); return IsBool() ? boolean : def; }
  int AsInt(int def) const { _ASSERTE(IsInt()||!Defined()); return IsInt() ? integer : def; }
  double AsFloat(double def) const { _ASSERTE(IsFloat()||!Defined()); return IsInt() ? integer : type=='f' ? floating_pt : def; }
  const char* AsString(const char* def) const { _ASSERTE(IsString()||!Defined()); return IsString() ? string : def; }

  int ArraySize() const { _ASSERTE(IsArray()); return IsArray()?array_size:1; }

  const AVSValue& operator[](int index) const {
    _ASSERTE(IsArray() && index>=0 && index<array_size);
    return (IsArray() && index>=0 && index<array_size) ? array[index] : *this;
  }

private:

  short type;  // 'a'rray, 'c'lip, 'b'ool, 'i'nt, 'f'loat, 's'tring, 'v'oid, or 'l'ong
  short array_size;
  union {
    IClip* clip;
    bool boolean;
    int integer;
    float floating_pt;
    const char* string;
    const AVSValue* array;
//    int64_t int64_tlong;
  };

  void Assign(const AVSValue* src, bool init) {
    if (src->IsClip() && src->clip)
      src->clip->AddRef();
    if (!init && IsClip() && clip)
      clip->Release();
    // make sure this copies the whole struct!
    ((qint32*)this)[0] = ((qint32*)src)[0];
    ((qint32*)this)[1] = ((qint32*)src)[1];
  }
};


// instantiable null filter
class GenericVideoFilter : public IClip {
protected:
  PClip child;
  VideoInfo vi;
public:
  GenericVideoFilter(PClip _child) : child(_child) { vi = child->GetVideoInfo(); }
  PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env) { return child->GetFrame(n, env); }
  void __stdcall GetAudio(void* buf, int64_t start, int64_t count, IScriptEnvironment* env) { child->GetAudio(buf, start, count, env); }
  const VideoInfo& __stdcall GetVideoInfo() { return vi; }
  bool __stdcall GetParity(int n) { return child->GetParity(n); }
  void __stdcall SetCacheHints(int cachehints,int frame_range);   // We do not pass cache requests upwards, only to the next filter.
};


class AvisynthError /* exception */ {
public:
  const char* const msg;
  AvisynthError(const char* _msg) : msg(_msg) {}
};




/* Helper classes useful to plugin authors */

class AlignPlanar : public GenericVideoFilter 
{
public:
  AlignPlanar(PClip _clip);
  static PClip Create(PClip clip);
  PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env);
};



class FillBorder : public GenericVideoFilter 
{
public:
  FillBorder(PClip _clip);
  static PClip Create(PClip clip);
  PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env);
};



class ConvertAudio : public GenericVideoFilter 
/**
  * Helper class to convert audio to any format
 **/
{
public:
  ConvertAudio(PClip _clip, int prefered_format);
  void __stdcall GetAudio(void* buf, int64_t start, int64_t count, IScriptEnvironment* env);

  static PClip Create(PClip clip, int sample_type, int prefered_type);
  static AVSValue __cdecl Create_float(AVSValue args, void*, IScriptEnvironment*);
  static AVSValue __cdecl Create_32bit(AVSValue args, void*, IScriptEnvironment*);
  static AVSValue __cdecl Create_24bit(AVSValue args, void*, IScriptEnvironment*);
  static AVSValue __cdecl Create_16bit(AVSValue args, void*, IScriptEnvironment*);
  static AVSValue __cdecl Create_8bit(AVSValue args, void*, IScriptEnvironment*);
  virtual ~ConvertAudio()
  {if (tempbuffer_size) {delete[] tempbuffer;tempbuffer_size=0;}}
private:
  void convertToFloat(char* inbuf, float* outbuf, char sample_type, int count);
  void convertFromFloat(float* inbuf, void* outbuf, char sample_type, int count);

  inline int Saturate_int8(float n);
  inline short Saturate_int16(float n);
  inline int Saturate_int24(float n);
  inline int Saturate_int32(float n);

  char src_format;
  char dst_format;
  int src_bps;
  char *tempbuffer;
  SFLOAT *floatbuffer;
  int tempbuffer_size;
};


// For GetCPUFlags.  These are backwards-compatible with those in VirtualDub.
enum {                    
                    /* slowest CPU to support extension */
  CPUF_FORCE			  = 0x01,   // N/A
  CPUF_FPU			    = 0x02,   // 386/486DX
  CPUF_MMX			    = 0x04,   // P55C, K6, PII
  CPUF_INTEGER_SSE	= 0x08,		// PIII, Athlon
  CPUF_SSE			    = 0x10,		// PIII, Athlon XP/MP
  CPUF_SSE2			    = 0x20,		// PIV, Hammer
  CPUF_3DNOW			  = 0x40,   // K6-2
  CPUF_3DNOW_EXT		= 0x80,		// Athlon
  CPUF_X86_64       = 0xA0   // Hammer (note: equiv. to 3DNow + SSE2, which only Hammer
                              //         will have anyway)
};
#define MAX_INT 0x7fffffff
#define MIN_INT 0x80000000



class IScriptEnvironment {
public:
  virtual __stdcall ~IScriptEnvironment() {}

  virtual /*static*/ int64_t __stdcall GetCPUFlags() = 0;

  virtual char* __stdcall SaveString(const char* s, int length = -1) = 0;
  virtual char* __stdcall Sprintf(const char* fmt, ...) = 0;
  // note: val is really a va_list; I hope everyone typedefs va_list to a pointer
  virtual char* __stdcall VSprintf(const char* fmt, void* val) = 0;

  __declspec(noreturn) virtual void __stdcall ThrowError(const char* fmt, ...) = 0;

  class NotFound /*exception*/ {};  // thrown by Invoke and GetVar

  typedef AVSValue (__cdecl *ApplyFunc)(AVSValue args, void* user_data, IScriptEnvironment* env);

  virtual void __stdcall AddFunction(const char* name, const char* params, ApplyFunc apply, void* user_data) = 0;
  virtual bool __stdcall FunctionExists(const char* name) = 0;
  virtual AVSValue __stdcall Invoke(const char* name, const AVSValue args, const char** arg_names=0) = 0;

  virtual AVSValue __stdcall GetVar(const char* name) = 0;
  virtual bool __stdcall SetVar(const char* name, const AVSValue& val) = 0;
  virtual bool __stdcall SetGlobalVar(const char* name, const AVSValue& val) = 0;

  virtual void __stdcall PushContext(int level=0) = 0;
  virtual void __stdcall PopContext() = 0;

  // align should be 4 or 8
  virtual PVideoFrame __stdcall NewVideoFrame(const VideoInfo& vi, int align=FRAME_ALIGN) = 0;

  virtual bool __stdcall MakeWritable(PVideoFrame* pvf) = 0;

  virtual /*static*/ void __stdcall BitBlt(unsigned char* dstp, int dst_pitch, const unsigned char* srcp, int src_pitch, int row_size, int height) = 0;

  typedef void (__cdecl *ShutdownFunc)(void* user_data, IScriptEnvironment* env);
  virtual void __stdcall AtExit(ShutdownFunc function, void* user_data) = 0;

  virtual void __stdcall CheckVersion(int version = AVISYNTH_INTERFACE_VERSION) = 0;

  virtual PVideoFrame __stdcall Subframe(PVideoFrame src, int rel_offset, int new_pitch, int new_row_size, int new_height) = 0;

	virtual int __stdcall SetMemoryMax(int mem) = 0;

  virtual int __stdcall SetWorkingDir(const char * newdir) = 0;

};


// avisynth.dll exports this; it's a way to use it as a library, without
// writing an AVS script or without going through AVIFile.
IScriptEnvironment* __stdcall CreateScriptEnvironment(int version = AVISYNTH_INTERFACE_VERSION);


#pragma pack(pop)

#endif //__AVISYNTH_H__