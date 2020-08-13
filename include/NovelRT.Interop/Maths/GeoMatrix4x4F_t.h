// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root for more information.

#ifndef NOVELRT_INTEROP_MATHS_GEOMATRIX4X4F_T_H
#define NOVELRT_INTEROP_MATHS_GEOMATRIX4X4F_T_H

#include "NovelRT.Interop/Maths/GeoVector4F_t.h"

#ifdef __cplusplus
extern "C" {
#endif

  struct GeoMatrix4x4F_t
  {
    GeoVector4F_t x;
    GeoVector4F_t y;
    GeoVector4F_t z;
    GeoVector4F_t w;
  };

  GeoMatrix4x4F_t GeoMatrix4x4F_create(GeoVector4F_t& x, GeoVector4F_t& y, GeoVector4F_t& z, GeoVector4F_t& w);
  GeoVector4F_t GeoMatrix4x4F_getX(GeoMatrix4x4F_t& gm);
  void GeoMatrix4x4F_setX(GeoMatrix4x4F_t& gm, const GeoVector4F_t& value);
  GeoVector4F_t GeoMatrix4x4F_getY(GeoMatrix4x4F_t& gm);
  void GeoMatrix4x4F_setY(GeoMatrix4x4F_t& gm, const GeoVector4F_t& value);
  GeoVector4F_t GeoMatrix4x4F_getZ(GeoMatrix4x4F_t& gm);
  void GeoMatrix4x4F_setZ(GeoMatrix4x4F_t& gm, const GeoVector4F_t& value);
  GeoVector4F_t GeoMatrix4x4F_getW(GeoMatrix4x4F_t& gm);
  void GeoMatrix4x4F_setW(GeoMatrix4x4F_t& gm, const GeoVector4F_t& value);
  GeoMatrix4x4F_t GeoMatrix4x4F_getDefaultIdentity();
  bool GeoMatrix4x4F_equal(const GeoMatrix4x4F_t& first, const GeoMatrix4x4F_t& other);
  bool GeoMatrix4x4F_notEqual(const GeoMatrix4x4F_t& first, const GeoMatrix4x4F_t& other);
  GeoMatrix4x4F_t GeoMatrix4x4F_addMatrix(const GeoMatrix4x4F_t& first, const GeoMatrix4x4F_t& other);
  GeoMatrix4x4F_t GeoMatrix4x4F_subtractMatrix(const GeoMatrix4x4F_t& first, const GeoMatrix4x4F_t& other);
  GeoMatrix4x4F_t GeoMatrix4x4F_multiplyMatrix(const GeoMatrix4x4F_t& first, const GeoMatrix4x4F_t& other);
  void GeoMatrix4x4F_addIntoMatrix(GeoMatrix4x4F_t& first, const GeoMatrix4x4F_t& other);
  void GeoMatrix4x4F_subtractFromMatrix(GeoMatrix4x4F_t& first, const GeoMatrix4x4F_t& other);
  void GeoMatrix4x4F_multiplyIntoMatrix(GeoMatrix4x4F_t& first, const GeoMatrix4x4F_t& other);
  GeoMatrix4x4F_t GeoMatrix4x4F_addFloat(const GeoMatrix4x4F_t& matrix, float value);
  GeoMatrix4x4F_t GeoMatrix4x4F_subtractFloat(const GeoMatrix4x4F_t& matrix, float value);
  GeoMatrix4x4F_t GeoMatrix4x4F_multiplyFloat(const GeoMatrix4x4F_t& matrix, float value);
  void GeoMatrix4x4F_addFloatIntoMatrix(GeoMatrix4x4F_t& matrix, float value);
  void GeoMatrix4x4F_subFloatFromMatrix(GeoMatrix4x4F_t& matrix, float value);
  void GeoMatrix4x4F_multiplyFloatIntoMatrix(GeoMatrix4x4F_t& matrix, float value);

#ifdef __cplusplus
}
#endif

#endif //NOVELRT_INTEROP_MATHS_GEOMATRIX4X4F_T_H
