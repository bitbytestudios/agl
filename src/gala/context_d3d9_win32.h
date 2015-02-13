//===-- gala/context_d3d9_win32.h -------------------------------*- C++ -*-===//
//
//  Gala
//
//  This file is distributed under the terms described in LICENSE.
//
//  Author(s):
//
//    * Michael Williams <mike@origamicomet.com>
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief TODO(mike): Document this file.
///
//===----------------------------------------------------------------------===//

#ifndef _GALA_CONTEXT_D3D9_WIN32_H_
#define _GALA_CONTEXT_D3D9_WIN32_H_

//============================================================================//

#include "gala/config.h"
#include "gala/linkage.h"
#include "gala/foundation.h"
#include "gala/error.h"
#include "gala/context.h"

//===----------------------------------------------------------------------===//

#define _WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <d3d9.h>

//============================================================================//

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//===----------------------------------------------------------------------===//

/// \brief
///
typedef struct gala_context_d3d9 {
  /// \copydoc ::gala_context_t
  gala_context_t __context__;
  /// TODO(mike): Document this.
  IDirect3DDevice9 *Direct3DDevice9;
  /// TODO(mike): Document this.
  HWND hFocusWindow;
} gala_context_d3d9_t;

//===----------------------------------------------------------------------===//

extern
gala_error_t gala_context_create_swap_chain_d3d9(
  gala_context_t *context,
  const gala_swap_chain_opts_t *opts,
  gala_swap_chain_t **swap_chain,
  const gala_error_details_t **error_details);

//===----------------------------------------------------------------------===//

#ifdef __cplusplus
}
#endif // __cplusplus

//============================================================================//

#endif // _GALA_CONTEXT_D3D9_WIN32_H_

//============================================================================//
