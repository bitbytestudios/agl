//===-- gala/d3d11/types.h ---------------------------------------*- C++ -*-===//
//
//  Gala
//
//  This file is distributed under the terms described in LICENSE.
//
//  Author(s):
//
//   * Michael Williams <mike@origamicomet.com>
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief
///
//===----------------------------------------------------------------------===//

#ifndef _GALA_D3D11_TYPES_H_
#define _GALA_D3D11_TYPES_H_

//============================================================================//

#include "gala/backend.h"

//===----------------------------------------------------------------------===//

#if BITBYTE_FOUNDATION_TIER0_SYSTEM == __BITBYTE_FOUNDATION_TIER0_SYSTEM_WINDOWS__
  #define WIN32_LEAN_AND_MEAN
  #define WIN32_EXTRA_LEAN

  #include <windows.h>
  #include <DXGI.h>
  #include <d3d11.h>

  #undef WIN32_EXTRA_LEAN
  #undef WIN32_LEAN_AND_MEAN

  #undef NEAR
  #undef FAR
  #undef near
  #undef far
  #undef NO_ERROR
  #undef ERROR
  #undef MK_SHIFT
  #undef MK_ALT
  #undef min
  #undef max
  #undef rad1
#else
  #error ("Direct3D 11 is unavailable or unsupported on this platform!")
#endif

//============================================================================//

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//===----------------------------------------------------------------------===//

struct gala_d3d11_backend {
  gala_backend_t __backend__;
#if BITBYTE_FOUNDATION_TIER0_SYSTEM == __BITBYTE_FOUNDATION_TIER0_SYSTEM_WINDOWS__
  struct {
    HMODULE dll;
    IDXGIFactory *factory;
  } dxgi;
  struct {
    UINT count;
    IDXGIAdapter **itfs;
  } adapters;
#endif
};

//===----------------------------------------------------------------------===//

struct gala_d3d11_adapter {
  gala_adapter_t __adapter__;
#if BITBYTE_FOUNDATION_TIER0_SYSTEM == __BITBYTE_FOUNDATION_TIER0_SYSTEM_WINDOWS__
  IDXGIAdapter *itf;
  struct {
    UINT count;
    IDXGIOutput **itfs;
  } outputs;
#endif
};

//===----------------------------------------------------------------------===//

struct gala_d3d11_output {
  gala_output_t __output__;
#if BITBYTE_FOUNDATION_TIER0_SYSTEM == __BITBYTE_FOUNDATION_TIER0_SYSTEM_WINDOWS__
  IDXGIOutput *itf;
#endif
};

//===----------------------------------------------------------------------===//

#ifdef __cplusplus
}
#endif // __cplusplus

//============================================================================//

#endif // _GALA_D3D11_TYPES_H_

//============================================================================//