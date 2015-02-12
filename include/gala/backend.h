//===-- gala/backend.h ------------------------------------------*- C++ -*-===//
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

#ifndef _GALA_BACKEND_H_
#define _GALA_BACKEND_H_

//============================================================================//

#include "gala/config.h"
#include "gala/linkage.h"
#include "gala/foundation.h"
#include "gala/error.h"

//===----------------------------------------------------------------------===//

#include "gala/adapter.h"
#include "gala/context.h"

//============================================================================//

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//===----------------------------------------------------------------------===//

/// \brief
///
typedef enum gala_backend_type {
  /// Null.
  GALA_BACKEND_NULL = 0,
  /// Direct3D 9.
  GALA_BACKEND_D3D9 = 1
} gala_backend_type_t;

//===----------------------------------------------------------------------===//

/// \brief
///
typedef gala_error_t (*gala_backend_shutdown_fn)(
  struct gala_backend *backend,
  const gala_error_details_t **error_details);

//===----------------------------------------------------------------------===//

/// \brief
///
typedef gala_error_t (*gala_backend_create_context_fn)(
  struct gala_backend *backend,
  const size_t adapter,
  gala_context_t **context,
  const gala_error_details_t **error_details);

//===----------------------------------------------------------------------===//

/// \brief
///
typedef struct gala_backend {
  /// \copydoc ::gala_backend_type_t
  gala_backend_type_t type;
  /// \copydoc ::gala_backend_shutdown_fn
  gala_backend_shutdown_fn shutdown;
  /// \copydoc :;gala_backend_create_context_fn
  gala_backend_create_context_fn create_context;
  /// TODO(mike): Document this.
  size_t num_adapters;
  /// TODO(mike): Document this.
  const gala_adapter_t **adapters;
} gala_backend_t;

//===----------------------------------------------------------------------===//

/// \brief
/// \param type
/// \param backend
/// \param error_details
/// \returns
///
extern
GALA_PUBLIC
gala_error_t gala_backend_initialize(
  const gala_backend_type_t type,
  gala_backend_t **backend,
  const gala_error_details_t **error_details);

//===----------------------------------------------------------------------===//

/// \brief
/// \param backend
/// \param buf
/// \param buf_sz
/// \param error_details
/// \returns
///
extern
GALA_PUBLIC
gala_error_t gala_backend_to_s(
  const gala_backend_t *backend,
  char *buf,
  const size_t buf_sz,
  const gala_error_details_t **error_details);

//===----------------------------------------------------------------------===//

#ifdef __cplusplus
}
#endif // __cplusplus

//============================================================================//

#ifdef __cplusplus

//===----------------------------------------------------------------------===//

namespace gala {

//===----------------------------------------------------------------------===//

/// \copydoc ::gala_backend_t
class Backend {
 public:
  /// \copydoc ::gala_backend_type_t
  enum Type {
    /// \copydoc ::GALA_BACKEND_NULL
    kNull = ::GALA_BACKEND_NULL,
    /// \copydoc ::GALA_BACKEND_D3D9
    kDirect3D9 = ::GALA_BACKEND_D3D9
  };

 public:
  /// \copydoc ::gala_backend_initialize
  template <Type _Type>
  static
  GALA_PUBLIC
  ::gala::Error initialize(
    ::gala::Backend **backend,
    const ::gala::ErrorDetails **error_details = NULL)
  {
    return (::gala::Error)::gala_backend_initialize((gala_backend_type_t)_Type,
                                                    (::gala_backend_t **)backend,
                                                    (const ::gala_error_details_t **)error_details);
  }

  /// \copydoc ::gala_backend_t::shutdown
  ::gala::Error shutdown(
    const ::gala::ErrorDetails **error_details = NULL)
  {
    return (::gala::Error)__backend__.shutdown(&__backend__,
                                               (const ::gala_error_details_t **)error_details);
  }

  /// \copydoc ::gala_backend::create_context
  ::gala::Error create_context(
    const size_t adapter,
    ::gala::Context **context,
    const ::gala::ErrorDetails **error_details = NULL)
  {
    return (::gala::Error)__backend__.create_context(&__backend__,
                                                     adapter,
                                                     (::gala_context_t **)context,
                                                     (const ::gala_error_details_t **)error_details);
  }

 public:
  /// \copydoc ::gala_backend_to_s
  ::gala::Error to_s(
    char *buf,
    const size_t buf_sz,
    const ::gala::ErrorDetails **error_details = NULL) const
  {
    return (::gala::Error)::gala_backend_to_s(&__backend__,
                                              buf, buf_sz,
                                              (const ::gala_error_details_t **)error_details);
  }

 public:
  /// \copydoc ::gala_backend_t::type
  ::gala::Backend::Type type() const {
    return (::gala::Backend::Type)__backend__.type;
  }

  /// \copydoc ::gala_backend_t::num_adapters
  size_t num_adapters() const {
    return __backend__.num_adapters;
  }

  /// \copydoc ::gala_backend_t::adapters
  const ::gala::Adapter **adapters() const {
    return (const ::gala::Adapter **)__backend__.adapters;
  }

 public:
  ::gala_backend_t __backend__;
};

//===----------------------------------------------------------------------===//

} // gala

//===----------------------------------------------------------------------===//

#endif // __cplusplus

//============================================================================//

#endif // _GALA_BACKEND_H_

//============================================================================//
