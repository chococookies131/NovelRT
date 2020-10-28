// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root for more information.
#include "NovelRT.Interop/NovelRTInteropUtils.h"

#ifndef NOVELRT_INTEROP_TIMING_TIMESTAMP_H
#define NOVELRT_INTEROP_TIMING_TIMESTAMP_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TimestampHandle* NovelRTTimestamp;

int32_t NovelRT_Timestamp_create(uint64_t ticks, NovelRTTimestamp* outputTimestamp, const char** errorMessage);

int32_t NovelRT_Timestamp_isNaN(NovelRTTimestamp timestamp, const char** errorMessage);
int32_t NovelRT_Timestamp_getSecondsDouble(NovelRTTimestamp timestamp, double* output, const char** errorMessage);
int32_t NovelRT_Timestamp_getSecondsFloat(NovelRTTimestamp timestamp, float* output, const char** errorMessage);
int32_t NovelRT_Timestamp_zero(NovelRTTimestamp* outputTimestamp, const char** errorMessage);
int32_t NovelRT_Timestamp_fromSeconds(double seconds, NovelRTTimestamp* outputTimestamp, const char** errorMessage);
int32_t NovelRT_Timestamp_addTimestamp(NovelRTTimestamp first, NovelRTTimestamp other, NovelRTTimestamp* output, const char** errorMessage);
int32_t NovelRT_Timestamp_subtractTimestamp(NovelRTTimestamp first, NovelRTTimestamp other, NovelRTTimestamp* output, const char** errorMessage);
int32_t NovelRT_Timestamp_multiplyTimestamp(NovelRTTimestamp first, NovelRTTimestamp other, NovelRTTimestamp* output, const char** errorMessage);
int32_t NovelRT_Timestamp_divideTimestamp(NovelRTTimestamp first, NovelRTTimestamp other, NovelRTTimestamp* output, const char** errorMessage);
int32_t NovelRT_Timestamp_addAssignTimestamp(NovelRTTimestamp first, NovelRTTimestamp other, const char** errorMessage);
int32_t NovelRT_Timestamp_subtractAssignTimestamp(NovelRTTimestamp first, NovelRTTimestamp other, const char** errorMessage);
int32_t NovelRT_Timestamp_multiplyAssignTimestamp(NovelRTTimestamp first, NovelRTTimestamp other, const char** errorMessage);
int32_t NovelRT_Timestamp_divideAssignTimestamp(NovelRTTimestamp first, NovelRTTimestamp other, const char** errorMessage);
int32_t NovelRT_Timestamp_lessThan(NovelRTTimestamp lhs, NovelRTTimestamp rhs, const char** errorMessage);
int32_t NovelRT_Timestamp_lessThanOrEqualTo(NovelRTTimestamp lhs, NovelRTTimestamp rhs, const char** errorMessage);
int32_t NovelRT_Timestamp_greaterThan(NovelRTTimestamp lhs, NovelRTTimestamp rhs, const char** errorMessage);
int32_t NovelRT_Timestamp_greaterThanOrEqualTo(NovelRTTimestamp lhs, NovelRTTimestamp rhs, const char** errorMessage);
int32_t NovelRT_Timestamp_equal(NovelRTTimestamp lhs, NovelRTTimestamp rhs, const char** errorMessage);
int32_t NovelRT_Timestamp_notEqual(NovelRTTimestamp lhs, NovelRTTimestamp rhs, const char** errorMessage);

#ifdef __cplusplus
}
#endif

#endif // NOVELRT_INTEROP_TIMING_TIMESTAMP_H